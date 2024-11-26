#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define EPS 0.000001 


double** CreateMatrix(unsigned int n)
{
    srand(time(NULL));
    double** matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(/*2**/n * sizeof(double));
    }

    return matrix;
}


void freeMatrix(unsigned int n, double** matrix)
{
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void Inic(double** matrix, unsigned int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j </*2**/n; j++) {
            if (j < n) matrix[i][j] = 10 + rand() % 90;
            else
            {
                if (i + n == j) matrix[i][j] = 1;
                else matrix[i][j] = 0;
            }
        }
    }
}


void PrintMatrix(double** matrix, unsigned int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < /*2 **/ n; j++) {
            printf("%.6f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    double** M = CreateMatrix(3);
    Inic(M, 3);
    PrintMatrix(M, 3);
    double** A= CreateMatrix(3);
    PrintMatrix(A, 3);
    freeMatrix(3,M);
    freeMatrix(3, A);
}