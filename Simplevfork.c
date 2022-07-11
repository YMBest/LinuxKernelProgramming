#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	pid_t pid;
	pid = vfork();
	if(pid < 0) perror("vfork");
	if(pid == 0){
		sleep(3); printf("I am child"); _exit(0);
	}
	else if(pid > 0){
		printf("I am father\n");
	}

	return 0;
}
