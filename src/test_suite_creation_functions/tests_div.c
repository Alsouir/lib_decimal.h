#include "../unit_tests.h"

START_TEST(s21_div_test_1) {
  s21_decimal src1, src2, result;  // origin,
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 3;
  //   origin.bits[0] = 0b00000000000000000000000000000000;
  //   origin.bits[1] = 0b00000000000000000000000000000000;
  //   origin.bits[2] = 0b00000000000000000000000000000000;
  //   origin.bits[3] = 0b00000000000000000000000000000000;
  //   ck_assert_int_eq(origin.bits[3], result.bits[3]);
  //   ck_assert_int_eq(origin.bits[2], result.bits[2]);
  //   ck_assert_int_eq(origin.bits[1], result.bits[1]);
  //   ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_div_test_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -5;
  // src2 = 1;
  src1.bits[0] = 0b00000000000000000000000000000101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_div_test_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 5;
  // src2 = -1;
  src1.bits[0] = 0b00000000000000000000000000000101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_div_test_4) {
  s21_decimal src1, src2, origin, result;  //
  int value_type_result, value_type_origin;
  // src1 = 79,228,162,514,264,337,593,543,950,335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b10000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_div_test_5) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_div_test_6) {
  s21_decimal src1, src2, result;  // origin,
  int value_type_result, value_type_origin;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 3;
  //   origin.bits[0] = 0b00000000000000000000000000000000;
  //   origin.bits[1] = 0b00000000000000000000000000000000;
  //   origin.bits[2] = 0b00000000000000000000000000000000;
  //   origin.bits[3] = 0b00000000000000000000000000000000;
  //   ck_assert_int_eq(origin.bits[3], result.bits[3]);
  //   ck_assert_int_eq(origin.bits[2], result.bits[2]);
  //   ck_assert_int_eq(origin.bits[1], result.bits[1]);
  //   ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_div_test_7) {
  s21_decimal src1, src2, result;  // origin,
  int value_type_result, value_type_origin;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 1;
  //   origin.bits[0] = 0b11111111111111111111111111111111;
  //   origin.bits[1] = 0b11111111111111111111111111111111;
  //   origin.bits[2] = 0b11111111111111111111111111111111;
  //   origin.bits[3] = 0b00000000000000010000000000000000;
  //   ck_assert_int_eq(origin.bits[3], result.bits[3]);
  //   ck_assert_int_eq(origin.bits[2], result.bits[2]);
  //   ck_assert_int_eq(origin.bits[1], result.bits[1]);
  //   ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_div_test_8) {
  s21_decimal src1, src2, result;  // origin,
  int value_type_result, value_type_origin;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 1;
  //   origin.bits[0] = 0b00110011001100110011001100110110;
  //   origin.bits[1] = 0b00110011001100110011001100110011;
  //   origin.bits[2] = 0b10110011001100110011001100110011;
  //   origin.bits[3] = 0b00000000000000000000000000000000;
  //   ck_assert_int_eq(origin.bits[3], result.bits[3]);
  //   ck_assert_int_eq(origin.bits[2], result.bits[2]);
  //   ck_assert_int_eq(origin.bits[1], result.bits[1]);
  //   ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_div_test_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 54235441235644,123;
  // src2 = 1.2;
  // 45196201029703.4358333333333
  src1.bits[0] = 0b10110001000101100100111011011011;
  src1.bits[1] = 0b00000000110000001010111011011000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_div(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10100110000100010011110101010101;
  origin.bits[1] = 0b00111001100011001010111010000011;
  origin.bits[2] = 0b10010010000010010110101111010111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

Suite *test_div(void) {
  Suite *s = suite_create("div");
  TCase *tc = tcase_create("div");

  tcase_add_test(tc, s21_div_test_1);
  tcase_add_test(tc, s21_div_test_2);
  tcase_add_test(tc, s21_div_test_3);
  tcase_add_test(tc, s21_div_test_4);
  tcase_add_test(tc, s21_div_test_5);
  tcase_add_test(tc, s21_div_test_6);
  tcase_add_test(tc, s21_div_test_7);
  tcase_add_test(tc, s21_div_test_8);
  tcase_add_test(tc, s21_div_test_9);

  suite_add_tcase(s, tc);
  return s;
}
