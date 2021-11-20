#include "childList.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
void doChild(int);

int main(){
    int countChild = 1;
    pid_t id;
    int status;
    initStack();
    for(;countChild<=10;countChild++){
        id = fork();
        if(id >= 1){
            pushChild(id);
        }else if(id == 0){
            doChild(countChild);
        }
    }
    sleep(10);
    while((id = dequeueChild()) != 0){
        waitpid(-1, &status, WUNTRACED);
        printf("child %d has gone with %d\n", id, status >> 8);
    }
}
void doChild(int tabSize){
    for(int i = 0; i < 5;i++){
        for(int j = 0;j < tabSize;j++){
            printf(" ");
        }
        printf("child %4d: Hello\n",getpid());
        sleep(1);
    }
    exit(tabSize);
}