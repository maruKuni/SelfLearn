#include "mythread.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[]){
    int i, j;
    int N;
    if(argc > 1){
        N = atoi(argv[1]);
    }else{
        N = 4;
    }
    pthread_t tid;
    result_prodct *prod;
    srand((unsigned int)time(NULL));
    Matrix *left = initMatrix(N, N);
    Matrix *right = initMatrix(N, N);
    Matrix *result = initMatrix(N, N);
    randomMatrix(left);
    randomMatrix(right);
    // printf("left\n");
    // printMatrix(left);
    // printf("right\n");
    // printMatrix(right);
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            order_with_result *order = (order_with_result *)malloc(sizeof(order_with_result));
            order->row = i;
            order->column = j;
            order->left = left;
            order->right = right;
            order->result = result;
            pthread_create(&tid, NULL, calcProdDirect, order);
        }
    }
    //printf("result\n");
    //printMatrix(result);
    free(right);
    free(left);
    free(result);
    return 0;
}