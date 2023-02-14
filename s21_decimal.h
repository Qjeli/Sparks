#ifndef SRC_S21_DECIMAL_H
#define SRC_S21_DECIMAL_H

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS_SIZE 4

typedef struct {
    int bits[BITS_SIZE];
} s21_decimal;

#define OK 0
#define s21_START_INFO 96
#define s21_NAN 3
#define TOO_MUCH_OR_INF 1
#define TOO_FEW_OR_NEG_INF  2
#define division_by_0 3

int s21_getBit(s21_decimal d, int i); //получения 1 или 0 для каждого бита
void s21_setBit(s21_decimal *d, int i, int value); // определенной позиции переменной 1
int s21_getScale(const s21_decimal d); //Возвращает масштаб данных, разрешенных в этом свойстве
void s21_setScale(s21_decimal *d, int scale); //для увеличение или уменьшение масштаба
void s21_check_scale(s21_decimal *value1, s21_decimal *value2);
int s21_getSign(const s21_decimal d); //заменa  параметра
void s21_setSign( s21_decimal *d, int sign);

void s21_init_decimal(s21_decimal *dec);
int s21_scale_equalization(s21_decimal *value_1, s21_decimal *value_2, int err_num);

void s21_decl_to_null(s21_decimal *decl);
void s21_bits_copy(s21_decimal value, s21_decimal *dest);
int s21_last_bit(s21_decimal value);
void s21_setting(s21_decimal tmp_buf, s21_decimal *tmp_del, s21_decimal *tmp_mod, int *discharge);
int s21_shift_left(s21_decimal *value, int num);
int s21_shift_right(s21_decimal *first, int shift);

int s21_integer_division(s21_decimal value_1, s21_decimal value_2, s21_decimal *result, s21_decimal *remainder, int error_code);
void s21_first_prepare(s21_decimal tmp_div, s21_decimal *tmp_mod,s21_decimal *tmp_del, s21_decimal value_2, int *discharge);
void s21_first_step(s21_decimal *tmp_div, s21_decimal value_2,
                    int *scale_value1, s21_decimal *tmp_res, int *index_res);
int count_src(float src, char* str_src);

int add(s21_decimal left, s21_decimal right, s21_decimal *result); // вспомогательная функция для сложения
void inverse(s21_decimal *value);
int is_Null(s21_decimal value);
int check(s21_decimal val_1, s21_decimal val_2, s21_decimal *result);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); //сложение
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); //вычитание
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); //умножение
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); //деление
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); //остаток от деления

int s21_is_less(s21_decimal value1, s21_decimal value2); // Меньше
int s21_is_less_or_equal(s21_decimal, s21_decimal); // Меньше или равно
int s21_is_greater(s21_decimal value_1, s21_decimal value_2); // Больше
int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2); // Больше или равно
int s21_is_equal(s21_decimal value1, s21_decimal value2); // Равно
int s21_is_not_equal(s21_decimal, s21_decimal); //Не равно

void s21_simple_sub(s21_decimal value1, s21_decimal value2, s21_decimal *result);
int s21_simple_add(s21_decimal value1, s21_decimal value2, s21_decimal *result);
s21_decimal s21_simple_div(s21_decimal value1, s21_decimal value2, s21_decimal *result);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int int_get_bit(unsigned int number, int byte);
void int_shift_left(unsigned int* num, int shift, int n);
void int_set_bit(unsigned int* number, int byte, int n);
int div_ten(s21_decimal* number);

int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);

//  bit[0] is small 32 bits
//  bit[1] is medium 32 bits 64
//  bit[2] is high 32 bits 96
//  bit[3]
//  Биты от 0 до 15, младшее слово, не используются и должны быть равны нулю.
//  Биты с 16 по 23 должны содержать показатель степени от 0 до 28, который указывает степень 10 для разделения целого числа.
//  Биты с 24 по 30 не используются и должны быть равны нулю.
//  Бит 31 содержит знак; 0 означает положительный, а 1 означает отрицательный

#endif  // SRC_S21_DECIMAL