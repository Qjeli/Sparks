#include "s21_decimal.h"

#include <stdio.h>
#include <string.h>
// #include <сheck.h>

int main(void) {
  float f, z, result;
  s21_decimal a = {{5, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  s21_decimal res = {0};
  // s21_from_float_to_decimal(11861612618.656, &a);
  // s21_from_float_to_decimal(513555912.99, &b);
  // s21_setSign(&b, 0);
  // s21_setSign(&a, 1);
  s21_from_float_to_decimal(11860, &a);
  s21_from_float_to_decimal(222222, &b);
  //s21_setSign(&b, 0);
  //s21_setSign(&a, 1);
  s21_mul(a, b, &res); // 10010000110110 0.9270000
                       // 10001101001001 0.903333
  s21_from_decimal_to_float(res, &result);
  s21_from_decimal_to_float(a, &f);
  s21_from_decimal_to_float(b, &z);
  printf("result %f\n", f * z);  // 10001101001001
  printf("resDec %u %u %u %u \nsign: %d\nfromDecToFloat %lf\nres %lf %lf\n", res.bits[0], res.bits[1],res.bits[2],res.bits[3],s21_getSign(res),result, f, z);
}