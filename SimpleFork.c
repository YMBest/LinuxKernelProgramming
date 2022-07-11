#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
	for(int i = 0; i < 4; i++){
		printf("------%d\n",i);
	}

	pid_t pid = fork();
	if(pid < 0){perror("fork fail");}

	if(pid > 0){printf("Parent process, pid = %d\n",getpid());}

	if(pid == 0){printf("Child process,pid = %d\n",getpid());}

	for(int i = 0; i < 4; i++){
		printf("%d\n",i);
	}
	return 0;

}
