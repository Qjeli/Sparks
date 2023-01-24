#include "arifmet.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
    for (int i = 0; i < 4; i++) {
        result->bits[i] = value.bits[i];
    }
    s21_setSign(result, !s21_getSign(value));
    return 0;
}