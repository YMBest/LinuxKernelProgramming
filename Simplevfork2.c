#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int a = 10;
int main(int argc, char *argv[]){
	pid_t pid;
	int b = 20;
	pid = vfork();
	if(pid < 0) perror("vfork");
	if(pid == 0){
		a = 100; b = 200; printf("son: a = %d, b = %d\n", a,b);	
	       	_exit(0);
	}
	else if(pid > 0){
		printf("father: a = %d, b =  %d\n", a,b);
	}

	return 0;
}
