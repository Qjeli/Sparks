#include "s21_decimal.h"

int add(s21_decimal left, s21_decimal right, s21_decimal *result) {
  int res = 0;
  int tmp = 0;
  for (int i = 0; i <= 96; i++) {
    int tmp1 = s21_getBit(left, i);
    int tmp2 = s21_getBit(right, i);
    int tmp_res = tmp1 + tmp2 + tmp;
    if (tmp_res == 0) {
      s21_setBit(result, i, 0);
      tmp = 0;
    } else if (tmp_res == 1) {
      s21_setBit(result, i, 1);
      tmp = 0;
    } else if (tmp_res == 2 || tmp_res == 3) {
      if (i == 95) {
        res = 1;
        break;
      }
      s21_setBit(result, i, tmp_res == 2 ? 0 : 1);
      tmp = 1;
    }
  }

  s21_setScale(result, s21_getScale(left));
  int setSingn = (s21_getSign(left) + s21_getSign(right) + tmp) % 2;
  s21_setSign(result, setSingn);
  if (setSingn == 1) {
    result->bits[0] = ~result->bits[0];
    result->bits[1] = ~result->bits[1];
    result->bits[2] = ~result->bits[2];
    int tmp = 1;
    for (int i = 0; i <= 96; i++) {
      int tmp1 = s21_getBit(*result, i);
      int tmp_res = tmp1 + tmp;
      if (tmp_res == 0) {
        s21_setBit(result, i, 0);
        tmp = 0;
      } else if (tmp_res == 1) {
        s21_setBit(result, i, 1);
        tmp = 0;
      } else if (tmp_res == 2 || tmp_res == 3) {
        s21_setBit(result, i, tmp_res == 2 ? 0 : 1);
        tmp = 1;
      }
    }
  }
  return res;
}

// used in s21_add
void inverse(s21_decimal *value) {
  value->bits[0] = ~value->bits[0];
  value->bits[1] = ~value->bits[1];
  value->bits[2] = ~value->bits[2];
  int tmp = 1;
  for (int i = 0; i <= 96; i++) {
    int tmp1 = s21_getBit(*value, i);
    int tmp_res = tmp1 + tmp;
    if (tmp_res == 0) {
      s21_setBit(value, i, 0);
      tmp = 0;
    } else if (tmp_res == 1) {
      s21_setBit(value, i, 1);
      tmp = 0;
    } else if (tmp_res == 2 || tmp_res == 3) {
      s21_setBit(value, i, tmp_res == 2 ? 0 : 1);
      tmp = 1;
    }
  }
  s21_setSign(value, (s21_getSign(*value) + tmp) % 2);
}

// used in s21_mul
s21_decimal s21_div_only_bits(s21_decimal value1, s21_decimal value2,
                              s21_decimal *buf) {
  s21_init_decimal(buf);
  s21_decimal result = {{0, 0, 0, 0}};
  for (int i = s21_last_bit(value1); i >= 0; i--) {
    if (s21_getBit(value1, i)) s21_setBit(buf, 0, 1);
    if (s21_is_greater_or_equal(*buf, value2) == 1) {
      s21_sub(*buf, value2, buf);
      if (i != 0) s21_shift_left(buf, 1);
      if (s21_getBit(value1, i - 1)) s21_setBit(buf, 0, 1);
      s21_shift_left(&result, 1);
      s21_setBit(&result, 0, 1);
    } else {
      s21_shift_left(&result, 1);
      if (i != 0) s21_shift_left(buf, 1);
      if ((i - 1) >= 0 && s21_getBit(value1, i - 1)) s21_setBit(buf, 0, 1);
    }
  }
  return result;
}

// used in s21_mul
int s21_zero_check(s21_decimal value1, s21_decimal value2) {
  int zero = 1;
  s21_decimal *tmp1 = &value1;
  s21_decimal *tmp2 = &value2;
  if (tmp1 && tmp2) {
    if (!value1.bits[0] && !value2.bits[0] && !value1.bits[1] &&
        !value2.bits[1] && !value1.bits[2] && !value2.bits[2])
      zero = 0;
  }
  return zero;
}

