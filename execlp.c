#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 300
int main(int argc, char *argv[])
{
	char buf[BUFSIZE];
	int n;
	pid_t fpid;
	printf("%% ");

	while((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0 ){
		buf[n - 1] = '\0';
		fpid = fork();
		if(fpid < 0){
			printf("fork error!\n");
			return 0;
		}
		else if(fpid == 0){
		//	printf("in child process.\n");
		//	printf("pid: %4d, ppid: %4d\n", getpid(), getppid());
			execlp(buf, buf, (char *)0);
			exit(EXIT_SUCCESS);
		}
			
			if( waitpid(fpid,NULL, 0 ) < 0)
				printf("waitpid error\n");
			//printf("in parent.\n");
			//printf("pid: %4d, ppid: %4d\n", getpid(), getppid());

		
		printf("%% ");
	}

	exit(EXIT_SUCCESS);
}


