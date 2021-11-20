#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <strings.h>
#define ERR -1

void sigmsg(void);
void usage(void);
int main(int argc, char *argv[]){
    unsigned int time;
    if(argc != 2)
        usage();
    if(signal(SIGALRM, (void *)sigmsg) == ERR){
        perror("signal");
        exit(1);
    }
    time = atoi(argv[1]);
    alarm(time);
    if(pause() == ERR)
        printf(" ** signal is caught !! **\n");
    exit(0);
}
void sigmsg(){
    printf(" ** time is arrived \n");
}
void usage(){
    fprintf(stderr, "Usage :  times\n");
    exit(1);
}