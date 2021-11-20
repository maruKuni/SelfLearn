#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void usage();
char *command_name;
int main(int argc, char *argv[]){
    int i;
    void sigmsg(void);
    char *rindex(const char *s, int c);

    if((command_name = rindex(argv[0], '/'))!= NULL){
        command_name++;
    }else{
        command_name=argv[0];
    }
    if(argc != 1)
        usage();
    
    if(signal(SIGINT, (void *)sigmsg) == SIG_ERR){
        perror("signal");
        exit(1);
    }
    for(i = 1; i <= 15;i++){
        sleep(1);
        printf("%2d : aliving and kicking!!\n", i);
    }
    exit(0);
}
void sigmsg(void){
    printf(" ** interrupt key is pressed **\n");
    // if(signal(SIGINT, (void * )sigmsg) == SIG_ERR){
    //     perror("signal");
    //     exit(1);
    // }
}
void usage(){
    fprintf(stderr, "Usage : %s\n", command_name);
    exit(1);
}