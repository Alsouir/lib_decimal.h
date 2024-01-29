#include "../s21_decimal.h"

int reduction_to_whole_number(s21_decimal value, s21_decimal *result) {
  s21_decimal result_decimal;
  reset_decimal(&result_decimal);
  reset_decimal(result);
  result->bits[0] = value.bits[0];
  result->bits[1] = value.bits[1];
  result->bits[2] = value.bits[2];
  int dividend = 0;  // делимое

  int index_bit_in_result = 0;
  int degree = read_degree((value.bits[3]));
  for (int i = 0; i < degree; i++) {
    dividend = cycle_divide_decimal_by_10(*result, &result_decimal,
                                          &index_bit_in_result);
    write_result_division_decimal_by_10(result, result_decimal,
                                        index_bit_in_result);
  }

  int sign_decimal = read_bit(value.bits[3], 31);
  write_bit(&(result->bits[3]), 31, sign_decimal);
  return dividend;
}

int cycle_divide_decimal_by_10(s21_decimal value, s21_decimal *result_decimal,
                               int *index_bit_in_result) {
  int dividend = 0;
  *index_bit_in_result = 0;
  int first_search_min_dividend = true;
  for (int i = 95; i >= 0; i--) {
    dividend = dividend * 2 + read_bit_in_decimal(value, i);
    if (dividend >= 10) {
      write_bit_in_decimal(result_decimal, *index_bit_in_result, 1);
      dividend = dividend % 10;
      first_search_min_dividend = false;
      *index_bit_in_result = *index_bit_in_result + 1;
    } else if (first_search_min_dividend == false) {
      write_bit_in_decimal(result_decimal, *index_bit_in_result, 0);
      *index_bit_in_result = *index_bit_in_result + 1;
    }
  }
  return dividend;
}

int cycle_divide_long_decimal_by_10(s21_long_decimal value,
                                    s21_long_decimal *result_decimal,
                                    int *index_bit_in_result) {
  int dividend = 0;
  *index_bit_in_result = 0;
  int first_search_min_dividend = true;
  for (int i = 191; i >= 0; i--) {
    dividend = dividend * 2 + read_bit_in_long_decimal(value, i);
    if (dividend >= 10) {
      write_bit_in_long_decimal(result_decimal, *index_bit_in_result, 1);
      dividend = dividend % 10;
      first_search_min_dividend = false;
      *index_bit_in_result = *index_bit_in_result + 1;
    } else if (first_search_min_dividend == false) {
      write_bit_in_long_decimal(result_decimal, *index_bit_in_result, 0);
      *index_bit_in_result = *index_bit_in_result + 1;
    }
  }
  return dividend;
}