
#ifndef CHILD_STACK_H
#define CHILD_STACK_H
#define MAX_CHILD 1000
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
typedef struct childStack{
    pid_t id;
    struct childStack *prev;
    struct childStack *next;
}childStack;

static childStack *head;
static childStack *tail;
static int length;
void initStack();
pid_t popChild();
void pushChild(pid_t);
void queueChild(pid_t);
pid_t dequeueChild();

void initStack(){
    length = 1;
    head = (childStack * )malloc(sizeof(childStack *));
    tail = head;
    head->id = 0;
    head->prev = NULL;
    head->next = NULL;
}

void pushChild(pid_t id){
    if(length == MAX_CHILD){
        printf("this Stack is too long%d\n", MAX_CHILD);
        return;
    }
    if(length++ == 1){
        head->id = id;
        return;
    }
    childStack *tmp = (childStack * )malloc(sizeof(childStack *));
    tmp->id = id;
    tmp->prev= head;
    head->next=tmp;
    head = tmp;
}
pid_t popChild(){
    length--;
    if(length == 0){
        return 0;
    }
    
    pid_t ret = head->id;
    childStack *tmp = head;
    head = head->prev;
    free(tmp);
    return ret;
}
void queueChild(pid_t id){
    if(length == MAX_CHILD){
        printf("this Stack is too long%d\n", MAX_CHILD);
        return;
    }
    if(length++ == 1){
        head->id = id;
        return;
    }
    childStack *tmp = (childStack * )malloc(sizeof(childStack *));
    tmp->id = id;
    tail->prev=tmp;
    tmp->next=tail;
    tmp->prev=NULL;
    tail=tmp;
}
pid_t dequeueChild(){
    return popChild();
}
#endif