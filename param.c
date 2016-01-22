#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void
func(int count, ...)
{
	int i;
	int *temp = &count;
	va_list ap;
	va_start(ap, count);
	printf("&count = %x\n", &count);
	printf("&ap = %ld\n", ap);
	i = va_arg(ap, int);
	printf("1 *= %ld : %d\n", ap, i);
	i = va_arg(ap, int);
	printf("2 *= %ld : %d\n", ap, i);
	i = va_arg(ap, int);
	printf("3 *= %ld : %d\n", ap, i);
	va_end(ap);
	
}

int
main()
{
	int a = 4;
	int b = 5;
	int c = 6;
	func(3,a,b,c);
	return 0;
}
