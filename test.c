#include <stdio.h>
#include <string.h>

//

#define BITS_SIZE 4

typedef struct {
    int bits[BITS_SIZE];
} s21_decimal;

void s21_setBit(s21_decimal *d, int i, int value) {
    unsigned int mask = 1u << (i % 32);
    if (i / 32 < 4 && value) {
    d->bits[i / 32] |= mask;
  } else if (i / 32 < 4 && !value) {
    d->bits[i / 32] &= ~mask;  // ~ это побитовая инверсия
    // мы сбрасываем то значение которое было здесь. теперь оно = 0
  }
}

int s21_getBit(s21_decimal d, int i) {
    unsigned int mask = 1u << (i % 32); // u значит беззнаковая 1
    return d.bits [i / 32] & mask; 
}

int s21_getSign(const s21_decimal d) {
    unsigned int mask = 1u << 31;
    return !!(d.bits[3] & mask); // получаем или 0 или 1
}

int s21_getScale(const s21_decimal d) {
    return(char)(d.bits[3] >> 16);  // а если стоит знак отрицания то это не учитывают
    // return(char)((d.bits[3]& ~(1<<31)) >> 16);  // мой вариант
    // но остается вопрос. а что по степени. она же может быть отрицательной
}

void s21_setSign(s21_decimal *d, int sign) {
    s21_setBit(d, 127, sign);
}

//

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    memset(&(dst->bits), 0, sizeof(dst->bits));  //  filling an array of bits with zeros, with the size of bits
    if (src < 0) {  //  if srs is not negative then...
        dst->bits[3] = dst->bits[3] | (1u << 31);  //  make bit 31 into bit 1 in bits[3]
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

//

int s21_negate(s21_decimal value, s21_decimal *result) {
    for (int i = 0; i < 4; i++) {
        result->bits[i] = value.bits[i];
    }
    s21_setSign(result, !s21_getSign(value));
    return 0;
} // works, but the conversion seems odd

void negate_test() {
    int value_int = 0, res = 0;
    s21_decimal value_dec, value_dec_neg;
    scanf("%d", &value_int);
    s21_from_int_to_decimal(value_int, &value_dec);
    s21_negate(value_dec, &value_dec_neg);
    s21_from_decimal_to_int(value_dec_neg, &res);
    printf("%d\n", res);
}

int main() {
    negate_test();
    return 0;
}