#include "../s21_matrix.h"

// Создание матриц
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = INCORRECT_MATRIX; // Изначально предполагаем, что матрица некорректна

  // Проверка, что количество строк и столбцов больше 0 и указатель на матрицу не равен NULL
  if (rows > 0 && columns > 0 && result != NULL) {
    // Выделяем память под массив указателей на строки
    if ((result->matrix = (double **)calloc(rows, sizeof(double *)))) {
      result->rows = rows; // Сохраняем количество строк
      result->columns = columns; // Сохраняем количество столбцов

      // Цикл по строкам: выделяем память для каждой строки (массив столбцов)
      for (int i = 0; i < rows; i++) {
        if ((result->matrix[i] = (double *)calloc(columns, sizeof(double)))) {
          status = OK; // Если память успешно выделена, считаем матрицу корректной
          
          // Инициализируем все элементы матрицы нулями
          for (int j = 0; j < columns; j++) {
            result->matrix[i][j] = 0;
          }

        } else { 
          // Если не удалось выделить память для одной из строк
          // Освобождаем уже выделенную память для предыдущих строк
          for (int q = 0; q < i; q++) {
            free(result->matrix[q]); // Освобождаем каждую строку
          }
          free(result->matrix); // Освобождаем сам массив указателей на строки
          break; // Прекращаем цикл, так как произошла ошибка
        }
      }
    }
  }

  return status; // Возвращаем статус выполнения
}
