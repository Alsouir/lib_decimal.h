CC=gcc
CFLAGS=-c -Wall  -Werror -Wextra -g -std=c11
CCTEST=gcc -fprofile-arcs -ftest-coverage

all: s21_decimal.a

s21_decimal.a: s21_decimal.o create_secondary_functions
	ar rc s21_decimal.a s21_decimal.o additional_*.o

s21_decimal.o: s21_decimal.c 
	$(CC) $(CFLAGS) s21_decimal.c

create_secondary_functions: secondary_functions/*.c
	$(CC) $(CFLAGS) secondary_functions/*.c

unit_tests.o: unit_tests.c 
	$(CC) $(CFLAGS) unit_tests.c

tests_suite: test_suite_creation_functions/*.c
	$(CC) $(CFLAGS) test_suite_creation_functions/*.c

test: clean unit_tests.o tests_suite s21_decimal.a
ifeq ($(shell uname),Linux)   
	$(CC) unit_tests.o tests_*.o s21_decimal.a -o unit_tests -lcheck -lm -lsubunit   
else   
	$(CC) unit_tests.o tests_*.o s21_decimal.a -o unit_tests -lcheck   
endif 


html_s21_decimal.a: html_s21_decimal.o html_create_secondary_functions
	ar rc html_s21_decimal.a s21_decimal.o additional_*.o

html_s21_decimal.o: s21_decimal.c 
	$(CCTEST) $(CFLAGS) s21_decimal.c

html_create_secondary_functions: secondary_functions/*.c
	$(CCTEST) $(CFLAGS) secondary_functions/*.c

html_test: unit_tests.o tests_suite html_s21_decimal.a
ifeq ($(shell uname),Linux)   
	$(CCTEST)  unit_tests.o tests_*.o html_s21_decimal.a -o unit_tests -lcheck -lm -lsubunit   
else   
	$(CCTEST)  unit_tests.o tests_*.o html_s21_decimal.a -o unit_tests -lcheck    
endif

gcov_report:clean html_test
	./unit_tests
	lcov -t "unit_tests" -o fizzbuzz.info -c -d .
	genhtml -o report fizzbuzz.info

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info *.gcov