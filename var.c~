#include <stdio.h>
#define pi 3.1415926
int strlen_t(char *s);
int atoi_t(char *s);
int lower_t(char c);
#define HELLOWORLD "hello ""world~"

int main(int argc, char *argv[])
{
	char c = 'c';
	int count;
	printf("please enter a year to see wether is a leap year or not:");
	scanf("%d", &count);
	if((count % 4 == 0 && count % 100 != 0) || (count % 400 == 0))
		printf("%d is a leap year.\n", count);
	else 
		printf("%d is not a leap year.\n", count);
	count = strlen_t(HELLOWORLD);
	printf("the string :%s,has %d characters.\n", HELLOWORLD, count);
	while((c = getchar()) != '#')
		putchar(c);	
	return 0;	
}
int strlen_t(char *s)
{
	int count = 0;
	while(*s++ != '\0')
		count ++;
	return count;
}

int atoi_t(char *s)
{
	int n,i;
	n = 0;
	for(; *s >= '0' && *s <= '9'; s++)
		n = n * 10 + (*s - '0');
	return n;
}
int lower(char c)
{
	if(c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else 
		return c;
}
