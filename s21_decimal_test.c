#include "s21_decimal.h"

#include <check.h>
#include <stdio.h>
#include <string.h>


/* ----------------------------------------------------------------
 * s21_add    <
 * ---------------------------------------------------------------- */

START_TEST(decimal_plus_plus) {
  s21_decimal x = {
      {4294967295, 4294967295, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "0 0 1 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_2) {
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

START_TEST(decimal_plus_plus_3) {
  s21_decimal x = {{20, 1, 0, 0b10000000000000000000000000000000}};
  s21_decimal y = {{21, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "41 1 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_4) {
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

START_TEST(decimal_plus_plus_5) {
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

START_TEST(decimal_plus_plus_6) {
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

START_TEST(decimal_plus_plus_7) {
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

START_TEST(decimal_plus_plus_8) {
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

START_TEST(decimal_plus_plus_9) {
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

START_TEST(decimal_plus_plus_10) {
  s21_decimal x = {{0, 0, 3000000000, 0}};
  s21_decimal y = {{0, 0, 3000000000, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_11) {
  s21_decimal x = {{1, 0, 0, 1835008}};
  s21_decimal y = {{1, 0, 0, 2149318656}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
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
  s21_set_scale(&x, 5);
  s21_set_scale(&y, 5);
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
  s21_set_scale(&x, 0);
  s21_set_scale(&y, 0);
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
  s21_set_scale(&x, 28);
  s21_set_scale(&y, 28);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * s21_mul    <
 * ---------------------------------------------------------------- */

START_TEST(decimal_mul_1) {
  s21_decimal x = {{0, 0, 0, 0b00000000000011110000000000000000}};
  s21_decimal y = {{0, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 1114112";
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
  s21_set_scale(&x, 14);
  s21_set_scale(&y, 14);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "200000 0 0 1835008";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_11) {
  s21_decimal x = {{0, 0, 555555555, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_scale(&y, 1);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "0 0 555555555 65536";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_14) {
  s21_decimal x = {{400, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{500, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_scale(&x, 17);
  s21_set_scale(&y, 18);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_15) {
  s21_decimal x = {{400, 0, 5000000, 0b00000000000000000000000000000000}};
  s21_decimal y = {{500, 0, 5000000, 0b00000000000000000000000000000000}};
  s21_set_scale(&x, 12);
  s21_set_scale(&y, 12);
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
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
 * s21_is_less    <
 * ---------------------------------------------------------------- */

START_TEST(decimal_is_less_1) {
  s21_decimal x = {{4294967295, 0, 0, 0b00000000000000000000000000000000}};
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

START_TEST(decimal_is_less_or_equal_or_equal_3) {
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



// /* ----------------------------------------------------------------
//  * s21_is_greater   >
//  * ---------------------------------------------------------------- */

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


// /* ----------------------------------------------------------------
//  * 21_is_greater_or_equal   >=
//  * ---------------------------------------------------------------- */

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

START_TEST(decimal_is_greater_or_equal_or_equal_3) {
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


// /* ----------------------------------------------------------------
//  * s21_is_equal      ==
//  * ---------------------------------------------------------------- */

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

// /* ----------------------------------------------------------------
//  * s21_is_not_equal     !=
//  * ---------------------------------------------------------------- */


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


// /* ----------------------------------------------------------------
//  * void s21_setSign(s21_decimal *d, int bit_value)     !=
//  * ---------------------------------------------------------------- */

START_TEST(decimal_s21_setSign_1) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_setSign(&x, 0);
  ck_assert_int_eq(s21_setSign(&x), s21_setSign(&y));
}
END_TEST

START_TEST(decimal_s21_setSign_2) {
  s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_setSign(&x, 1);
  ck_assert_int_eq(s21_setSign(&x), s21_setSign(&y));
}
END_TEST

START_TEST(decimal_s21_setSign_3) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_setSign(&x, 0);
  ck_assert_int_eq(s21_setSign(&x), s21_setSign(&y));
}
END_TEST

START_TEST(decimal_s21_setSign_4) {
  s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
  s21_setSign(&x, 1);
  ck_assert_int_eq(s21_setSign(&x), s21_setSign(&y));
}
END_TEST



// /* ----------------------------------------------------------------
//  * int s21_getScale(s21_decimal d);
//  * ---------------------------------------------------------------- */

START_TEST(s21_getScale_1) {
  s21_decimal x = {{0, 0, 0, 0b10000000000011110000000000000000}};
  int res1 = s21_getScale(&x);
  int res2 = 15;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_getScale_2) {
  s21_decimal x = {{0, 0, 0, 0b10000000000000000000000000000000}};
  int res1 = s21_getScale(&x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_getScale_3) {
  s21_decimal x = {{0, 0, 0, 0b10000000000011010000000000000000}};
  int res1 = s21_getScale(&x);
  int res2 = 13;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_getScale_4) {
  s21_decimal x = {{0, 0, 0, 0b00000000000011110000000000000000}};
  int res1 = s21_getScale(&x);
  int res2 = 15;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_getScale_5) {
  s21_decimal x = {{0, 0, 0, 0b00000000000000000000000000000000}};
  int res1 = s21_getScale(&x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_getScale_6) {
  s21_decimal x = {{0, 50, 0, 0b00000000000011010000000000000000}};
  int res1 = s21_getScale(&x);
  int res2 = 13;
  ck_assert_int_eq(res1, res2);
}
END_TEST

// /* ----------------------------------------------------------------
//  * int s21_setScale(s21_decimal d);
//  * ---------------------------------------------------------------- */

START_TEST(s21_setScale_1) {
  s21_decimal x = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 15);
  int res1 = s21_getScale(&x);
  int res2 = 15;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_setScale_2) {
  s21_decimal x = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 0);
  int res1 = s21_getScale(&x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_setScale_3) {
  s21_decimal x = {{0, 0, 0, 0b10000000000010000000000000000000}};
  s21_setScale(&x, 13);
  int res1 = s21_getScale(&x);
  int res2 = 13;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_setScale_4) {
  s21_decimal x = {{0, 0, 0, 0b00000000000000110000000000000000}};
  s21_setScale(&x, 15);
  int res1 = s21_getScale(&x);
  int res2 = 15;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_setScale_5) {
  s21_decimal x = {{0, 0, 0, 0b00000000000001000000000000000000}};
  s21_setScale(&x, 0);
  int res1 = s21_getScale(&x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_setScale_6) {
  s21_decimal x = {{0, 50, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 13);
  int res1 = s21_getScale(&x);
  int res2 = 13;
  ck_assert_int_eq(res1, res2);
}
END_TEST


// /* ----------------------------------------------------------------
//  * void s21_scale_equalization(s21_decimal *value_1, s21_decimal *value_2);
//  * ---------------------------------------------------------------- */

START_TEST(s21_scale_equalization_1) {
  s21_decimal x = {{10, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal y = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 1);
  s21_setScale(&y, 0);
  s21_scale_equalization(&x, &y, OK);
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
  s21_scale_equalization(&x, &y, OK);
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
  s21_scale_equalization(&x, &y, OK);
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
  s21_scale_equalization(&x, &y, OK);
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



// /* ----------------------------------------------------------------
//  * s21_from_int_to_decimal;
//  * ---------------------------------------------------------------- */

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

START_TEST(from_int_to_decimal_4) {
  int z = s21_from_int_to_decimal(15, 0);
  ck_assert_int_eq(z, 1);
}
END_TEST




// /* ----------------------------------------------------------------
//  * s21_from_decimal_to_int;
//  * ---------------------------------------------------------------- */

START_TEST(from_decimal_to_int_1) {
  s21_decimal x = {{150, 13658, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 10);
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, -5866);
}
END_TEST

START_TEST(from_decimal_to_int_2) {
  s21_decimal x = {{150, 13658, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 10);
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 5866);
}
END_TEST

START_TEST(from_decimal_to_int_3) {
  s21_decimal x = {{150, 13658, 155, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 10);
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 0);
}
END_TEST

START_TEST(from_decimal_to_int_4) {
  s21_decimal x = {{2100000000, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 0);
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 2100000000);
}
END_TEST

START_TEST(from_decimal_to_int_5) {
  s21_decimal x = {{2100000000, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 0);
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, -2100000000);
}
END_TEST

START_TEST(from_decimal_to_int_6) {
  s21_decimal x = {{3100000000, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 0);
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 0);
}
END_TEST

START_TEST(from_decimal_to_int_7) {
  s21_decimal x = {{3100000000, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 0);
  int y;
  int n1 = s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_decimal_to_int_8) {
  s21_decimal x = {{9, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 1);
  int y;
  s21_from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 0);
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
  tcase_add_test(tc1_1, decimal_is_less_or_equal_or_equal_3);
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
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_or_equal_3);
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
  tcase_add_test(tc1_1, decimal_s21_set_sign_1);
  tcase_add_test(tc1_1, decimal_s21_set_sign_2);
  tcase_add_test(tc1_1, decimal_s21_set_sign_3);
  tcase_add_test(tc1_1, decimal_s21_set_sign_4);
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
  tcase_add_test(tc1_1, decimal_mul_11);
  tcase_add_test(tc1_1, decimal_mul_14);
  tcase_add_test(tc1_1, decimal_mul_15);
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
  tcase_add_test(tc1_1, s21_getScale_1);
  tcase_add_test(tc1_1, s21_getScale_2);
  tcase_add_test(tc1_1, s21_getScale_3);
  tcase_add_test(tc1_1, s21_getScale_4);
  tcase_add_test(tc1_1, s21_getScale_5);
  tcase_add_test(tc1_1, s21_getScale_6);
  tcase_add_test(tc1_1, s21_setScale_1);
  tcase_add_test(tc1_1, s21_setScale_2);
  tcase_add_test(tc1_1, s21_setScale_3);
  tcase_add_test(tc1_1, s21_setScale_4);
  tcase_add_test(tc1_1, s21_setScale_5);
  tcase_add_test(tc1_1, s21_setScale_6);
  tcase_add_test(tc1_1, s21_scale_equalization_1);
  tcase_add_test(tc1_1, s21_scale_equalization_2);
  tcase_add_test(tc1_1, s21_scale_equalization_3);
  tcase_add_test(tc1_1, s21_scale_equalization_4);
  tcase_add_test(tc1_1, s21_scale_equalization_5);
  tcase_add_test(tc1_1, s21_scale_equalization_6);
  tcase_add_test(tc1_1, s21_scale_equalization_7);
  tcase_add_test(tc1_1, s21_scale_equalization_8);
  tcase_add_test(tc1_1, from_int_to_decimal_1);
  tcase_add_test(tc1_1, from_int_to_decimal_2);
  tcase_add_test(tc1_1, from_int_to_decimal_3);
  tcase_add_test(tc1_1, from_int_to_decimal_4);
  tcase_add_test(tc1_1, from_decimal_to_int_1);
  tcase_add_test(tc1_1, from_decimal_to_int_2);
  tcase_add_test(tc1_1, from_decimal_to_int_3);
  tcase_add_test(tc1_1, from_decimal_to_int_4);
  tcase_add_test(tc1_1, from_decimal_to_int_5);
  tcase_add_test(tc1_1, from_decimal_to_int_6);
  tcase_add_test(tc1_1, from_decimal_to_int_7);
  tcase_add_test(tc1_1, from_decimal_to_int_8);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}