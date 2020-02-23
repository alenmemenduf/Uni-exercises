#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <wait.h>
int main(int argc,char *argv[])
{
  char shm_name[] = "myshm";
  int shm_fd;

  shm_fd = shm_open(shm_name, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
  if(shm_fd<0){
	perror(NULL);
	return errno;
  }

  int i,n = argc;
  size_t shm_size = getpagesize()*n;
  size_t page_size = getpagesize();
  if(ftruncate(shm_fd, n*shm_size) == -1)
  {
	perror(NULL);
	shm_unlink(shm_name);
	return errno;
  }

	printf("Starting parent %d\n",getpid());
    char* shm_ptr;

for(int i=1;i<n;i++)
{

  shm_ptr = mmap(0,page_size,PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,(i-1)*page_size);

  if(shm_ptr == MAP_FAILED)
  {

	perror(NULL);
	shm_unlink(shm_name);
	return errno;
  }

  pid_t pid = fork();
  int x = atoi(argv[i]);
  
  if(pid<0)
	{
	perror(NULL);
	return errno;
	}

  else if(pid==0)
  {
	shm_ptr+=sprintf(shm_ptr,"%d:",x);
    shm_ptr+=sprintf(shm_ptr,"%d",x);
  	while(x!=1)
  	{
	if(x%2==0)
		x/=2;
	else
		x = 3*x+1;
    shm_ptr+=sprintf(shm_ptr,"%d",x);
  	}
    printf("Parent %d Child %d\n", getppid(),getpid());
    perror(NULL);
	return 1;

  }
    munmap(shm_ptr,page_size);

}
    for(i=1;i<n;i++)
    {
        wait(NULL);
    }
    for(i=1;i<n;i++)
    {
    shm_ptr = mmap(0,page_size,PROT_READ,MAP_SHARED,shm_fd,(i-1)*page_size);
    printf("%s\n",shm_ptr);
    munmap(shm_ptr,page_size);

    }
return 0;
}
