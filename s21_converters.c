#include "s21_decimal.h"

void s21_simple_sub(s21_decimal value1, s21_decimal value2, s21_decimal *result) {
  s21_decl_to_null(result);
  for (int i = 0; i < 96; i++) {
    int bit_dec1 = s21_getBit(value1, i);
    int bit_dec2 = s21_getBit(value2, i);

    s21_setBit(result, i, bit_dec1 ^ bit_dec2);

    if (!bit_dec1 && bit_dec2) {
      int k = i + 1;
      while ((bit_dec1 = s21_getBit(value1, k)) != 1) {
        s21_setBit(&value1, k, 1);
        k++;
      }
      s21_setBit(&value1, k, 0);
    }
  }
}

int s21_simple_add(s21_decimal value1, s21_decimal value2, s21_decimal *result) {
  s21_decl_to_null(result);
  int rank = 0;
  for (int i = 0; i < 96; i++) {
    int bit_dec1 = s21_getBit(value1, i);
    int bit_dec2 = s21_getBit(value2, i);

    s21_setBit(result, i, bit_dec1 ^ bit_dec2 ^ rank);

    rank = (bit_dec1 && bit_dec2) || (bit_dec1 && rank) || (bit_dec2 && rank);
  }
  return rank;
}

s21_decimal s21_simple_div(s21_decimal value1, s21_decimal value2, s21_decimal *result) {
  if (result) {
    s21_decl_to_null(result);
  }

  s21_decimal ret = {0};
  s21_decimal temp = {0};
  if (s21_is_greater_or_equal(value1, value2)) {
    s21_setBit(&temp, 0, 1);
  }
  if (s21_is_greater(value2, value1)) {
    while (1) {
        s21_decimal copy_val2 = value2;
        while (s21_is_greater_or_equal(value1, copy_val2) && !(s21_getBit(value1, 95) && s21_getBit(copy_val2, 95))) {
          s21_shift_left(&copy_val2, 95);
          s21_shift_left(&temp, 95);
        }

        if ((!s21_getBit(value1, 95) && s21_getBit(copy_val2, 95)) || (s21_is_greater_or_equal(copy_val2, value1))) {
          s21_shift_right(&copy_val2, 96);
          s21_shift_right(&temp, 96);
        }

        s21_simple_sub(value1, copy_val2, &value1);
        if (result) {
          s21_simple_add(*result, temp, result);
        }
        s21_decl_to_null(&temp);
        s21_setBit(&temp, 0, 1);

        if (s21_is_less(value1, value2)) {
        break;
      }
    }
  }
  ret = value1;
  return ret;
}

/// | - - - - - - - - - Converters - - - - - - - - - - - |

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    memset(&(dst->bits), 0, sizeof(dst->bits));  //  filling an array of bits with zeros, with the size of bits
    if (src < 0) {  //  if srs is not negative then...
        dst->bits[3] = dst->bits[3] | (1u << 31);  //  make bit 31 into bit 1 in bits[3]
        src = -src;  //  make src negative
    }
    dst->bits[0] = src;  //  add src to bit[0]
    return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int flag = 0;  // флаг ошибки
  s21_decimal ten;  //  умножение на 10
  s21_decimal add;  //  для простого сложения
  s21_init_decimal(dst);
  if(fabsl(src) < 1e-28 && fabsl(src) < 0) {  //  условие ошибки
    flag = 1;
  }
  printf("%u\n ", dst->bits[0]);
  char str_src[1000];
  int count = count_src(src, str_src), is_full = 0; //  count_src копирует переносит массив оттуда в str_src

  s21_from_int_to_decimal(10, &ten);
  //printf("%s yy", str_src);
  for (size_t i = 0; i < strlen(str_src); i++) {  //  проходим по элементам и проверяем условие
        if (str_src[i] != '.' && str_src[i] != '-') {
            s21_from_int_to_decimal(str_src[i] - '0', &add);
            s21_simple_add(*dst, add, dst);
            
            is_full = s21_mul(*dst, ten, dst);
        }
    }

    if (is_full) {
        s21_simple_div(*dst, ten, dst);
    }

    s21_setSign(dst, src < 0);
    s21_setScale(dst, count);

  return flag;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
   int flag = 0;
    int data = 0;
    int scale = s21_getScale(src);

    if (scale + 31 < 95) {
        for (int i = scale + 31; i <= 95; ++i) {
            if (s21_getBit(src, i)) {
                flag = 1;
            }
        }

    }

    if (!flag) {
        for (int i = scale + 30; i >= scale; --i) {
            data <<= 1;
            data |= s21_getBit(src, i);
        }
        if (s21_getSign(src)) {
            data = -data;
        }
        *dst = data;
    }
    return flag;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int flag = 0;
  if (dst) {
    long int exp = s21_getScale(src);  //  <- decimal value of binary 007F8000
    //exp >>= 16;  //  shift exp to the right for 16 bits
    *dst = (float)(src.bits[0] * pow(10, -exp));
    if (s21_getSign(src)) {
      *dst *= -1;
    }
  } else {
    flag = 1;
  }
  return flag;
}
