#include "matrix_lib.h"
#include <string.h>
int main(int argc, char *argv[]){
    int i, j, k;
    double tmp;
    int N;
    Matrix* left, *right, *result;
    if(argc > 1){
        N = atoi(argv[1]);
    }else{
        N = 4;
    }
    left = initMatrix(N, N);
    right = initMatrix(N, N);
    result = initMatrix(N, N);
    randomMatrix(left);
    randomMatrix(right);
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tmp = 0;
            for(k = 0; k < N; k++){
                tmp += getEntry(left, i, k)*getEntry(right, k, j);
            }
            setEntry(result, i, j, tmp);
        }
    }
    free(right);
    free(left);
    free(result);
}