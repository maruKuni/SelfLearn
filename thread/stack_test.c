#include "stack.h"
#include <time.h>
int main(){
    srand((unsigned int)time(NULL));
    for(int i = 0; i < 10;i++){
        push(rand()%20);
    }
    while(HEAD != NULL){
        printf("%d\n", pop());
    }
}