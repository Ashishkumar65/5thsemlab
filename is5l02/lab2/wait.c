#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
	pid_t pid1=fork(),pid2=fork();
	//if(pid1==0&&pid2==0)
	//{
	//	sleep(1);
	//	printf("Both Child processes are executing\n");
	//	exit(0);
	//}
	if(pid1==0&&pid2>0)
	{	
		sleep(1);
		printf("First Child process is executing. It's PID is %d. It's Parent's PID is %d\n",getpid(),getppid());
		//exit(0);
	}
	else if(pid1>0&&pid2==0)
	{	
		sleep(1);
		printf("Second Child process is executing. It's PID is %d. It's Parent's PID is %d\n",getpid(),getppid());
		//exit(0);
	}
	else if(pid1==0&&pid2==0)
	{
		//sleep(1);wait(NULL);
		printf("Only child processes are executing\n");
		//exit(0);
		//printf("Parent process is now executing.It's PID is %d\n",getppid());
	}
	else{
		wait(NULL);
		printf("Parent process is executing. It's PID is %d\n",getpid());
		exit(1);
	}
	return 0;
}	
