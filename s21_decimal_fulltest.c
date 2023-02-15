#include "s21_decimal.h"

#include <check.h>
#include <stdio.h>
#include <string.h>

// grishakir's tests depend on conversion, add them only after it is fixed

// NEGATE from Serzhunya

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
  s21_decimal a = {{4294967295, 0, 0, 0}};
  s21_decimal etalon = {{4294967295, 0, 0, ~(INT_MAX)}};

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
  s21_decimal a = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal etalon = {{4294967295, 4294967295, 4294967295, 0}};

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
  s21_decimal a = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal etalon = {{4294967295, 4294967295, 4294967295, ~(INT_MAX)}};

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
  s21_decimal a = {{4294967295, 4294967295, 4294967295, ~(INT_MAX)}};
  s21_decimal etalon = {{4294967295, 4294967295, 4294967295, 0}};

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
  s21_decimal val = {{2, 0, 0, ~(4294967295 / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_2) {
  s21_decimal val = {{0, 0, 0, ~(4294967295 / 2)}};
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

// NEGATE from rynortheast

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
  s21_decimal val = {{2, 0, 0, ~(4294967295 / 2)}};
  s21_decimal res = {0};
  int sign_before = s21_getSign(val);
  s21_negate(val, &res);
  int sign_after = s21_getSign(res);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_2_2) {
  s21_decimal val = {{0, 0, 0, ~(4294967295 / 2)}};
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

// TRUNCATE from padmemur

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

// TRUNCATE from chastity or kchonsu or MedmeFord

START_TEST(s21_truncate_1) {
  s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
  s21_setScale(&x, 3);
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_truncate(x, &z);
  char res1[1000], res2[1000] = "15 0 0 2147483648";
  snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal x = {{15008, 0, 0, 0b00000000000000000000000000000000}};
  s21_setScale(&x, 2);
  s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_truncate(x, &z);
  char res1[1000], res2[1000] = "150 0 0 0";
  snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

// TRUNCATE from rynortheast

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

START_TEST(truncate_1) {
  s21_decimal val = {{2, 0, 0, ~(4294967295 / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -2.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_3) {
  s21_decimal val = {{2, 0, 0, ~(4294967295 / 2)}};
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

// ROUND from rynortheast

// START_TEST(round_0) {
//   s21_decimal val = {{7, 7, 7, 0}};
//   s21_decimal res = {0};
//   s21_round(val, &res);
//   float fres = 0;
//   s21_from_decimal_to_float(res, &fres);
//   float need = 129127208515966861312.0;
//   ck_assert_float_eq(need, fres);
// }
// END_TEST

// START_TEST(round_9) {
//   s21_decimal val = {{128, 0, 0, 0}};
//   s21_decimal res = {0};
//   s21_setScale(&val, 1);
//   s21_round(val, &res);
//   float fres = 0;
//   s21_from_decimal_to_float(res, &fres);
//   float need = 13;
//   ck_assert_float_eq(need, fres);
// }
// END_TEST

// ROUND from chastity or kchonsu or MedmeFord

START_TEST(s21_round_1) {
s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
s21_setScale(&x, 0);
s21_decimal z = {{0, 0, 0, 0}};
s21_round(x, &z);
char res1[1000], res2[1000] = "95008 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_2) {
s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
s21_setScale(&x, 1);
s21_decimal z = {{0, 0, 0, 0}};
s21_round(x, &z);
char res1[1000], res2[1000] = "9501 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_3) {
s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
s21_setScale(&x, 2);
s21_decimal z = {{0, 0, 0, 0}};
s21_round(x, &z);
char res1[1000], res2[1000] = "950 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_4) {
s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
s21_setScale(&x, 4);
s21_decimal z = {{0, 0, 0, 0}};
s21_round(x, &z);
char res1[1000], res2[1000] = "10 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_5) {
s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
s21_setScale(&x, 5);
s21_decimal z = {{0, 0, 0, 0}};
s21_round(x, &z);
char res1[1000], res2[1000] = "1 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_6) {
s21_decimal x = {{95008, 0, 0, 0b00000000000000000000000000000000}};
s21_setScale(&x, 6);
s21_decimal z = {{0, 0, 0, 0}};
s21_round(x, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_7) {
s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
s21_setScale(&x, 0);
s21_decimal z = {{0, 0, 0, 0}};
s21_round(x, &z);
char res1[1000], res2[1000] = "95008 0 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_8) {
s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
s21_setScale(&x, 1);
s21_decimal z = {{0, 0, 0, 0}};
s21_round(x, &z);
char res1[1000], res2[1000] = "9501 0 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_9) {
s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
s21_setScale(&x, 2);
s21_decimal z = {{0, 0, 0, 0}};
s21_round(x, &z);
char res1[1000], res2[1000] = "950 0 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_10) {
s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
s21_setScale(&x, 4);
s21_decimal z = {{0, 0, 0, 0}};
s21_round(x, &z);
char res1[1000], res2[1000] = "10 0 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_11) {
s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
s21_setScale(&x, 5);
s21_decimal z = {{0, 0, 0, 0}};
s21_round(x, &z);
char res1[1000], res2[1000] = "1 0 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_round_12) {
s21_decimal x = {{95008, 0, 0, 0b10000000000000000000000000000000}};
s21_setScale(&x, 6);
s21_decimal z = {{0, 0, 0, 0}};
s21_round(x, &z);
char res1[1000], res2[1000] = "0 0 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

// ROUND from novexex

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

// ROUND from padmemur

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

// FLOOR from rynortheast

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

// FLOOR from chastity or kchonsu or MedmeFord

START_TEST(s21_floor_1) {
s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
s21_setScale(&x, 3);
s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
s21_floor(x, &z);
char res1[1000], res2[1000] = "16 0 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_floor_2) {
s21_decimal x = {{15008, 0, 0, 0b00000000000000000000000000000000}};
s21_setScale(&x, 3);
s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
s21_floor(x, &z);
char res1[1000], res2[1000] = "15 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_floor_3) {
s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
s21_setScale(&x, 10);
s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
s21_floor(x, &z);
char res1[1000], res2[1000] = "1 0 0 2147483648";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

// FLOOR from novexex

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

// FLOOR from padmemur

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

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc);
  tcase_add_test(tc, s21_negate_1);
  tcase_add_test(tc, s21_negate_2);
  tcase_add_test(tc, s21_negate_3);
  tcase_add_test(tc, s21_negate_4);
  tcase_add_test(tc, s21_negate_5);
  tcase_add_test(tc, s21_test_negate_0);
  tcase_add_test(tc, s21_test_negate_1);
  tcase_add_test(tc, s21_test_negate_2);
  tcase_add_test(tc, s21_test_negate_3);
  tcase_add_test(tc, s21_test_negate_4);
  tcase_add_test(tc, s21_test_negate_5);
  tcase_add_test(tc, s21_test_negate_6);
  tcase_add_test(tc, s21_test_negate_7);
  tcase_add_test(tc, s21_test_negate_8);
  tcase_add_test(tc, negate_0);
  tcase_add_test(tc, negate_1);
  tcase_add_test(tc, negate_2);
  tcase_add_test(tc, negate_3);
  tcase_add_test(tc, negate_0_2);
  tcase_add_test(tc, negate_1_2);
  tcase_add_test(tc, negate_2_2);
  tcase_add_test(tc, negate_3_2);
  tcase_add_test(tc, s21_truncate_test);  // truncate
  tcase_add_test(tc, s21_truncate_1);
  tcase_add_test(tc, s21_truncate_2);
  tcase_add_test(tc, truncate_0);
  tcase_add_test(tc, truncate_1);
  tcase_add_test(tc, truncate_3);
  tcase_add_test(tc, truncate_4);
  // tcase_add_test(tc, round_0);  // round
  // tcase_add_test(tc, round_9);
  tcase_add_test(tc, s21_round_1);
  tcase_add_test(tc, s21_round_2);
  tcase_add_test(tc, s21_round_3);
  tcase_add_test(tc, s21_round_4);
  tcase_add_test(tc, s21_round_5);
  tcase_add_test(tc, s21_round_6);
  tcase_add_test(tc, s21_round_7);
  tcase_add_test(tc, s21_round_8);
  tcase_add_test(tc, s21_round_9);
  tcase_add_test(tc, s21_round_10);
  tcase_add_test(tc, s21_round_11);
  tcase_add_test(tc, s21_round_12);
  tcase_add_test(tc, s21_round_1_n);
  tcase_add_test(tc, s21_round_2_n);
  tcase_add_test(tc, s21_round_3_n);
  tcase_add_test(tc, s21_round_4_n);
  tcase_add_test(tc, s21_round_test);
  tcase_add_test(tc, floor_0);  // floor
  tcase_add_test(tc, floor_1);
  tcase_add_test(tc, floor_2);
  tcase_add_test(tc, floor_3);
  tcase_add_test(tc, s21_floor_1);
  tcase_add_test(tc, s21_floor_2);
  tcase_add_test(tc, s21_floor_3);
  tcase_add_test(tc, s21_floor_1_n);
  tcase_add_test(tc, s21_floor_2_n);
  tcase_add_test(tc, s21_floor_test);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}