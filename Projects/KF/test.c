#include <stdio.h>
#include <stdlib.h>

// Função para imprimir a matriz
void printMatrix(int rows, int cols, double matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Função para calcular a transposta da matriz
void transposeMatrix(int rows, int cols, double original[rows][cols], double transposed[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = original[i][j];
        }
    }
}

int main() {
    // Definir as dimensões da matriz
    int rows = 2;
    int cols = 2;

    // Matriz original
    double A[2][2] = {
        {1, 2},
        {3, 4}
    };

    // Matriz para armazenar a transposta
    double A_T[2][2];

    // Calcular a transposta
    transposeMatrix(rows, cols, A, A_T);

    // Imprimir a matriz transposta
    printf("Matriz transposta:\n");
    printMatrix(cols, rows, A_T);

    return 0;
}