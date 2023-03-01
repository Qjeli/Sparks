#include "s21_decimal.h"

// need to add error check?
int s21_negate(s21_decimal value, s21_decimal *result) {
    *result = value;
    s21_setSign(result, !s21_getSign(value));
    return 0;
}

// -- helper functions from padmemur --
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

int div_ten(s21_decimal* number) {
    unsigned int buffer = 0;
    int scale_of_number = s21_getScale(*number);
    s21_decimal result = {{0, 0, 0, 0}};
    int highest_bit_pos = s21_last_bit(*number);
    for (int i = 0; i < highest_bit_pos + 2; i++) {
        if (buffer >= 10) {
            s21_shift_left(&result, 1); // 1?
            s21_setBit(&result, 0, 1);
            buffer -= 10;
            int new_bit = s21_getBit(*number, highest_bit_pos - i);
            buffer = buffer << 1;
            int_set_bit(&buffer, 0, new_bit);
        } else {
            s21_shift_left(&result, 1); // 1?
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
// -------------

// src: padmemur
// passes most of the tests
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

/*
// src: grishakir
// does not work, tests from rynortheast are wrong
// need to add error check
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
}
*/

// src: padmemur
// passes more than half of the tests
// try to test in main
int s21_round(s21_decimal value, s21_decimal *result) {
    int res = 0;
    if (result) {
        int is_less_then_zero = 0;
        s21_decimal tmp_value;
        s21_decimal half;
        s21_decimal diff;
        s21_decimal one = {{1, 0, 0, 0}};
        s21_from_float_to_decimal(0.5, &half);
        s21_decimal zero = {{0, 0, 0, 0}};
        if (s21_is_less(value, zero)) {
            is_less_then_zero = 1;
            s21_negate(value, &value);
        }
        s21_truncate(value, &tmp_value);
        s21_sub(value, tmp_value, &diff);
        if (s21_is_greater_or_equal(diff, half)) {
            s21_add(tmp_value, one, result);
        } else {
            *result = tmp_value;
        }
        if (is_less_then_zero) {
            s21_negate(*result, result);
        }
    } else {
        res = 1;
    }
    return res;
}

// src: grishakir
// passes more than half of the tests, need to check in main
/*
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
}
*/

// src: padmemur
// works, passes almost all tests

int s21_floor(s21_decimal value, s21_decimal *result) {
    int res = 0;
    if (result) {
        s21_decimal zero = {{0, 0, 0, 0}};
        s21_decimal one = {{1, 0, 0, 0}};
        s21_truncate(value, result);
        if (s21_is_less(value, zero)) {
            s21_sub(*result, one, result);
            s21_setSign(result, !s21_getSign(*result));
        }
    } else {
        res = 1;
    }
    return res;
}


// src: nyarlath
/*
int s21_floor(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  if (s21_getScale(value) > 28) {
    flag = 1;
  } else {
    s21_decimal tmp = {{1, 0, 0, 0}};
    s21_truncate(value, result);
    //if (s21_getBit(value, 127) == 1) {
    if (s21_getSign(*result) == 1) {
      //s21_sub(*result, tmp, result);
      s21_sub(*result, tmp, result);
      s21_setSign(result, !s21_getSign(*result));
    }
  }
  return flag;
}
*/