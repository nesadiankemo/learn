#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "syscalls.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dirent.h"
void fsize(char *);
int main(int argc, char **argv)
{
	if(argc == 1)
		fsize(".");
	else
		while(--argc > 0)
			fsize(*++argv);
	return 0;
}
