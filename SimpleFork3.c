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
		if(j == i){ 
			usleep(100000);
			printf("%d process, pid = %d\n",j,getpid());	
		}       //for each child process, it exits at its specific i
	}
	if(i == number){ 
		int status;
		pid_t ret;
		printf("parent process, pid = %d\n", getpid());
		while((ret = waitpid(-1, &status, WNOHANG)) != -1){
			if(ret == 0) continue;
				printf("wait %d pid\n",ret);
			if(WIFEXITED(status))
				printf("exit,status = %d\n", WEXITSTATUS(status));
		
		}
	
	}

	return 0;
}
