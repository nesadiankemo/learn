#include <unistd.h>
#include <stdio.h>

int
main(void)
{
	FILE *fd = NULL;
	int c;
	while((c = getc(stdin)) != EOF){
		if(putc(c, stdout) == EOF){
			printf("output error\n");
		}	
	}	
	if(ferror(stdin))
		printf("input error\n");
	return 0;
}
