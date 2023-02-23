#include "s21_decimal.h"

#include <check.h>
#include <stdio.h>
#include <string.h>

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

/* ----------------------------------------------------------------
 * s21_from_float_to_decimal;
 * ---------------------------------------------------------------- */

START_TEST(from_float_to_decimal_1) {
float src = 56.986;
s21_decimal z = {{0, 0, 0, 0}};
int n1 = s21_from_float_to_decimal(src, &z);
char res1[1000], res2[1000] = "56986 0 0 196608";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_2) {
float src = 1.0 / 0.0;
s21_decimal z = {{0, 0, 0, 0}};
int n1 = s21_from_float_to_decimal(src, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_float_to_decimal_3) {
float src = -1.596;
s21_decimal z = {{0, 0, 0, 0}};
int n1 = s21_from_float_to_decimal(src, &z);
char res1[1000], res2[1000] = "1596 0 0 2147680256";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
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