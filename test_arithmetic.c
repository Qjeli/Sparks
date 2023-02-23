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
char res1[1000], res2[1000] = "41 1 0 2147483648";
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
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_11) {
s21_decimal x = {{1, 0, 0, 1835008}};
s21_decimal y = {{1, 0, 0, 2149318656}};
s21_decimal z = {{0, 0, 0, 0}};
s21_add(x, y, &z);
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
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
char res1[1000], res2[1000] = "3 0 0 2147483648";
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
char res1[1000], res2[1000] = "0 0 0 0";
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
char res1[1000], res2[1000] = "0 0 0 0";
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
char res1[1000], res2[1000] = "0 0 0 0";
snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
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
  tcase_add_test(tc1_1, mod_2);
  tcase_add_test(tc1_1, mod_3);
  tcase_add_test(tc1_1, mod_4);
  tcase_add_test(tc1_1, mod_5);
  tcase_add_test(tc1_1, mod_6);
  tcase_add_test(tc1_1, mod_7);
  tcase_add_test(tc1_1, mod_8);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}