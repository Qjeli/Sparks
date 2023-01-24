#include "arifmet.h"


// Считаем количество знаков в src
int count_src(float src, char* str_src) {
    int count_str = 0, k = 1;
    char str[100];

    snprintf(str, sizeof(str), "%f", src);

    for (int i = (int) strlen(str) - 1; i >= 0; i--) {
        if (str[i] == '0' && k == 1) {
            str[i] = '\0';
            continue;
        } else {
            k = -1;
        }
        if (str[i] == '.') {
            break;
        }
        count_str++;
    }

    strncpy(str_src, str, strlen(str) + 1);

    return count_str;
}

/// | - - - - - - - - - comparison - - - - - - - - - - - |

int s21_is_less(s21_decimal value1, s21_decimal value2) {
  return s21_is_greater(value2, value1);
}

int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2) {
  return (s21_is_less(value1, value2) || s21_is_equal(value1, value2));
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int res = OK;
  s21_check_scale(&value_1, &value_2);
  int num1 = 0, num2 = 0;
  int sign1 = s21_getSign(value_1), sign2 = s21_getSign(value_2);  // removed & from value_1 and value_2
  for (int i = 95; i >= 0; i--) {
    num1 = s21_getBit(value_1, i);
    num2 = s21_getBit(value_2, i);
    if (num1 > num2) {
      res = 1;
      break;
    }
    if (num1 < num2) {
      res = 0;
      break;
    }
  }
  if (sign1 && !sign2)
    res = 0;
  else if (!sign1 && sign2)
    res = 1;
  else if (sign1 && sign2)
    res = !res;
  return s21_is_equal(value_1, value_2) ? 0 : res;
}

// duplication
 /*
int s21_is_greater(s21_decimal num1, s21_decimal num2) {  // возвращает 0 если первый больше второго
  int result = -1;
  int sign_num1 = s21_getSign(num1);
  int sign_num2 = s21_getSign(num2);
  if (sign_num1 == sign_num2 && sign_num1 == 0) {  // оба положительные
    result = s21_is_greater_num(num1, num2, result);
  } else if (sign_num1 == 1 &&
             sign_num2 == 0) {  // num1 - отрицательный, num2 - положительный
    result = 1;
  } else if (sign_num1 == 0 &&
             sign_num2 == 1) {  // num1 - положительный, num2 - отрицательный
    result = 0;
  } else if (sign_num1 == sign_num2 && sign_num1 == 1) {  // оба отрицательный
      result = !s21_is_greater_num(num1, num2, result);
    }
  return result;
}
*/

int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2) {
  return (s21_is_greater(value1, value2) || s21_is_equal(value1, value2));
}

int s21_is_equal(s21_decimal value1, s21_decimal value2) {
  s21_check_scale(&value1, &value2);
  int res = 1;
  int sign1 = s21_getSign(value1), sign2 = s21_getSign(value2);  // removed & from value_1 and value_2
  for (int i = 95; i >= 0; i--) {
    if (s21_getBit(value1, i) != s21_getBit(value2, i)) {
      res = 0;
      break;
    }
  }
  if (sign1 != sign2) res = 0;
  return res;
}

int s21_is_not_equal(s21_decimal value1, s21_decimal value2) {
  return (!s21_is_equal(value1, value2));
}



/// | - - - - - - - - - ariphmetic - - - - - - - - - - - |


int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int res = OK; int flag = 0;
    //int buf;
    s21_init_decimal(result);
    s21_scale_equalization(&value_1, &value_2, 0);
    int left = s21_getBit(value_1, 0); // полуаем самый первый бит левого числа
    int right = s21_getBit(value_2, 0); // тож самое но для правого
    if(left != right) { // если они не равны. Хз в чем прикол правда,
    // честно я б поставила если каждый из них = 1
        if(left == 1) flag = 1; 
        if(right == 1) flag = 1;  // понимаю что проверка на бесконечность, но чел, почему это проверяем только если не равны друг другу
        // чувство что это все же для вычитания 
    }
    if(flag == 0) {
        int tmp = 0;
        for(int i = 0; i < 96; i++) {
            int tmp1 = s21_getBit(value_1, i);
            int tmp2 = s21_getBit(value_2, i);
            int tmp_res = tmp1 + tmp2 + tmp;
            if(tmp_res == 0) {
                s21_setBit(result, i, 0);  // removed * from result
                tmp = 0;
            } else if (tmp_res == 1) {
                s21_setBit(result, i, 1);  // removed * from result
                tmp = 0;
            } else if(tmp_res == 2 || tmp_res == 3) {
                if(i == 95) {
                    res = 1;
                    break;
                }
                s21_setBit(result, i, tmp_res == 2? 0:1);  // removed * from result
                tmp = 1;
            }
        }
        s21_setScale(result, s21_getScale(value_1));// устанавливаем размер для результата
        if(left == 1) {
            s21_setSign(result,  1);
        }
    } else if(flag == 1) {
        s21_setSign(&value_1, 0);
        res = s21_sub(value_2, value_1, result);
    } else if (flag == 2) {
        s21_setSign(&value_2, 0);
        res = s21_sub(value_1, value_2, result);
    }
    if(s21_getScale(*result) > 28 || (result->bits[0] == 0 && result->bits[1] == 0 && result->bits[2] == 0)) 
        res = 2;
    if (res != 0) s21_init_decimal(result);
    return res;
}

