#include "s21_decimal.h"

#include <check.h>
#include <stdio.h>
#include <string.h>

// /* ----------------------------------------------------------------
//  * void s21_setSign(s21_decimal *d, int bit_value)     !=
//  * ---------------------------------------------------------------- */

// START_TEST(decimal_s21_setSign_1) {
//   s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
//   s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
//   s21_setSign(&x, 0);
//   ck_assert_int_eq(s21_setSign(&x), s21_setSign(&y));
// }
// END_TEST

// START_TEST(decimal_s21_setSign_2) {
//   s21_decimal x = {{0, 0, 1, 0b10000000000000000000000000000000}};
//   s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
//   s21_setSign(&x, 1);
//   ck_assert_int_eq(s21_setSign(&x), s21_setSign(&y));
// }
// END_TEST

// START_TEST(decimal_s21_setSign_3) {
//   s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
//   s21_decimal y = {{0, 0, 1, 0b00000000000000000000000000000000}};
//   s21_setSign(&x, 0);
//   ck_assert_int_eq(s21_setSign(&x), s21_setSign(&y));
// }
// END_TEST

// START_TEST(decimal_s21_setSign_4) {
//   s21_decimal x = {{0, 0, 1, 0b00000000000000000000000000000000}};
//   s21_decimal y = {{0, 0, 1, 0b10000000000000000000000000000000}};
//   s21_setSign(&x, 1);
//   ck_assert_int_eq(s21_setSign(&x), s21_setSign(&y));
// }
// END_TEST



// /* ----------------------------------------------------------------
//  * int s21_getScale(s21_decimal d);
//  * ---------------------------------------------------------------- */

START_TEST(s21_getScale_1) {
  s21_decimal x = {{0, 0, 0, 0b10000000000011110000000000000000}};
  int res1 = s21_getScale(x);
  int res2 = 15;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_getScale_2) {
  s21_decimal x = {{0, 0, 0, 0b10000000000000000000000000000000}};
  int res1 = s21_getScale(x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_getScale_3) {
  s21_decimal x = {{0, 0, 0, 0b10000000000011010000000000000000}};
  int res1 = s21_getScale(x);
  int res2 = 13;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_getScale_4) {
  s21_decimal x = {{0, 0, 0, 0b00000000000011110000000000000000}};
  int res1 = s21_getScale(x);
  int res2 = 15;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_getScale_5) {
  s21_decimal x = {{0, 0, 0, 0b00000000000000000000000000000000}};
  int res1 = s21_getScale(x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_getScale_6) {
  s21_decimal x = {{0, 50, 0, 0b00000000000011010000000000000000}};
  int res1 = s21_getScale(x);
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
  int res1 = s21_getScale(x);
  int res2 = 15;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_setScale_2) {
  s21_decimal x = {{0, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 0);
  int res1 = s21_getScale(x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_setScale_3) {
  s21_decimal x = {{0, 0, 0, 0b10000000000010000000000000000000}};
  s21_setScale(&x, 13);
  int res1 = s21_getScale(x);
  int res2 = 13;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_setScale_4) {
  s21_decimal x = {{0, 0, 0, 0b00000000000000110000000000000000}};
  s21_setScale(&x, 15);
  int res1 = s21_getScale(x);
  int res2 = 15;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_setScale_5) {
  s21_decimal x = {{0, 0, 0, 0b00000000000001000000000000000000}};
  s21_setScale(&x, 0);
  int res1 = s21_getScale(x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_setScale_6) {
  s21_decimal x = {{0, 50, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 13);
  int res1 = s21_getScale(x);
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


int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  // tcase_add_test(tc1_1, decimal_s21_setSign_1);
  // tcase_add_test(tc1_1, decimal_s21_setSign_2);
  // tcase_add_test(tc1_1, decimal_s21_setSign_3);
  // tcase_add_test(tc1_1, decimal_s21_setSign_4);
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

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}