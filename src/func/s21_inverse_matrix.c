#include "../s21_matrix.h"

// Обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK; // Изначально предполагаем, что все в порядке
  double determ = 0; // Переменная для хранения определителя матрицы

  // Проверка корректности входных данных
  if (!(A && result && A->matrix)) {
    status = INCORRECT_MATRIX; // Некорректные указатели или пустая матрица
  } else if (A->columns != A->rows) {
    status = CALCULATION_ERROR; // Матрица не квадратная, обратная матрица не существует
  } 
  // Вычисляем определитель и проверяем, что он не равен нулю (матрица невырожденная)
  else if (s21_determinant(A, &determ) != OK || fabs(determ) < 1e-7) {
    status = CALCULATION_ERROR; // Определитель слишком мал или равен нулю — обратная матрица не существует
  } 
  else {
    // Создаем матрицу для результата с теми же размерами
    if (!(status = s21_create_matrix(A->columns, A->rows, result))) {
      // Обработка случая, когда матрица 1x1
      if (A->rows == 1) {
        result->matrix[0][0] = 1 / A->matrix[0][0]; // Обратная к 1x1 — просто 1/элемент
      } else {
        matrix_t first = {0}, second = {0}; // Вспомогательные матрицы для вычислений

        // Вычисляем матрицу алгебраических дополнений
        s21_calc_complements(A, &first);

        // Транспонируем матрицу дополнений
        s21_transpose(&first, &second);

        // Заполняем матрицу результата путем деления элементов транспонированной матрицы на определитель
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->rows; j++) {
            result->matrix[i][j] = second.matrix[i][j] / determ;
          }
        }

        // Очищаем временные матрицы
        s21_remove_matrix(&first);
        s21_remove_matrix(&second);
      }
    }
  }

  return status; // Возвращаем статус результата
}

