#include "arifmet.h"

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