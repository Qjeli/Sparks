#include <arifmet.h>
// сложение
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int errCode = 0;
    info info_val1 = {0};
    info info_val2 = {0};
    set_info(value_1, &info_val1);
    set_info(value_2, &info_val2);

    return errCode;
}
/*void set_bit_nums(unsigned int *val, int bit, int pos) {
    if (bit != 0 && get_bit_nums(*val, pos) == 0) {
        *val = *val | (bit << pos);
    } else if (bit == 0 && get_bit_nums(*val, pos) == 1) {
        *val = *val & ~((bit + 1) << pos);
    }
}*/
void set_info(s21_decimal value, info *info_vall) {
    int j = 0;
    for(int i = 16; i <= 23; i++){
        int bit = get_info(value, i);
        // скорее всего сюда еще нужны проверки 
        info_vall->move = info_vall->move | (bit << j);
        j ++;
    }
    if( (value.bits[3] >> 31) & 1 == 1) {
         // если этот символ 0 то и менять ничего не надо 
        info_vall->sing = 1; 
    }
}

int get_info(s21_decimal value, int i) {
    return( (value.bits[3] >> i) & 1);
}
