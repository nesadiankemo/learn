#include <stdio.h>
#include <string.h>
#define N 100
struct student
{
int num;
char name[8];
char Class[8];
double score1;
double score2;
double score3;
double totalscore;
double averagescore;
}stu[N];

void sort(struct student *stu, int num);
inline void exchange1(struct student *i, struct student *j);

int main()
    {
    int choice,i,q=0,tempnum,j;
    int count = 0;              //记录录入总人数
    char bestone_flag = 0;      //
    printf("这是学生成绩与奖学金评定系统：\n1-添加一个学生的的记录.\n2-查看一个学生的记录.\n3-修改一个学生的记录.\n4-浏览所有学生记录.\n5-删除一个学生的信息.\n6-奖学金评定.\n");
    for( ; ;)           //改用死循环或者其他参数
    {
        printf("请输入要进行操作项前的数字：");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("请输入你要添加学生的信息:\n");
            printf("学号: ");
            scanf("%d",&stu[count].num);
            printf("姓名: ");
            scanf("%s",stu[count].name); 
            printf("班级: ");
            scanf("%s",stu[count].Class);
        	printf("数学成绩：");
            scanf("%lf",&stu[count].score1);
        	printf("英语成绩：");
            scanf("%lf",&stu[count].score2);
        	printf("C++语言成绩：");
            scanf("%lf",&stu[count].score3);
        	q++;
            stu[count].totalscore=stu[count].score1+stu[count].score2+stu[count].score3;
            stu[count].averagescore=(stu[count].score1+stu[count].score2+stu[count].score3)/3.0;
            count ++;
        }
        else if(choice==2)
        {
            printf("请输入要查看学生的学号:");
            scanf("%d",&tempnum);
            for(j = 0;j < N;j++){            //这里不用完全搜索，其实只要搜索已经记录的人数count 就行了
                if(stu[j].num == tempnum)
                {
                    //i=j;
                    printf(" 学号:%d\n 姓名:%s\n 班级:%s\n",stu[j].num,stu[j].name,stu[j].Class);
                    printf(" 数学成绩:%lf\n",stu[j].score1);
                    printf(" 英语成绩:%lf\n",stu[j].score2);
                    printf(" C++语言成绩:%lf\n",stu[j].score3);
                    printf(" 总成绩:%lf\n",stu[j].totalscore);
                    printf(" 平均成绩:%lf\n",stu[j].averagescore);

                    break;  //到匹配的学号后，跳出循环
                }
            }
        }
        else if(choice==3)
        {
            printf("请输入未修改前学生的学号：");
            scanf("%d",&tempnum);
            for(j=0;j<N;j++)
            if(stu[j].num==tempnum)
            {
                //i=j;
            	printf("请输入修改后学生的信息：\n");
            		printf("学号：");
                scanf("%d",&stu[j].num);
            	    printf("姓名：");
                scanf("%s",stu[j].name);
                    printf("班级: ");
                scanf("%s",stu[j].Class);
            		printf("数学成绩：");
                scanf("%lf",&stu[j].score1);
            		printf("英语成绩：");
                scanf("%lf",&stu[j].score2);
            		printf("C++语言成绩：");
            		scanf("%lf",&stu[j].score3);
                break;
            }
        }
        else if(choice==4)
        {
        	for(i = 0;i<=q;i++)        //start from [0]
            {
                printf(" 学号:%d 姓名:%s 班级:%s",stu[i].num,stu[i].name,stu[i].Class);
                printf(" 数学成绩:%lf",stu[i].score1);
                printf(" 英语成绩:%lf",stu[i].score2);
                printf(" C++语言成绩:%lf",stu[i].score3);
                printf(" 总成绩:%lf",stu[i].totalscore);
                printf(" 平均成绩:%lf\n",stu[i].averagescore);	
            }
        }
        else if(choice==5)
        {
                printf("请输入要删除学生的学号：");
             scanf("%d",&tempnum);
            for(j=0;j<N;j++)
            if(stu[j].num==tempnum)
            {
                for(i=j;i<q-1;i++)          
                stu[i]=stu[i+1]; 
                q--;
                count --;   //count 跟 q的功能好像是相同的 
            }
        }
        else if(choice==6)
        {
            double  max_score = 0;
            int     num;        //记录总成绩最高的数组序号
            for(i = 0;i < count; i++){                   //到总成绩最高的
                if(stu[i].totalscore > max_score){
                    max_score = stu[i].totalscore;
                    num = i;
                }
            }
            printf("%lf, %lf, %lf\n", stu[num].score1, stu[num].score2, stu[num].score3);
            if(stu[num].score1 >= 75 && stu[num].score2 >= 75 && stu[num].score3 >= 75){        //判断总成绩最高的是单科符合条件
                printf("学习标兵是:\n  学号:%d  姓名%s\n",stu[num].num,stu[num].name);
            }else{
                printf("none\n");
            }
                
        }
        else if(choice == 7)
        {
            int fiveprc = 0;
            int shift = 0;
            sort(stu, count);
            fiveprc = count * 0.5;
            if(fiveprc == 0){
                printf("none\n");       //去掉一个标兵，肯定没有三好学生
                break;
            }
            for(i = 1; i < fiveprc; i++){
                if(stu[i].totalscore < stu[0].totalscore){          //排除总成绩第一并列的情况，即排除标兵
                    break;
                }
            }
            printf("三好学生有:\n");
            for( ; i < fiveprc; i++){                               //排除掉标兵剩下的就是三好学生了
                if(stu[i].score1 >= 75 && stu[i].score2 >= 75 && stu[i].score3 >= 75){      //判断单科成绩
                    printf("%s: %lf\n", stu[i].name, stu[i].totalscore);
                }
            }
            shift = --i;
            for(i = fiveprc; i < count; i++){                        //考虑有跟最后一名三好学生同成绩的
                if(stu[shift].totalscore <= stu[i].totalscore){
                    if(stu[i].score1 >= 75 && stu[i].score2 >= 75 && stu[i].score3 >= 75){
                        printf("%s: %lf\n", stu[i].name, stu[i].totalscore);
                    }
                }else{
                    break;
                }
            }
            
        }
        else
        {
                printf("输入错误，请重新输入:");
        }
    }
    return 0;
}

/*
* 排序
* num:需要排序的个数,即已经录入的人数
*/
void sort(struct student *stu, int num)
{
    int i, j;
    for(i = 0; i < num; i++){
        for(j = i+1; j < num; j++){
            if(stu[i].totalscore < stu[j].totalscore) {
                exchange1(&stu[i], &stu[j]);
            }
        }
    }
}

/*
* 交换两个结构体内容
*/
inline void exchange1(struct student *i, struct student *j)
{
    struct student temp;

    memcpy(&temp, i, sizeof(struct student));
    memcpy(i, j, sizeof(struct student));
    memcpy(j, &temp, sizeof(struct student));
}