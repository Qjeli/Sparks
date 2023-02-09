#include <stdio.h>
#include <string.h>
#include "s21_decimal.h"

void test_neg() {
    int value_int = 0, res = 0;
    s21_decimal value_dec, value_dec_neg;
    scanf("%d", &value_int);
    s21_from_int_to_decimal(value_int, &value_dec);
    s21_negate(value_dec, &value_dec_neg);
    s21_from_decimal_to_int(value_dec_neg, &res);
    printf("%d\n", res);
}

void test_trunc() {
    float value = 0;
    int res = 0;
    s21_decimal value_dec, value_dec_tru;
    scanf("%f", &value);
    s21_from_float_to_decimal(value, &value_dec);
    s21_truncate(value_dec, &value_dec_tru);
    s21_from_decimal_to_int(value_dec_tru, &res);
    printf("%d\n", res);
}

void test_div() {
    int num1 = 100;
    int num2 = 10;
    int res_int = 0;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_decimal res_dec = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_div(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    printf("%d\n", res_int);
}

int main() {
    test_trunc();
    return 0;
}