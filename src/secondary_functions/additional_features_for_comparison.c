#include "../s21_decimal.h"

int read_the_comparison_sign(s21_decimal value) {
  int result = read_bit(value.bits[3], 31);
  int last_no_zero = last_no_0_in_decimal(value, 95);
  if (last_no_zero == -1) {
    result = 0;
  }
  return result;
}

int comparison_of_decimals_with_sings(s21_decimal value_1,
                                      s21_decimal value_2) {
  int sing_1 = read_the_comparison_sign(value_1);
  int sing_2 = read_the_comparison_sign(value_2);
  int result_comparison_of_decimals = comparison_of_decimals(value_1, value_2);

  if (result_comparison_of_decimals == 0) {
    if (sing_1 == 1 && sing_2 == 0) {
      result_comparison_of_decimals = 2;
    } else if (sing_1 == 0 && sing_2 == 1) {
      result_comparison_of_decimals = 1;
    }
  } else if (result_comparison_of_decimals == 1) {
    if (sing_1 == 1) {
      result_comparison_of_decimals = 2;
    }
  } else {
    if (sing_2 == 1) {
      result_comparison_of_decimals = 1;
    }
  }

  return result_comparison_of_decimals;
}