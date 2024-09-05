#include "../s21_matrix.h"

// Умножение матрицы на число
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;  // Изначально предполагаем успешное выполнение

  // Проверка корректности указателей на матрицы
  if (!(A && result)) {
    status = INCORRECT_MATRIX;  // Некорректные указатели
  } 
  // Создание матрицы результата с такими же размерами, как у матрицы A
  else if (!(status = s21_create_matrix(A->rows, A->columns, result))) {
    // Перемножаем каждый элемент матрицы A на число number
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return status;  // Возвращаем статус операции
}

