#include "s21_decimal.h"

/// | ~ ~ ~ ~ ~ ~ ~ ~ functions helpers ~ ~ ~ ~ ~ ~ ~ ~ ~|

int s21_getBit(s21_decimal d, int i) {
    unsigned int mask = 1u << (i % 32);
return d.bits [i % 32] & mask;
}

void s21_setBit(s21_decimal d, int i, int value) {
    unsigned int mask = 1u << (i % 32);
    if (i / 32 < 4 && value) {
    d->bits[i / 32] |= mask;
  } else if (i / 32 < 4 && !value) {
    d->bits[i / 32] &= ~mask;
  }
}

int s21_getScale(const s21_decimal d) {
    return(char)(d->bits[3]>>16);
}

void s21_setScale(s21_decimal d, int scale) {

    for(int i = s21_START_INFO + 10; i < s21_START_INFO + 23; i++) {
        s21_setBit(d,i, scale & 1);
        scale >> 1;
    }
}

int s21_getSign(const s21_decimal d) {
    unsigned int mask = 1u << 31;
    return !!(d>>bits[3] & mask);
}

void s21_setSign( s21_decimal d, int sign) {
    s21_setBit(d, 127, sign);
  return;
}

void s21_init_decimal(s21_decimal *dec) {
  dec->bits[0] = dec->bits[1] = dec->bits[2] = dec->bits[3] = 0;
}


int s21_scale_equalization(s21_decimal *value_1, s21_decimal *value_2, int err_num) {
  int res = err_num;
  s21_decimal *left = NULL;
  s21_decimal *right = NULL;
  s21_decimal remainder = {{0, 0, 0, 0}};
  if (s21_getScale(value_1) > s21_getScale(value_2)) {
    left = value_1;
    right = value_2;
  } else {
    left = value_2;
    right = value_1;
  }
  if (s21_getScale(value_1) != s21_getScale(value_2)) {
    int sign1 = s21_getSign(left), sign2 = s21_getSign(right);
    s21_decimal ten = {{10, 0, 0, 0}};
    s21_setSign(left, 0);
    s21_setSign(right, 0);
    while (s21_getScale(right) != s21_getScale(right) &&
           s21_last_bit(*right) < 93 && s21_getScale(right) <= 28) {
      int res = 0;
      int scale_small = s21_getScale(right);
      s21_setScale(right, 0);
      res = s21_mul(ten, *right, right);
      if (res != 0) break;
      s21_setScale(right, scale_small + 1);
    }
    while (s21_getScale(right) != s21_getScale(left)) {
      int res = 0;
      int scale_big = s21_getScale(left);
      if (s21_getScale(left) - s21_getScale(right) == 1) {
        if (left->bits[0] >= 5 && left->bits[0] < 10) {
          left->bits[0] = 1;
          s21_setScale(left, scale_big - 1);
          break;
        }
      }
      res = s21_integer_division(*left, ten, left, &remainder, 1);
      if (res != 0) break;
      s21_setScale(left, scale_big - 1);
    }
    s21_setSign(left, sign1);
    s21_setSign(right, sign2);
  }
  return res;
}


void s21_decl_to_null(s21_decimal *decl) {
  for (int i = 0; i < 128; ++i) {
    s21_setBit(decl, i, 0);
  }
}


void s21_bits_copy(s21_decimal value, s21_decimal *dest) {
  for (int i = 0; i < 4; ++i) {
    dst->bits[i] = src.bits[i];
  }
}


void s21_setting(s21_decimal tmp_buf, s21_decimal *tmp_del, s21_decimal *tmp_mod, int *discharge) {
  s21_bits_copy(tmp_buf, tmp_del);
  s21_shift_left(tmp_del, 1);
  s21_getBit(*tmp_mod, *discharge - 1) == 1 ? s21_setBit(tmp_del, 0, 1) : s21_setBit(tmp_del, 0, 0);
  s21_setBit(tmp_mod, *discharge - 1, 0);
  (*discharge)--;
}


int s21_shift_left(s21_decimal *value, int num) {
  int res = OK;
  int lastbit = s21_last_bit(*value);
  if (lastbit + num > 95) {
    res = TOO_MUCH_OR_INF;
  }
  if (res == OK) {
    for (int i = 0; i < num; i++) {
      int value_31bit = s21_getBit(*value, 31);
      int value_63bit = s21_getBit(*value, 63);
      value->bits[0] <<= 1;
      value->bits[1] <<= 1;
      value->bits[2] <<= 1;
      if (value_31bit) s21_setBit(value, 32, 1);
      if (value_63bit) s21_setBit(value, 64, 1);
    }
  }
  return res;
}