// used in s21_mul
int s21_bit_addition(s21_decimal *value1, s21_decimal *value2,
                     s21_decimal *result) {
  int buf = 0, res = OK;
  for (int i = 0; i < 96; i++) {
    int bit1 = s21_getBit(*value1, i);
    int bit2 = s21_getBit(*value2, i);
    if (bit1 && bit2) {
      if (buf) {
        s21_setBit(result, i, 1);
      } else {
        s21_setBit(result, i, 0);
        buf = 1;
      }
    } else if (!bit1 && !bit2) {
      if (buf) {
        s21_setBit(result, i, 1);
        buf = 0;
      } else {
        s21_setBit(result, i, 0);
      }
    } else if (bit1 != bit2) {
      if (buf) {
        s21_setBit(result, i, 0);
      } else {
        s21_setBit(result, i, 1);
      }
    }
    if (i == 95 && buf == 1) res = TOO_MUCH_OR_INF;
  }
  return res;
}

/// | - - - - - - - - - ariphmetic - - - - - - - - - - - |

// сложение
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // считаем что одинаковый размер
  int res = OK;
  s21_decimal right = value_1;
  s21_decimal left = value_2;
  s21_init_decimal(result);
  s21_scale_equalization(&right, &left, 0);
  if (s21_getSign(right) == s21_getSign(left)) {
    res = add(left, right, result);
  } else if (s21_getSign(right) != s21_getSign(left)) {
    if (s21_getSign(right) == 1) {
      inverse(&right);
      res = add(left, right, result);
    } else if (s21_getSign(left) == 1) {
      inverse(&left);
      res = add(left, right, result);
    }
  }
  if ((s21_getSign(right) == 1) && (s21_getSign(left) == 1)) {
    s21_negate(*result, result);
  }
  return res;
}

// вычитание
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0, flag = 0;
  s21_init_decimal(result);
  s21_scale_equalization(&value_1, &value_2, 0);
  int sign1 = s21_getBit(value_1, 127);
  int sign2 = s21_getSign(value_2);
  if (sign1 != sign2) {
    if (sign1 == 0) flag = 1;
    if (sign2 == 0) flag = 2;
  }
  if (flag == 0) {
    if (sign1 == 0) {
      if (s21_is_less(value_1, value_2)) {
        s21_setSign(result, 1);
        s21_decimal hold = value_1;
        value_1 = value_2;
        value_2 = hold;
      }
      for (int i = 0; i < 96; i++) {
        int tmp1 = s21_getBit(value_1, i);
        int tmp2 = s21_getBit(value_2, i);
        int tmp_res = tmp1 - tmp2;
        if (tmp_res == 0) {
          s21_setBit(result, i, 0);
          continue;
        } else if (tmp_res == 1) {
          s21_setBit(result, i, 1);
        } else if (tmp_res == -1) {
          int n = i + 1;
          while (s21_getBit(value_1, n) != 1) {
            s21_setBit(&value_1, n, 1);
            n++;
          }
          s21_setBit(&value_1, n, 0);
          s21_setBit(result, i, 1);
        }
      }
      s21_setScale(result, s21_getScale(value_1));
    } else if (sign1 == 1) {
      s21_setBit(&value_1, 127, 0);
      s21_setBit(&value_2, 127, 0);
      res = s21_sub(value_2, value_1, result);
    }
  } else if (flag == 1) {
    s21_setBit(&value_2, 127, 0);
    res = s21_add(value_1, value_2, result);
  } else if (flag == 2) {
    s21_setBit(&value_2, 127, 1);
    res = s21_add(value_1, value_2, result);
  }
  if (s21_getScale(*result) > 28 ||
      (s21_getScale(*result) == 28 && result->bits[0] == 0 &&
       result->bits[1] == 0 && result->bits[2] == 0))
    res = 2;
  if (res != 0) s21_init_decimal(result);
  return res;
}

