#include "../unit_tests.h"

START_TEST(s21_is_not_equal_test_1) {
  s21_decimal src1, src2;
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
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 0;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_2) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 0 / 10^x;
  // src2 = 0 / 10;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100100000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 0;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_3) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 11 / 10^x;
  // src2 = 11 / 10;
  src1.bits[0] = 0b00000000000000000000000000001011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100100000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_4) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 11 / 10^x;
  // src2 = 11 ;
  src1.bits[0] = 0b00000000000000000000000000001011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100100000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_5) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 11 ;
  // src2 = 11 / 10 ^x;
  src1.bits[0] = 0b00000000000000000000000000001011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100100000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_6) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 13 ;
  // src2 = 8;
  src1.bits[0] = 0b00000000000000000000000000001101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_7) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 13 / 10^ x;
  // src2 = 8;
  src1.bits[0] = 0b00000000000000000000000000001101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100100000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_8) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 13 / 10^ x;
  // src2 = 8 / 10^y;
  src1.bits[0] = 0b00000000000000000000000000001101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100100000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_9) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 13 ;
  // src2 = 8 / 10^y;
  src1.bits[0] = 0b00000000000000000000000000001101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_10) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 130/10 ;
  // src2 = 13;
  src1.bits[0] = 0b00000000000000000000000010000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 0;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_11) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 13;
  // src2 = 130/10;
  src1.bits[0] = 0b00000000000000000000000000001101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000010000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 0;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_12) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 8;
  // src2 = 13;
  src1.bits[0] = 0b00000000000000000000000000001000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_13) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 8;
  // src2 = 13 / 10;
  src1.bits[0] = 0b00000000000000000000000000001000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_14) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 8 / 10^x;
  // src2 = 13 / 10;
  src1.bits[0] = 0b00000000000000000000000000001000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010010000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_15) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 8 / 10^x;
  // src2 = 13;
  src1.bits[0] = 0b00000000000000000000000000001000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_16) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 8000 / 1000;
  // src2 = 800 / 100;
  src1.bits[0] = 0b00000000000000000001111101000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000110000000000000000;
  src2.bits[0] = 0b00000000000000000000001100100000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 0;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_17) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = -13;
  // src2 = 8;
  src1.bits[0] = 0b00000000000000000000000000001101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_18) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = -13;
  // src2 = -8;
  src1.bits[0] = 0b00000000000000000000000000001101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_19) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = -13;
  // src2 = 13;
  src1.bits[0] = 0b00000000000000000000000000001101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_is_not_equal_test_20) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 13;
  // src2 = -13;
  src1.bits[0] = 0b00000000000000000000000000001101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_is_not_equal(src1, src2);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

Suite *test_is_not_equal(void) {
  Suite *s = suite_create("is_not_equal");
  TCase *tc = tcase_create("is_not_equal");

  tcase_add_test(tc, s21_is_not_equal_test_1);
  tcase_add_test(tc, s21_is_not_equal_test_2);
  tcase_add_test(tc, s21_is_not_equal_test_3);
  tcase_add_test(tc, s21_is_not_equal_test_4);
  tcase_add_test(tc, s21_is_not_equal_test_5);
  tcase_add_test(tc, s21_is_not_equal_test_6);
  tcase_add_test(tc, s21_is_not_equal_test_7);
  tcase_add_test(tc, s21_is_not_equal_test_8);
  tcase_add_test(tc, s21_is_not_equal_test_9);
  tcase_add_test(tc, s21_is_not_equal_test_10);
  tcase_add_test(tc, s21_is_not_equal_test_11);
  tcase_add_test(tc, s21_is_not_equal_test_12);
  tcase_add_test(tc, s21_is_not_equal_test_13);
  tcase_add_test(tc, s21_is_not_equal_test_14);
  tcase_add_test(tc, s21_is_not_equal_test_15);
  tcase_add_test(tc, s21_is_not_equal_test_16);
  tcase_add_test(tc, s21_is_not_equal_test_17);
  tcase_add_test(tc, s21_is_not_equal_test_18);
  tcase_add_test(tc, s21_is_not_equal_test_19);
  tcase_add_test(tc, s21_is_not_equal_test_20);

  suite_add_tcase(s, tc);
  return s;
}
