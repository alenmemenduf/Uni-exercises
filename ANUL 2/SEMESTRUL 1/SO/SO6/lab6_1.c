
//problema cu inversarea stringurilor thread-uri

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
void* inversare(void *args)
{
int i,k=0;
char *s = args;
int n = strlen(s);

char copy = (char)malloc(n);
	for(i=n-1;i>=0;i--)
	{
	copy[k++] = s[i];
	}
return copy;
}

int main(int argc,char *argv[])
{
	char *s = argv[1];

	pthread_t tid;
	pthread_create(&tid,NULL,inversare,s);
	void *t;
	pthread_join(tid, &t);
	printf("%s \n", (char*)t);
	return 0;
}
