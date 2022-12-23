#ifndef SRC_CONVERTER
#define SRC_CONVERTER

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS_SIZE 4

typedef struct 
{
    int bits[BITS_SIZE];
} s21_decimal;

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

//  bit[0] is small 32 bits
//  bit[1] is medium 32 bits
//  bit[2] is high 32 bits
//  bit[3]
//  Биты от 0 до 15, младшее слово, не используются и должны быть равны нулю.
//  Биты с 16 по 23 должны содержать показатель степени от 0 до 28, который указывает степень 10 для разделения целого числа.
//  Биты с 24 по 30 не используются и должны быть равны нулю.
//  Бит 31 содержит знак; 0 означает положительный, а 1 означает отрицательный

#endif  // SRC_CONVERTER