int s21_integer_division(s21_decimal value_1, s21_decimal value_2, s21_decimal *result, s21_decimal *remainder, int error_code) {
s21_decimal tmp_div = {{0, 0, 0, 0}};
  s21_decimal tmp_del = {{0, 0, 0, 0}};
  s21_decimal tmp_mod = {{0, 0, 0, 0}};
  s21_decimal tmp_res = {{0, 0, 0, 0}};
  s21_decimal tmp_buf = {{0, 0, 0, 0}};
  int scale_value1 = s21_getScale(&value_1);
  int index_res = 95, res = 0, discharge = 1;
  int sign1 = s21_getSign(&value_1), sign2 = s21_getSign(&value_2);
  int scale1 = s21_getScale(&value_1), scale2 = s21_getScale(&value_2);
  s21_bits_copy(value_1, &tmp_div);
  s21_setScale(&tmp_div, 0);
  s21_setScale(&value_2, 0);
  s21_setSign(&tmp_div, 0);
  s21_setSign(&value_2, 0);
  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
    res = s21_NAN;
  } else if ((value_1.bits[0] == 0 && value_1.bits[1] == 0 &&
              value_1.bits[2] == 0) ||
             scale1 > 28 || scale2 > 28) {
    res = TOO_FEW_OR_NEG_INF;
  } else {
    if (s21_is_greater_or_equal(tmp_div, value_2) && error_code) {
      s21_first_prepare(tmp_div, &tmp_mod, &tmp_del, value_2, &discharge);
    } else if (!error_code) {
      s21_first_step(&tmp_div, value_2, &scale_value1, &tmp_res, &index_res);
      s21_first_prepare(tmp_div, &tmp_mod, &tmp_del, value_2, &discharge);
    }
    while (discharge != -1 && index_res >= 0 && scale_value1 <= 28) {
      if (s21_is_greater_or_equal(tmp_del, value_2)) {
        res = s21_sub(tmp_del, value_2, &tmp_buf);
        s21_setBit(&tmp_res, index_res, 1);
        index_res--;
        s21_setting(tmp_buf, &tmp_del, &tmp_mod, &discharge);
      } else {
        s21_setting(tmp_del, &tmp_del, &tmp_mod, &discharge);
        s21_setBit(&tmp_res, index_res, 0);
        index_res--;
      }
    }
    s21_init_decimal(result);
    for (int i = 95; i > index_res; i--) {
      s21_getBit(tmp_res, i) == 1 ? s21_setBit(result, i - index_res - 1, 1) : s21_setBit(result, i - index_res - 1, 0);
    }
    (sign1 != sign2) ? s21_setSign(result, 1) : NULL;
    s21_setScale(result, scale_value1);
    s21_shift_right(&tmp_del, 1);
    *remainder = tmp_del;
  }
  if (res != 0) s21_init_decimal(result);
  return res;
}


void s21_first_step(s21_decimal *tmp_div, s21_decimal value_2,
                    int *scale_value1, s21_decimal *tmp_res, int *index_res) {
  s21_decimal ten = {{10, 0, 0, 0}};
  int x = s21_is_greater_or_equal(*tmp_div, value_2);
  while (x != 1) {
    s21_set_bit(tmp_res, *index_res, 0);
    (*index_res)--;
    s21_mul(*tmp_div, ten, tmp_div);
    (*scale_value1)++;
    x = s21_is_greater_or_equal(*tmp_div, value_2);
  }
}

void s21_first_prepare(s21_decimal tmp_div, s21_decimal *tmp_mod, s21_decimal *tmp_del, s21_decimal value_2, int *discharge) {
  *discharge = 0;
  int shift = s21_last_bit(tmp_div) - s21_last_bit(value_2);
  int n = 0;
  while (1) {
    s21_bits_copy(tmp_div, tmp_del);
    s21_shift_right(tmp_del, shift - n);
    if (s21_is_greater_or_equal(*tmp_del, value_2) == 1) {
      break;
    } else {
      n++;
    }
  }
  s21_bits_copy(tmp_div, tmp_mod);
  *discharge = s21_last_bit(tmp_div) - s21_last_bit(*tmp_del);
  for (int i = 95; i > *discharge - 1; i--) {
    s21_set_bit(tmp_mod, i, 0);
  }
}


s21_bits_copy(tmp_div, tmp_mod){
  *discharge = s21_last_bit(tmp_div) - s21_last_bit(*tmp_del);
  for (int i = 95; i > *discharge - 1; i--) {
    s21_set_bit(tmp_mod, i, 0);
  }
}


