#include <fcntl.h>
//#include "syscalls.h"
#include <stdio.h>
#define PERMS 0666
//#define BUFSIZE 100000

int fd,fd1;

main()
{
	char buf[BUFSIZ] = {"hello world!"};
	int n;

	if(fd1 = open("./test.c", O_RDONLY, 0) == -1)
		printf("can't open file!");
	if(fd = open("./dat.c", O_WRONLY, 0) == -1)
		printf("can't creat file!");
	while(n = read(fd1, buf, BUFSIZ) >= 0)
		if(write(fd, buf, n) != n)
			printf("write err");
	close(fd);
	return 0;
}