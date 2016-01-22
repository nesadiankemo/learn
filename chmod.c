#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int 
main(void)
{
	struct stat statbuf;
	if(stat("foo", &statbuf) < 0)
		printf("stat error for foo\n");
	if(chmod("foo", (statbuf.st_mode) & ~S_IWGRP) < 0)
		printf("chmod error for foo\n");
	if(chmod("bar", S_IRUSR | S_IRGRP | S_IROTH) < 0)
		printf("chmod error for bar\n");
	return 0;
}
