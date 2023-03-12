#include "s21_decimal.h"

void conversion() {
float f, z, result;
  s21_decimal a = {{5, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  s21_decimal res = {0};
  s21_from_float_to_decimal(0.542 , &a);
  s21_from_float_to_decimal(0.6 , &b);
  // // s21_setSign(&b, 0);
  // s21_setSign(&a, 1);
  s21_div(a, b, &res); // 10010000110110 0.9270000
                       // 10001101001001 0.903333
  s21_from_decimal_to_float(res, &result);
  s21_from_decimal_to_float(a, &f);
  s21_from_decimal_to_float(b, &z);
  printf("result %f\n", f / z);  // 10001101001001
  printf("resDec %u %u %u %u \nsign: %d\nfromDecToFloat %lf\nres %lf %lf\n", res.bits[0], res.bits[1],res.bits[2],res.bits[3],s21_getSign(res),result, f, z);
}

void sub_test() {
    int num1 = -11;
    int num2 = 10;
    int sum_int = -21;
    s21_decimal a, b;
    
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);

    s21_decimal res_dec = {0};
    int res_int = 0;
    
    s21_sub(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    
    printf("%d-%d\n", num1, num2);
    printf("%d - result\n", res_int);
    printf("%d - must be\n", sum_int);
}

void mul_test() {
  float num1 = 9403.0e2;
  float num2 = 9403.0e2;
  float res_origin = 884164090000;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
    
    printf("%f x %f\n", num1, num2);
    printf("%f - result\n", res_float);
    printf("%f - must be\n", res_origin);
}

void div_test_d() {
// s21_div_5

  s21_decimal src1, src2, result, origin;
  // 0
  // 0.015
  // 0
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;

  s21_div(src1, src2, &result);
  float res_fl = 0;
  float ori_fl = 0;
  s21_from_decimal_to_float(result, &res_fl);
  s21_from_decimal_to_float(origin, &ori_fl);

  float val1 = 0;
  float val2 = 0;
  s21_from_decimal_to_float(src1, &val1);
  s21_from_decimal_to_float(src2, &val2);

  int check = s21_div(src1, src2, &result);

  printf("%f / %f\n", val1, val2);
  printf("%f - result; returns %d\n", res_fl, check);
  printf("%f - must be\n", ori_fl);
}

void div_test_f() {
// s21_div_8

  s21_decimal src1, src2, result;
  float a = 1.0 / 0.0;
  float b = 1.0 / 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);

  float val1 = 0;
  float val2 = 0;
  float res_fl = 0;
  float ori_fl = a / b;
  s21_from_decimal_to_float(src1, &val1);
  s21_from_decimal_to_float(src2, &val2);
  
  int check = s21_div(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_fl);

  printf("%f / %f\n", val1, val2);
  printf("%f - result; returns %d\n", res_fl, check);
  printf("%f - must be\n", ori_fl);
}

void decimal_sub_8() {
    s21_decimal x = {{2, 0, 0, 0b10000000000000000000000000000000}};
    s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
    s21_decimal z = {{0, 0, 0, 0}};
    s21_decimal r = {{3, 0, 0, 2147483648}};  // res2
    s21_sub(x, y, &z);

    float a = 0;
    float b = 0;
    float res1 = 0;
    float res2 = 0;
    s21_from_decimal_to_float(x, &a);
    s21_from_decimal_to_float(y, &b);
    s21_from_decimal_to_float(z, &res1);
    s21_from_decimal_to_float(r, &res2);
    
    printf("%f - %f\n", a, b);
    printf("%f - result\n", res1);
    printf("%f - must be\n", res2);
}

void decimal_sub_11() {
    s21_decimal x = {{1, 0, 0, 0b10000000000000000000000000000000}};
    s21_decimal y = {{1, 0, 0, 0b10000000000000000000000000000000}};
    s21_setScale(&x, 28);
    s21_setScale(&y, 28);
    s21_decimal z = {{0, 0, 0, 0}};
    s21_decimal r = {{0, 0, 0, 0}};  // res2
    s21_sub(x, y, &z);

    float a = 0;
    float b = 0;
    float res1 = 0;
    float res2 = 0;
    s21_from_decimal_to_float(x, &a);
    s21_from_decimal_to_float(y, &b);
    s21_from_decimal_to_float(z, &res1);
    s21_from_decimal_to_float(r, &res2);
    
    printf("%f - %f\n", a, b);
    printf("%f - result\n", res1);
    printf("%f - must be\n", res2);
}

int main() {
    decimal_sub_8();
    return 0;
}