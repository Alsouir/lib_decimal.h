#include "../s21_decimal.h"

int prefabrication_addition(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal *result) {
  int result_add = 0;
  int degree_value_1 = 0;
  int degree_value_2 = 0;
  int max_degree = 0;
  reduction_greatest_common_denominator_decimals(
      &value_1, &value_2, &degree_value_1, &degree_value_2, &max_degree);

  result_add = addition(value_1, value_2, result);

  if (result_add != 0) {
    max_degree = max_degree - 1;
    rounding_decimal(&value_1, max_degree, &degree_value_1);
    rounding_decimal(&value_2, max_degree, &degree_value_2);

    result_add = addition(value_1, value_2, result);
  }

  write_degree_in_decimal(result, max_degree);

  return result_add;
}

int addition(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int result_add = 0;
  int balance = 0;

  for (int i = 0; i < 96; i++) {
    addition_two_bits_in_decimal(result, i, read_bit_in_decimal(value_1, i),
                                 read_bit_in_decimal(value_2, i), &balance);
  }

  if (balance != 0) {
    result_add = 1;
  }

  return result_add;
}

void increasing_denominator_addition(s21_decimal *value, int *max_degree,
                                     int *degree_value) {
  int count_multiplication = *max_degree - *degree_value;
  for (int i = 0; i < count_multiplication; i++) {
    int multiplication_successful = multiplying_decimal_by_10(value);
    if (multiplication_successful == 1) {
      *max_degree = *degree_value;
    } else {
      *degree_value = *degree_value + 1;
    }
  }
}

void rounding_decimal(s21_decimal *value, int min_degree, int *degree_value) {
  while (*degree_value > min_degree && *degree_value > 0) {
    dividing_decimal_10(value);
    *degree_value = *degree_value - 1;
  }
}

void dividing_decimal_10(s21_decimal *value) {
  s21_decimal result_decimal;
  reset_decimal(&result_decimal);
  int dividend = 0;  // делимое

  int index_bit_in_result = 0;
  dividend =
      cycle_divide_decimal_by_10(*value, &result_decimal, &index_bit_in_result);
  write_result_division_decimal_by_10(value, result_decimal,
                                      index_bit_in_result);

  round_decimal(value, dividend);
}

void dividing_long_decimal_10_no_round(s21_long_decimal *value, int *dividend) {
  s21_long_decimal result_decimal;
  reset_long_decimal(&result_decimal);
  *dividend = 0;  // делимое

  int index_bit_in_result = 0;
  *dividend = cycle_divide_long_decimal_by_10(*value, &result_decimal,
                                              &index_bit_in_result);
  write_result_division_long_decimal_by_10(value, result_decimal,
                                           index_bit_in_result);
}

void write_result_division_decimal_by_10(s21_decimal *value,
                                         s21_decimal result_decimal,
                                         int index_bit_in_result) {
  reset_number_in_decimal(value);

  for (int i = 0; i < index_bit_in_result; i++) {
    write_bit_in_decimal(value, 95 - (96 - index_bit_in_result) - i,
                         read_bit_in_decimal(result_decimal, i));
  }
}

void write_result_division_long_decimal_by_10(s21_long_decimal *value,
                                              s21_long_decimal result_decimal,
                                              int index_bit_in_result) {
  reset_number_in_long_decimal(value);

  for (int i = 0; i < index_bit_in_result; i++) {
    write_bit_in_long_decimal(value, 191 - (192 - index_bit_in_result) - i,
                              read_bit_in_long_decimal(result_decimal, i));
  }
}

void round_decimal(s21_decimal *value, int remainder_division) {
  if ((remainder_division > 5 && remainder_division < 10) ||
      (remainder_division == 5 && read_bit_in_decimal(*value, 0) == 1)) {
    decimal_plus_1(value);
  }
}

void round_long_decimal(s21_long_decimal *value, int remainder_division) {
  if ((remainder_division > 5 && remainder_division < 10) ||
      (remainder_division == 5 && read_bit_in_long_decimal(*value, 0) == 1)) {
    long_decimal_plus_1(value);
  }
}

