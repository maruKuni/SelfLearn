#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#define ERR -1

void sigpid(void);
int nwait;
int main(){
    pid_t pid;
    pid_t mypid;
    if(signal(SIGCHLD, (void *)sigpid) == SIG_ERR){
        perror("signal");
        exit(1);
    }
    nwait = 0;
    if((pid = fork()) == 0){
        //子プロセス
        mypid = getpid();
        printf("Child process : execute a new program (childA). pid = %d\n", pid);
        if(execl("childA", "childA", (char *)0) == ERR){
            perror("execl");
            exit(1);
        }
    }
    if((pid = fork()) == 0){
        //子プロセス
        mypid = getpid();
        printf("Child process : execute a new program (childB). pid = %d\n", pid);
        if(execl("childB", "childB", (char *)0) == ERR){
            perror("execl");
            exit(1);
        }
    }
    if((pid = fork()) == 0){
        //子プロセス
        mypid = getpid();
        printf("Child process : execute a new program (childC). pid = %d\n", pid);
        if(execl("childC", "childC", (char *)0) == ERR){
            perror("execl");
            exit(1);
        }
    }
    while(nwait < 3);
    exit(0);
}
void sigpid(void){
    pid_t cpid;
    int status;
    nwait++;
    cpid =wait(&status);
    printf("Parent process : child process has just finished. pid = %d\n",cpid);
    printf("status = %04d", status);
    
}