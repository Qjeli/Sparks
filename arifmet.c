#include <arifmet.h>
// сложение
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    int errCode = 0;
    info info_val1 = {0};
    info info_val2 = {0};
    set_info(value_1, &info_val1);
    set_info(value_2, &info_val2);
    if (info_val1.sign == info_val2.sign) {
        equalization_exp(&info_val1, &info_val2);
    }
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
    info_vall->sing = ((value.bits[3] >> 31) & 1);
}

int get_info(s21_decimal value, int i) {
    return( (value.bits[3] >> i) & 1);
}

void equalization_exp(info *info_val1, info *info_val2) {
    int sdv1 = info_val1->move;
    int sdv2 = info_val2->move;
    if (sdv1 > sdv2) {
        for(int i = 16; i <= 25 ; i++) {
            int sdv = sdv1 >> i;
            sdv2 = sdv2 || (sdv << i);
        }
        info_val2->move = sdv2;
    }
    else if (sdv1 < sdv2) {
        for(int i = 16; i <= 25 ; i++) {
            int sdv = sdv1 >> i;
            sdv1 = sdv1 || (sdv << i);
        }
        info_val1->move = sdv1;
    }
}