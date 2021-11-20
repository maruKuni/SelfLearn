#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
    pid_t id = fork();
    if(id >= 1){
        int status;
        wait(&status);
        printf("My child has gone: %d\n", status >> 8);
    }else if(id == 0){
        sleep(1);
        printf("child: Bye\n");
        exit(100);
    }else {
        perror("fork failed\n");
    }
}