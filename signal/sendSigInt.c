#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#define ERR -1

int main(int argc, char *argv[]){
    pid_t pid;
    pid_t mypid;
    pid_t cpid;
    int status;
    int i;
    if(argc < 2)
        exit(1);
    if( (pid = fork()) == 0){
        mypid = getpid();
        printf("Child process : execute a new program(%s). pid = %d\n", argv[1], mypid);
        if((execv(argv[1], &argv[1])) == ERR){
            perror("execv");
            exit(1);
        }
    }else if(pid >= 1){
        for(i = 0; i < 4; i++){
            sleep(3);
            if(kill(pid, SIGINT) == ERR){
                perror("kill");
                exit(1);
            }
        }
        cpid = wait(&status);
        printf("Parent process : child process has just finished. pid = %d\n", cpid);
        printf("status = %04x\n",status);
    }else{
        perror("fork");
        exit(1);
    }
    exit(0);
    
}