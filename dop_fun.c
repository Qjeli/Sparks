#include "arifmet.h"

/// | ~ ~ ~ ~ ~ ~ ~ ~ functions helpers ~ ~ ~ ~ ~ ~ ~ ~ ~|

int s21_getBit(s21_decimal d, int i) {
    unsigned int mask = 1u << (i % 32); // u значит беззнаковая 1
return d.bits [i / 32] & mask; 
}

void s21_setBit(s21_decimal *d, int i, int value) {
    unsigned int mask = 1u << (i % 32);
    if (i / 32 < 4 && value) {
    d->bits[i / 32] |= mask;
  } else if (i / 32 < 4 && !value) {
    d->bits[i / 32] &= ~mask;  // ~ это побитовая инверсия
    // мы сбрасываем то значение которое было здесь. теперь оно = 0
  }
}

int s21_getScale(const s21_decimal d) {
    return(char)(d.bits[3] >> 16);  // а если стоит знак отрицания то это не учитывают
    // return(char)((d.bits[3]& ~(1<<31)) >> 16);  // мой вариант
    // но остается вопрос. а что по степени. она же может быть отрицательной
}

void s21_setScale(s21_decimal *d, int scale) {
    for(int i = s21_START_INFO + 16; i < s21_START_INFO + 24; i++) {
        s21_setBit(d, i, scale & 1);  // возможно будет ошибка
        scale >> 1;
    }
}

int s21_getSign(const s21_decimal d) {
    unsigned int mask = 1u << 31;
    return !!(d.bits[3] & mask); // получаем или 0 или 1
}

void s21_setSign( s21_decimal *d, int sign) {
    s21_setBit(&d, 127, sign);
}

void s21_init_decimal(s21_decimal *dec) {
  dec->bits[0] = dec->bits[1] = dec->bits[2] = dec->bits[3] = 0;
}

int s21_scale_equalization(s21_decimal *value_1, s21_decimal *value_2, int err_num) { // выравнивание по степени
  int res = err_num;
  s21_decimal *left = NULL;
  s21_decimal *right = NULL;
  s21_decimal remainder = {0};  // остаток
  if (s21_getScale(*value_1) > s21_getScale(*value_2)) {  // смотрим какой из них больше
    left = value_1;
    right = value_2;
  } else {
    left = value_2;
    right = value_1;
  }
  if (s21_getScale(*value_1) != s21_getScale(*value_2)) { // получаем то на сколько сдвиг
    int sign1 = s21_getSign(*left), sign2 = s21_getSign(*right); // получаем знак
    s21_decimal ten = {{10, 0, 0, 0}};  // что это и зачем оно
    s21_setSign(left, 0);
    s21_setSign(right, 0);
    while (s21_getScale(*left) != s21_getScale(*right) && // change right on left
           s21_last_bit(*right) < 93 && s21_getScale(*right) <= 28) {
      res = OK; // предпочла б чтоб вместо ок писали 0
      int scale_small = s21_getScale(*right);
      s21_setScale(right, 0);
      res = s21_mul(ten, *right, right);
      if (res != 0) break;
      s21_setScale(right, scale_small + 1);
    }
    while (s21_getScale(*right) != s21_getScale(*left)) {
      int res = OK;
      int scale_big = s21_getScale(*left);
      if (s21_getScale(*left) - s21_getScale(*right) == 1) {
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
    dest->bits[i] = value.bits[i]; // хз что куда надо копировать 
  }
}

// dafuq?
/*
void s21_bits_copy(s21_decimal tmp_div, s21_decimal *tmp_mod){
  int discharge = s21_last_bit(tmp_div) - s21_last_bit(*tmp_mod); 
  for (int i = 95; i > discharge - 1; i--) {
    s21_set_bit(tmp_mod, i, 0);
  }
}
*/

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

int s21_shift_right(s21_decimal *first, int shift) {
  int res_val = 1;
  for (int i = 0; i < shift; i++) {
    int value_32bit = s21_getBit(*first, 32);
    int value_64bit = s21_getBit(*first, 64);
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

int s21_integer_division(s21_decimal value_1, s21_decimal value_2, s21_decimal *result, s21_decimal *remainder, int error_code) {
    s21_decimal tmp_div = {0};
    s21_decimal tmp_del = {0};
    s21_decimal tmp_mod = {0};
    s21_decimal tmp_res = {0};
    s21_decimal tmp_buf = {0};
  int scale_value1 = s21_getScale(value_1);
  int index_res = 95, res = 0, discharge = 1;
  int sign1 = s21_getSign(value_1), sign2 = s21_getSign(value_2); 
  int scale1 = s21_getScale(value_1), scale2 = s21_getScale(value_2);
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
    (sign1 != sign2) ? s21_setSign(&result, 1) : NULL;
    s21_setScale(result, scale_value1);
    s21_shift_right(&tmp_del, 1);
    *remainder = tmp_del;
  }
  if (res != 0) s21_init_decimal(result);
  return res;
}

// не используется
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

int s21_last_bit(s21_decimal value) {
  int last_bit = 95;
  for (; last_bit >= 0 && s21_getBit(value, last_bit) == 0; last_bit--) {
  }
  return last_bit;
}
