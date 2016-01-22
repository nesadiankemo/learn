#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int i;
	struct stat buf;
	char *str;
	for(i = 1; i < argc; i++){
		printf("%s :", argv[i]);
		if(lstat(argv[i], &buf) < 0){
			printf("error!\n");
			continue;
		}	
		if(S_ISREG(buf.st_mode))
			str = "file";
		else if(S_ISDIR(buf.st_mode))
			str = "directory";
		else if(S_ISFIFO(buf.st_mode))
			str = "FIFO";
		else if(S_ISCHR(buf.st_mode))
			str = "character special file";
		else if(S_ISBLK(buf.st_mode))
			str = "block file";
		else if(S_ISLNK(buf.st_mode))
			str = "link file";
		else if(S_ISSOCK(buf.st_mode))
			str = "socket file";
		else 
			str = "unknow";
		printf("%s\n", str);
	}
	return 0;
}
