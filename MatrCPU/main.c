#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define EPS 0.000001 


double** CreateMatrix(unsigned int n)
{
    srand(time(NULL));
    double** matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(2*n * sizeof(double));
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
        for (int j = 0; j <2*n; j++) {
            if (j < n) matrix[i][j] = rand() % 99999;
            else
            {
                if (i + n == j) matrix[i][j] = 1;
                else matrix[i][j] = 0;
            }
        }
    }
}

void SRowMatrix(unsigned int row, double** matrix, unsigned int n)
{
    for (int i=0; i < n; i++)
    {
        if (i != row)
        {
            double k = matrix[i][row] / matrix[row][row];
            for (int j = 0; j < 2 * n; j++)
            {
                matrix[i][j] -= k * matrix[row][j];
            }
        }
    }
}

void SAllMatrix(double** matrix, unsigned int n)
{
    for (int z = 0; z < n; z++)
    {
        SRowMatrix(z, matrix, n);
        //if (z % 50 == 0)
        //{
        //    system("cls");
        //    puts("Wait.");
        //}
        //if (z % 101 == 0)
        //{
        //    system("cls");
        //    puts("Wait..");
        //}
        //if (z % 151 == 0)
        //{
        //    system("cls");
        //    puts("Wait...");
        //}

        
    }
}


void PrintMatrixRev(double** matrix, unsigned int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            printf("%.6f", matrix[i][j]);
        }
        printf("\n");
    }
}

void PrintMatrixOrig(double** matrix, unsigned int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", (int)matrix[i][j]);
        }
        printf("\n");
    }
}

void GoToOneRows(double** matrix, unsigned int n)
{
    for (int i = 0; i < n; i++)
    {
        double k = matrix[i][i];
        matrix[i][i] /= k;
        for (int j = n; j < 2 * n; j++)
        {
            matrix[i][j] /= k;
        }
    }
}

int main(void)
{
    int n = 1000;
    double** M = CreateMatrix(n);
    Inic(M, n);
    clock_t start, end;
    start = clock();
    //PrintMatrixOrig(M, 1000);
    SAllMatrix(M, n);
    GoToOneRows(M, n);
    end = clock();
    freeMatrix(n, M);
    double time = (((double)(end-start))*1000) / CLOCKS_PER_SEC;

    /*PrintMatrixRev(M, 1000);*/
    /*system("cls");*/
    printf("Ready!!! Process took: ");
    printf("%d ms", (int)time);
    
}