#include "../s21_matrix.h"

// Транспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = OK;  // Изначально предполагаем успешное выполнение

  // Проверка корректности указателей на матрицы
  if (!(A && result)) {
    status = INCORRECT_MATRIX;  // Один или несколько указателей некорректны
  } 
  // Создание матрицы результата с размерами, соответствующими транспонированной матрице
  else if (!(status = s21_create_matrix(A->columns, A->rows, result))) {
    // Выполнение транспонирования матрицы
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];  // Перенос значения из A в результат
      }
    }
  }

  return status;  // Возвращаем статус операции
}

