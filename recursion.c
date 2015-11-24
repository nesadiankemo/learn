#include <stdio.h>

void printd(int n)
{
	if(n < 0){
		putchar('-');
		n = -n;
	}
	if(n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}

void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);
	if(left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left + 1;i <= right; i++)
		if(v[i] < v[left])
			swap(v, ++last, i);
	swap(v,left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void main()
{
	int s[] = {2,6,7,1,3,5,4,6,9,10,8,'\0'};
	int i;
	// int n;
	// scanf("%d",&n);
	// printd(n);
	// printf("\n");
	printf("before :");
	for(i = 0; i < 11; i++)
		printf("%d ",s[i]);
	printf("\n");
	qsort(s,0,11 - 1);

	printf("after :");
	for(i = 0; i < 11; i++)
		printf("%d ",s[i]);
	printf("\n");

}