#include "../s21_matrix.h"

// Сложение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;  // Изначально предполагаем успешное выполнение

  // Проверка корректности указателей на матрицы
  if (!(A && B && result)) {
    status = INCORRECT_MATRIX;  // Один или несколько указателей некорректны
  } 
  // Проверка совпадения размеров матриц A и B
  else if (!(A->rows == B->rows && A->columns == B->columns)) {
    status = CALCULATION_ERROR;  // Размеры матриц не совпадают
  } 
  // Создание матрицы результата с теми же размерами, что и у A
  else if (!(status = s21_create_matrix(A->rows, A->columns, result))) {
    // Выполнение сложения матриц
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }

  return status;  // Возвращаем статус операции
}

