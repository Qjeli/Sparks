#ifndef SRC_DESIMAL_H_
#define SRC_DESIMAL_H_

#include "stdio.h" 
/*0 - OK
1 - the number is too large or equal to infinity
2 - the number is too small or equal to negative infinity
3 - division by 0*/
#define BITS_SIZE 4
typedef struct // структура для decimal
{
    int bits[BITS_SIZE];
} s21_decimal;

typedef struct 
{
    int sign; // знак
    int move; // сдвиг запятой числа
} info;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// доп функции
void set_info(s21_decimal value, info *info_vall);
int get_info(s21_decimal value, int i);
#endif // SRC_DESIMAL_H_
