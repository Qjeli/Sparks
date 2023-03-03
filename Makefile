CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -std=c11
NAME = s21_decimal.a test
TEST_LIBS = -lcheck -lrt -lm -lpthread -lsubunit
OBJECTS = s21_another.o s21_arithmetic.o s21_comparison.o s21_converters.o s21_decimal.o
SOURSES = s21_another.c s21_arithmetic.c s21_comparison.c s21_converters.c s21_decimal.c
#TEST_OBJECTS = test_another.o test_arithmetic.o test_comparison.o test_converters.o test_decimal.o
TEST_OBJECT = test_arithmetic.o

.PHONY: all clean test s21_decimal.a gcov_report

all: $(NAME)

fulltest: $(TEST_OBJECT) s21_decimal.a $(OBJECTS)
	$(CC) $(OBJECTS) $(TEST_OBJECT) s21_decimal.a $(TEST_LIBS) -o fulltest
	./fulltest

test: s21_decimal_test.c $(SOURSES)
	$(CC) $(CC_FLAGS) s21_decimal_test.c $(SOURSES) -lm -o test
	./test

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main
	./main

s21_decimal.o: s21_decimal.c
	$(CC) $(CC_FLAGS) -c s21_decimal.c -g

s21_another.o: s21_another.c
	$(CC) $(CC_FLAGS) -c s21_another.c -g

s21_arithmetic.o: s21_arithmetic.c
	$(CC) $(CC_FLAGS) -c s21_arithmetic.c -g

s21_comparison.o: s21_comparison.c
	$(CC) $(CC_FLAGS) -c s21_comparison.c -g

s21_converters.o: s21_converters.c
	$(CC) $(CC_FLAGS) -c s21_converters.c -g

test_another.o: test_another.c
	$(CC) $(CC_FLAGS) -c test_another.c

test_arithmetic.o: test_arithmetic.c
	$(CC) $(CC_FLAGS) -c test_arithmetic.c

test_comparison.o: test_comparison.c
	$(CC) $(CC_FLAGS) -c test_comparison.c

test_converters.o: test_converters.c
	$(CC) $(CC_FLAGS) -c test_converters.c

test_decimal.o: test_decimal.c
	$(CC) $(CC_FLAGS) -c test_decimal.c

s21_decimal_test.o: s21_decimal_test.c
	$(CC) $(CC_FLAGS) -c s21_decimal_test.c

gcov_report: s21_decimal.a 
	$(CC) $(CC_FLAGS) --coverage s21_decimal_test.c $(SOURSES) s21_decimal.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

check: s21_decimal.a
	cppcheck *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	$(CC) s21_decimal_test.c s21_decimal.a -lcheck
	$(CC) $(CC_FLAGS) -c s21_decimal_test.c -o test.o
	$(CC) test.o s21_decimal.a $(TEST_LIBS) -o test
	CK_FORK=no leaks --atExit -- ./test

s21_decimal.a: $(OBJECTS)
	$(CC) -c $(SOURSES)
	ar rcs s21_decimal.a $(OBJECTS)

clean:
	rm -rf *.o fulltest test s21_decimal.a s21_decimal_test.c.gcov s21_decimal.c.gcov s21_decimal_test.gc* s21_decimal.gc* report gcov_report.info CPPLINT.cfg a.out gcov_test*

lo:
	for i in `seq 100 $(OP)`;	do ./test; done;

vg: s21_decimal.a
	CK_FORK=no valgrind --tool=memcheck ./test
	 
lik: s21_decimal.a
	CK_FORK=no leaks -atExit -- ./test

install lcov:
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov
