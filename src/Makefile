FLAGS= -lm -lsubunit -lcheck -lpthread 
CC=gcc -Wall -Wextra -Werror -std=c11
FUNC_FILES_C=s21_math.c
FUNC_FILES_O=s21_math.o
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_math.a
GLFLAGS=--coverage
OPEN_CMD = xdg-open
ADD_LIB = -lcheck -lm -lpthread -lrt -lsubunit


all: s21_math.a


build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C)

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

s21_math.a:
	$(CC) $(FLAGS) $(GCOVFLAGS) -c $(FUNC_FILES_C)
	make build_library
	rm -rf *.o

test: s21_math.a
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) tests.c -L. s21_math.a  -o tests $(ADD_LIB)
	./tests

gcov_report: clean build_object_files build_library test
	lcov -o tests.info -c -d .  
	genhtml -o report tests.info
	$(OPEN_CMD) report/index.html
	make clean

 
clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.a
	rm -rf *.info
	rm -rf *tests

rebuild:
	make clean
	make