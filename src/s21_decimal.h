#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s21_decimal {
  int bits[4];
} s21_decimal;

typedef struct s21_long_decimal {
  int bits[7];
} s21_long_decimal;

#define MAX_DECIMAL powl(2.0, 96) - 1
#define MIN_DECIMAL -1 * MAX_DECIMAL

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Функции для работы с битами
int read_degree(int bits_info);
void write_degree_in_decimal(s21_decimal *bits_info, int degree);

int read_bit_in_decimal(s21_decimal bits_info, int i);            // !!!!!!!!!
int read_bit_in_long_decimal(s21_long_decimal bits_info, int i);  // !!!!!!!!!

int read_bit(int bits_info, int i);
void change_bit(int *bits, int index_bit);

void change_bit_in_decimal(s21_decimal *bits, int index_bit);  // !!!!!!!!!
void change_bit_in_long_decimal(s21_long_decimal *bits,
                                int index_bit);  // !!!!!!!!!
void write_bit_in_decimal(s21_decimal *bits, int index_bit,
                          int new_value);  // !!!!!!!!!
void write_bit_in_long_decimal(s21_long_decimal *bits, int index_bit,
                               int new_value);  // !!!!!!!!!

void write_bit(int *bits, int index_bit, int new_value);
void write_0_to_bit(int *bits, int index_bit);
void write_1_to_bit(int *bits, int index_bit);

// Вспомогательные функции для арифметических действий
int prefabrication_addition(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal *result);
int addition(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void increasing_denominator_addition(s21_decimal *value, int *max_degree,
                                     int *degree_value);
void rounding_decimal(s21_decimal *value, int min_degree, int *degree_value);

void dividing_decimal_10(s21_decimal *value);  // !!!!!!!!!
void dividing_long_decimal_10_no_round(s21_long_decimal *value,
                                       int *dividend);  // !!!!!!!!!

void write_result_division_decimal_by_10(s21_decimal *value,
                                         s21_decimal result_decimal,
                                         int index_bit_in_result);  // !!!!!!!!!
void write_result_division_long_decimal_by_10(
    s21_long_decimal *value, s21_long_decimal result_decimal,
    int index_bit_in_result);                                    // !!!!!!!!!
void round_decimal(s21_decimal *value, int remainder_division);  // !!!!!!!!!
void round_long_decimal(s21_long_decimal *value,
                        int remainder_division);              // !!!!!!!!!
void decimal_plus_1(s21_decimal *value);                      // !!!!!!!!!
void long_decimal_plus_1(s21_long_decimal *value);            // !!!!!!!!!
int multiplying_decimal_by_10(s21_decimal *value);            // !!!!!!!!!
int multiplying_long_decimal_by_10(s21_long_decimal *value);  // !!!!!!!!!
void addition_two_bits_in_decimal(s21_decimal *value, int index_for_bit,
                                  int bit_1, int bit_2,
                                  int *balance);  // !!!!!!!!!
void addition_two_bits_in_long_decimal(s21_long_decimal *value,
                                       int index_for_bit, int bit_1, int bit_2,
                                       int *balance);  // !!!!!!!!!

int comparison_of_decimals(s21_decimal value_1, s21_decimal value_2);
void reduction_greatest_common_denominator_decimals(s21_decimal *value_1,
                                                    s21_decimal *value_2,
                                                    int *degree_value_1,
                                                    int *degree_value_2,
                                                    int *max_degree);
int subtraction_decimals(s21_decimal value_1, s21_decimal value_2,
                         s21_decimal *result);

void subtraction_two_bits_in_decimal(s21_decimal *value, int index_for_bit,
                                     int bit_1, int bit_2,
                                     int *loan);  // !!!!!!!!!
void subtraction_two_bits_in_long_decimal(s21_long_decimal *value,
                                          int index_for_bit, int bit_1,
                                          int bit_2, int *loan);  // !!!!!!!!!
void reset_decimal(s21_decimal *result);                          // !!!!!!!!!
void reset_long_decimal(s21_long_decimal *result);                // !!!!!!!!!
void reset_number_in_decimal(s21_decimal *result);                // !!!!!!!!!
void reset_number_in_long_decimal(s21_long_decimal *result);      // !!!!!!!!!

// Дополнительные вспомогательные функции для умножения/деления
int last_no_0_in_decimal(s21_decimal value, int last_index);  // !!!!!!!!!
int last_no_0_in_long_decimal(s21_long_decimal value,
                              int last_index);  // !!!!!!!!!

int multiplication_decimals(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal *result);
int addition_to_multiply(s21_decimal *value_1, s21_decimal *value_2,
                         s21_decimal *result, int *general_degree);
int comparison_of_digits_of_long_decimals(s21_long_decimal value_1,
                                          s21_long_decimal value_2);
void assign_sign_for_multiplication_division(s21_decimal value_1,
                                             s21_decimal value_2,
                                             s21_decimal *result);

// Дополнительные вспомогательные функции для деления
int division_decimal(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result, int *general_degree);
int division_by_column(s21_long_decimal value_1, s21_long_decimal value_2,
                       s21_long_decimal *result, int *general_degree);
void add_bit_in_long_decimal(s21_long_decimal *value, int bit);
void reduce_long_decimal(s21_long_decimal *value_1, s21_long_decimal value_2);
void round_quotient_in_long_decimal(s21_long_decimal *result,
                                    s21_long_decimal balance,
                                    s21_long_decimal value_2);
void reduction_long_decinal_by_10_without_remainder(int *general_degree,
                                                    s21_long_decimal *result);

// Дополнительные вспомогательные функции для округления
int reduction_to_whole_number(s21_decimal value, s21_decimal *result);
int cycle_divide_decimal_by_10(s21_decimal value, s21_decimal *result_decimal,
                               int *index_bit_in_result);
int cycle_divide_long_decimal_by_10(s21_long_decimal value,
                                    s21_long_decimal *result_decimal,
                                    int *index_bit_in_result);

// Дополнительные функции для сравнения
int read_the_comparison_sign(s21_decimal value);
int comparison_of_decimals_with_sings(s21_decimal value_1, s21_decimal value_2);

// Дополнительные вспомогательные функции для преоброзователей
void write_float_in_decimal(float src, int integer_number,
                            int length_befor_point, char char_str[100],
                            char integer[100], int i, s21_decimal *dst);
void from_decimal_to_long_decimal(s21_decimal value, s21_long_decimal *result);
int from_long_decimal_to_decimal(s21_long_decimal value, int degree,
                                 s21_decimal *result);

#endif