// вычитание 
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int res = OK, flag = 0;
  s21_init_decimal(result);
  s21_scale_equalization(&value_1, &value_2, 0);
  int left = s21_getBit(value_1, 127);
  int right = s21_getSign(value_2);
  if (left != right) {
    if (left == 0) flag = 1;
    if (right == 0) flag = 2;
  }
  if (flag == 0) {
    if (left == 0) {
      if (s21_is_less(value_1, value_2)) {
        s21_setSign(result, 1);
        s21_decimal hold = value_1;
        value_1 = value_2;
        value_2 = hold;
      }
      for (int i = 0; i < 96; i++) {
        int tmp1 = s21_getBit(value_1, i);
        int tmp2 = s21_getBit(value_2, i);
        int tmp_res = tmp1 - tmp2;
        if (tmp_res == 0) {
          s21_setBit(result, i, 0);  // removed * from result
          continue;
        } else if (tmp_res == 1) {
          s21_setBit(result, i, 1);  // removed * from result
        } else if (tmp_res == -1) {
          int n = i + 1;
          while (s21_getBit(value_1, n) != 1) {
            s21_setBit(&value_1, n, 1);  // added & to value_1
            n++;
          }
          s21_setBit(&value_1, n, 0);  // added & to value_1
          s21_setBit(result, i, 1);  // removed * from result
        }
      }
      s21_setScale(result, s21_getScale(value_1));
    } else if (left == 1) {
      s21_setBit(&value_1, 127, 0);  // added & to value_1
      s21_setBit(&value_2, 127, 0);  // added & to value_2
      res = s21_sub(value_2, value_1, result);
    }
  } else if (flag == 1) {
    s21_setBit(&value_2, 127, 0);  // added & to value_2
    res = s21_add(value_1, value_2, result);
  } else if (flag == 2) {
    s21_setBit(&value_2, 127, 1);  // added & to value_2
    res = s21_add(value_1, value_2, result);
  }
  if (s21_getScale(*result) > 28 ||
      (s21_getScale(*result) == 28 && result->bits[0] == 0 &&
       result->bits[1] == 0 && result->bits[2] == 0))
    res = 2;
  if (res != 0) s21_init_decimal(result);
  return res;
}

// умножение
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) { // нет проверки на флаги
    int flag = 0;
    int sign_control = 0;
    s21_decimal tmp;
    s21_decl_to_null(&tmp);
    s21_decl_to_null(result);
    if (s21_getSign(value_1) != s21_getSign(value_2)) {
        sign_control = 1;
    }
    s21_setSign(&value_1, 0);
    s21_setSign(&value_2, 0);
    s21_scale_equalization(&value_1, &value_2, 0);
    s21_bits_copy(tmp, &value_1);

    int b = 5;
    for (int i = 0; i < 96 && b > 0; i++) {
        if (s21_getBit(value_2, i)) {
            flag = s21_add(*result, tmp, result);
        }
        s21_shift_left(&tmp, 1);

        s21_from_decimal_to_int(tmp, &b);
    }
    s21_setSign(result, sign_control);
    return flag;
}

