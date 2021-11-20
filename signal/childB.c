#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ALIVE_TIME 7
int main(){
	for(int i = 0;i < ALIVE_TIME;i++){
		sleep(1);
		printf("\tchildB:%3d\n", i);
	}
	exit(20);
}
