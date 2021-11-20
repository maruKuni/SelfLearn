#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ALIVE_TIME 10
int main(){
	for(int i = 0; i < ALIVE_TIME;i++){
		sleep(1);
		printf("\t\tChildC:%3d\n", i);
	}
	exit(30);	
}
