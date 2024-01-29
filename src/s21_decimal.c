#include "s21_decimal.h"

// Сложение decimal
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  reset_decimal(result);
  int result_add = 0;
  int sign_value_1 = read_bit(value_1.bits[3], 31);
  int sign_value_2 = read_bit(value_2.bits[3], 31);
  if (sign_value_1 == sign_value_2) {
    write_bit(&(result->bits[3]), 31, sign_value_1);
    result_add = prefabrication_addition(value_1, value_2, result);
    if (result_add == 1) {
      result_add = result_add + sign_value_1;
    }
  } else {
    switch (comparison_of_decimals(value_1, value_2)) {
      case 0:
        write_bit(&(result->bits[3]), 31, 0);
        break;
      case 1:
        subtraction_decimals(value_1, value_2, result);
        write_bit(&(result->bits[3]), 31, sign_value_1);
        break;
      case 2:
        subtraction_decimals(value_2, value_1, result);
        write_bit(&(result->bits[3]), 31, sign_value_2);
        break;
    }
  }
  return result_add;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  reset_decimal(result);
  int result_sub = 0;

  change_bit(&(value_2.bits[3]), 31);

  result_sub = s21_add(value_1, value_2, result);

  return result_sub;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  reset_decimal(result);
  int result_mul = 0;
  assign_sign_for_multiplication_division(value_1, value_2, result);

  result_mul = multiplication_decimals(value_1, value_2, result);

  if (result_mul == 1) {
    result_mul = result_mul + read_bit(result->bits[3], 31);
  }

  return result_mul;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  reset_decimal(result);
  int result_div = 0;

  assign_sign_for_multiplication_division(value_1, value_2, result);

  int degree_value_1 = read_degree(value_1.bits[3]);
  int degree_value_2 = read_degree(value_2.bits[3]);
  int general_degree = degree_value_1 - degree_value_2;

  int last_no_zero_in_value_1 = last_no_0_in_decimal(value_1, 95);
  int last_no_zero_in_value_2 = last_no_0_in_decimal(value_2, 95);

  if (last_no_zero_in_value_2 == -1) {
    // деление на 0;
    reset_decimal(result);
    result_div = 3;
  } else if (last_no_zero_in_value_1 != -1) {
    // Делим числа
    result_div = division_decimal(value_1, value_2, result, &general_degree);
  } else {
    reset_decimal(result);
  }

  if (result_div == 1) {
    result_div = result_div + read_bit(result->bits[3], 31);
  }

  return result_div;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int result_floor = 0;

  int dividend = reduction_to_whole_number(value, result);

  int degree = read_degree((value.bits[3]));
  int sign_decimal = read_bit(value.bits[3], 31);
  if (sign_decimal == 1 && degree > 0 && dividend != 0) {
    decimal_plus_1(result);
  }
  return result_floor;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int result_floor = 0;

  int dividend = reduction_to_whole_number(value, result);
  int degree = read_degree((value.bits[3]));

  if (dividend >= 5 && degree > 0) {
    decimal_plus_1(result);
  }
  return result_floor;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int result_floor = 0;
  reduction_to_whole_number(value, result);
  return result_floor;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int result_negate = 0;
  reset_decimal(result);
  result->bits[0] = value.bits[0];
  result->bits[1] = value.bits[1];
  result->bits[2] = value.bits[2];
  result->bits[3] = value.bits[3];
  change_bit(&(result->bits[3]), 31);
  return result_negate;
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  int result_comparison_of_decimals =
      comparison_of_decimals_with_sings(value_1, value_2);

  if (result_comparison_of_decimals == 2) {
    result = 1;
  }

  return result;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  int result_comparison = comparison_of_decimals_with_sings(value_1, value_2);
  if (result_comparison == 2 || result_comparison == 0) {
    result = 1;
  }

  return result;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  int result_comparison = comparison_of_decimals_with_sings(value_1, value_2);
  if (result_comparison == 1) {
    result = 1;
  }

  return result;
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  int result_comparison = comparison_of_decimals_with_sings(value_1, value_2);
  if (result_comparison == 1 || result_comparison == 0) {
    result = 1;
  }

  return result;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  int result_comparison = comparison_of_decimals_with_sings(value_1, value_2);
  if (result_comparison == 0) {
    result = 1;
  }

  return result;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  int result_comparison = comparison_of_decimals_with_sings(value_1, value_2);
  if (result_comparison != 0) {
    result = 1;
  }

  return result;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int result = 0;
  if (dst == NULL) {
    result = 1;
  } else {
    reset_decimal(dst);
    if (src < 0) {
      write_1_to_bit(&dst->bits[3], 31);
      src *= -1;
    }
    dst->bits[0] = src;
  }
  return result;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int result = 0;
  if (dst == NULL) {
    result = 1;
  } else {
    int degree = read_degree(src.bits[3]);
    if (degree == 0 && src.bits[1] == 0 && src.bits[2] == 0) {
      *dst = src.bits[0];
      result = 0;
    } else {
      s21_decimal result_decimal = {{0}};
      s21_truncate(src, &result_decimal);
      if (result_decimal.bits[1] == 0 && result_decimal.bits[2] == 0) {
        *dst = result_decimal.bits[0];
        result = 0;
      } else {
        result = 1;
      }
    }
    int sign = read_bit(src.bits[3], 31);
    if (sign == 1 && result == 0) {
      *dst *= -1;
    }
  }
  return result;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int result = 0;
  if (isnan(src) == 1 || dst == NULL || src < MIN_DECIMAL ||
      src > MAX_DECIMAL) {
    result = 1;
    reset_decimal(dst);
  } else {
    reset_decimal(dst);
    if (src < 0) {
      write_1_to_bit(&dst->bits[3], 31);
      src *= -1;
    }
    int length_befor_point = 0;
    char char_str[100], integer[100];
    sprintf(char_str, "%f", src);
    int i = 0;

    while (char_str[i] != '.') {
      integer[i] = char_str[i];
      length_befor_point++;
      i++;
    }
    integer[i] = '\0';
    int integer_number = atoi(integer);
    if (i > 7) {
      dst->bits[0] = integer_number / pow(10, i - 7);
    }
    write_float_in_decimal(src, integer_number, length_befor_point, char_str,
                           integer, i, dst);
  }
  return result;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int result = 0;
  if (dst == NULL) {
    result = 1;
  } else {
    int degree = read_degree(src.bits[3]);
    float number = 0;

    for (int j = 0; j < 96; j++) {
      number += read_bit_in_decimal(src, j) * pow(2, j);
    }

    *dst = number * (1 / pow(10, degree));
    int sign = read_bit(src.bits[3], 31);
    if (sign == 1) {
      *dst *= -1;
    }
  }
  return result;
}
