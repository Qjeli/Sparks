#include "s21_decimal.h"

#include <check.h>
#include <stdio.h>
#include <string.h>

/* ----------------------------------------------------------------
 * s21_add    <
 * ---------------------------------------------------------------- */

START_TEST(decimal_plus_plus) {
s21_decimal x = {{4294967295, 4294967295, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{1, 0, 0,                   0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_add(x, y, &z);
char res1[1000], res2[1000] = "0 0 1 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_2) {
s21_decimal x = {{20, 1, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{21, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_add(x, y, &z);
char res1[1000], res2[1000] = "4294967295 0 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_3) {
s21_decimal x = {{20, 1, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{21, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_add(x, y, &z);
char res1[1000], res2[1000] = "41 1 0 2147483648";  // ...
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_4) {
s21_decimal x = {{20, 1, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{21, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_add(x, y, &z);
char res1[1000], res2[1000] = "4294967295 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_5) {
s21_decimal x = {{20, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{21, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_add(x, y, &z);
char res1[1000], res2[1000] = "1 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_6) {
s21_decimal x = {{25, 1, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{21, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_add(x, y, &z);
char res1[1000], res2[1000] = "4 1 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_7) {
s21_decimal x = {{100, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{100, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_add(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_8) {
s21_decimal x = {{99, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{100, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_add(x, y, &z);
char res1[1000], res2[1000] = "1 0 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_9) {
s21_decimal x = {{0, 0, 300000000, 1835008}};
s21_decimal y = {{0, 0, 300000000, 1835008}};
s21_decimal z = {{0, 0, 0, 0}};
s21_add(x, y, &z);
char res1[1000], res2[1000] = "0 0 600000000 1835008";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_10) {
s21_decimal x = {{0, 0, 3000000000, 0}};
s21_decimal y = {{0, 0, 3000000000, 0}};
s21_decimal z = {{0, 0, 0, 0}};
s21_add(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";  // ...
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_11) {
s21_decimal x = {{1, 0, 0, 1835008}};
s21_decimal y = {{1, 0, 0, 2149318656}};
s21_decimal z = {{0, 0, 0, 0}};
s21_add(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";  // ...
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(add_test_1) {
  int num1 = 42;
  int num2 = 30;
  int sum_int = 72;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
  ck_assert_int_eq(s21_add(a, b, &res_dec), 0);
}
END_TEST

START_TEST(add_test_2) {
  int num1 = 1000;
  int num2 = 2000;
  int sum_int = 3000;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_3) {
  int num1 = 0;
  int num2 = 0;
  int sum_int = 0;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_4) {
  int num1 = -15;
  int num2 = 5;
  int sum_int = -10;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_5) {
  int num1 = 11115;
  int num2 = 5;
  int sum_int = 11120;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_6) {
  int num1 = -1;
  int num2 = -10;
  int sum_int = -11;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_7) {
  s21_decimal src1, src2;
  int a = -1234;
  int b = 234;
  int res_origin = -1000;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_8) {
  s21_decimal src1, src2;
  int a = -9403;
  int b = 234;
  int res_origin = -9169;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_9) {
  s21_decimal src1, src2;
  int a = 9403;
  int b = 202;
  int res_origin = 9605;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_10) {
  s21_decimal src1, src2;
  int a = 450;
  int b = -50;
  int res_origin = 400;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_11) {
  s21_decimal src1, src2;
  float num1 = 7.25;
  float num2 = 9.5;
  float res_origin = 16.75;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_12) {
  s21_decimal src1, src2;
  int num1 = -1234;
  float num2 = 1.234;
  float res_origin = -1232.766;
  s21_from_int_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_13) {
  s21_decimal src1, src2;
  int num1 = -1234;
  float num2 = -1.234;
  float res_origin = -1235.234;
  s21_from_int_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_14) {
  s21_decimal src1, src2;
  float num1 = -94;
  float num2 = 0.00234;
  float res_origin = num1 + num2;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_15) {
  s21_decimal src1, src2;
  float num1 = -940.3;
  float num2 = 0.000234;
  float res_origin = -940.299766;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_16) {
  s21_decimal src1, src2;
  float num1 = -0.9403;
  float num2 = 0.000234;
  float res_origin = -0.940066;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_17) {
  s21_decimal src1, src2;
  float num1 = -0.9403;
  float num2 = 2.0234;
  float res_origin = num1 + num2;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_18) {
  s21_decimal src1, src2;
  float num1 = -0.9403;
  float num2 = -112.0234;
  float res_origin = -112.9637;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_19) {
  s21_decimal src1, src2;
  float num1 = -0.94e03;
  float num2 = -112.0234;
  float res_origin = -1052.0234;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_20) {
  s21_decimal src1, src2;
  float num1 = -0.94e03;
  float num2 = -112.0e2;
  float res_origin = -12140;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST


/* ----------------------------------------------------------------
 * s21_sub    <
 * ---------------------------------------------------------------- */


START_TEST(decimal_sub_1) {
s21_decimal x = {{1, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_sub(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_2) {
s21_decimal x = {{2, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_sub(x, y, &z);
char res1[1000], res2[1000] = "1 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_3) {
s21_decimal x = {{1, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{2, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_sub(x, y, &z);
char res1[1000], res2[1000] = "1 0 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_4) {
s21_decimal x = {{2, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{2, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_sub(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_5) {
s21_decimal x = {{1, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{2, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_sub(x, y, &z);
char res1[1000], res2[1000] = "1 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_6) {
s21_decimal x = {{2, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{1, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_sub(x, y, &z);
char res1[1000], res2[1000] = "1 0 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_7) {
s21_decimal x = {{2, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{1, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_sub(x, y, &z);
char res1[1000], res2[1000] = "3 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_8) {
s21_decimal x = {{2, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_sub(x, y, &z);
char res1[1000], res2[1000] = "3 0 0 2147483648";  // ...
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_9) {
s21_decimal x = {{0, 0, 3000000000, 0b10000000000000000000000000000000}};
s21_decimal y = {{0, 0, 3000000001, 0b00000000000000000000000000000000}};
s21_setScale(&x, 5);
s21_setScale(&y, 5);
s21_decimal z = {{0, 0, 0, 0}};
s21_sub(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";  // ...
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_10) {
s21_decimal x = {{0, 0, 3000000000, 0b10000000000000000000000000000000}};
s21_decimal y = {{0, 0, 3000000001, 0b00000000000000000000000000000000}};
s21_setScale(&x, 0);
s21_setScale(&y, 0);
s21_decimal z = {{0, 0, 0, 0}};
s21_sub(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";  // ...
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_11) {
s21_decimal x = {{1, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{1, 0, 0, 0b10000000000000000000000000000000}};
s21_setScale(&x, 28);
s21_setScale(&y, 28);
s21_decimal z = {{0, 0, 0, 0}};
s21_sub(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";  // ...
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_subTest1) {
  // 863
  s21_decimal src1, src2, origin;
  // src1 = 2;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest2) {
  // 889
  s21_decimal src1, src2, origin;
  // src1 = 3;
  // src2 = 2;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest3) {
  // 915
  s21_decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest4) {
  // 941
  s21_decimal src1, src2, origin;
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest5) {
  // 967
  s21_decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest6) {
  // 993
  s21_decimal src1, src2, origin;
  // src1 = 2;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest7) {
  // 1019
  s21_decimal src1, src2, origin;
  // src1 = 6521;
  // src2 = 74121;

  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000010000100000010000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest8) {
  // 1045
  s21_decimal src1, src2, origin;
  // src1 = 4;
  // src2 = 97623323;

  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000101110100011001110100010111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest9) {
  // 1071
  s21_decimal src1, src2, origin;
  // src1 = 65658654;
  // src2 = 5;

  src1.bits[0] = 100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 95;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 5;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest10) {
  // 1097
  s21_decimal src1, src2, origin;
  // src1 = -364748;
  // src2 = 1;

  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000001011001000011001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest11) {
  // 1123
  s21_decimal src1, src2, origin;
  // src1 = 1;
  // src2 = 98745654321;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b11111101101100110001110000110000;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest12) {
  // 1149
  s21_decimal src1, src2, origin;
  // src1 = -9878798789;
  // src2 = -3;

  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b01001100110100101000000111000010;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest13) {
  // 1175
  s21_decimal src1, src2, origin;
  // src1 = 9999999999999999999;
  // src2 = 1;

  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b10001001111001111111111111111110;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest14) {
  // 1201
  s21_decimal src1, src2, origin;
  // src1 = 18446744073709551615;
  // src2 = 1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b11111111111111111111111111111110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest15) {
  // 1227
  s21_decimal src1, src2, origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;

  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;

  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b11000000100010111000101000100010;
  origin.bits[1] = 0b11111111111111111111111111111101;
  origin.bits[2] = 0b00000000000000000000000000001001;
  origin.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest16) {
  // 1253
  s21_decimal src1, src2, origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = 54564654;

  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;

  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b10010100100110011101101011101101;
  origin.bits[1] = 0b11000101100100110110100101100010;
  origin.bits[2] = 0b10110000001111101111000110111100;
  origin.bits[3] = 0b10000000000011100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest17) {
  // 1279
  s21_decimal src1, src2, origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;

  // -545454512454545.35265454545645 exp 14
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;

  // -5.352654545456454545645464 exp 24
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  // -54545451245453999999999999999 exp 14
  s21_sub(src1, src2, &result);

  // -54545451245453999999999999999 exp 14
  origin.bits[0] = 0b01001111100110101111111111111111;
  origin.bits[1] = 0b11111001111001100011111011011011;
  origin.bits[2] = 0b10110000001111101111000010010100;
  origin.bits[3] = 0b10000000000011100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest18) {
  // 1305
  s21_decimal src1, src2, origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;

  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest19) {
  // 1331
  s21_decimal src1, src2, origin;
  // src1 = 12345677.987654345678987654346;
  // 12345677.987654345678987654346
  // src2 = 87654323456.9876545678987653;
  // 87654323456.9876545678987653
  // printf("\ns21_subTest19 s21_subTest19 s21_subTest19\n\n");

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);
  // 87641977779.00000022221977764 exp 17

  origin.bits[0] = 0b10010010000001100111100010100100;
  origin.bits[1] = 0b10001011011010100100100011011111;
  origin.bits[2] = 0b00011100010100011001001100010001;
  origin.bits[3] = 0b10000000000100010000000000000000;
  // print_2(&src1);
  // print_2(&src2);
  // print_2(&result);
  // print_2(&origin);
  // 87641977779.00000022221977765 exp 17
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest20) {
  // 1357
  s21_decimal src1, src2, origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b11010010000011011110010110111111;
  origin.bits[1] = 0b10100111010011100111001000100001;
  origin.bits[2] = 0b00011100010100111001110111101101;
  origin.bits[3] = 0b10000000000100010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest21) {
  // 1383
  s21_decimal src1, src2, origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b11010010000011011110010110111111;
  origin.bits[1] = 0b10100111010011100111001000100001;
  origin.bits[2] = 0b00011100010100111001110111101101;
  origin.bits[3] = 0b00000000000100010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest22) {
  // 1409
  s21_decimal src1, src2, origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b10010010000001100111100010100100;
  origin.bits[1] = 0b10001011011010100100100011011111;
  origin.bits[2] = 0b00011100010100011001001100010001;
  origin.bits[3] = 0b00000000000100010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest23) {
  // 1435
  s21_decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest24) {
  // 1461
  s21_decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest25) {
  // 1487
  s21_decimal src1, src2, origin;
  // src1 = 0;
  // src2 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest26) {
  // 1513
  s21_decimal src1, src2, origin;
  // src1 = 792281625142643375935439503;
  // src2 = -1;

  src1.bits[0] = 0b00101000111101011100001010001111;
  src1.bits[1] = 0b11110101110000101000111101011100;
  src1.bits[2] = 0b00000010100011110101110000101000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00101000111101011100001010010000;
  origin.bits[1] = 0b11110101110000101000111101011100;
  origin.bits[2] = 0b00000010100011110101110000101000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest27) {
  // 1539
  s21_decimal src1, src2, origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;

  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b01011011000111100101100000001101;
  origin.bits[1] = 0b01101101111100110111111101100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest28) {
  // 1565
  s21_decimal src1, src2, origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;

  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b11101000101010001011011101111000;
  origin.bits[1] = 0b00000000000111110100000111110001;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest29) {
  // 1591
  s21_decimal src1, src2, origin;
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;

  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;

  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00001110111111111010100000101010;
  origin.bits[1] = 0b00101001110101100000001000110100;
  origin.bits[2] = 0b00000000000001011111000010100001;
  origin.bits[3] = 0b10000000000110000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest30) {
  // 1617
  s21_decimal src1, src2, origin;
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;

  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;

  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b11010010100100100111101010001100;
  origin.bits[1] = 0b10011110100111100111000100000100;
  origin.bits[2] = 0b00011111101010011000000100111000;
  origin.bits[3] = 0b10000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest31) {
  // 1643
  s21_decimal src1, src2, origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;

  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;

  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b01011010101111100101111101110011;
  origin.bits[1] = 0b00101101001111010011000001101000;
  origin.bits[2] = 0b00000100101010001101010101010111;
  origin.bits[3] = 0b10000000000111000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest32) {
  // 1669
  s21_decimal src1, src2, origin;
  // src1 = -0.77545545454546589781;
  // src2 = 87894515154546456456;

  src1.bits[0] = 0b10101100001010000001100001010101;
  src1.bits[1] = 0b00110100001010010001111010111100;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000101000000000000000000;

  src2.bits[0] = 0b00010011111011011111011110001000;
  src2.bits[1] = 0b11000011110010000000101111011001;
  src2.bits[2] = 0b00000000000000000000000000000100;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b10111000010101011100100001001001;
  origin.bits[1] = 0b01100110100011011000001100010111;
  origin.bits[2] = 0b00011100011001100111011011000001;
  origin.bits[3] = 0b10000000000010000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest33) {
  // 1695
  s21_decimal src1, src2, origin;
  // src1 = -7922816251426433759354395033;
  // src2 = 1;

  src1.bits[0] = 0b10011001100110011001100110011001;
  src1.bits[1] = 0b10011001100110011001100110011001;
  src1.bits[2] = 0b00011001100110011001100110011001;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b10011001100110011001100110011010;
  origin.bits[1] = 0b10011001100110011001100110011001;
  origin.bits[2] = 0b00011001100110011001100110011001;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_mul    <
 * ---------------------------------------------------------------- */

START_TEST(decimal_mul_1) {
s21_decimal x = {{0, 0, 0, 0b00000000000000000000000000000000}};  // 0b00000000000011110000000000000000
s21_decimal y = {{0, 0, 0, 0b00000000000000000000000000000000}};  // 0b00000000000000100000000000000000
s21_decimal z = {{0, 0, 0, 0}};
s21_mul(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";  // 1114112
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_2) {
s21_decimal x = {{2, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{5, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_mul(x, y, &z);
char res1[1000], res2[1000] = "10 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_3) {
s21_decimal x = {{2, 1, 2, 0b00000000000000000000000000000000}};
s21_decimal y = {{5, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_mul(x, y, &z);
char res1[1000], res2[1000] = "10 5 10 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_4) {
s21_decimal x = {{2, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{0, 0, 10, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_mul(x, y, &z);
char res1[1000], res2[1000] = "0 0 20 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_5) {
s21_decimal x = {{1000000000, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{6, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_mul(x, y, &z);
char res1[1000], res2[1000] = "1705032704 1 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_6) {
s21_decimal x = {{1000000000, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{6, 0, 0,          0b10000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_mul(x, y, &z);
char res1[1000], res2[1000] = "1705032704 1 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_7) {
s21_decimal x = {{1000000000, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{6, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_mul(x, y, &z);
char res1[1000], res2[1000] = "1705032704 1 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_8) {
s21_decimal x = {{1000000000, 0, 0, 0b00000000000011110000000000000000}};
s21_decimal y = {{6, 0, 0,          0b10000000000000010000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_mul(x, y, &z);
char res1[1000], res2[1000] = "1705032704 1 0 2148532224";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_9) {
s21_decimal x = {{1, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{165, 22, 6587456, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_mul(x, y, &z);
char res1[1000], res2[1000] = "165 22 6587456 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_10) {
s21_decimal x = {{400, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{500, 0, 0, 0b00000000000000000000000000000000}};
s21_setScale(&x, 14);
s21_setScale(&y, 14);
s21_decimal z = {{0, 0, 0, 0}};
s21_mul(x, y, &z);
char res1[1000], res2[1000] = "200000 0 0 1835008";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST
/*
START_TEST(decimal_mul_14) {
s21_decimal x = {{400, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{500, 0, 0, 0b00000000000000000000000000000000}};
s21_setScale(&x, 17);
s21_setScale(&y, 18);
s21_decimal z = {{0, 0, 0, 0}};
s21_mul(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_15) {
s21_decimal x = {{400, 0, 5000000, 0b00000000000000000000000000000000}};
s21_decimal y = {{500, 0, 5000000, 0b00000000000000000000000000000000}};
s21_setScale(&x, 12);
s21_setScale(&y, 12);
s21_decimal z = {{0, 0, 0, 0}};
s21_mul(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST
*/

START_TEST(decimal_mul_16) {
s21_decimal src1, src2;
int a = 9403;
int b = 202;
int res_our_dec = 0;
s21_from_int_to_decimal(a, &src1);
s21_from_int_to_decimal(b, &src2);
int res_origin = 1899406;
s21_decimal res_od;
s21_mul(src1, src2, &res_od);
s21_from_decimal_to_int(res_od, &res_our_dec);
ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_div;
 * ---------------------------------------------------------------- */

START_TEST(div_1) {
s21_decimal x = {{3100000000, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
s21_div(x, y, &z);
char res1[1000], res2[1000] = "3100000000 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(div_2) {
s21_decimal x = {{1, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{3100000000, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
s21_div(x, y, &z);
char res1[1000], res2[1000] = "3225810516 0 0 1245184";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(div_3) {
s21_decimal x = {{52525252, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{0, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
int n1 = 0;
n1 = s21_div(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(div_4) {
s21_decimal x = {{52525252, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{0, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
int n1 = 0;
n1 = s21_div(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(div_5) {
s21_decimal x = {{52525252, 0, 0, 0b0000000000000000000000000000000}};
s21_decimal y = {{0, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
int n1 = 0;
n1 = s21_div(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(div_6) {
s21_decimal x = {{52525252, 0, 0, 8845}};
s21_decimal y = {{0, 0, 0, 10}};
s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
int n1 = 0;
n1 = s21_div(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(div_7) {
s21_decimal x = {{52525252, 0, 0, 65465}};
s21_decimal y = {{0, 0, 0, 9598595}};
s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
int n1 = 0;
n1 = s21_div(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(div_8) {
s21_decimal x = {{5, 0, 0, 0}};
s21_decimal y = {{3, 0, 0, 0}};
s21_decimal z = {{0, 0, 0, 0}};
s21_setScale(&x, 0);
s21_setScale(&y, 20);
int n1 = 0;
n1 = s21_div(x, y, &z);
char res1[1000], res2[1000] = "447392427 1737688055 903501810 524288";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(div_9) {
s21_decimal x = {{5, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{3, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_setScale(&x, 0);
s21_setScale(&y, 20);
int n1 = 0;
n1 = s21_div(x, y, &z);
char res1[1000], res2[1000] = "447392427 1737688055 903501810 2148007936";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(div_10) {
s21_decimal x = {{5, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{3, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_setScale(&x, 0);
s21_setScale(&y, 20);
int n1 = 0;
n1 = s21_div(x, y, &z);
char res1[1000], res2[1000] = "447392427 1737688055 903501810 2148007936";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(div_11) {
s21_decimal x = {{5, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal y = {{3, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_setScale(&x, 0);
s21_setScale(&y, 20);
int n1 = 0;
n1 = s21_div(x, y, &z);
char res1[1000], res2[1000] = "447392427 1737688055 903501810 524288";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(div_12) {
s21_decimal x = {{5, 0, 50, 0b10000000000000000000000000000000}};
s21_decimal y = {{5, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_setScale(&x, 0);
s21_setScale(&y, 20);
int n1 = 0;
n1 = s21_div(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 3);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_mod;
 * ---------------------------------------------------------------- */

START_TEST(mod_1) {
s21_decimal x = {{150000008, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{15, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
s21_setScale(&x, 3);
s21_setScale(&y, 0);
int n1 = 0;
n1 = s21_mod(x, y, &z);
char res1[1000], res2[1000] = "8 0 0 196608";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 0);
}
END_TEST
/*
START_TEST(mod_2) {
s21_decimal x = {{150000008, 0, 500000000, 0b00000000000000000000000000000000}};
s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
s21_setScale(&x, 0);
s21_setScale(&y, 3);
int n1 = 0;
n1 = s21_mod(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 196608";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 0);
}
END_TEST
*/

START_TEST(mod_3) {
s21_decimal x = {{91, 0, 0, 0}};
s21_decimal y = {{50, 0, 0, 0}};
s21_decimal z = {{0, 0, 0, 0}};
s21_setScale(&x, 0);
s21_setScale(&y, 0);
int n1 = 0;
n1 = s21_mod(x, y, &z);
char res1[1000], res2[1000] = "41 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(mod_4) {
s21_decimal x = {{91, 0, 0, 0}};
s21_decimal y = {{95, 0, 0, 0}};
s21_decimal z = {{0, 0, 0, 0}};
s21_setScale(&x, 0);
s21_setScale(&y, 0);
int n1 = 0;
n1 = s21_mod(x, y, &z);
char res1[1000], res2[1000] = "91 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(mod_5) {
s21_decimal x = {{91, 0, 0, 0}};
s21_decimal y = {{0, 0, 0, 0}};
s21_decimal z = {{0, 0, 0, 0}};
s21_setScale(&x, 0);
s21_setScale(&y, 0);
int n1 = 0;
n1 = s21_mod(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 3);
}
END_TEST
/*
START_TEST(mod_6) {
s21_decimal x = {{91, 0, 0, 0}};
s21_decimal y = {{5, 0, 0, 0}};
s21_decimal z = {{0, 0, 0, 0}};
s21_setScale(&x, 50);
s21_setScale(&y, 0);
int n1 = 0;
n1 = s21_mod(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 2);
}
END_TEST
*/

START_TEST(mod_7) {
s21_decimal x = {{125, 0, 0, 0}};
s21_decimal y = {{3, 0, 0, 0}};
s21_decimal z = {{0, 0, 0, 0}};
s21_setScale(&x, 1);
s21_setScale(&y, 0);
int n1 = 0;
n1 = s21_mod(x, y, &z);
char res1[1000], res2[1000] = "5 0 0 65536";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(mod_8) {
s21_decimal x = {{125, 0, 0, 0}};
s21_decimal y = {{3, 0, 0, 0}};
s21_decimal z = {{0, 0, 0, 0}};
s21_setScale(&x, 0);
s21_setScale(&y, 1);
int n1 = 0;
n1 = s21_mod(x, y, &z);
char res1[1000], res2[1000] = "2 0 0 65536";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(mod_test_1) {
  int num1 = 3;
  int num2 = 2;
  int res_origin = num1 % num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mod(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mod_test_2) {
  int num1 = -98765;
  int num2 = 1234;
  int res_origin = num1 % num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mod(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mod_test_3) {
  int num1 = 30198;
  int num2 = 20210;
  int res_origin = num1 % num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mod(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mod_test_4) {
  int num1 = -98765;
  int num2 = -1234;
  int res_origin = num1 % num2;
  // printf("%f", fmod(-98765, -1234));
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mod(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mod_test_5) {
  int num1 = 98765;
  int num2 = 127234;
  int res_origin = num1 % num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mod(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mod_test_6) {
  int num1 = 342576;
  int num2 = 1542134;
  int res_origin = num1 % num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mod(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST


int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, decimal_plus_plus);
  tcase_add_test(tc1_1, decimal_plus_plus_2);
  tcase_add_test(tc1_1, decimal_plus_plus_3);
  tcase_add_test(tc1_1, decimal_plus_plus_4);
  tcase_add_test(tc1_1, decimal_plus_plus_5);
  tcase_add_test(tc1_1, decimal_plus_plus_6);
  tcase_add_test(tc1_1, decimal_plus_plus_7);
  tcase_add_test(tc1_1, decimal_plus_plus_8);
  tcase_add_test(tc1_1, decimal_plus_plus_9);
  tcase_add_test(tc1_1, decimal_plus_plus_10);
  tcase_add_test(tc1_1, decimal_plus_plus_11);

  tcase_add_test(tc1_1, add_test_1);
  tcase_add_test(tc1_1, add_test_2);
  tcase_add_test(tc1_1, add_test_3);
  tcase_add_test(tc1_1, add_test_4);
  tcase_add_test(tc1_1, add_test_5);
  tcase_add_test(tc1_1, add_test_6);
  tcase_add_test(tc1_1, add_test_7);
  tcase_add_test(tc1_1, add_test_8);
  tcase_add_test(tc1_1, add_test_9);
  tcase_add_test(tc1_1, add_test_10);
  tcase_add_test(tc1_1, add_test_11);
  tcase_add_test(tc1_1, add_test_12);
  tcase_add_test(tc1_1, add_test_13);
  tcase_add_test(tc1_1, add_test_14);
  tcase_add_test(tc1_1, add_test_15);
  tcase_add_test(tc1_1, add_test_16);
  tcase_add_test(tc1_1, add_test_17);
  tcase_add_test(tc1_1, add_test_18);
  tcase_add_test(tc1_1, add_test_19);
  tcase_add_test(tc1_1, add_test_20);

  tcase_add_test(tc1_1, decimal_mul_1);
  tcase_add_test(tc1_1, decimal_mul_2);
  tcase_add_test(tc1_1, decimal_mul_3);
  tcase_add_test(tc1_1, decimal_mul_4);
  tcase_add_test(tc1_1, decimal_mul_5);
  tcase_add_test(tc1_1, decimal_mul_6);
  tcase_add_test(tc1_1, decimal_mul_7);
  tcase_add_test(tc1_1, decimal_mul_8);
  tcase_add_test(tc1_1, decimal_mul_9);
  tcase_add_test(tc1_1, decimal_mul_10);
  // tcase_add_test(tc1_1, decimal_mul_14);
  // tcase_add_test(tc1_1, decimal_mul_15);
  tcase_add_test(tc1_1, decimal_mul_16);

  tcase_add_test(tc1_1, decimal_sub_1);
  tcase_add_test(tc1_1, decimal_sub_2);
  tcase_add_test(tc1_1, decimal_sub_3);
  tcase_add_test(tc1_1, decimal_sub_4);
  tcase_add_test(tc1_1, decimal_sub_5);
  tcase_add_test(tc1_1, decimal_sub_6);
  tcase_add_test(tc1_1, decimal_sub_7);
  tcase_add_test(tc1_1, decimal_sub_8);
  tcase_add_test(tc1_1, decimal_sub_9);
  tcase_add_test(tc1_1, decimal_sub_10);
  tcase_add_test(tc1_1, decimal_sub_11);

  tcase_add_test(tc1_1, s21_subTest1);
  tcase_add_test(tc1_1, s21_subTest2);
  tcase_add_test(tc1_1, s21_subTest3);
  tcase_add_test(tc1_1, s21_subTest4);
  tcase_add_test(tc1_1, s21_subTest5);
  tcase_add_test(tc1_1, s21_subTest6);
  tcase_add_test(tc1_1, s21_subTest7);
  tcase_add_test(tc1_1, s21_subTest8);
  tcase_add_test(tc1_1, s21_subTest9);
  tcase_add_test(tc1_1, s21_subTest10);
  tcase_add_test(tc1_1, s21_subTest11);
  tcase_add_test(tc1_1, s21_subTest12);
  tcase_add_test(tc1_1, s21_subTest13);
  tcase_add_test(tc1_1, s21_subTest14);
  tcase_add_test(tc1_1, s21_subTest15);
  tcase_add_test(tc1_1, s21_subTest16);
  tcase_add_test(tc1_1, s21_subTest17);
  tcase_add_test(tc1_1, s21_subTest18);
  tcase_add_test(tc1_1, s21_subTest19);
  tcase_add_test(tc1_1, s21_subTest20);
  tcase_add_test(tc1_1, s21_subTest21);
  tcase_add_test(tc1_1, s21_subTest22);
  tcase_add_test(tc1_1, s21_subTest23);
  tcase_add_test(tc1_1, s21_subTest24);
  tcase_add_test(tc1_1, s21_subTest25);
  tcase_add_test(tc1_1, s21_subTest26);
  tcase_add_test(tc1_1, s21_subTest27);
  tcase_add_test(tc1_1, s21_subTest28);
  tcase_add_test(tc1_1, s21_subTest29);
  tcase_add_test(tc1_1, s21_subTest30);
  tcase_add_test(tc1_1, s21_subTest31);
  tcase_add_test(tc1_1, s21_subTest32);
  tcase_add_test(tc1_1, s21_subTest33);

  tcase_add_test(tc1_1, div_1);
  tcase_add_test(tc1_1, div_2);
  tcase_add_test(tc1_1, div_3);
  tcase_add_test(tc1_1, div_4);
  tcase_add_test(tc1_1, div_5);
  tcase_add_test(tc1_1, div_6);
  tcase_add_test(tc1_1, div_7);
  tcase_add_test(tc1_1, div_8);
  tcase_add_test(tc1_1, div_9);
  tcase_add_test(tc1_1, div_10);
  tcase_add_test(tc1_1, div_11);
  tcase_add_test(tc1_1, div_12);

  tcase_add_test(tc1_1, mod_1);
  // tcase_add_test(tc1_1, mod_2);
  tcase_add_test(tc1_1, mod_3);
  tcase_add_test(tc1_1, mod_4);
  tcase_add_test(tc1_1, mod_5);
  // tcase_add_test(tc1_1, mod_6);
  tcase_add_test(tc1_1, mod_7);
  tcase_add_test(tc1_1, mod_8);

  tcase_add_test(tc1_1, mod_test_1);
  tcase_add_test(tc1_1, mod_test_2);
  tcase_add_test(tc1_1, mod_test_3);
  tcase_add_test(tc1_1, mod_test_4);
  tcase_add_test(tc1_1, mod_test_5);
  tcase_add_test(tc1_1, mod_test_6);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}