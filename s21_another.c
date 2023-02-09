#include "s21_decimal.h"

// -------------------------------------------------

// src: dec_4
int s21_negate(s21_decimal value, s21_decimal *result) {
    // for (int i = 0; i < 4; i++) {
    //     result->bits[i] = value.bits[i];
    // }
    // longer way
    
    *result = value; // shorter way

    s21_setSign(result, !s21_getSign(value));
    return 0;
}

// src: grishakir
int s21_truncate(s21_decimal value, s21_decimal *result) {
    s21_bits_copy(value, result);

    for (int i = 0; i < s21_getScale(value); ++i) {
        s21_shift_right(result, 1);
    }
    s21_setScale(result, 0);
    return 0;
} // passes half of the tests, need to check in main
// need to add error check

// src: grishakir
int s21_round(s21_decimal value, s21_decimal *result) {
    s21_decimal one = {{1, 0, 0, 0}};
    s21_bits_copy(value, result);

    if (s21_getScale(value)) {
        if (s21_getBit(value, s21_getScale(value) - 1)) {
            if (s21_getSign(value)) {
                s21_sub(value, one, result);
            } else {
                s21_add(value, one, result);
            }
        }
        for (int i = 0; i < s21_getScale(value); ++i) 
            {}
        s21_setScale(result, 0);
    }
    return 0;
} // passes most of the tests, need to check in main
// need to add error check

// src: grishakir
int s21_floor(s21_decimal value, s21_decimal *result) {
    int flag = 0;
    int flag_not_error = 0;
    s21_decimal one = {{1, 0, 0, 0}};

    if (!s21_getSign(value)) {
        flag = s21_truncate(value, result);
    } else {
        s21_bits_copy(*result, &value);
        for (int i = 0; i < s21_getScale(value); ++i) {
            flag_not_error |= s21_getBit(value, i);
        }
        if (flag_not_error) {
            flag = s21_sub(value, one, result);
        }
        flag = s21_truncate(*result, result);
    }
    return flag;
} // passes half of the tests, need to check in main
// need to add error check
