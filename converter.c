#include "converter.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    memset(&(dst->bits), 0, sizeof(dst->bits));  //  filling an array of bits with zeros, with the size of bits
    if (src < 0) {  //  if srs is not negative then...
        dst->bits[3] |= (1 << 31);  //  make bit 31 into bit 1 in bits[3]
        src = -src;  //  make src negative
    }
    dst->bits[0] = src;  //  add src to bit[0]
    return 0;
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
