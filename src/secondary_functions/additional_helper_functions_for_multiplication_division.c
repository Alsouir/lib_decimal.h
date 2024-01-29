#include "../s21_decimal.h"

int last_no_0_in_decimal(s21_decimal value, int last_index) {
  int result = -1;

  for (int i = last_index; i >= 0 && result == -1; i--) {
    if (read_bit_in_decimal(value, i) != 0) {
      result = i;
    }
  }

  return result;
}

// Может просто заменить на массив int для универсальности?
int last_no_0_in_long_decimal(s21_long_decimal value, int last_index) {
  int result = -1;

  for (int i = last_index; i >= 0 && result == -1; i--) {
    if (read_bit_in_long_decimal(value, i) != 0) {
      result = i;
    }
  }

  return result;
}

int multiplication_decimals(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal *result) {
  int result_mul = 0;

  int degree_value_1 = read_degree(value_1.bits[3]);
  int degree_value_2 = read_degree(value_2.bits[3]);
  int general_degree = degree_value_1 + degree_value_2;

  int last_no_zero_in_value_1 = last_no_0_in_decimal(value_1, 95);
  int last_no_zero_in_value_2 = last_no_0_in_decimal(value_2, 95);

  if (last_no_zero_in_value_1 == -1 || last_no_zero_in_value_2 == -1) {
    general_degree = 0;
    reset_decimal(result);
  } else {
    result_mul =
        addition_to_multiply(&value_1, &value_2, result, &general_degree);
  }
  return result_mul;
}

// Умножение столбиком
int addition_to_multiply(s21_decimal *value_1, s21_decimal *value_2,
                         s21_decimal *result, int *general_degree) {
  int result_mul = 0;
  int balance = 0;

  s21_long_decimal long_value_1, long_value_2, long_result;
  from_decimal_to_long_decimal(*value_1, &long_value_1);
  from_decimal_to_long_decimal(*value_2, &long_value_2);
  from_decimal_to_long_decimal(*result, &long_result);

  int last_no_zero_in_value_2 = last_no_0_in_long_decimal(long_value_2, 95);

  while (last_no_zero_in_value_2 != -1) {
    for (int i = last_no_zero_in_value_2, index_value = 0; i < 192;
         i++, index_value++) {
      int bit_1 = read_bit_in_long_decimal(long_result, i);
      int bit_2 = read_bit_in_long_decimal(long_value_1, index_value);
      addition_two_bits_in_long_decimal(&long_result, i, bit_1, bit_2,
                                        &balance);
    }
    last_no_zero_in_value_2 =
        last_no_0_in_long_decimal(long_value_2, last_no_zero_in_value_2 - 1);
  }

  result_mul =
      from_long_decimal_to_decimal(long_result, *general_degree, result);

  return result_mul;
}

int comparison_of_digits_of_long_decimals(s21_long_decimal value_1,
                                          s21_long_decimal value_2) {
  int result = 0;

  for (int i = 191; i >= 0 && result == 0; i--) {
    int bit_1 = read_bit_in_long_decimal(value_1, i);
    int bit_2 = read_bit_in_long_decimal(value_2, i);
    if (bit_1 > bit_2) {
      result = 1;
    } else if (bit_2 > bit_1) {
      result = 2;
    }
  }

  return result;
}

void assign_sign_for_multiplication_division(s21_decimal value_1,
                                             s21_decimal value_2,
                                             s21_decimal *result) {
  int sign_value_1 = read_bit(value_1.bits[3], 31);
  int sign_value_2 = read_bit(value_2.bits[3], 31);
  if (sign_value_1 == sign_value_2) {
    write_bit(&(result->bits[3]), 31, 0);
  } else {
    write_bit(&(result->bits[3]), 31, 1);
  }
}