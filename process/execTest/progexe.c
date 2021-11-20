#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ERR -1

void usage(void);
char *command_name;

int main(int argc, char *argv[]){
    char *rindex(const char *s, int c);
    if((command_name = rindex(argv[0], '/')) != NULL)
        command_name++;
    else 
        command_name = argv[0];
    
    if(argc  <2)
        usage();
    if(execvp(argv[1], &argv[1]) == ERR){
        perror("execv");
        exit(1);
    }
}
void usage(void){
    fprintf(stderr, "Usage: %s command [option]\n",command_name);
    exit(1);
}