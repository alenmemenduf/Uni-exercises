#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
	int fd1,fd2;
	char text[4096];
	fd1 = open(argv[1],O_RDONLY);
	fd2 = open(argv[2],O_CREAT|O_WRONLY,0666);
	
	while(read(fd1,text,1))
		write(fd2,text,1);
	return 0;
}
