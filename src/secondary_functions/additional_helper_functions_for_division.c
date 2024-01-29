#include "../s21_decimal.h"

int division_decimal(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result, int *general_degree) {
  int result_div = 0;
  int result_mul = 0;

  s21_long_decimal long_value1, long_value2, long_result;
  from_decimal_to_long_decimal(value_1, &long_value1);
  from_decimal_to_long_decimal(value_2, &long_value2);
  from_decimal_to_long_decimal(*result, &long_result);

  while (result_mul == 0) {
    result_mul = multiplying_long_decimal_by_10(&long_value1);
    if (result_mul == 0) {
      *general_degree = *general_degree + 1;
    }
  }
  result_div = division_by_column(long_value1, long_value2, &long_result,
                                  general_degree);

  if (result_div == 0) {
    result_div =
        from_long_decimal_to_decimal(long_result, *general_degree, result);
  }

  return result_div;
}

int division_by_column(s21_long_decimal value_1, s21_long_decimal value_2,
                       s21_long_decimal *result, int *general_degree) {
  int result_div = 0;

  s21_long_decimal balance;
  reset_long_decimal(&balance);
  int last_bit_in_value_1 = last_no_0_in_long_decimal(value_1, 191);

  while (comparison_of_digits_of_long_decimals(balance, value_2) == 2) {
    add_bit_in_long_decimal(
        &balance, read_bit_in_long_decimal(value_1, last_bit_in_value_1));
    last_bit_in_value_1 = last_bit_in_value_1 - 1;
  }
  add_bit_in_long_decimal(result, 1);

  reduce_long_decimal(&balance, value_2);
  if (last_bit_in_value_1 >= 0) {
    add_bit_in_long_decimal(
        &balance, read_bit_in_long_decimal(value_1, last_bit_in_value_1));
  }
  last_bit_in_value_1 = last_bit_in_value_1 - 1;
  while (last_bit_in_value_1 >= -1) {
    if (comparison_of_digits_of_long_decimals(balance, value_2) == 2) {
      add_bit_in_long_decimal(result, 0);
    } else {
      add_bit_in_long_decimal(result, 1);
      reduce_long_decimal(&balance, value_2);
    }
    if (last_bit_in_value_1 >= 0) {
      add_bit_in_long_decimal(
          &balance, read_bit_in_long_decimal(value_1, last_bit_in_value_1));
    }
    last_bit_in_value_1 = last_bit_in_value_1 - 1;
  }

  if (last_no_0_in_long_decimal(balance, 191) == -1) {
    // Максимальное уменьшение числа в 10 (без потери точности)
    reduction_long_decinal_by_10_without_remainder(general_degree, result);
  } else {
    // Округление частного на основе остатка.
    round_quotient_in_long_decimal(result, balance, value_2);
  }

  while (*general_degree < 0 && result_div == 0) {
    result_div = multiplying_long_decimal_by_10(result);
    *general_degree = *general_degree + 1;
  }
  return result_div;
}

void add_bit_in_long_decimal(s21_long_decimal *value, int bit) {
  int last_no_zero_in_balance = last_no_0_in_long_decimal(*value, 191);
  for (int i = last_no_zero_in_balance; i >= 0; i--) {
    write_bit_in_long_decimal(value, i + 1,
                              read_bit_in_long_decimal(*value, i));
  }
  write_bit_in_long_decimal(value, 0, bit);
}

void reduce_long_decimal(s21_long_decimal *value_1, s21_long_decimal value_2) {
  int loan = 0;
  for (int i = 0; i < 192; i++) {
    int bit_1 = read_bit_in_long_decimal(*value_1, i);
    int bit_2 = read_bit_in_long_decimal(value_2, i);
    subtraction_two_bits_in_long_decimal(value_1, i, bit_1, bit_2, &loan);
  }
}

void round_quotient_in_long_decimal(s21_long_decimal *result,
                                    s21_long_decimal balance,
                                    s21_long_decimal value_2) {
  // нужны 1-ые пять цифр деления баланса на значение
  add_bit_in_long_decimal(&balance, 0);
  int result_division_balance = 0;
  for (int i = 0; i < 5; i++) {
    result_division_balance = result_division_balance * 2;
    if (comparison_of_digits_of_long_decimals(balance, value_2) == 2) {
      add_bit_in_long_decimal(&balance, 0);
    } else {
      result_division_balance = result_division_balance + 1;
      reduce_long_decimal(&balance, value_2);
    }
  }

  if (result_division_balance == 16) {
    result_division_balance = 5;
  } else if (result_division_balance > 16) {
    result_division_balance = 6;
  } else {
    result_division_balance = result_division_balance * 10 / 32;
  }

  round_long_decimal(result, result_division_balance);
}

void reduction_long_decinal_by_10_without_remainder(int *general_degree,
                                                    s21_long_decimal *result) {
  int balance = 0;
  s21_long_decimal result_of_division_by_10;
  reset_long_decimal(&result_of_division_by_10);
  int index_bit_in_result = 0;
  while (*general_degree > 0 && balance == 0) {
    balance = cycle_divide_long_decimal_by_10(
        *result, &result_of_division_by_10, &index_bit_in_result);
    if (balance == 0) {
      write_result_division_long_decimal_by_10(result, result_of_division_by_10,
                                               index_bit_in_result);
      *general_degree = *general_degree - 1;
    }
  }
}