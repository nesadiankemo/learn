#include "stdio.h"
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n) & ~(~0 << n))
}
main()
{
	int vol,temp;
	int c;
	long nc;
	//while(1){
		printf("Enter number:\n");
		scanf("%d",&temp);
		vol = (int)15*temp/12;
		printf("vol = %d\n", vol);
	//}
	// while((c = getchar()) != EOF){
	// 	putchar(c);
	// }
	//c = EOF;
	//printf("EOF:%x\n",c);


}
