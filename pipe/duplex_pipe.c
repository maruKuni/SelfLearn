#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#define BUFSIZE 256
#define ERR -1
void usage();
char *command_name;

int main(int argc, char *argv[]){
    char buf[BUFSIZE];
    int fd1[2];     //Child to Parent
    int fd2[2];     //Parent to Child
    pid_t pid;
    int msglen;
    char *rindex(const char *s, int c);
    if((command_name = rindex(argv[0], '/')) != NULL){
        command_name++;
    }else{
        command_name = argv[0];
    }

    if(argc != 3){
        usage();
    }
    if(pipe(fd1) == ERR){
        perror("pipe");
        exit(1);
    }
    if(pipe(fd2) == ERR){
        perror("pipe");
        exit(1);
    }
    if((pid = fork()) == 0){
        //子プロセス
        close(fd1[0]);//fd1はchild to parent.読み出しは不要なのでclose
        close(fd2[1]);//fd2はParent to child. 書き込みは不要なのでclose
        msglen = strlen(argv[1]);
        if(write(fd1[1], argv[1], msglen) == ERR){
            perror("child : write");
            exit(1);
        }
        if(read(fd2[0], buf, BUFSIZE) == ERR){
            perror("child : read");
            exit(1);
        }
        printf("\n<CHILD> message from parent : %s\n\n", buf);
    }else if(pid >= 1){
        //親プロセス
        close(fd1[1]);//fd1はchild to parent. 書き込みは不要なのでclose
        close(fd2[0]);//fd2はparent to child. 読み込みは不要なのでclose
        if(read(fd1[0], buf, BUFSIZE) == ERR){
            perror("parent : read");
            exit(1);
        }
        printf("\n <PARENT> message from child : %s\n", buf);
        msglen = strlen(argv[2]) + 1;
        if(write(fd2[1], argv[2], BUFSIZE) == ERR){
            perror("parent :write");
            exit(1);
        }
        wait(NULL);
    }else{
        perror("fork");
        exit(1);
    }
}
void usage(){
    fprintf(stderr, "Usage : %s message(CtoP) message(PtoC)\n", command_name);
}