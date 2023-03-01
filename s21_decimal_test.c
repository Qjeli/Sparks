#include "s21_decimal.h"

void test_neg_int() {
    int fl_daint = 0, res = 0;
    s21_decimal value_dec, value_dec_neg;
    scanf("%d", &fl_daint);
    s21_from_int_to_decimal(fl_daint, &value_dec);
    s21_negate(value_dec, &value_dec_neg);
    s21_from_decimal_to_int(value_dec_neg, &res);
    printf("%d\n", res);
}

void test_neg_float() {
    float fl_daint = 0, res = 0;
    s21_decimal value_dec, value_dec_neg;
    scanf("%f", &fl_daint);
    s21_from_float_to_decimal(fl_daint, &value_dec);
    s21_negate(value_dec, &value_dec_neg);
    s21_from_decimal_to_float(value_dec_neg, &res);
    printf("%f\n", res);
}

void conversion() {
float f, z, result;
  s21_decimal a = {{5, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  s21_decimal res = {0};
  s21_from_float_to_decimal(0.542 , &a);
  s21_from_float_to_decimal(0.6 , &b);
  // // s21_setSign(&b, 0);
  // s21_setSign(&a, 1);
  s21_div(a, b, &res); // 10010000110110 0.9270000
                       // 10001101001001 0.903333
  s21_from_decimal_to_float(res, &result);
  s21_from_decimal_to_float(a, &f);
  s21_from_decimal_to_float(b, &z);
  printf("result %f\n", f / z);  // 10001101001001
  printf("resDec %u %u %u %u \nsign: %d\nfromDecToFloat %lf\nres %lf %lf\n", res.bits[0], res.bits[1],res.bits[2],res.bits[3],s21_getSign(res),result, f, z);
}

void test_trunc() {
    float value = 0;
    float res = 0;
    s21_decimal value_dec;
    s21_decimal value_dec_tru;
    scanf("%f", &value);
    s21_from_float_to_decimal(value, &value_dec);
    s21_truncate(value_dec, &value_dec_tru);
    //s21_setScale(&value_dec_tru, 1);
    s21_from_decimal_to_float(value_dec_tru, &res);
    printf("%f\n", res);
}

void s21_truncate_test() {
    float a = -4.6;
    s21_decimal fl_d;
    s21_from_float_to_decimal(a, &fl_d);
    s21_truncate(fl_d, &fl_d);
    float result;
    s21_from_decimal_to_float(fl_d, &result);
    printf("%f - result\n", result);
    printf("-4 - must be\n");
}

void truncate_0() {
    s21_decimal val = {{7, 7, 7, 0}};
    s21_decimal res = {0};
    s21_truncate(val, &res);
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    printf("%f - result\n129127208515966861312.0 - must be\n", fres);
}

void s21_truncate_1() {
    s21_decimal x = {{15008, 0, 0, 0b10000000000000000000000000000000}};
    s21_setScale(&x, 3);
    s21_decimal z = {{0, 0, 0, 0b00000000000000000000000000000000}};
    s21_truncate(x, &z);
    char res1[1000];
    char res2[1000] = "15 0 0 2147483648";
    snprintf(res1, sizeof(char)*1000, "%u %u %u %u", z.bits[0], z.bits[1], z.bits[2], z.bits[3]);
    printf("%s\n", res1);
    printf("%s\n", res2);
}

void floor_1() {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  s21_floor(val, &res);
  float fres = 0;
  float value_fl = 0;
  s21_from_decimal_to_float(res, &fres);
  s21_from_decimal_to_float(val, &value_fl);
  printf("%d - UINT_MAX\n", ~(UINT_MAX / 2));
  printf("%f - initial value\n", value_fl);
  printf("%f - result\n", fres);
  printf("-2 - must be\n");
}

void test_floor() {
    float a = -4;
    s21_decimal fl_d, fl_dr;
    s21_from_float_to_decimal(a, &fl_d);
    s21_floor(fl_d, &fl_dr);
    float result;
    s21_from_decimal_to_float(fl_dr, &result);
    printf("%f - result\n", result);
    printf("-4 - must be\n");
}

void test_round() {
    float a = -0.95008;
    float b = 0.95008;
    s21_decimal fl_da, fl_dar;
    s21_decimal fl_db, fl_dbr;
    s21_from_float_to_decimal(a, &fl_da);
    s21_from_float_to_decimal(b, &fl_db);
    // s21_setScale(&fl_da, 6);
    // s21_setScale(&fl_db, 6);
    s21_round(fl_da, &fl_dar);
    s21_round(fl_db, &fl_dbr);
    float result_a;
    float result_b;
    s21_from_decimal_to_float(fl_dar, &result_a);
    s21_from_decimal_to_float(fl_dbr, &result_b);
    printf("%f - result\n", result_a);
    printf("-1 - must be\n");
    printf("%f - result\n", result_b);
    printf("1 - must be\n");
}

int main() {
    test_floor();
    return 0;
}