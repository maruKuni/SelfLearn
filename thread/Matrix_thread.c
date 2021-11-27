#include "mythread.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void calcProdMatrix(order_operate *order){
    int i;
    result_prodct *result = (result_prodct *)malloc(sizeof(result_prodct));
    if(result == NULL){
        perror("malloc");
        exit(1);
    }
    initResult(result, order);
    for(i = 0; i < order->left->column; i++){
        result->value += getEntry(order->left,order->row,i)*getEntry(order->right,i,order->column);
    }
    free(order);
    pthread_exit(result);
}
void applyResult(result_prodct *result, Matrix *dest){
    setEntry(dest, result->row, result->column, result->value);
    free(result);
}
void initResult(result_prodct *result, order_operate* order){
    result->value = 0;
    result->row = order->row;
    result->column = order->column;
}
void push_thread(pthread_t id){
    thread_stack *stack = (thread_stack *)malloc(sizeof(thread_stack));
    stack->tid = id;
    stack->prev = HEAD_T_STACK;
    HEAD_T_STACK = stack;
}
pthread_t pop_thread(){
    if(HEAD_T_STACK == NULL){
        perror("stack is empty\n");
        exit(1);
    }
    pthread_t ret = HEAD_T_STACK->tid;
    HEAD_T_STACK = HEAD_T_STACK->prev;
    return ret;
}
void calcProdDirect(order_with_result *order){
    int i;
    double tmp = 0;
    for(i = 0; i < order->left->column; i++){
        tmp += getEntry(order->left,order->row,i)*getEntry(order->right,i,order->column);
    }
    setEntry(order->result,order->row,order->column,tmp);
    free(order);
    pthread_exit(NULL);
}