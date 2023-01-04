#ifndef SRC_DESIMAL_H_
#define SRC_DESIMAL_H_

#include "stdio.h" 

#define BITS_SIZE 4
typedef struct // 
{
    int bits[BITS_SIZE];
} s21_decimal;


int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

#endif // SRC_DESIMAL_H_
