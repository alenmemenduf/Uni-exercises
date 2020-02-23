#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <wait.h>
int main()
{
	pid_t pid = fork();
	if(pid<0)
		return errno;
	else if(pid==0)
	{
		printf("My PID=%d,Child PID=%d\n",getppid(),getpid());
		char *argv[] = {"ls",NULL};
		execve("/bin/ls",argv,NULL);
		perror(NULL);
	}
	else
	{
		printf("Child %d terminated\n", wait(NULL));
	}

}
