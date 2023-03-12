#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal* result) {
  *result = value;
  s21_setSign(result, !s21_getSign(value));
  return 0;
}

int int_get_bit(unsigned int number, int byte) {
  return (number & 1 << byte) ? 1 : 0;
}

void int_shift_left(unsigned int* num, int shift, int n) { *num ^= shift << n; }

void int_set_bit(unsigned int* number, int byte, int n) {
  if (int_get_bit(*number, byte) != n) int_shift_left(number, 1, byte);
}

int div_ten(s21_decimal* number) {
  unsigned int buffer = 0;
  int scale_of_number = s21_getScale(*number);
  s21_decimal result = {{0, 0, 0, 0}};
  int highest_bit_pos = s21_last_bit(*number);
  for (int i = 0; i < highest_bit_pos + 2; i++) {
    if (buffer >= 10) {
      s21_shift_left(&result, 1);  // 1?
      s21_setBit(&result, 0, 1);
      buffer -= 10;
      int new_bit = s21_getBit(*number, highest_bit_pos - i);
      buffer = buffer << 1;
      int_set_bit(&buffer, 0, new_bit);
    } else {
      s21_shift_left(&result, 1);  // 1?
      s21_setBit(&result, 0, 0);
      int new_bit = s21_getBit(*number, highest_bit_pos - i);
      buffer = buffer << 1;
      int_set_bit(&buffer, 0, new_bit);
    }
  }
  buffer = buffer << 1;
  *number = result;
  s21_setScale(number, scale_of_number);
  return buffer;
}

int s21_truncate(s21_decimal value, s21_decimal* result) {
  int res = 0;
  if (result) {
    int scale = s21_getScale(value);
    int sign = s21_getBit(value, 127);

    for (int i = 0; i < scale; i++) {
      div_ten(&value);
    }

    *result = value;
    s21_setBit(result, 127, sign);
    s21_setScale(result, 0);
  } else {
    res = 1;
  }
  return res;
}

int s21_round(s21_decimal value, s21_decimal* result) {
  int res = 0;
  if (result) {
    int is_less_than_zero = 0;
    s21_decimal zero = {{0, 0, 0, 0}};
    s21_decimal half;
    s21_decimal one = {{1, 0, 0, 0}};
    s21_decimal value_int;
    s21_decimal mantissa;
    s21_from_float_to_decimal(0.5, &half);
    if (s21_is_less(value, zero)) {
      is_less_than_zero = 1;
      s21_negate(value, &value);
    }
    s21_truncate(value, &value_int);
    s21_sub(value, value_int, &mantissa);

    // there is an issue with the commented comparison
    float mantissa_fl, half_fl;
    s21_from_decimal_to_float(mantissa, &mantissa_fl);
    s21_from_decimal_to_float(half, &half_fl);
    if (mantissa_fl >= half_fl) {
      // if (s21_is_greater_or_equal(mantissa, half)) {
      s21_add(value_int, one, result);
    } else {
      *result = value_int;
    }

    if (is_less_than_zero) {
      s21_negate(*result, result);
    }
  } else {
    res = 1;
  }
  return res;
}

int s21_floor(s21_decimal value, s21_decimal* result) {
  int res = 0;
  if (result) {
    s21_decimal zero = {{0, 0, 0, 0}};
    s21_decimal one = {{1, 0, 0, 0}};
    s21_decimal value_int;
    s21_truncate(value, result);
    s21_truncate(value, &value_int);
    if (s21_is_less(value, zero) && s21_is_not_equal(value, value_int)) {
      s21_sub(*result, one, result);
      // s21_setSign(result, !s21_getSign(*result));
    }
  } else {
    res = 1;
  }
  return res;
}
