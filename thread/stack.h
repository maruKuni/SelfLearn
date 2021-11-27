#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>
/** intスタック */
typedef struct STACK{
    int value;
    struct STACK *prev;
}STACK;
/** スタックの先頭 */
STACK *HEAD;
/** push */
void push(int value){
    STACK *tmp = (STACK *)malloc(sizeof(STACK));
    tmp->value = value;
    tmp->prev = HEAD;
    HEAD = tmp;
}
/** pop */
int pop(){
    if(HEAD == NULL){
        perror("stack is empty");
        exit(1);
    }
    int ret = HEAD->value;
    HEAD = HEAD->prev;
    return ret;
}
#endif