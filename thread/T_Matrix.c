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
    //printf("left matrix\n");
    //printMatrix(left);
    //printf("right matrix\n");
    //printMatrix(right);
    
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            order_operate *order = (order_operate *)malloc(sizeof(order_operate));
            order->row = i;
            order->column = j;
            order->left = left;
            order->right = right;
            pthread_create(&tid,NULL,calcProdMatrix,order);
            push_thread(tid);
        }
    }
    while(HEAD_T_STACK != NULL){
        tid = pop_thread();
        pthread_join(tid, &prod);
        applyResult(prod, result);
    }
    //printMatrix(result);
    free(right);
    free(left);
    free(result);
    return 0;
}