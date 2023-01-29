#include <stdio.h>
#include <string.h>
#include "arifmet.h"

// padmemur common
/*
int int_get_bit(unsigned int number, int byte) {
    return (number & 1 << byte) ? 1 : 0;
}

void int_shift_left(unsigned int* num, int shift, int n) {
    *num ^= shift << n;
}

void int_set_bit(unsigned int* number, int byte, int n) {
    if (int_get_bit(*number, byte) != n)
        int_shift_left(number, 1, byte);
}

void s21_shift_decimal_left(s21_decimal* number) {
    int low_last_bit = s21_getBit(*number, 31);
    int mid_last_bit = s21_getBit(*number, 63);

    number->bits[0] <<= 1;
    number->bits[1] <<= 1;
    number->bits[2] <<= 1;

    s21_setBit(number, 32, low_last_bit);
    s21_setBit(number, 64, mid_last_bit);
}

int get_higher_bit(s21_decimal value) {
    int i = 95;
    for (; i >= 0; i--) {
        if (s21_getBit(value, i)) {
            break;
        }
    }
    return i;
}

int s21_div_by_10(s21_decimal* number) {
    unsigned int buffer = 0;
    int scale_of_number = s21_getScale(*number);
    s21_decimal result = {{0, 0, 0, 0}};
    int highest_bit_pos = get_higher_bit(*number);
    for (int i = 0; i < highest_bit_pos + 2; i++) {
        if (buffer >= 10) {
            s21_shift_decimal_left(&result);
            s21_setBit(&result, 0, 1);
            buffer -= 10;
            int new_bit = s21_getBit(*number, highest_bit_pos - i);
            buffer = buffer << 1;
            int_set_bit(&buffer, 0, new_bit);
        } else {
            s21_shift_decimal_left(&result);
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
*/

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

// src: padmemur
/*
int s21_truncate(s21_decimal value, s21_decimal* result) {
    int res = 0;
    if (result) {
        int scale = s21_getScale(value);
        int sign = s21_getBit(value, 127);

        for (int i = 0; i < scale; i++) {
            s21_div_by_10(&value);
        }

        *result = value;
        s21_setBit(result, 127, sign);
        s21_setScale(result, 0);
    } else {
        res = 1;
    }
    return res;
}
*/

/*
int s21_truncate(s21_decimal value, s21_decimal* result) {
    int res = 0;
    s21_decimal ten = {{10, 0, 0, 0}};
    if (result) {
        int scale = s21_getScale(value);
        int sign = s21_getBit(value, 127);

        for (int i = 0; i < scale; i++) {
            s21_div(value, ten, result);
        }

        *result = value;
        s21_setBit(result, 127, sign);
        s21_setScale(result, 0);
    } else {
        res = 1;
    }
    return res;
}
*/

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

// src: grishakir
// round

int main() {
    return 0;
}