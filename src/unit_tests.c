#include "unit_tests.h"

int main() {
  Suite *suite_list[] = {test_add(),
                         test_sub(),
                         test_mul(),
                         test_div(),
                         test_floor(),
                         test_round(),
                         test_truncate(),
                         test_negate(),
                         test_is_less(),
                         test_is_less_or_equal(),
                         test_is_greater(),
                         test_is_greater_or_equal(),
                         test_is_equal(),
                         test_is_not_equal(),
                         test_from_int_to_decimal(),
                         test_from_decimal_to_int(),
                         test_from_float_to_decimal(),
                         test_from_decimal_to_float(),
                         NULL};

  for (int i = 0; suite_list[i] != NULL; i++) {
    SRunner *suite_runner = srunner_create(suite_list[i]);

    srunner_run_all(suite_runner, CK_NORMAL);

    srunner_free(suite_runner);
  }
  return 0;
}