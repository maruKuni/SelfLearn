#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    pid_t id = fork();
    if(id >= 1){
        printf("I am parent. My child is %d\n", id);
    }else{
        printf("I am child. My ID is %d\n", getpid());
    }
}