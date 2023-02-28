#include "s21_decimal.h"

#include <check.h>
#include <stdio.h>
#include <string.h>

START_TEST(decimal_plus_plus) {
  s21_decimal x = {
      {4294967294, 4294967295, 4294967295, 0b00000000000000000000000000000000}};
  s21_decimal y = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_add(x, y, &z);
  char res1[1000], res2[1000] = "4294967295 4294967295 4294967295 0";
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
  char res1[1000], res2[1000] = "41 1 0 0";
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
  char res1[1000], res2[1000] = "0 0 1705032704 0";
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
  char res1[1000], res2[1000] = "0 0 0 1835008";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
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

/* ----------------------------------------------------------------
 * void set_sign(s21_decimal *d, int bit_value)     !=
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
 * int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
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

/* ----------------------------------------------------------------
 * s21_sub    вычитание
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
  char res1[1000], res2[1000] = "3 0 0 0";
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
  char res1[1000], res2[1000] = "0 0 1705032705 327680";
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
  char res1[1000], res2[1000] = "0 0 1705032705 0";
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
  char res1[1000], res2[1000] = "0 0 0 1835008";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * int s21_getScale(&s21_decimal d);
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
 * int s21_setScale(s21_decimal d);
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
 * void scale_equalize(s21_decimal *value_1, s21_decimal *value_2);
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

/* ----------------------------------------------------------------
 * s21_from_int_to_decimal;
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
 * s21_from_decimal_to_int;
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
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(mod_3) {
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

START_TEST(mod_4) {
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

START_TEST(mod_5) {
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

START_TEST(mod_7) {
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

START_TEST(mod_8) {
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

/* ----------------------------------------------------------------
 * s21_from_float_to_decimal;
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

/* ----------------------------------------------------------------
 * s21_from_decimal_to_float;
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
  tcase_add_test(tc1_1, mod_1);
  tcase_add_test(tc1_1, mod_3);
  tcase_add_test(tc1_1, mod_4);
  tcase_add_test(tc1_1, mod_5);
  tcase_add_test(tc1_1, mod_7);
  tcase_add_test(tc1_1, mod_8);
  tcase_add_test(tc1_1, from_float_to_decimal_1);
  tcase_add_test(tc1_1, from_float_to_decimal_2);
  tcase_add_test(tc1_1, from_float_to_decimal_3);
  tcase_add_test(tc1_1, from_decimal_to_float_1);
  tcase_add_test(tc1_1, from_decimal_to_float_2);
  tcase_add_test(tc1_1, from_decimal_to_float_3);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
