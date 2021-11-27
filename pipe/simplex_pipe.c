#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <strings.h>
#define ERR -1
#define BUFSIZE 256
int main(int argc, char *argv[]){
    char buf[BUFSIZE];
    int fd[2];
    pid_t pid;
    int msglen;
    if(pipe(fd) == ERR){
        perror("pipe");
        exit(1);
    }
    if((pid = fork()) == 0){
        close(fd[0]);
        msglen = strlen(argv[1]) + 1;
        if(write(fd[1], argv[1], msglen) == ERR){
            perror("write");
            exit(1);
        }
    }else if(pid >= 1){
        close(fd[1]);
        if(read(fd[0], buf, BUFSIZE) == ERR){
            perror("read");
            exit(1);
        }
        printf("\nMessage from child process : \n");
        printf("\n     %s\n", buf);
    }else{
        perror("fork");
        exit(1);
    }
    exit(1);

}