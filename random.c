#include "stdio.h"
#include "stdlib.h"

#define TABLESIZE 10
#define MAXVAL 4
void main()
{
	unsigned int randtab[TABLESIZE],i;
	int maxval,num;
	printf("please enter the max variable and the number generate:");
	scanf("%d %d",&maxval, &num);
	srand((unsigned )time(NULL));
	printf("the number generated as follow:\n");
	for(i = 0; i < num; i++){
		printf("%d",randtab[i] = rand() % maxval);
		printf("\n");
	}

}