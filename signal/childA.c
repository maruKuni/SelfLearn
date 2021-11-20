#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ALIVE_TIME 5
int main(){
	for(int i = 0;i < ALIVE_TIME ;i++){
		sleep(1);
		printf("childA:%3d\n", i);
	}
	exit(10);
}
