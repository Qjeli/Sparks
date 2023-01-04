// вычитание
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int errCode = 0;
    if(value_2.bits[3] > 2147483648)
    errCode = s21_add(value_1, -value_2, result);
    return errCode;
}
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int errCode = 0;
    return errCode;
}
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int errCode = 0;
    if (value_2.bits[0] == 0 && value_2.bits[1] == 0) errCode = 3;
    else {
        
    }
    return errCode;
}
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int errCode = 0;
    return errCode;
}
