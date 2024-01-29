#include "../s21_decimal.h"

void write_float_in_decimal(float src, int integer_number,
                            int length_befor_point, char char_str[100],
                            char integer[100], int i, s21_decimal *dst) {
  float remains = src - (float)integer_number;
  int length_after_point = 0;
  int count_number_after_point = 0;
  if (remains > 0 && length_befor_point < 8) {
    if (char_str[0] != '0') {
      length_after_point = 7 - length_befor_point;
    } else {
      length_after_point = 8 - length_befor_point;
    }
    int flag = 0;
    char last_number[2];
    for (int j = 0; j < length_after_point && char_str[i + 1] != '\0';
         i++, j++) {
      integer[i] = char_str[i + 1];
      if (char_str[i + 2] != '\0' && length_after_point - 1 == j) {
        flag = 1;
        last_number[0] = char_str[i + 2];
        last_number[1] = '\0';
      }
      count_number_after_point++;
    }
    integer_number = atoi(integer);
    int additional_zeros = length_after_point - count_number_after_point;
    while (additional_zeros > 0 || integer_number < 1000000) {
      integer[i] = '0';
      i++;
      additional_zeros--;
      count_number_after_point++;
      integer_number = atoi(integer);
    }

    integer_number = atoi(integer);

    if (flag == 1 && atoi(last_number) >= 5) integer_number++;
    dst->bits[0] = integer_number;
    write_degree_in_decimal(dst, count_number_after_point);
  } else if (remains == 0) {
    dst->bits[0] = integer_number;
    write_degree_in_decimal(dst, count_number_after_point);
  }
}

void from_decimal_to_long_decimal(s21_decimal value, s21_long_decimal *result) {
  result->bits[0] = value.bits[0];
  result->bits[1] = value.bits[1];
  result->bits[2] = value.bits[2];
  result->bits[3] = 0;
  result->bits[4] = 0;
  result->bits[5] = 0;
  result->bits[6] = value.bits[3];
}

// Перевод из long decimal в decimal. 0 - ошибки нет, 1 число слишком большое
int from_long_decimal_to_decimal(s21_long_decimal value, int degree,
                                 s21_decimal *result) {
  int result_translation = 0;
  int dividend = 0;
  bool need_round = false;
  while (degree > 28) {
    dividing_long_decimal_10_no_round(&value, &dividend);
    degree = degree - 1;
    need_round = true;
  }
  int last_no_zero = last_no_0_in_long_decimal(value, 191);
  while (last_no_zero > 95 && degree > 0) {
    dividing_long_decimal_10_no_round(&value, &dividend);
    degree = degree - 1;
    need_round = true;
    last_no_zero = last_no_0_in_long_decimal(value, 191);
  }
  if (need_round) {
    if (dividend >= 5 && value.bits[0] == -1 && value.bits[1] == -1 &&
        value.bits[2] == -1 && degree == 0) {
      result_translation = 1;
    } else if (dividend >= 5 && value.bits[0] == -1 && value.bits[1] == -1 &&
               value.bits[2] == -1) {
      dividing_long_decimal_10_no_round(&value, &dividend);
      degree = degree - 1;
      round_long_decimal(&value, dividend);
    } else {
      round_long_decimal(&value, dividend);
    }
  }
  last_no_zero = last_no_0_in_long_decimal(value, 191);
  if (last_no_zero > 95) {
    result_translation = 1;
  } else {
    result->bits[0] = value.bits[0];
    result->bits[1] = value.bits[1];
    result->bits[2] = value.bits[2];
    write_degree_in_decimal(result, degree);
  }

  return result_translation;
}