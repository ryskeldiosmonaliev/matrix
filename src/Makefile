CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
OS=$(shell uname)
ifeq ($(OS), Darwin)
	CHECK = -lcheck -lpthread -lm
else
	CHECK = -lcheck -lpthread -lm -lsubunit
endif

# Список исходных файлов
SOURCE = func/s21_calc_complements.c func/s21_determinant.c func/s21_inverse_matrix.c func/s21_mult_number.c func/s21_sub_matrix.c func/s21_transpose.c \
	func/s21_create_matrix.c func/s21_eq_matrix.c func/s21_mult_matrix.c func/s21_remove_matrix.c func/s21_sum_matrix.c

# Файл с тестами
TESTS = Tests.c

# Создание объектов из исходников
OBJECTS = $(SOURCE:.c=.o)

# Цели, которые должны выполняться всегда
.PHONY: all clean test rebuild gcov_report val style

# Цель по умолчанию
all: clean s21_matrix.a test

# Создание статической библиотеки
s21_matrix.a: $(OBJECTS)
	ar rcs s21_matrix.a $(OBJECTS)
	ranlib s21_matrix.a

# Сборка и запуск тестов
test: $(OBJECTS) $(TESTS:.c=.o) s21_matrix.a
	$(CC) $(CFLAGS) $(TESTS) s21_matrix.a $(CHECK) -o test $(shell pkg-config --cflags --libs check)
	./test

# Отчёт по покрытию кода с использованием gcov
gcov_report: clean s21_matrix.a
	$(CC) $(CFLAGS) --coverage $(SOURCE) $(TESTS) s21_matrix.a $(CHECK) -o test $(shell pkg-config --cflags --libs check)
	./test
	mkdir -p report
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html
	rm -rf *.gcda *.gcno *.out

# Очистка временных файлов
clean:
	-rm -rf *.o func/*.o *.a test *.gcno *.gcda test.info report


# Пересборка проекта
rebuild: clean all

# Проверка утечек памяти с помощью valgrind
val: clean test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test

# Проверка стиля кода
style:
	clang-format -n func/*.c *.c
