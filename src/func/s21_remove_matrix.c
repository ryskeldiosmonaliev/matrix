#include "../s21_matrix.h"

// Очистка матриц
void s21_remove_matrix(matrix_t *A) {
  // Проверка на корректность указателя и наличия выделенной памяти
  if (A && A->matrix) {
    // Очищаем память, выделенную для строк матрицы
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);  // Освобождаем память для каждой строки
    }
    // Очищаем память, выделенную для массива указателей на строки
    free(A->matrix);
    
    // Обнуляем указатель на матрицу и размеры
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