void decimal_plus_1(s21_decimal *value) {
  bool not_finish = true;
  for (int i = 0; i < 96 && not_finish; i++) {
    if (read_bit_in_decimal(*value, i) == 0) {
      not_finish = false;
    }
    change_bit_in_decimal(value, i);
  }
}

void long_decimal_plus_1(s21_long_decimal *value) {
  bool not_finish = true;
  for (int i = 0; i < 192 && not_finish; i++) {
    if (read_bit_in_long_decimal(*value, i) == 0) {
      not_finish = false;
    }
    change_bit_in_long_decimal(value, i);
  }
}

int multiplying_decimal_by_10(s21_decimal *value) {
  int result = 0;
  s21_decimal result_decimal;
  reset_decimal(&result_decimal);
  for (int i = 0; i < 95; i++) {
    write_bit_in_decimal(&result_decimal, i + 1,
                         read_bit_in_decimal(*value, i));
  }
  if (read_bit_in_decimal(*value, 95) == 1) {
    result = 1;
  }

  int balance = 0;
  if (result == 0) {
    for (int i = 0; i < 93; i++) {
      addition_two_bits_in_decimal(
          &result_decimal, i + 3, read_bit_in_decimal(*value, i),
          read_bit_in_decimal(result_decimal, i + 3), &balance);
    }
  }
  if (balance + read_bit_in_decimal(*value, 93) +
          read_bit_in_decimal(*value, 94) + read_bit_in_decimal(*value, 95) !=
      0) {
    result = 1;
  } else {
    value->bits[0] = result_decimal.bits[0];
    value->bits[1] = result_decimal.bits[1];
    value->bits[2] = result_decimal.bits[2];
  }
  return result;
}

int multiplying_long_decimal_by_10(s21_long_decimal *value) {
  int result = 0;
  s21_long_decimal result_decimal;
  reset_long_decimal(&result_decimal);
  for (int i = 0; i < 192; i++) {
    write_bit_in_long_decimal(&result_decimal, i + 1,
                              read_bit_in_long_decimal(*value, i));
  }
  if (read_bit_in_long_decimal(*value, 191) == 1) {
    result = 1;
  }

  int balance = 0;
  if (result == 0) {
    for (int i = 0; i < 189; i++) {
      addition_two_bits_in_long_decimal(
          &result_decimal, i + 3, read_bit_in_long_decimal(*value, i),
          read_bit_in_long_decimal(result_decimal, i + 3), &balance);
    }
  }
  if (balance + read_bit_in_long_decimal(*value, 189) +
          read_bit_in_long_decimal(*value, 190) +
          read_bit_in_long_decimal(*value, 191) !=
      0) {
    result = 1;
  } else {
    value->bits[0] = result_decimal.bits[0];
    value->bits[1] = result_decimal.bits[1];
    value->bits[2] = result_decimal.bits[2];
    value->bits[3] = result_decimal.bits[3];
    value->bits[4] = result_decimal.bits[4];
    value->bits[5] = result_decimal.bits[5];
  }
  return result;
}

void addition_two_bits_in_decimal(s21_decimal *value, int index_for_bit,
                                  int bit_1, int bit_2, int *balance) {
  switch (*balance + bit_1 + bit_2) {
    case 0:
      write_bit_in_decimal(value, index_for_bit, 0);
      balance = 0;
      break;
    case 1:
      write_bit_in_decimal(value, index_for_bit, 1);
      *balance = 0;
      break;
    case 2:
      write_bit_in_decimal(value, index_for_bit, 0);
      *balance = 1;
      break;
    case 3:
      write_bit_in_decimal(value, index_for_bit, 1);
      *balance = 1;
      break;
  }
}

void addition_two_bits_in_long_decimal(s21_long_decimal *value,
                                       int index_for_bit, int bit_1, int bit_2,
                                       int *balance) {
  switch (*balance + bit_1 + bit_2) {
    case 0:
      write_bit_in_long_decimal(value, index_for_bit, 0);
      balance = 0;
      break;
    case 1:
      write_bit_in_long_decimal(value, index_for_bit, 1);
      *balance = 0;
      break;
    case 2:
      write_bit_in_long_decimal(value, index_for_bit, 0);
      *balance = 1;
      break;
    case 3:
      write_bit_in_long_decimal(value, index_for_bit, 1);
      *balance = 1;
      break;
  }
}