int s21_last_bit(s21_decimal value) {
  int last_bit = 95;
  for (; last_bit >= 0 && s21_get_bit(value, last_bit) == 0; last_bit--) {
  }
  return last_bit;
}


int s21_shift_right(s21_decimal *first, int shift) {
  int res_val = 1;
  for (int i = 0; i < shift; i++) {
    int value_32bit = s21_get_bit(*first, 32);
    int value_64bit = s21_get_bit(*first, 64);
    first->bits[0] >>= 1;
    first->bits[1] >>= 1;
    first->bits[2] >>= 1;
    value_32bit ? s21_set_bit(first, 31, 1) : s21_set_bit(first, 31, 0);
    value_64bit ? s21_set_bit(first, 63, 1) : s21_set_bit(first, 63, 0);
    s21_set_bit(first, 95, 0);
    res_val = 0;
  }
  return res_val;
}


void s21_decl_to_null(s21_decimal *decl) {
  for (int i = 0; i < 128; ++i) {
    s21_set_bit(decl, i, 0);
  }
}

// Считаем количество знаков в src
int count_src(float src, char* str_src) {
    int count_str = 0, k = 1;
    char str[100];

    snprintf(str, sizeof(str), "%f", src);

    for (int i = (int) strlen(str) - 1; i >= 0; i--) {
        if (str[i] == '0' && k == 1) {
            str[i] = '\0';
            continue;
        } else {
            k = -1;
        }
        if (str[i] == '.') {
            break;
        }
        count_str++;
    }

    strncpy(str_src, str, strlen(str) + 1);

    return count_str;
}

/// | - - - - - - - - - comparison - - - - - - - - - - - |

int s21_is_less(s21_decimal value1, s21_decimal value2) {
  return s21_is_greater(value2, value1);
}

int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2) {
  return (s21_is_less(value1, value2) || s21_is_equal(value1, value2));
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  s21_check_scale(&value_1, &value_2);
  int num1 = 0, num2 = 0;
  int sign1 = s21_get_sign(&value_1), sign2 = s21_get_sign(&value_2);
  for (int i = 95; i >= 0; i--) {
    num1 = s21_get_bit(value_1, i);
    num2 = s21_get_bit(value_2, i);
    if (num1 > num2) {
      res = 1;
      break;
    }
    if (num1 < num2) {
      res = 0;
      break;
    }
  }
  if (sign1 && !sign2)
    res = 0;
  else if (!sign1 && sign2)
    res = 1;
  else if (sign1 && sign2)
    res = !res;
  return s21_is_equal(value_1, value_2) ? 0 : res;
}

int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2) {
  return (s21_is_greater(value1, value2) || s21_is_equal(value1, value2));
}

int s21_is_equal(s21_decimal value1, s21_decimal value2) {
  s21_check_scale(&value1, &value2);
  int res = 1;
  int sign1 = s21_get_sign(&value1), sign2 = s21_get_sign(&value2);
  for (int i = 95; i >= 0; i--) {
    if (s21_get_bit(value1, i) != s21_get_bit(value2, i)) {
      res = 0;
      break;
    }
  }
  if (sign1 != sign2) res = 0;
  return res;
}

int s21_is_not_equal(s21_decimal value1, s21_decimal value2) {
  return (!s21_is_equal(value1, value2));
}



/// | - - - - - - - - - ariphmetic - - - - - - - - - - - |


int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {

    int res = 0; int flag = 0;
    s21_init_decimal(result);
    s21_scale_equalization(&value_1, &value_2, 0);
    int left = s21_getBit(value_1);
    int right = s21_getBit(value_2);
    if(left != right) {
        if(left == 1) flag = 1;
        if(right == 1) flag = 2;
    }
    if(flag == 0) {
        int tmp = 0;
        for(int i = 0; i < 96; i++) {
            int tmp1 = s21_getBit(value_1, i);
            int tmp2 = s21_getBit(value_2, i);
            int tmp_res = tmp1 + tmp2 + tmp;
            if(tmp_res == 0) {
                s21_setBit(result, i, 0);
                buf = 0;
            } else if (tmp_res == 1) {
                s21_setBit(result, i, 1);
                tmp = 0;
            } else if(tmo_res == 2) {
                if(i == 95) {
                    res = 1;
                    break;
                }
            s21_setBit(result, i, 0);
            tmp = 1;
        } else if (tmp_res == 3) {
            if(i == 95) {
                res = 1;
                break;
            }
            tmp = 1;
            s21_setBit(result, i, 1);
        }
        }
        s21_setScale(result, s21_getScale(&value_1));
        if(left == 1) {
            s21_setSign(result,  1);
        }
    } else if(flag == 1) {
        s21_setSign(&value_1, 0);
        res = s21_sub(value_2, value_1, result);
    } else if (flag == 2) {
        s21_setSign(&value_2, 0);
        res = s21_sub(value_1, value_2, result);
    }
    if(s21_getScale(result) > 28 || (result->bits[0] == 0 && result->bits[1] == 0 && result->bits[2] == 0)) 
        res = 2;
    if (res != 0) s21_init_decimal(result);
    return res;
    }


