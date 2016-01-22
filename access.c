#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc != 2){
		printf("arg error!\n");	
		return 0;
	}
	if(access(argv[1], R_OK) < 0){
		printf("access error for %s\n", argv[1]);	
	}		
	else {
		printf("access ok\n");	
	}
	if(open(argv[1], O_RDONLY) < 0){
		printf("read error for %s\n", argv[1]);	
	}
	else {
		printf("read ok\n");	
	}
	return 0;
}

