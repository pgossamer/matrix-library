CC=g++

all: clean s21_matrix_oop.a test check

s21_matrix_oop.a:
	$(CC) -c s21_matrix_oop.cpp
	@ar rcs s21_matrix_oop.a s21_matrix_oop.o

test:
	$(CC) s21_matrix_test_oop.cpp s21_matrix_oop.cpp -o test -lgtest
	./test

check: 
	cp -f ./materials/CPPLINT.cfg CPPLINT.cfg
	python3 ./materials/cpplint.py --extensions=cpp *.cpp
	CK_FORK=no leaks --atExit -- ./test

gcov_report:
	$(CC) --coverage s21_matrix_test_oop.cpp -o s21_test s21_matrix_oop.cpp -lgtest
	./s21_test
	lcov -t "s21_test" --no-external -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

clean:
	@rm -f *.o *.a *.gcda *.gcno *.info CPPLINT.cfg
	@rm -rf *.o *.a test s21_test report s21_matrix_oop *.dSYM 
