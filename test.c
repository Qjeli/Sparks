#include <stdio.h>
#include <string.h>
#include "arifmet.h"

// grishakir common

#define START_MID 32
#define START_HIGHT 64

void s21_copy(s21_decimal *dst, s21_decimal src) {
    // dst->state = src.state;
    for (int i = 0; i < 4; ++i) {
        dst->bits[i] = src.bits[i];
    }
}

void s21_right_shift(s21_decimal *decl) {
    int tmp = s21_getBit(*decl, START_MID);
    int tmp_1 = s21_getBit(*decl, START_HIGHT);

    for (int i = 0; i < 3; ++i) {
        decl->bits[i] >>= 1;
    }
    s21_setBit(decl, START_MID - 1, tmp);
    s21_setBit(decl, START_HIGHT - 1, tmp_1);
    return;
}

// mine

// src: dec_4
int s21_negate(s21_decimal value, s21_decimal *result) {
    // for (int i = 0; i < 4; i++) {
    //     result->bits[i] = value.bits[i];
    // }
    
    *result = value; // shorter way

    s21_setSign(result, !s21_getSign(value));
    return 0;
} // works, but the conversion seems odd
// need to add error check

void test_neg() {
    int value_int = 0, res = 0;
    s21_decimal value_dec, value_dec_neg;
    scanf("%d", &value_int);
    s21_from_int_to_decimal(value_int, &value_dec);
    s21_negate(value_dec, &value_dec_neg);
    s21_from_decimal_to_int(value_dec_neg, &res);
    printf("%d\n", res);
}

// src: grishakir
int s21_truncate(s21_decimal value, s21_decimal *result) {
    s21_copy(result, value);

    for (int i = 0; i < s21_getScale(value); ++i) {
        s21_right_shift(result);
    }
    s21_setScale(result, 0);
    return 0;
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

int main() {
    test_trunc();
    return 0;
}