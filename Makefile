CC=g++

all: clean _matrix_oop.a test check

_matrix_oop.a:
	$(CC) -c _matrix_oop.cpp
	@ar rcs _matrix_oop.a _matrix_oop.o

test:
	$(CC) _matrix_test_oop.cpp _matrix_oop.cpp -o test -lgtest
	./test

check: 
	cp -f ./materials/CPPLINT.cfg CPPLINT.cfg
	python3 ./materials/cpplint.py --extensions=cpp *.cpp
	CK_FORK=no leaks --atExit -- ./test

gcov_report:
	$(CC) --coverage _matrix_test_oop.cpp -o _test _matrix_oop.cpp -lgtest
	./_test
	lcov -t "_test" --no-external -o _test.info -c -d .
	genhtml -o report _test.info
	open ./report/index.html

clean:
	@rm -f *.o *.a *.gcda *.gcno *.info CPPLINT.cfg
	@rm -rf *.o *.a test _test report _matrix_oop *.dSYM 
