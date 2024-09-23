#include <stdio.h>
#include <stdlib.h>
// Function to allocate memory for a matrix
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc((size_t)rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc((size_t)cols * sizeof(int));
    }
    return matrix;
}
// Function to deallocate memory for a matrix
void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
// Function to multiply two matrices
int** multiplyMatrices(int** matrixA, int** matrixB, int rowsA, int colsA, int colsB) {
    int** result = allocateMatrix(rowsA, colsB);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}
// Function to print a matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int rowsA, colsA, rowsB, colsB;
// Getting Matrix Size for Memory Allocation 
    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &rowsA);
    printf("Enter the number of columns for matrix A: ");
    scanf("%d", &colsA);
    printf("Enter the number of rows for matrix B: ");
    scanf("%d", &rowsB);
    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &colsB);

    if (colsA != rowsB) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }
    int** matrixA = allocateMatrix(rowsA, colsA);
    int** matrixB = allocateMatrix(rowsB, colsB);
    int** result = NULL;
// User-input for Matrix A
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
// User-input for Matrix A
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }
    result = multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB);
    printf("Matrix A:\n");
    printMatrix(matrixA, rowsA, colsA);
    printf("Matrix B:\n");
    printMatrix(matrixB, rowsB, colsB);
// Printing result
    printf("The Result of Matrix Multiplication is:-\n");
    printMatrix(result, rowsA, colsB);
    deallocateMatrix(matrixA, rowsA);
    deallocateMatrix(matrixB, rowsB);
    deallocateMatrix(result, rowsA);
    return 0;
}


