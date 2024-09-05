#include "../s21_matrix.h"

// Умножение двух матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;  // Изначально предполагаем успешное выполнение операции

  // Проверка корректности входных данных
  if (!(A && B && result)) {
    status = INCORRECT_MATRIX;  // Некорректные указатели
  } 
  // Проверка, можно ли перемножать матрицы (число столбцов A должно совпадать с числом строк B)
  else if (A->columns != B->rows) {
    status = CALCULATION_ERROR;  // Невозможно перемножить матрицы с такими размерами
  } 
  // Создание матрицы результата с размерами A->rows x B->columns
  else if (!(status = s21_create_matrix(A->rows, B->columns, result))) {
    // Цикл для вычисления произведения матриц
    for (int i = 0; i < A->rows; i++) {  // Перебираем строки матрицы A
      for (int j = 0; j < B->columns; j++) {  // Перебираем столбцы матрицы B
        for (int z = 0; z < B->rows; z++) {  // Перебираем элементы строки A и столбца B
          result->matrix[i][j] += A->matrix[i][z] * B->matrix[z][j];  // Суммируем произведение элементов
        }
      }
    }
  }

  return status;  // Возвращаем статус операции
}