// умножение
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  int sign_result = 0;
  s21_init_decimal(result);
  if (s21_getSign(value_1) != s21_getSign(value_2)) {
    sign_result = 1;
  } else {
    sign_result = 0;
  }
  int last_bit_1 = s21_last_bit(value_1);
  s21_decimal tmp_res = {{0, 0, 0, 0}};
  for (int i = 0; i <= last_bit_1; i++) {
    s21_init_decimal(&tmp_res);
    int value_bit_1 = s21_getBit(value_1, i);
    if (value_bit_1) {
      tmp_res = value_2;
      if ((95 - last_bit_1 - 1) == i && sign_result == 0) {
        res = TOO_MUCH_OR_INF;
        break;
      } else if ((95 - last_bit_1 - 1) == i && sign_result == 1) {
        res = TOO_FEW_OR_NEG_INF;
        break;
      }
      s21_shift_left(&tmp_res, i);
      res = s21_bit_addition(result, &tmp_res, result);
    }
  }
  while (res != OK &&
         (s21_getScale(value_1) > 0 || s21_getScale(value_2) > 0)) {
    s21_decimal *chosen_num = NULL, *other_num = NULL;
    if (s21_last_bit(value_1) > s21_last_bit(value_2) &&
        s21_getScale(value_1) > 0) {
      chosen_num = &value_1;
      other_num = &value_2;
    } else if (s21_last_bit(value_2) > s21_last_bit(value_1) &&
               s21_getScale(value_2) > 0) {
      chosen_num = &value_2;
      other_num = &value_1;
    } else {
      break;
    }
    int chosen_num_scale = s21_getScale(*chosen_num);
    s21_decimal ten = {{10, 0, 0, 0}};
    s21_decimal remainder = {{0, 0, 0, 0}};
    s21_decimal tmp_div = s21_div_only_bits(*chosen_num, ten, &remainder);
    s21_decimal zero = {{0, 0, 0, 0}};
    if (s21_zero_check(tmp_div, zero) == 1) {
      s21_bits_copy(tmp_div, chosen_num);
    } else {
      s21_bits_copy(remainder, chosen_num);
    }
    s21_setScale(chosen_num, --chosen_num_scale);
    res = s21_mul(*chosen_num, *other_num, result);
  }
  int scale = s21_getScale(value_1) + s21_getScale(value_2);
  s21_setScale(result, scale);
  s21_setSign(result, sign_result);
  if ((res != OK) || scale > 28) {
    s21_init_decimal(result);
  }
  return res;
}

// деление
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal remainder = {{1, 0, 0, 0}};
  s21_decimal tmp_res = {{0, 0, 0, 0}};
  s21_decimal zero = {{0, 0, 0, 0}};
  int res = 0, count = 0;
  int scale1 = s21_getScale(value_1), scale2 = s21_getScale(value_2), scale = 0;
  int sign1 = s21_getSign(value_1), sign2 = s21_getSign(value_2);
  s21_setSign(&value_1, 0);
  s21_setSign(&value_2, 0);
  (scale1 >= scale2) ? scale = (scale1 - scale2)
                     : s21_scale_equalization(&value_1, &value_2, 0);
  if (s21_is_equal(value_2, zero)) res = s21_NAN;
  if (s21_is_greater(value_2, value_1) && scale == 0) {
    s21_decimal ten = {{10, 0, 0, 0}};
    while (s21_is_greater(value_2, value_1)) {
      s21_mul(value_1, ten, &value_1);
      scale++;
      if (scale == 28) break;
    }
  }
  s21_setScale(&value_1, scale);
  while (count < 10) {
    *result = tmp_res;
    res = s21_integer_division(value_1, value_2, &tmp_res, &remainder, 0);
    if (s21_getScale(tmp_res) == 0 && s21_last_bit(tmp_res) > 93) {
      res = TOO_MUCH_OR_INF;
      break;
    }
    s21_add(tmp_res, *result, &tmp_res);
    if (remainder.bits[0] == 0 && remainder.bits[1] == 0 &&
        remainder.bits[2] == 0)
      break;
    value_1 = remainder;
    s21_setScale(&value_1, scale + count);
    count++;
  }
  *result = tmp_res;
  (sign1 != sign2) ? s21_setSign(result, 1) : NULL;
  if (res != 0) s21_init_decimal(result);
  return res;
}

// остаток от деления
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal tmp = {{0, 0, 0, 0}};
  int res = OK;
  res = s21_div(value_1, value_2, &tmp);
  if (res == OK) res = s21_truncate(tmp, &tmp);
  if (res == OK) res = s21_mul(tmp, value_2, &tmp);
  if (res == OK) res = s21_sub(value_1, tmp, result);
  return res;
}
