#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
	int i;
	int number = 5;

	pid_t pid;

	for(i = 0; i < number; i++){
		pid = fork();
		if(pid < 0){perror("fork fail"); exit(1);}
		if(pid == 0) break;
		// Leave child process out of loop, thus only parent process execute this fork()
	}
	
	for(int j = 0; j < number; j++){
		if(j == i) printf("%d process, pid = %d\n",j,getpid());	
	}       //for each child process, it exits at its specific i

	if(i == number) printf("parent process, pid = %d\n", getpid());

	return 0;
}
