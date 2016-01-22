#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t fpid;
	int count = 0;
	printf("before fork()\n");
	fpid = fork();
	if(fpid < 0){
		printf("error!\n");
	}else if(fpid == 0){
		printf("I am the child process, my process id is %d\n", getpid());
		count ++;
	}else{
		printf("I am the parent process, my process id is %d\n", getpid());
		count ++;
	}

	printf("统计：%d\n", count);
	return 0;
}