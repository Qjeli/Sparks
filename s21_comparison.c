#include "s21_decimal.h"

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