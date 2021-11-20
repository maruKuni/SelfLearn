#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
int main(){
    int i = 1;
    for(;i <= __INT16_MAX__;i++){
        if(kill(i, 0) == 0){
            printf("pid %d is exists.\n", i);
        }
    }
}