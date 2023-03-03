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
int is_Null(s21_decimal value) {
  int res = 0;  // is not null
  if (value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0) {
    res = 1;
  }
  return res;
}

// used in s21_div
int check(s21_decimal val_1, s21_decimal val_2, s21_decimal *result) {
  int flag = 0;
  if (val_2.bits[0] == 0 && val_2.bits[1] == 0 &&
      val_2.bits[2] == 0) {  // div on 0
    flag = 3;
  } else if (val_1.bits[0] == 0 && val_1.bits[1] == 0 && val_1.bits[2] == 0) {
    s21_init_decimal(result);
    flag = 4;
  }
  return flag;
}

/// | - - - - - - - - - ariphmetic - - - - - - - - - - - |

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

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = OK;
  s21_decimal left = value_1;
  s21_decimal right = value_2;
  s21_init_decimal(result);
  // s21_scale_equalization(&right, &left, 0);
  int singRight = s21_getSign(right);
  // int singLeft = s21_getSign(left); //
  s21_setSign(&right, singRight = 1 - singRight);
  if (s21_getSign(left) == s21_getSign(right)) {
    s21_setSign(&right, 0);
    s21_setSign(&left, 0);
    s21_setSign(result, singRight);  // установка знака
  } 
  // if ((s21_getSign(value_1) == 1) && (s21_getSign(value_2) == 0)) {
  //   // s21_setSign(result, singLeft);  // установка знака
  //   // s21_negate(right, &right);
  //   // s21_negate(*result, result);
  // }
  s21_add(left, right, result);  // сложение
  return res;
}

// умножение
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = 0;

  s21_decimal tmp;
  s21_decl_to_null(&tmp);
  s21_decl_to_null(result);
  s21_decimal left = value_1;
  s21_decimal right = value_2;
  if (!is_Null(left) && !is_Null(right)) {
    for (int i = 0; i < 96; i++) {
      if (s21_getBit(right, i) == 1) {
        s21_add(*result, left, result);
      }
      s21_shift_left(&left, 1);
    }
    int set_sgn = s21_getSign(left) ^ s21_getSign(right);
    s21_setSign(result, set_sgn);
    s21_setScale(result, s21_getScale(left) + s21_getScale(right));
  }

  return flag;
}

//деление
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = 0;
  s21_decimal val_1 = value_1;
  s21_decimal val_2 = value_2;
  s21_scale_equalization(&val_1, &val_2, 0);
  if (check(value_1, value_2, result) !=
      0) {  // если делит на 0 или 0 делит на что-то
    // why
  } else {
    int bit = 0;
    int sign_1 = s21_getSign(value_1);  // получаем знак
    int sign_2 = s21_getSign(value_2);
    if (sign_1 != sign_2) {
      s21_setSign(result, 1);
    } else {
      s21_setSign(result, 0);
    }

    s21_setSign(&val_1, 0);  // зануляем знак
    s21_setSign(&val_2, 0);

    while ((s21_is_greater_or_equal(val_2, val_1)) &&
           (bit == 0)) {          // меньше и не равен
      s21_shift_left(&val_1, 1);  // посмотрим как сработает
      bit =
          s21_getBit(val_2, 95);  // берем самый последний бит. он должен быть 1
    }
    while (!(s21_is_greater(val_2, val_1)) &&
           (bit == 0)) {          // меньше и не равен
      s21_shift_left(&val_2, 1);  // посмотрим как сработает
      bit =
          s21_getBit(val_2, 95);  // берем самый последний бит. он должен быть 1
    }
    while (val_2.bits[0] > 0) {
      s21_shift_left(result, 1);
      if (s21_is_greater(val_2, val_1)) {
        s21_setBit(result, 0, 0);
      } else {
        s21_sub(val_1, val_2, &val_1);  // непосредственно производим вычитание
        s21_setBit(result, 0, 1);
      }
      if (s21_is_greater(val_2, val_1)) {
        s21_shift_right(&val_2, 1);
      }
    }
  }
  s21_setScale(result, s21_getScale(value_1));
  return flag;
}

//остаток от деления
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = 0;
  s21_decimal val_1 = value_1;
  s21_decimal val_2 = value_2;
  s21_scale_equalization(&val_1, &val_2, 0);
  if ((flag = check(val_1, val_2, result)) != 0) {
  } else {
    int bit = 0;
    int sign_1 = s21_getSign(value_1);
    s21_setSign(&val_1, 0);
    s21_setSign(&val_2, 0);

    s21_decimal val_og = val_2;
    while (!(s21_is_greater_or_equal(val_2, val_1)) && (bit == 0)) {
      s21_shift_left(&val_2, 1);
      bit = s21_getBit(val_2, 95);
    }
    while (s21_is_greater_or_equal(val_2, val_og) ||
           s21_is_greater_or_equal(val_1, val_og)) {
      s21_shift_left(result, 1);
      if (s21_is_greater(val_2, val_1)) {
      } else {
        s21_sub(val_1, val_2, &val_1);
      }
      s21_shift_right(&val_2, 1);
    }
    *result = val_1;
    if (sign_1 == 1) {
      s21_setSign(result, 1);
    } else {
      s21_setSign(result, 0);
    }
  }
  if (flag == 4) flag = 0;
  return flag;
}