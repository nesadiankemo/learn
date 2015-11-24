#include <unistd.h>
#include <stdio.h>
#define BUFSIZE 1024
int main()
{
	char buf[BUFSIZE];
	int n;
	while((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0)
		if(write(STDOUT_FILENO, buf, n) != n){
			printf("write error!\n");
			return -1;
		}	
	return 0; 
}
