#include "matrix_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void removeMatrix(Matrix *mat){
    free(mat);   
}
double getEntry(Matrix *matrix, int row, int column){
    return *(matrix->entry + row * matrix->column + column);
}
void setEntry(Matrix *matrix, int row, int column, double value){
    *(matrix->entry + row * matrix->column + column) = value;
}
Matrix *initMatrix(int row, int column){
    Matrix *ret = (Matrix *)malloc(sizeof(Matrix));
    if(ret == NULL){
        perror("malloc");
        exit(1);
    }
    ret->entry = (double *)malloc(sizeof(double)*row*column);
    if(ret->entry == NULL){
        perror("malloc");
        exit(1);
    }
    ret->row = row;
    ret->column = column;
    memset(ret->entry,0,sizeof(ret->entry));
    return ret;
}
void randomMatrix(Matrix *matrix){
    int i, j;
    for(i = 0; i < matrix->row; i++){
        for(j = 0; j < matrix->column; j++){
            setEntry(matrix, i, j, rand() % 100);
        }
    }
}
void printMatrix(Matrix *matrix){
    int i, j;
    for(i = 0; i < matrix->row ; i++){
        for(j = 0; j < matrix->column; j++){
            printf("%8.3f,", getEntry(matrix, i, j));
        }
        printf("\033[1D \n");
    }
}