// сравнение двух decimal (без учета знака). 0 - равны, 1-больше первое число,
// 2-больше второе
int comparison_of_decimals(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  int degree_value_1 = 0;
  int degree_value_2 = 0;
  int max_degree = 0;
  reduction_greatest_common_denominator_decimals(
      &value_1, &value_2, &degree_value_1, &degree_value_2, &max_degree);

  for (int i = 95; i >= 0 && result == 0; i--) {
    int bit_1 = read_bit_in_decimal(value_1, i);
    int bit_2 = read_bit_in_decimal(value_2, i);
    if (bit_1 > bit_2) {
      result = 1;
    } else if (bit_2 > bit_1) {
      result = 2;
    }
  }

  return result;
}

// Сокращение двух decimal к наибольшему общему знаменателю
void reduction_greatest_common_denominator_decimals(s21_decimal *value_1,
                                                    s21_decimal *value_2,
                                                    int *degree_value_1,
                                                    int *degree_value_2,
                                                    int *max_degree) {
  *degree_value_1 = read_degree(value_1->bits[3]);
  *degree_value_2 = read_degree(value_2->bits[3]);
  *max_degree = *degree_value_1;
  if (*degree_value_2 > *max_degree) {
    *max_degree = *degree_value_2;
  }

  increasing_denominator_addition(value_1, max_degree, degree_value_1);
  increasing_denominator_addition(value_2, max_degree, degree_value_2);

  rounding_decimal(value_1, *max_degree, degree_value_1);
  rounding_decimal(value_2, *max_degree, degree_value_2);
}

int subtraction_decimals(s21_decimal value_1, s21_decimal value_2,
                         s21_decimal *result) {
  int result_subtraction = 0;

  int degree_value_1 = 0;
  int degree_value_2 = 0;
  int max_degree = 0;
  reduction_greatest_common_denominator_decimals(
      &value_1, &value_2, &degree_value_1, &degree_value_2, &max_degree);

  int loan = 0;
  for (int i = 0; i < 96; i++) {
    int bit_1 = read_bit_in_decimal(value_1, i);
    int bit_2 = read_bit_in_decimal(value_2, i);
    subtraction_two_bits_in_decimal(result, i, bit_1, bit_2, &loan);
  }

  write_degree_in_decimal(result, max_degree);

  return result_subtraction;
}

void subtraction_two_bits_in_decimal(s21_decimal *value, int index_for_bit,
                                     int bit_1, int bit_2, int *loan) {
  switch (bit_1 - bit_2 - *loan) {
    case -2:
      write_bit_in_decimal(value, index_for_bit, 0);
      *loan = 1;
      break;
    case -1:
      write_bit_in_decimal(value, index_for_bit, 1);
      *loan = 1;
      break;
    case 0:
      write_bit_in_decimal(value, index_for_bit, 0);
      *loan = 0;
      break;
    case 1:
      write_bit_in_decimal(value, index_for_bit, 1);
      *loan = 0;
      break;
  }
}

void subtraction_two_bits_in_long_decimal(s21_long_decimal *value,
                                          int index_for_bit, int bit_1,
                                          int bit_2, int *loan) {
  switch (bit_1 - bit_2 - *loan) {
    case -2:
      write_bit_in_long_decimal(value, index_for_bit, 0);
      *loan = 1;
      break;
    case -1:
      write_bit_in_long_decimal(value, index_for_bit, 1);
      *loan = 1;
      break;
    case 0:
      write_bit_in_long_decimal(value, index_for_bit, 0);
      *loan = 0;
      break;
    case 1:
      write_bit_in_long_decimal(value, index_for_bit, 1);
      *loan = 0;
      break;
  }
}

void reset_decimal(s21_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
}

void reset_long_decimal(s21_long_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  result->bits[4] = 0;
  result->bits[5] = 0;
  result->bits[6] = 0;
}

void reset_number_in_decimal(s21_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
}

void reset_number_in_long_decimal(s21_long_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  result->bits[4] = 0;
  result->bits[5] = 0;
}