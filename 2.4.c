#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void childTask(){
	char name[20];
	printf("Please enter your name:\n");
	scanf("%s",name);
	printf("Your name is %s.\n",name);
}

void parentTask(){
	printf("Job is done\n");
}
int main(){

	for(int i = 1; i < 5; i++){
		pid_t pid = fork();

		if(pid == 0){
			childTask();
			exit(EXIT_SUCCESS);
		}
		else if (pid > 0){
			wait(NULL);
		}
		else{
			printf("Unable to create child process.");
		}
	}
	parentTask();
	return EXIT_SUCCESS;
}
