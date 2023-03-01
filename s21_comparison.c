#include "s21_decimal.h"

/// | - - - - - - - - - comparison - - - - - - - - - - - |

int s21_is_less(s21_decimal value1, s21_decimal value2) {
  return s21_is_greater(value2, value1);
}

int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2) {
  return (s21_is_less(value1, value2) || s21_is_equal(value1, value2));
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int res = OK;
  s21_check_scale(&value_1, &value_2);
  int num1 = 0, num2 = 0;
  int sign1 = s21_getSign(value_1), sign2 = s21_getSign(value_2);
  int i = 95;
  while (i >= 0) {
    num1 = s21_getBit(value_1, i);
    num2 = s21_getBit(value_2, i);
    if (num1 > num2) {
      res = 1;
      i = 0;
    }
    if (num1 < num2) {
      res = 0;
      i = 0;
    }

    i--;
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
  int sign1 = s21_getSign(value1), sign2 = s21_getSign(value2);
  int i = 95;
  while (i >= 0) {
    if (s21_getBit(value1, i) != s21_getBit(value2, i)) {
      res = 0;
      i = 0;
    }
    i--;
  }
  if (sign1 != sign2) res = 0;
  return res;
}

int s21_is_not_equal(s21_decimal value1, s21_decimal value2) {
  return (!s21_is_equal(value1, value2));
}