int s21_is_greater_num(s21_decimal num1,s21_decimal  num2, int result){
  result = 0;
  //if (num1.bits[3] == num2.bits[3]) {
      if (num1.bits[2] == num2.bits[2]) {
        if (num1.bits[1] == num2.bits[1]) {
          if (num1.bits[0] == num2.bits[0]) {
            result = 0; // они равны
          }
          else if(num1.bits[0] >= num2.bits[0])
            result = 0;
          else result = 1; 
        }
        else if(num1.bits[1] >= num2.bits[1])
            result = 0;
          else result = 1; 
      }
      else if(num1.bits[2] >= num2.bits[2])
            result = 0;
          else result = 1; 
 // }
  return result;
}


//деление
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = 0; 
  s21_decimal val_1 = value_1;
  s21_decimal val_2 = value_2;
  int bit = 0;
  int sign_1 = s21_getSign(value_1);  // получаем знак
  int sign_2 = s21_getSign(value_2);

  if (sign_1 != sign_2) {
    s21_setSign(result, 1);
  } else {
    s21_setSign(result, 0);
  }

 // s21_setSign(&val_1, 0);  // зануляем знак
 // s21_setSign(&val_2, 0);

  s21_decimal val_og = val_2;
///////////////////////////////////////////////////////
  int i = 0;
  while (!s21_is_greater_or_equal(val_1, val_2)) {
    s21_sub(val_1, val_2, &val_1);  // непосредственно производим вычитание
    s21_setBit(result, i, 1);  // removed * from result
    i++;
  }

    return flag;
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{
   int flag = 0; 
  s21_decimal val_1 = value_1;
  s21_decimal val_2 = value_2;
  int bit = 0;
  int sign_1 = s21_getSign(value_1);  // получаем знак
  int sign_2 = s21_getSign(value_2);

  if (sign_1 != sign_2) {
    s21_setSign(result, 1);
  } else {
    s21_setSign(result, 0);
  }

 // s21_setSign(&val_1, 0);  // зануляем знак
 // s21_setSign(&val_2, 0);

  s21_decimal val_og = val_2;
///////////////////////////////////////////////////////
  while (!s21_is_greater_or_equal(val_1, val_2)) {
    s21_sub(val_1, val_2, &val_1);  // непосредственно производим вычитание
  }
  *result = val_1; 
    return flag;

}


/// | - - - - - - - - - Converters - - - - - - - - - - - |


int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    memset(&(dst->bits), 0, sizeof(dst->bits));  //  filling an array of bits with zeros, with the size of bits
    if (src < 0) {  //  if srs is not negative then...
        dst->bits[3] = dst->bits[3] | (1u << 31);  //  make bit 31 into bit 1 in bits[3]
        src = -src;  //  make src negative
    }
    dst->bits[0] = src;  //  add src to bit[0]
    return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int flag = 0;  // флаг ошибки
  s21_decimal ten;  //  умножение на 10
  s21_decimal add;  //  для простого сложения
  int rank = 0;
  if(fabsf(src) < 1e-28 && fabsf(src) < 0) {  //  условие ошибки
    flag = 1;
  }

  char str_src[1000];
  int count = count_src(src, str_src), is_overfill = 0; //  count_src копирует переносит массив оттуда в str_src

  s21_from_int_to_decimal(10, &ten);

  for (size_t i = 0; i < strlen(str_src); i++) {  //  проходим по элементам и проверяем условие
        if (str_src[i] != '.' && str_src[i] != '-') {
            s21_from_int_to_decimal(str_src[i] - '0', &add);
            memset(&(dst->bits), 0, sizeof(dst->bits));
            for (int j = 0; j < 96; j++) {  //  второй цикл конвертирования
              int bit1 = s21_getBit(*dst, j);
              int bit2 = s21_getBit(add, j);

              s21_setBit(dst, j, bit1 ^ bit2 ^ rank);  //  ^ - правда когда один из битов 1, но не оба // removed * from dst
            }
            is_overfill = s21_mul(*dst, ten, dst);  //  не знаю что делать дальше
        }
    }

    s21_setSign(dst, src < 0);  // removed & from dst
    s21_setScale(dst, count_src);

  return flag;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
   int flag = 0;
    int data = 0;
    int scale = s21_getScale(src);

    if (scale + 31 < 95) {
        for (int i = scale + 31; i <= 95; ++i) {
            if (s21_getBit(src, i)) {
                flag = 1;
            }
        }

    }

    if (!flag) {
        for (int i = scale + 30; i >= scale; --i) {
            data <<= 1;
            data |= s21_getBit(src, i);
        }
        if (s21_getSign(src)) {
            data = -data;
        }
        *dst = data;
    }
    return flag;
}