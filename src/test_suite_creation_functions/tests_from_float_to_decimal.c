#include "../unit_tests.h"

START_TEST(s21_float_to_decimal_test_1) {
  s21_decimal val;
  s21_from_float_to_decimal(0.03F, &val);

  ck_assert_int_eq(val.bits[0], 3000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 524288);
  s21_from_float_to_decimal(127.1234F, &val);
  ck_assert_int_eq(val.bits[0], 1271234);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 262144);
}
END_TEST

START_TEST(s21_float_to_decimal_test_2) {
  s21_decimal val;
  s21_from_float_to_decimal(22.14836E+03F, &val);
  ck_assert_int_eq(val.bits[0], 2214836);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 131072);
}
END_TEST

START_TEST(s21_float_to_decimal_test_3) {
  s21_decimal val;
  s21_from_float_to_decimal(1.02E+09F, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_float_to_decimal_test_4) {
  s21_decimal val;
  float a = 1.0F / 0.0F;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_float_to_decimal_test_5) {
  s21_decimal val;
  float a = -1.0F / 0.0F;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_float_to_decimal_test_6) {
  s21_decimal val;
  float a = NAN;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_float_to_decimal_test_7) {
  s21_decimal val;
  s21_from_float_to_decimal(0.0F, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

Suite *test_from_float_to_decimal(void) {
  Suite *s = suite_create("float_to_decimal");
  TCase *tc = tcase_create("float_to_decimal");

  tcase_add_test(tc, s21_float_to_decimal_test_1);
  tcase_add_test(tc, s21_float_to_decimal_test_2);
  tcase_add_test(tc, s21_float_to_decimal_test_3);
  tcase_add_test(tc, s21_float_to_decimal_test_4);
  tcase_add_test(tc, s21_float_to_decimal_test_5);
  tcase_add_test(tc, s21_float_to_decimal_test_6);
  tcase_add_test(tc, s21_float_to_decimal_test_7);

  suite_add_tcase(s, tc);
  return s;
}