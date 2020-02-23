#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int n=argc;
	printf("Starting parent %d\n",getpid());
	fflush(stdout);
	for(int i=0;i<n;i++)
	{
		pid_t pid = fork();
		if(pid<0)
		  return errno;
		else if(pid==0)
		{
			printf("%s:",argv[i]);
			execve("./lab4_2",argv+i,NULL);
			perror(NULL);
		}
		else
		{
		printf("Done Parent %d Me %d\n",getpid(),wait(NULL));
		}
	} 
	printf("Done Parent %d Me %d\n",getppid(),getpid());
}