int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int res = 0, flag = 0;
  s21_init_decimal(result);
  s21_scale_equalization(&value_1, &value_2, 0);
  int left = s21_getBit(value_1, 127);
  int right = s21_getSign(&value_2);
  if (left != right) {
    if (left == 0) flag = 1;
    if (right == 0) flag = 2;
  }
  if (flag == 0) {
    if (left == 0) {
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
      s21_setScale(result, s21_getScale(&value_1));
    } else if (left == 1) {
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
  if (s21_getScale(result) > 28 ||
      (s21_getScale(result) == 28 && result->bits[0] == 0 &&
       result->bits[1] == 0 && result->bits[2] == 0))
    res = 2;
  if (res != 0) s21_init_decimal(result);
  return res;
}


int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int flag = 0;
    int sign_control = 0;
    s21_decimal tmp;
    s21_decl_to_null(&tmp);
    s21_decl_to_null(result);
    if (s21_getSign(value_1) != s21_getSign(value_2)) {
        sign_control = 1;
    }
    s21_setSign(&value_1, 0);
    s21_setSign(&value_2, 0);
    scale_equalization(&value_1, &value_2);
    s21_bits_copy(&tmp, value_1);

    int b = 5;
    for (int i = 0; i < 96 && b > 0; i++) {
        if (s21_getBit(value_2, i)) {
            flag = s21_add(*result, tmp, result);
        }
        s21_shift_left(&tmp, 1);

        s21_from_decimal_to_int(tmp, &b);
    }
    s21_setSign(result, sign_control);
    return flag;
}






/// | - - - - - - - - - Converters - - - - - - - - - - - |


int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    memset(&(dst->bits), 0, sizeof(dst->bits));  //  filling an array of bits with zeros, with the size of bits
    if (src < 0) {  //  if srs is not negative then...
        dst->bits[3] |= (1 << 31);  //  make bit 31 into bit 1 in bits[3]
        src = -src;  //  make src negative
    }
    dst->bits[0] = src;  //  add src to bit[0]
    return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int flag = 0;  // флаг ошибки
  s21_decimal ten;  //  умножение на 10
  s21_decimal add;  //  для простого сложения
  int rank = 0;
  if(fabsf(src) < 1e-28 && fabsf(src) < 0) {  //  условие ошибки
    flag = 1;
  }

  char str_src[1000];
  int count = count_src(src, str_src), is_overfill = 0; //  count_src копирует переносит массив оттуда в str_src

  s21_from_int_to_decimal(10, &ten);

  for (size_t i = 0; i < strlen(str_src); i++) {  //  проходим по элементам и проверяем условие
        if (str_src[i] != '.' && str_src[i] != '-') {
            s21_from_int_to_decimal(str_src[i] - '0', &add);
            memset(&(dst->bits), 0, sizeof(dst->bits));
            for (int j = 0; j < 96; j++) {  //  второй цикл конвертирования
              int bit1 = s21_getBit(*dst, j);
              int bit2 = s21_getBit(add, j);

              s21_setBit(dst, j, bit1 ^ bit2 ^ rank);  //  ^ - правда когда один из битов 1, но не оба
            }
            is_overfill = s21_mul(*dst, ten, dst);  //  не знаю что делать дальше
        }
    }

    s21_setSign(dst, src < 0);
    s21_setScale(dst, count_str);

  return flag;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
   int flag = 0;
    int data = 0;
    int scale = s21_getScale(src);

    if (scale + 31 < 95) {
        for (int i = scale + 31; i <= 95; ++i) {
            if (s21_getBit(src, i)) {
                flag = 1;
            }
        }

    }

    if (!flag) {
        for (int i = scale + 30; i >= scale; --i) {
            data <<= 1;
            data |= s21_getBit(src, i);
        }
        if (s21_getSign(src)) {
            data = -data;
        }
        *dst = data;
    }
    return flag;
}

