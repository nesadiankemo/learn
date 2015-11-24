#include <stdio.h>
#define pointer

unsigned short buf[] = {0x0012,0x6211};
unsigned short des[10];
typedef struct{
	int day;
	char c;
}TEXT;

static TEXT s ={
	.day = 0,
	.c = 0
};
void exchange_BigEndian_to_LittleEndian(unsigned short *dest, unsigned short *src ,int size ){
	unsigned short temp;
	int i;
	for(i = 0;i < size; i++){
	#ifdef pointer
		temp = *(src + i) >> 8;
		temp += *(src + i) << 8;
		*(dest + i) = temp;
	#else
		temp = src[i] >> 8;
		temp += src[i] << 8;
		dest[i] = temp;
	#endif
	}
}

int main()
{
    int i;
    for(i = 0; i < sizeof(buf) >> 1 ;i++)
        printf("%x ",buf[i]);
    printf("\n");
    exchange_BigEndian_to_LittleEndian(des,buf,sizeof(buf) >> 1);
    for(i = 0; i < sizeof(buf) >> 1 ;i++)
        printf("%x ",des[i]);
    printf("\n");
    return 0;
}
