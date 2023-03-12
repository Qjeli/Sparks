#include "s21_decimal.h"

#include <check.h>
#include <stdio.h>
#include <string.h>

// s21_arithmetic

/* ----------------------------------------------------------------
 * s21_add    <
 * ---------------------------------------------------------------- */

START_TEST(decimal_add_1) {
  s21_decimal x = {{4294967294, S21_MAX_UINT, S21_MAX_UINT,
                    0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "4294967295 4294967295 4294967295 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_add_2) {
  s21_decimal x = {{20, 1, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{21, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "4294967295 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

/*
START_TEST(decimal_add_3) {
  s21_decimal x = {{20, 1, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{21, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "41 1 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST
*/

START_TEST(decimal_add_4) {
  s21_decimal x = {{20, 1, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{21, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "4294967295 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_add_5) {
  s21_decimal x = {{20, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{21, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_add_6) {
  s21_decimal x = {{25, 1, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{21, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "4 1 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_add_7) {
  s21_decimal x = {{100, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{100, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_add_8) {
  s21_decimal x = {{99, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{100, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_add_9) {
  s21_decimal x = {{0, 0, 300000000, 1835008}};
  s21_decimal y = {{0, 0, 300000000, 1835008}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "0 0 600000000 1835008";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_add_10) {
  s21_decimal x = {{0, 0, 3000000000, 0}};
  s21_decimal y = {{0, 0, 3000000000, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "0 0 1705032704 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_add_11) {
  s21_decimal x = {{1, 0, 0, 1835008}};
  s21_decimal y = {{1, 0, 0, 2149318656}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 1835008";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_sub - вычитание
 * ---------------------------------------------------------------- */

START_TEST(decimal_sub_1) {
  s21_decimal x = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_2) {
  s21_decimal x = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_3) {
  s21_decimal x = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_4) {
  s21_decimal x = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_5) {
  s21_decimal x = {{1, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_6) {
  s21_decimal x = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_7) {
  s21_decimal x = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char res1[1000], res2[1000] = "3 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_8) {
  s21_decimal x = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char res1[1000], res2[1000] = "3 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
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
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
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
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
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
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_mul - умножение
 * ---------------------------------------------------------------- */

START_TEST(decimal_mul_1) {
  s21_decimal x = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_2) {
  s21_decimal x = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "10 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_3) {
  s21_decimal x = {{2, 1, 2, 0b00000000000000000000000000000000}};
  s21_decimal y = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "10 5 10 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_4) {
  s21_decimal x = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 10, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "0 0 20 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_5) {
  s21_decimal x = {{1000000000, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{6, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "1705032704 1 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_6) {
  s21_decimal x = {{1000000000, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{6, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "1705032704 1 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_7) {
  s21_decimal x = {{1000000000, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{6, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "1705032704 1 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_8) {
  s21_decimal x = {{1000000000, 0, 0, 0b00000000000011110000000000000000}};
  s21_decimal y = {{6, 0, 0, 0b10000000000000010000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "1705032704 1 0 2148532224";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_9) {
  s21_decimal x = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{165, 22, 6587456, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "165 22 6587456 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
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
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_14) {
s21_decimal x = {{400, 0, 0, 0b00000000000000000000000000000000}};
s21_decimal y = {{500, 0, 0, 0b00000000000000000000000000000000}};
s21_setScale(&x, 17);
s21_setScale(&y, 18);
s21_decimal z = {{0, 0, 0, 0}};
s21_mul(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1],
z.bits[2], z.bits[3]); ck_assert_str_eq(res1, res2);
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
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1],
z.bits[2], z.bits[3]); ck_assert_str_eq(res1, res2);
}
END_TEST

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

START_TEST(decimal_div_1) {
  s21_decimal x = {{3100000000, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_div(x, y, &z);
  char res1[1000], res2[1000] = "3100000000 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_div_2) {
  s21_decimal x = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{3100000000, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_div(x, y, &z);
  char res1[1000], res2[1000] = "3225810516 0 0 1245184";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_div_3) {
  s21_decimal x = {{52525252, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(decimal_div_4) {
  s21_decimal x = {{52525252, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(decimal_div_5) {
  s21_decimal x = {{52525252, 0, 0, 0b0000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(decimal_div_6) {
  s21_decimal x = {{52525252, 0, 0, 8845}};
  s21_decimal y = {{0, 0, 0, 10}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(decimal_div_7) {
  s21_decimal x = {{52525252, 0, 0, 65465}};
  s21_decimal y = {{0, 0, 0, 9598595}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(decimal_div_8) {
  s21_decimal x = {{5, 0, 0, 0}};
  s21_decimal y = {{3, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 20);
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "447392427 1737688055 903501810 524288";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(decimal_div_9) {
  s21_decimal x = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 20);
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "447392427 1737688055 903501810 2148007936";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(decimal_div_10) {
  s21_decimal x = {{5, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{3, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 20);
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "447392427 1737688055 903501810 2148007936";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(decimal_div_11) {
  s21_decimal x = {{5, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 20);
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "447392427 1737688055 903501810 524288";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(decimal_div_12) {
s21_decimal x = {{5, 0, 50, 0b10000000000000000000000000000000}};
s21_decimal y = {{5, 0, 0, 0b10000000000000000000000000000000}};
s21_decimal z = {{0, 0, 0, 0}};
s21_setScale(&x, 0);
s21_setScale(&y, 20);
int n1 = 0;
n1 = s21_div(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1],
z.bits[2], z.bits[3]); ck_assert_str_eq(res1, res2); ck_assert_int_eq(n1, 3);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_mod
 * ---------------------------------------------------------------- */

START_TEST(decimal_mod_1) {
  s21_decimal x = {{150000008, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{15, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 3);
  s21_setScale(&y, 0);
  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "8 0 0 196608";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

// START_TEST(decimal_mod_2) {
// s21_decimal x = {{150000008, 0, 500000000, 0b00000000000000000000000000000000}};
// s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
// s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
// s21_setScale(&x, 0);
// s21_setScale(&y, 3);
// int n1 = 0;
// n1 = s21_mod(x, y, &z);
// char res1[1000], res2[1000] = "0 0 0 196608";
// snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1],
// z.bits[2], z.bits[3]); ck_assert_str_eq(res1, res2); ck_assert_int_eq(n1, 0);
// }
// END_TEST

START_TEST(decimal_mod_3) {
  s21_decimal x = {{91, 0, 0, 0}};
  s21_decimal y = {{50, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 0);
  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "41 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(decimal_mod_4) {
  s21_decimal x = {{91, 0, 0, 0}};
  s21_decimal y = {{95, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 0);
  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "91 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(decimal_mod_5) {
  s21_decimal x = {{91, 0, 0, 0}};
  s21_decimal y = {{0, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 0);
  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(decimal_mod_6) {
s21_decimal x = {{91, 0, 0, 0}};
s21_decimal y = {{5, 0, 0, 0}};
s21_decimal z = {{0, 0, 0, 0}};
s21_setScale(&x, 50);
s21_setScale(&y, 0);
int n1 = 0;
n1 = s21_mod(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1],
z.bits[2], z.bits[3]); ck_assert_str_eq(res1, res2); ck_assert_int_eq(n1, 2);
}
END_TEST

START_TEST(decimal_mod_7) {
  s21_decimal x = {{125, 0, 0, 0}};
  s21_decimal y = {{3, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 1);
  s21_setScale(&y, 0);
  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "5 0 0 65536";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(decimal_mod_8) {
  s21_decimal x = {{125, 0, 0, 0}};
  s21_decimal y = {{3, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 1);
  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "2 0 0 65536";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

// s21_comparison

/* ----------------------------------------------------------------
 * s21_is_less    <
 * ---------------------------------------------------------------- */

START_TEST(decimal_is_less_1) {
  s21_decimal x = {{S21_MAX_UINT, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 1, 0, 0b00000000000000000000000000000000}};
  int res1 = s21_is_less(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_2) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b00000000000000000000000000000000}};
  int res1 = s21_is_less(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_3) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_less(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_4) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b10000000000000000000000000000000}};
  int res1 = s21_is_less(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_5) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b10000000000000000000000000000000}};
  int res1 = s21_is_less(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_6) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_less(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_7) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_less(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_8) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_less(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * 21_is_less_or_equal    <=
 * ---------------------------------------------------------------- */

START_TEST(decimal_is_less_or_equal_1) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b00000000000000000000000000000000}};
  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_2) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b00000000000000000000000000000000}};
  int res1 = s21_is_less_or_equal(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_3) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_less_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_4) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b10000000000000000000000000000000}};
  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_5) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b10000000000000000000000000000000}};
  int res1 = s21_is_less_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_6) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_less_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_7) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_8) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_is_greater   >
 * ---------------------------------------------------------------- */

START_TEST(decimal_is_greater_1) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b00000000000000000000000000000000}};
  int res1 = s21_is_greater(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_2) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b00000000000000000000000000000000}};
  int res1 = s21_is_greater(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_3) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_greater(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_4) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b10000000000000000000000000000000}};
  int res1 = s21_is_greater(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_5) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b10000000000000000000000000000000}};
  int res1 = s21_is_greater(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_6) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_greater(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_7) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_greater(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_8) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_greater(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * 21_is_greater_or_equal   >=
 * ---------------------------------------------------------------- */

START_TEST(decimal_is_greater_or_equal_1) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b00000000000000000000000000000000}};
  int res1 = s21_is_greater_or_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_2) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b00000000000000000000000000000000}};
  int res1 = s21_is_greater_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_3) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_greater_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_4) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b10000000000000000000000000000000}};
  int res1 = s21_is_greater_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_5) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 2, 0b10000000000000000000000000000000}};
  int res1 = s21_is_greater_or_equal(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_6) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_greater_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_7) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_greater_or_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_8) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_greater_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_is_equal      ==
 * ---------------------------------------------------------------- */

START_TEST(decimal_is_equal_1) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_2) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_3) {
  s21_decimal x = {{0, 0, 1, 0b0000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_4) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_5) {
  s21_decimal x = {{0, 52, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_6) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1747, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_7) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{1747, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_is_not_equal     !=
 * ---------------------------------------------------------------- */

START_TEST(decimal_is_not_equal_1) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_2) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_3) {
  s21_decimal x = {{0, 0, 1, 0b0000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_4) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_5) {
  s21_decimal x = {{0, 52, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_6) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1747, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_7) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{1747, 0, 1, 0b00000000000000000000000000000000}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

// s21_converters

/* ----------------------------------------------------------------
 * s21_from_int_to_decimal
 * ---------------------------------------------------------------- */

START_TEST(from_int_to_decimal_1) {
  s21_decimal x = {{0, 0, 0, 0}};
  s21_decimal y = {{15, 0, 0, 0}};
  int z = 15;
  s21_from_int_to_decimal(z, &x);
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", x.bits[0], x.bits[1],
           x.bits[2], x.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u", y.bits[0], y.bits[1],
           y.bits[2], y.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(from_int_to_decimal_2) {
  s21_decimal x = {{0, 0, 0, 0}};
  s21_decimal y = {{15, 0, 0, 2147483648}};
  int z = -15;
  s21_from_int_to_decimal(z, &x);
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", x.bits[0], x.bits[1],
           x.bits[2], x.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u", y.bits[0], y.bits[1],
           y.bits[2], y.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(from_int_to_decimal_3) {
  s21_decimal x = {{0, 0, 0, 0}};
  s21_decimal y = {{0, 0, 0, 0}};
  int z = 0;
  s21_from_int_to_decimal(z, &x);
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", x.bits[0], x.bits[1],
           x.bits[2], x.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u", y.bits[0], y.bits[1],
           y.bits[2], y.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_from_decimal_to_int
 * ---------------------------------------------------------------- */

START_TEST(from_decimal_to_int_1) {
  s21_decimal x = {{150, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 150);
}
END_TEST

START_TEST(from_decimal_to_int_2) {
  s21_decimal x = {{12, 0, 0, 13653}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 12);
}
END_TEST

START_TEST(from_decimal_to_int_3) {
  s21_decimal x = {{123554, 0, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 123554);
}
END_TEST

START_TEST(from_decimal_to_int_4) {
  s21_decimal x = {{2100000000, 0, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 2100000000);
}
END_TEST

START_TEST(from_decimal_to_int_5) {
  s21_decimal x = {{2100000000, 0, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 2100000000);
}
END_TEST

START_TEST(from_decimal_to_int_6) {
  s21_decimal x = {{4234234, 0, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 4234234);
}
END_TEST

START_TEST(from_decimal_to_int_7) {
  s21_decimal x = {{1231231, 0, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 1231231);
}
END_TEST

START_TEST(from_decimal_to_int_8) {
  s21_decimal x = {{9, 0, 0, 0}};
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 9);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_from_float_to_decimal
 * ---------------------------------------------------------------- */

START_TEST(from_float_to_decimal_1) {
  float src = 56.986;
  s21_decimal z = {{0, 0, 0, 0}};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "56986 0 0 196608";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_2) {
  float src = 1.0 / 0.0;
  s21_decimal z = {{0, 0, 0, 0}};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "6374 0 0 196608";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_3) {
  float src = -1.596;
  s21_decimal z = {{0, 0, 0, 0}};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "1596 0 0 2147680256";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_4) {
  float src = 46237.42332 / 12712.37834;
  s21_decimal z = {{0, 0, 0, 0}};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "3637197 0 0 393216";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_from_decimal_to_float
 * ---------------------------------------------------------------- */

START_TEST(from_decimal_to_float_1) {
  s21_decimal x = {{15008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 3);
  float res1;
  int n1 = s21_from_decimal_to_float(x, &res1);
  float res2 = 15.008;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_decimal_to_float_2) {
  s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 3);
  float res1;
  int n1 = s21_from_decimal_to_float(x, &res1);
  float res2 = -15.008;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_decimal_to_float_3) {
  s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 3);
  float res1 = 0;
  int n1 = s21_from_decimal_to_float(x, NULL);
  float res2 = 0;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

// s21_another

/* ----------------------------------------------------------------
 * s21_negate
 * ---------------------------------------------------------------- */

START_TEST(s21_negate_1) {
  int a = 15;
  int res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_int_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(-15, res_a);
}
END_TEST

START_TEST(s21_negate_2) {
  float a = 10.12345;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.12345, res_a);
}
END_TEST

START_TEST(s21_negate_3) {
  float a = 10.1234e5;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.1234e5, res_a);
}
END_TEST

START_TEST(s21_negate_4) {
  float a = -10.1234e5;
  float res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(10.1234e5, res_a);
}
END_TEST

START_TEST(s21_negate_5) {
  int a = -15;
  int res_a = 0;
  s21_decimal src;
  s21_decimal res;
  s21_from_int_to_decimal(a, &src);
  s21_negate(src, &res);
  s21_from_decimal_to_int(res, &res_a);
  ck_assert_int_eq(15, res_a);
}
END_TEST

START_TEST(s21_test_negate_0) {  // 0 * -1 = 0
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  // int equal = s21_is_equal(b, etalon);
  int negate = s21_negate(b, &etalon);
  ck_assert_int_eq(negate, 0);
}
END_TEST

START_TEST(s21_test_negate_1) {  // 1 * -1 = -1
  s21_decimal a = {{1, 0, 0, 0}};
  s21_decimal etalon = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_2) {  // -1 * -1 = 1
  s21_decimal a = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{1, 0, 0, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_3) {  // 100 * -1 = -100
  s21_decimal a = {{100, 0, 0, 0}};
  s21_decimal etalon = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_4) {  //
  s21_decimal a = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{100, 0, 0, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_5) {  //
  s21_decimal a = {{S21_MAX_UINT, 0, 0, 0}};
  s21_decimal etalon = {{S21_MAX_UINT, 0, 0, ~(INT_MAX)}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_6) {  //
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
  s21_decimal etalon = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(s21_test_negate_7) {  //
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
  s21_decimal etalon = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(INT_MAX)}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_negate_8) {  //
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(INT_MAX)}};
  s21_decimal etalon = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};

  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal* ptr_b = &b;

  int add = s21_negate(a, ptr_b);  // a записываем в b по указателю ptr_b
  ck_assert_int_eq(add,
                   0);  // выходное значение int s21_negate - 0 TRUE и 1 FALSE

  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  int equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(negate_0) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_1) {
  s21_decimal val = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_2) {
  s21_decimal val = {{0, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_3) {
  s21_decimal val = {0};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_0_2) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  int sign_before = s21_getSign(val);
  s21_negate(val, &res);
  int sign_after = s21_getSign(res);

  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_1_2) {
  s21_decimal val = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  int sign_before = s21_getSign(val);
  s21_negate(val, &res);
  int sign_after = s21_getSign(res);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_2_2) {
  s21_decimal val = {{0, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  int sign_before = s21_getSign(val);
  s21_negate(val, &res);
  int sign_after = s21_getSign(res);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_3_2) {
  s21_decimal val = {0};
  s21_decimal res = {0};
  int sign_before = s21_getSign(val);
  s21_negate(val, &res);
  int sign_after = s21_getSign(res);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_truncate
 * ---------------------------------------------------------------- */

START_TEST(s21_truncate_test) {
  float a = 2.6;
  s21_decimal fl_d;
  s21_from_float_to_decimal(a, &fl_d);
  s21_truncate(fl_d, &fl_d);
  float result;
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, 2);
  a = -4.5;
  s21_from_float_to_decimal(a, &fl_d);
  s21_truncate(fl_d, &fl_d);
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, -4);
}
END_TEST

START_TEST(s21_truncate_1) {
  s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 3);
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_truncate(x, &z);
  char res1[1000], res2[1000] = "15 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal x = {{15008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 2);
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_truncate(x, &z);
  char res1[1000], res2[1000] = "150 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

/*
START_TEST(truncate_0) {
  s21_decimal val = {{7, 7, 7, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 129127208515966861312.0;
  ck_assert_float_eq(need, fres);
}
END_TEST
*/

START_TEST(truncate_1) {
  s21_decimal val = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -2.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_3) {
  s21_decimal val = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  s21_setScale(&val, 5);
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -0.0;
  ck_assert_float_eq(need, fres);
}

START_TEST(truncate_4) {
  s21_decimal val = {{128, 0, 0, 0}};
  s21_decimal res = {0};
  s21_setScale(&val, 1);
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 12;
  ck_assert_float_eq(need, fres);
}

/* ----------------------------------------------------------------
 * s21_round
 * ---------------------------------------------------------------- */

/*
START_TEST(round_0) {
  s21_decimal val = {{7, 7, 7, 0}};
  s21_decimal res = {0};
  s21_round(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 129127208515966861312.0;
  ck_assert_float_eq(need, fres);
}
END_TEST
*/

START_TEST(round_test) {
  s21_decimal val = {{128, 0, 0, 0}};
  s21_decimal res = {0};
  s21_setScale(&val, 1);
  s21_round(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 13;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(s21_round_1) {
  s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 0);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "95008 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 1);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "9501 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 2);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "950 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 4);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "10 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 5);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_6) {
  s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 6);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 0);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "95008 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_8) {
  s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 1);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "9501 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_9) {
  s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 2);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "950 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_10) {
  s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 4);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "10 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_11) {
  s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 5);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "1 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_12) {
  s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 6);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_round(x, &z);
  char res1[1000], res2[1000] = "0 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_1_n) {
  s21_decimal value_1 = {{7464923, 0, 0, 0}};
  s21_setScale(&value_1, 5);
  s21_decimal check = {{75, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_2_n) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  s21_setScale(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_3_n) {
  s21_decimal value_1 = {{7464923, 0, 0, 0}};
  s21_setSign(&value_1, 1);
  s21_setScale(&value_1, 5);
  s21_decimal check = {{75, 0, 0, 0}};
  s21_setSign(&check, 1);
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_4_n) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  s21_setSign(&value_1, 1);
  s21_setScale(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  s21_setSign(&check, 1);
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_test) {
  float a = 0.4;
  s21_decimal fl_d;
  s21_from_float_to_decimal(a, &fl_d);
  s21_round(fl_d, &fl_d);
  float result;
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, round(0.4));
  a = -3.5;
  s21_from_float_to_decimal(a, &fl_d);
  s21_round(fl_d, &fl_d);
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, round(-3.5));
  s21_decimal d1 = {{12345}};
  s21_setScale(&d1, 1);
  s21_round(d1, &d1);
  ck_assert_double_eq(d1.bits[0], round(1234.5));
}
END_TEST

/* ----------------------------------------------------------------
 * s21_floor
 * ---------------------------------------------------------------- */

START_TEST(floor_0) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_floor(val, &res));
}
END_TEST

START_TEST(floor_1) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-2, fres);
}
END_TEST

START_TEST(floor_2) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  s21_setScale(&val, 5);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-1, fres);
}
END_TEST

START_TEST(floor_3) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  s21_setScale(&val, 5);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(0, fres);
}
END_TEST

START_TEST(s21_floor_1) {
  s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 3);
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_floor(x, &z);
  char res1[1000], res2[1000] = "16 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal x = {{15008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 3);
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_floor(x, &z);
  char res1[1000], res2[1000] = "15 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 10);
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_floor(x, &z);
  char res1[1000], res2[1000] = "1 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_floor_1_n) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  s21_setScale(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_floor_2_n) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  s21_setScale(&value_1, 5);
  s21_setSign(&value_1, 1);
  s21_decimal check = {{75, 0, 0, 0}};
  s21_setSign(&check, 1);
  s21_decimal result;
  int return_value = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_floor_test) {
  float a = 0.4;
  s21_decimal fl_d;
  s21_from_float_to_decimal(a, &fl_d);
  s21_floor(fl_d, &fl_d);
  float result;
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, 0.0);

  a = -0.4;
  s21_from_float_to_decimal(a, &fl_d);
  s21_floor(fl_d, &fl_d);
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, -1);
  a = 0;
  s21_from_float_to_decimal(a, &fl_d);
  s21_floor(fl_d, &fl_d);
  s21_from_decimal_to_float(fl_d, &result);
  ck_assert_double_eq(result, 0);
}
END_TEST

// common_s21_decimal

/* ----------------------------------------------------------------
 * s21_set_sign     !=
 * ---------------------------------------------------------------- */

START_TEST(decimal_s21_set_sign_1) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_setSign(&x, 0);
  ck_assert_int_eq(s21_getSign(x), s21_getSign(y));
}
END_TEST

START_TEST(decimal_s21_set_sign_2) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_setSign(&x, 1);
  ck_assert_int_eq(s21_getSign(x), s21_getSign(y));
}
END_TEST

START_TEST(decimal_s21_set_sign_3) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_setSign(&x, 0);
  ck_assert_int_eq(s21_getSign(x), s21_getSign(y));
}
END_TEST

START_TEST(decimal_s21_set_sign_4) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_setSign(&x, 1);
  ck_assert_int_eq(s21_getSign(x), s21_getSign(y));
}
END_TEST

/* ----------------------------------------------------------------
 * s21_getScale
 * ---------------------------------------------------------------- */

START_TEST(s21_get_scale_1) {
  s21_decimal x = {{0, 0, 0, 0b10000000000011110000000000000000}};
  int res1 = s21_getScale(x);
  int res2 = 15;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_get_scale_2) {
  s21_decimal x = {{0, 0, 0, 0b10000000000000000000000000000000}};
  int res1 = s21_getScale(x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_get_scale_3) {
  s21_decimal x = {{0, 0, 0, 0b10000000000011010000000000000000}};
  int res1 = s21_getScale(x);
  int res2 = 13;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_get_scale_4) {
  s21_decimal x = {{0, 0, 0, 0b00000000000011110000000000000000}};
  int res1 = s21_getScale(x);
  int res2 = 15;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_get_scale_5) {
  s21_decimal x = {{0, 0, 0, 0b00000000000000000000000000000000}};
  int res1 = s21_getScale(x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_get_scale_6) {
  s21_decimal x = {{0, 50, 0, 0b00000000000011010000000000000000}};
  int res1 = s21_getScale(x);
  int res2 = 13;
  ck_assert_int_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_setScale
 * ---------------------------------------------------------------- */

START_TEST(s21_set_scale_1) {
  s21_decimal x = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 15);
  int res1 = s21_getScale(x);
  int res2 = 15;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_set_scale_2) {
  s21_decimal x = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 0);
  int res1 = s21_getScale(x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_set_scale_3) {
  s21_decimal x = {{0, 0, 0, 0b10000000000010000000000000000000}};
  s21_setScale(&x, 13);
  int res1 = s21_getScale(x);
  int res2 = 13;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_set_scale_4) {
  s21_decimal x = {{0, 0, 0, 0b00000000000000110000000000000000}};
  s21_setScale(&x, 15);
  int res1 = s21_getScale(x);
  int res2 = 15;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_set_scale_5) {
  s21_decimal x = {{0, 0, 0, 0b00000000000001000000000000000000}};
  s21_setScale(&x, 0);
  int res1 = s21_getScale(x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_set_scale_6) {
  s21_decimal x = {{0, 50, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 13);
  int res1 = s21_getScale(x);
  int res2 = 13;
  ck_assert_int_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * scale_equalization
 * ---------------------------------------------------------------- */

START_TEST(s21_scale_equalization_1) {
  s21_decimal x = {{10, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 1);
  s21_setScale(&y, 0);
  s21_scale_equalization(&x, &y, 0);
  s21_decimal x_test = {{10, 0, 0, 65536}};
  s21_decimal y_test = {{0, 0, 0, 65536}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_scale_equalization_2) {
  s21_decimal x = {{10, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 2);
  s21_setScale(&y, 0);
  s21_scale_equalization(&x, &y, 0);
  s21_decimal x_test = {{10, 0, 0, 131072}};
  s21_decimal y_test = {{100, 0, 0, 131072}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_scale_equalization_3) {
  s21_decimal x = {{10, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 28);
  s21_setScale(&y, 0);
  s21_scale_equalization(&x, &y, 0);
  s21_decimal x_test = {{10, 0, 0, 1835008}};
  s21_decimal y_test = {{268435456, 1042612833, 542101086, 1835008}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_scale_equalization_4) {
  s21_decimal x = {{10, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 28);
  s21_setScale(&y, 0);
  s21_scale_equalization(&x, &y, 0);
  s21_decimal x_test = {{10, 0, 0, 1835008}};
  s21_decimal y_test = {{1342177280, 918096869, 2710505431, 1835008}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_scale_equalization_5) {
  s21_decimal x = {{10, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 28);
  s21_scale_equalization(&x, &y, OK);
  s21_decimal x_test = {{268435456, 1042612833, 542101086, 1769472}};
  s21_decimal y_test = {{1, 0, 0, 1769472}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_scale_equalization_6) {
  s21_decimal x = {{10, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{5, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 0);
  s21_setScale(&y, 28);
  s21_scale_equalization(&x, &y, OK);
  s21_decimal x_test = {{268435456, 1042612833, 542101086, 2149253120}};
  s21_decimal y_test = {{1, 0, 0, 2149253120}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_scale_equalization_7) {
  s21_decimal x = {{10, 0, 100, 0b00000000000000000000000000000000}};
  s21_decimal y = {{5, 0, 1565, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 7);
  s21_setScale(&y, 0);
  s21_scale_equalization(&x, &y, OK);
  s21_decimal x_test = {{1, 0, 10, 393216}};
  s21_decimal y_test = {{5000000, 0, 1565000000, 393216}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_scale_equalization_8) {
  s21_decimal x = {{10, 0, 3000000000, 0b10000000000000000000000000000000}};
  s21_decimal y = {{13, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 28);
  s21_setScale(&y, 0);
  s21_scale_equalization(&x, &y, OK);
  s21_decimal x_test = {{1, 0, 300000000, 2149253120}};
  s21_decimal y_test = {{3355443200, 496403223, 704731412, 2149253120}};
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x.bits[0],
           x.bits[1], x.bits[2], x.bits[3], y.bits[0], y.bits[1], y.bits[2],
           y.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u %u %u %u %u", x_test.bits[0],
           x_test.bits[1], x_test.bits[2], x_test.bits[3], y_test.bits[0],
           y_test.bits[1], y_test.bits[2], y_test.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_simple_sub
 * ---------------------------------------------------------------- */

START_TEST(s21_simple_sub_test_1) {
  int num1 = -10;
  int num2 = -10;
  int dif_int = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_simple_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(s21_simple_sub_test_2) {
  int num1 = 9403;
  int num2 = 202;
  int dif_int = 9201;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_simple_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

END_TEST

START_TEST(s21_simple_sub_test_3) {
  int num1 = 900;
  int num2 = 100;
  int dif_int = 800;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_simple_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(s21_simple_sub_test_4) {
  s21_decimal x = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_simple_sub(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_simple_sub_test_5) {
  s21_decimal x = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_simple_sub(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_simple_sub_test_6) {
  s21_decimal x = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_simple_sub(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_simple_sub_test_7) {
  int num1 = -10;
  int num2 = -10;
  int dif_int = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_simple_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

int main(void) {
  Suite* s1 = suite_create("Core");
  TCase* tc1_1 = tcase_create("Core");
  SRunner* sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  // s21_arithmetic
  tcase_add_test(tc1_1, decimal_add_1);
  tcase_add_test(tc1_1, decimal_add_2);
  // tcase_add_test(tc1_1, decimal_add_3);
  tcase_add_test(tc1_1, decimal_add_4);
  tcase_add_test(tc1_1, decimal_add_5);
  tcase_add_test(tc1_1, decimal_add_6);
  tcase_add_test(tc1_1, decimal_add_7);
  tcase_add_test(tc1_1, decimal_add_8);
  tcase_add_test(tc1_1, decimal_add_9);
  tcase_add_test(tc1_1, decimal_add_10);
  tcase_add_test(tc1_1, decimal_add_11);

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
  tcase_add_test(tc1_1, decimal_mul_14);
  tcase_add_test(tc1_1, decimal_mul_15);
  tcase_add_test(tc1_1, decimal_mul_16);

  tcase_add_test(tc1_1, decimal_div_1);
  tcase_add_test(tc1_1, decimal_div_2);
  tcase_add_test(tc1_1, decimal_div_3);
  tcase_add_test(tc1_1, decimal_div_4);
  tcase_add_test(tc1_1, decimal_div_5);
  tcase_add_test(tc1_1, decimal_div_6);
  tcase_add_test(tc1_1, decimal_div_7);
  tcase_add_test(tc1_1, decimal_div_8);
  tcase_add_test(tc1_1, decimal_div_9);
  tcase_add_test(tc1_1, decimal_div_10);
  tcase_add_test(tc1_1, decimal_div_11);
  tcase_add_test(tc1_1, decimal_div_12);

  tcase_add_test(tc1_1, decimal_mod_1);
  // tcase_add_test(tc1_1, decimal_mod_2);
  tcase_add_test(tc1_1, decimal_mod_3);
  tcase_add_test(tc1_1, decimal_mod_4);
  tcase_add_test(tc1_1, decimal_mod_5);
  tcase_add_test(tc1_1, decimal_mod_6);
  tcase_add_test(tc1_1, decimal_mod_7);
  tcase_add_test(tc1_1, decimal_mod_8);

  // s21_comparison
  tcase_add_test(tc1_1, decimal_is_less_1);
  tcase_add_test(tc1_1, decimal_is_less_2);
  tcase_add_test(tc1_1, decimal_is_less_3);
  tcase_add_test(tc1_1, decimal_is_less_4);
  tcase_add_test(tc1_1, decimal_is_less_5);
  tcase_add_test(tc1_1, decimal_is_less_6);
  tcase_add_test(tc1_1, decimal_is_less_7);
  tcase_add_test(tc1_1, decimal_is_less_8);

  tcase_add_test(tc1_1, decimal_is_less_or_equal_1);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_2);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_3);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_4);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_5);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_6);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_7);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_8);

  tcase_add_test(tc1_1, decimal_is_greater_1);
  tcase_add_test(tc1_1, decimal_is_greater_2);
  tcase_add_test(tc1_1, decimal_is_greater_3);
  tcase_add_test(tc1_1, decimal_is_greater_4);
  tcase_add_test(tc1_1, decimal_is_greater_5);
  tcase_add_test(tc1_1, decimal_is_greater_6);
  tcase_add_test(tc1_1, decimal_is_greater_7);
  tcase_add_test(tc1_1, decimal_is_greater_8);

  tcase_add_test(tc1_1, decimal_is_greater_or_equal_1);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_2);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_3);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_4);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_5);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_6);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_7);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_8);

  tcase_add_test(tc1_1, decimal_is_equal_1);
  tcase_add_test(tc1_1, decimal_is_equal_2);
  tcase_add_test(tc1_1, decimal_is_equal_3);
  tcase_add_test(tc1_1, decimal_is_equal_4);
  tcase_add_test(tc1_1, decimal_is_equal_5);
  tcase_add_test(tc1_1, decimal_is_equal_6);
  tcase_add_test(tc1_1, decimal_is_equal_7);

  tcase_add_test(tc1_1, decimal_is_not_equal_1);
  tcase_add_test(tc1_1, decimal_is_not_equal_2);
  tcase_add_test(tc1_1, decimal_is_not_equal_3);
  tcase_add_test(tc1_1, decimal_is_not_equal_4);
  tcase_add_test(tc1_1, decimal_is_not_equal_5);
  tcase_add_test(tc1_1, decimal_is_not_equal_6);
  tcase_add_test(tc1_1, decimal_is_not_equal_7);

  // s21_converters
  tcase_add_test(tc1_1, from_int_to_decimal_1);
  tcase_add_test(tc1_1, from_int_to_decimal_2);
  tcase_add_test(tc1_1, from_int_to_decimal_3);
  tcase_add_test(tc1_1, from_decimal_to_int_1);
  tcase_add_test(tc1_1, from_decimal_to_int_2);
  tcase_add_test(tc1_1, from_decimal_to_int_3);
  tcase_add_test(tc1_1, from_decimal_to_int_4);
  tcase_add_test(tc1_1, from_decimal_to_int_5);
  tcase_add_test(tc1_1, from_decimal_to_int_6);
  tcase_add_test(tc1_1, from_decimal_to_int_7);
  tcase_add_test(tc1_1, from_decimal_to_int_8);
  tcase_add_test(tc1_1, from_float_to_decimal_1);
  tcase_add_test(tc1_1, from_float_to_decimal_2);
  tcase_add_test(tc1_1, from_float_to_decimal_3);
  tcase_add_test(tc1_1, from_float_to_decimal_4);
  tcase_add_test(tc1_1, from_decimal_to_float_1);
  tcase_add_test(tc1_1, from_decimal_to_float_2);
  tcase_add_test(tc1_1, from_decimal_to_float_3);

  // s21_another
  tcase_add_test(tc1_1, s21_negate_1);
  tcase_add_test(tc1_1, s21_negate_2);
  tcase_add_test(tc1_1, s21_negate_3);
  tcase_add_test(tc1_1, s21_negate_4);
  tcase_add_test(tc1_1, s21_negate_5);
  tcase_add_test(tc1_1, s21_test_negate_0);
  tcase_add_test(tc1_1, s21_test_negate_1);
  tcase_add_test(tc1_1, s21_test_negate_2);
  tcase_add_test(tc1_1, s21_test_negate_3);
  tcase_add_test(tc1_1, s21_test_negate_4);
  tcase_add_test(tc1_1, s21_test_negate_5);
  tcase_add_test(tc1_1, s21_test_negate_6);
  tcase_add_test(tc1_1, s21_test_negate_7);
  tcase_add_test(tc1_1, s21_test_negate_8);
  tcase_add_test(tc1_1, negate_0);
  tcase_add_test(tc1_1, negate_1);
  tcase_add_test(tc1_1, negate_2);
  tcase_add_test(tc1_1, negate_3);
  tcase_add_test(tc1_1, negate_0_2);
  tcase_add_test(tc1_1, negate_1_2);
  tcase_add_test(tc1_1, negate_2_2);
  tcase_add_test(tc1_1, negate_3_2);

  tcase_add_test(tc1_1, s21_truncate_test);
  tcase_add_test(tc1_1, s21_truncate_1);
  tcase_add_test(tc1_1, s21_truncate_2);
  // tcase_add_test(tc1_1, truncate_0);
  tcase_add_test(tc1_1, truncate_1);
  tcase_add_test(tc1_1, truncate_3);
  tcase_add_test(tc1_1, truncate_4);

  // tcase_add_test(tc1_1, round_0);
  tcase_add_test(tc1_1, round_test);
  tcase_add_test(tc1_1, s21_round_1);
  tcase_add_test(tc1_1, s21_round_2);
  tcase_add_test(tc1_1, s21_round_3);
  tcase_add_test(tc1_1, s21_round_4);
  tcase_add_test(tc1_1, s21_round_5);
  tcase_add_test(tc1_1, s21_round_6);
  tcase_add_test(tc1_1, s21_round_7);
  tcase_add_test(tc1_1, s21_round_8);
  tcase_add_test(tc1_1, s21_round_9);
  tcase_add_test(tc1_1, s21_round_10);
  tcase_add_test(tc1_1, s21_round_11);
  tcase_add_test(tc1_1, s21_round_12);
  tcase_add_test(tc1_1, s21_round_1_n);
  tcase_add_test(tc1_1, s21_round_2_n);
  tcase_add_test(tc1_1, s21_round_3_n);
  tcase_add_test(tc1_1, s21_round_4_n);
  tcase_add_test(tc1_1, s21_round_test);

  tcase_add_test(tc1_1, floor_0);
  tcase_add_test(tc1_1, floor_1);
  tcase_add_test(tc1_1, floor_2);
  tcase_add_test(tc1_1, floor_3);
  tcase_add_test(tc1_1, s21_floor_1);
  tcase_add_test(tc1_1, s21_floor_2);
  tcase_add_test(tc1_1, s21_floor_3);
  tcase_add_test(tc1_1, s21_floor_1_n);
  tcase_add_test(tc1_1, s21_floor_2_n);
  tcase_add_test(tc1_1, s21_floor_test);

  // common_s21_decimal
  tcase_add_test(tc1_1, decimal_s21_set_sign_1);
  tcase_add_test(tc1_1, decimal_s21_set_sign_2);
  tcase_add_test(tc1_1, decimal_s21_set_sign_3);
  tcase_add_test(tc1_1, decimal_s21_set_sign_4);
  tcase_add_test(tc1_1, s21_get_scale_1);
  tcase_add_test(tc1_1, s21_get_scale_2);
  tcase_add_test(tc1_1, s21_get_scale_3);
  tcase_add_test(tc1_1, s21_get_scale_4);
  tcase_add_test(tc1_1, s21_get_scale_5);
  tcase_add_test(tc1_1, s21_get_scale_6);
  tcase_add_test(tc1_1, s21_set_scale_1);
  tcase_add_test(tc1_1, s21_set_scale_2);
  tcase_add_test(tc1_1, s21_set_scale_3);
  tcase_add_test(tc1_1, s21_set_scale_4);
  tcase_add_test(tc1_1, s21_set_scale_5);
  tcase_add_test(tc1_1, s21_set_scale_6);
  tcase_add_test(tc1_1, s21_scale_equalization_1);
  tcase_add_test(tc1_1, s21_scale_equalization_2);
  tcase_add_test(tc1_1, s21_scale_equalization_3);
  tcase_add_test(tc1_1, s21_scale_equalization_4);
  tcase_add_test(tc1_1, s21_scale_equalization_5);
  tcase_add_test(tc1_1, s21_scale_equalization_6);
  tcase_add_test(tc1_1, s21_scale_equalization_7);
  tcase_add_test(tc1_1, s21_scale_equalization_8);

  tcase_add_test(tc1_1, s21_simple_sub_test_1);
  tcase_add_test(tc1_1, s21_simple_sub_test_2);
  tcase_add_test(tc1_1, s21_simple_sub_test_3);
  tcase_add_test(tc1_1, s21_simple_sub_test_4);
  tcase_add_test(tc1_1, s21_simple_sub_test_5);
  tcase_add_test(tc1_1, s21_simple_sub_test_6);
  tcase_add_test(tc1_1, s21_simple_sub_test_7);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
