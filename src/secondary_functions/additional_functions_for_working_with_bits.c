#include "../s21_decimal.h"

int read_degree(int bits_info) {
  int result = 0;

  for (int i = 16, index = 0; i <= 23; i++, index++) {
    result = result + read_bit(bits_info, i) * pow(2, index);
  }
  return result;
}

void write_degree_in_decimal(s21_decimal *bits_info, int degree) {
  for (int i = 23, index = 7; i > 15; i--, index--) {
    write_bit(&(bits_info->bits[3]), i, read_bit(degree, index));
  }
}

// Прочитать i-ый бит в decimal;
int read_bit_in_decimal(s21_decimal bits_info, int i) {
  return read_bit(bits_info.bits[i / 32], i - 32 * (i / 32));
}

// Прочитать i-ый бит в long_decimal;
int read_bit_in_long_decimal(s21_long_decimal bits_info, int i) {
  return read_bit(bits_info.bits[i / 32], i - 32 * (i / 32));
}

// Прочитать i-ый бит;
int read_bit(int bits_info, int i) { return ((bits_info >> i) & 1u); }

// изменить бит на противоположный
void change_bit(int *bits, int index_bit) {
  if (((*bits >> index_bit) & 1u) == 1) {
    write_0_to_bit(bits, index_bit);
  } else {
    write_1_to_bit(bits, index_bit);
  }
}

// изменить бит на противоположный
void change_bit_in_decimal(s21_decimal *bits, int index_bit) {
  if (read_bit_in_decimal(*bits, index_bit) == 1) {
    write_bit_in_decimal(bits, index_bit, 0);
  } else {
    write_bit_in_decimal(bits, index_bit, 1);
  }
}

void change_bit_in_long_decimal(s21_long_decimal *bits, int index_bit) {
  if (read_bit_in_long_decimal(*bits, index_bit) == 1) {
    write_bit_in_long_decimal(bits, index_bit, 0);
  } else {
    write_bit_in_long_decimal(bits, index_bit, 1);
  }
}

// присвоить значение биту в decimal
void write_bit_in_decimal(s21_decimal *bits, int index_bit, int new_value) {
  write_bit(&(bits->bits[index_bit / 32]), index_bit - (index_bit / 32) * 32,
            new_value);
}

// присвоить значение биту в long_decimal
void write_bit_in_long_decimal(s21_long_decimal *bits, int index_bit,
                               int new_value) {
  write_bit(&(bits->bits[index_bit / 32]), index_bit - (index_bit / 32) * 32,
            new_value);
}

// присвоить значение биту
void write_bit(int *bits, int index_bit, int new_value) {
  if (new_value == 0) {
    write_0_to_bit(bits, index_bit);
  } else {
    write_1_to_bit(bits, index_bit);
  }
}

// Установить значение 0 у бита
void write_0_to_bit(int *bits, int index_bit) {
  *bits = *bits & (~(1 << index_bit));
}

// Установить значение 1 у бита
void write_1_to_bit(int *bits, int index_bit) {
  *bits = *bits | (1 << index_bit);
}
