#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 3

char box[N+1][N+1]={0};
int count = 0;
int num = 0;
typedef struct node{
	int x;
	int y;
	struct node *next;
}point;
point * pointadd(point *p, int x, int  y)
{	
	if(p == NULL){
		p = (struct node *)malloc(sizeof(struct node));
		p->x = x;
		p->y = y;
		p->next = NULL;
	}
	else{
		p->next = pointadd(p->next, x ,y);
	}
    return p;
}


/**
*检测位置相对已放置的块是否合理
*合理则返回真，否则返回0
*/
int checklegal(int x, int y)
{
	int ret = 0;
	int i, j;
	if(box[x][y] || x < 1 || x > N || y < 1 || y > N)//判断是否出界或已放置方块
		return ret;
	for(i = 1; i <= N; i++)
		for(j = 1; j <= N; j++){
			if((box[i][j] && (abs(x-i) <= 1) && (abs(y-j) <= 1)) || count == 0){
				//printf("(%d,%d)is legal\n", x, y);	
				return 1;
			}	
		}
	//printf("(%d,%d)is illegal\n", x, y);
	return ret;
}

/*
*打印成图
*/
void do_print()
{
	int i, j;
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			if(box[i][j]){
				printf("*  ");	
				//box[i][j] = 0;
			}else {
				printf(".  ");	
			}
		
		}	
		printf("\n");
	}
}
static int step = 0;
static int s_x = 1;
static int s_y = 1;
point head = {
	.x = 0,
	.y = 0,
	.next = NULL,
};
point *record;

/*
*递归回溯放置block
*参数x,y为二维坐标，
*/
void putblock(int x, int y, int e_x, int e_y)
{
	int i,j;

	if(count == 0){					//第一块方块放置在区域中心区
		i = j = (N >> 1) + (N%2);
		//for(i=j=1; i <= (N>>1) + (0x00000001 & N); i++, j++)
		if(checklegal(i, j)){
			box[i][j] = 1;
			count++;
			putblock(i, j, i, j);	
			box[i][j] = 0;
			count --;
		}
	}
	else if(count < N){
		for(i = x-1; i <= e_x+1; i++){					//检测方块四周
			for(j = y-1; j <= e_y+1; j++){
				//printf("(%d, %d)\n", i, j);
				//box[i][j] = 1;
				if(checklegal(i, j)){
					box[i][j] = 1;
					//record = pointadd(record, x, y);
					count++;
					e_x = (i > e_x) ? i : e_x;
					e_y = (j > e_y) ? j : e_y;
					putblock(i, j, e_x, e_y);
					//if(count >= N){	
						box[i][j] = 0;
						count --;
					//}
				}
				//box[i][j] = 0;
			}
		}
	}
	else{
		printf("%d :\n", ++num);
		//do_print();	
	}	
}

int main()
{
	int i, j;
	//for(i = 1; i <= N; i++)
		//for(j = 1; j <= N; j++){
			putblock(1, 1, 1, 1);
			count = 0;
		//}
	return(0);
}
