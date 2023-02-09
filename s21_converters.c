#include "s21_decimal.h"

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
  int rank = 0;
  if(fabsf(src) < 1e-28 && fabsf(src) < 0) {  //  условие ошибки
    flag = 1;
  }

  char str_src[1000];
  int count = count_src(src, str_src), is_full = 0; //  count_src копирует переносит массив оттуда в str_src

  s21_from_int_to_decimal(10, &ten);

  for (size_t i = 0; i < strlen(str_src); i++) {  //  проходим по элементам и проверяем условие
        if (str_src[i] != '.' && str_src[i] != '-') {
            s21_from_int_to_decimal(str_src[i] - '0', &add);
            memset(&(dst->bits), 0, sizeof(dst->bits));
            for (int j = 0; j < 96; j++) {  //  второй цикл конвертирования
              int bit1 = s21_getBit(*dst, j);
              int bit2 = s21_getBit(add, j);

              s21_setBit(dst, j, bit1 ^ bit2 ^ rank);  //  ^ - правда когда один из битов 1, но не оба // removed * from dst
            }
            is_full = s21_mul(*dst, ten, dst);  //  не знаю что делать дальше
        }
    }

    if (is_full) {
        s21_div(*dst, ten, dst);
    }

    s21_setSign(dst, src < 0);  // removed & from dst
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
    long int exp = src.bits[3] & 8355840;  //  <- decimal value of binary 007F8000
    exp >>= 16;  //  shift exp to the right for 16 bits
    *dst = (float)(src.bits[0] * pow(10, -exp));

    if (s21_getSign(src)) {
      *dst = -*dst;
    }
  } else {
    flag = 1;
  }
  return flag;
}
