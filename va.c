fopen.c                                                                                             0000664 0001753 0001753 00000004516 12606076353 011043  0                                                                                                    ustar   ting                            ting                                                                                                                                                                                                                   #include "stdio.h"
#include "string.h"
//#include "ctype.h"

void printf_data(char *p);
char isdigit1(char *c);
int main()
{
	char ch[300];
	char *p;
	char flag = 0;
	FILE *fp = NULL;
	char pstr[20];
	printf("please input the item you want to read:\n");
	scanf("%s", pstr);
	fp = fopen("/proc/net/dev", "r");
	if(fp == NULL){
		printf("read error!\n");	
		return -1;	
	}
	/*fread(ch, 1, 1000, fp);
	printf("%s\n",ch);*/
	/*fgets(ch, 300, fp);
	printf("1 %s \n", ch);
	fgets(ch, 300, fp);
	printf("2 %s \n", ch);*/
	while(fgets(ch, 300, fp)){			//获取一行字符串
		if(p = strstr(ch, pstr)){		//搜索字符串 看是否有匹配项
			//printf("%s\n", p);
			flag = 1;
			while(*p++ != ':');
			printf_data(p);			//得到字符串所在行 将对应数值打印出来
			break;		
		}
	}
	if(!flag)
		printf("item not found!\n");
	fclose(fp);
	fp = NULL;
	return 0;
}
char isdigit1(char *c)
{
	return ((*c >= 0x30) && (*c <= 0x39)) ? *c : 0;		//判断字符是否为数字
}
void printf_data(char *p)
{
	//char *p;
	//p = s;
	int i;
	int num;
	for(i = 0; i < 16; i++){
		while(!isdigit1(p))
			p ++;
		switch(i){
			case 0:
				printf("Reveive:\n");
				printf("bytes:\t\terrs:\tdrop:\n");
				num = atoi(p);
				printf("%5d",num);
				while(isdigit1(p)){
						
						//putchar(*p);
						p ++;	
					}
				printf("\t");
				break;
			case 2:
				//printf("errs:\t");
				num = atoi(p);
				printf("%4d",num);
				while(isdigit1(p)){
						
						//putchar(*p);
						p ++;	
					}
				printf("\t");
				break;
			case 3:
				//printf("drop:\t");
				num = atoi(p);
				printf("%4d",num);
				while(isdigit1(p)){
						
						//putchar(*p);
						p ++;	
					}
				printf("\n\n");
				//printf("\n");
				break;
			case 8:
				printf("Transmit:\n");
				printf("bytes:\t\terrs:\t\tdrop:\n");
				while(isdigit1(p)){
						
						putchar(*p);
						p ++;	
					}
				printf("\t\t");
				break;
			case 10:
				//printf("errs:\t");
				while(isdigit1(p)){
						
						putchar(*p);
						p ++;	
					}
				printf("\t\t");
				break;
			case 11:
				//printf("drop:\t");
				while(isdigit1(p)){
						
						putchar(*p);
						p ++;	
					}
				printf("\n");
				break;
			default :
				while(isdigit1(p)){
					p ++;	
				}
				break;
							
		}
	}
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  