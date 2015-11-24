#include "stdio.h"
//#include "conio.h"

int main()
{
	FILE *fp = NULL;
	FILE *fp_s = NULL;
	char ch;
	char cp[300];
	int  count;
	fp_s = fopen("/usr/include/stdio.h", "r");
	if(fp_s == NULL){
		printf("file stdio.h open error!\n");
		return -1;
	}
	fp = fopen("/home/ting/workfile/write1.txt", "w");
	if(fp == NULL){
		printf("open err!\n");
		//getch();
		return -1;
	}
	/***********************************************************************/
#if 0
	while((ch = getc(fp_s)) != EOF){		//#define getchar() getc(stdin)
		fputc(ch, fp);
	}
#endif
	count = fread(cp, 1, 300, fp_s);
	fwrite(cp, 1, count, fp);
	count = fread(cp, 1, 300, fp_s);
	fwrite(cp, 1, count, fp);
	/***********************************************************************/
	fclose(fp);
	fclose(fp_s);
	fp = fopen("/home/ting/workfile/write1.txt", "r");
	if(fp == NULL){
		printf("open err2!\n");
		//getch();
		return -1;
	}
	while((ch = getc(fp)) != EOF)
		putchar(ch);
	//getch();
	//printf("\n");
	return 0;
}