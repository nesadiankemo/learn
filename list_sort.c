#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int no;
	int creat_time;
	struct node *next;
}list;


list * listadd(list *p, int no, int  creattime)
{	
	if(p == NULL){
		p = (struct node *)malloc(sizeof(struct node));
		p->no = no;
		p->creat_time = creattime;
		p->next = NULL;
	}
	else{
		p->next = listadd(p->next, no ,creattime);
	}
    return p;
}

list* sort(list * head)  
{  
    if (head == NULL)  
        return NULL;  
    list* p = head;  
    list* p_pre = p;  
    char flag = 0;   //用于标记是否有交换，当数组有序的时候，提高判断效率  
  
    while(p_pre->next != NULL)  
    {  
        int  temp1 = p_pre->creat_time;
        int temp2 = p_pre->no;  
        p = p->next;  
        while (p)  
        {      
            if(temp1 <= (p->creat_time))  //从小到大排序
            {  
                p = p->next;  
                continue;  
            }  
            else  
            {  
                int  temp1_change;
                int temp2_change;  
                temp1_change = p->creat_time; 
                temp2_change = p->no; 
                p->creat_time = p_pre->creat_time;
                p->no = p_pre->no;  
                p_pre->creat_time = temp1_change;  
                p_pre->no = temp2_change;
                p = p->next;  
                flag = 1;  
            }  
            if (flag == 0)  
            {  
               return head;  
            }  
        }         
        p_pre = p_pre->next;  
        p = p_pre;  
    }  
    return head;  
      
}  

list *InsertSort(list *head)  
{  
    list *first; /*为原链表剩下用于直接插入排序的节点头指针*/  
    list *t; /*临时指针变量：插入节点*/  
    list *p; /*临时指针变量*/  
    list *q; /*临时指针变量*/  
  
    first = head->next; /*原链表剩下用于直接插入排序的节点链表：可根据图12来理解。*/  
    head->next = NULL; /*只含有一个节点的链表的有序链表：可根据图11来理解。*/  
  
    while (first != NULL) /*遍历剩下无序的链表*/  
    {  
        /*注意：这里for语句就是体现直接插入排序思想的地方*/  
        for (t = first, q = head; ((q != NULL) && (q->creat_time > t->creat_time)); p = q, q = q->next); /*无序节点在有序链表中找插入的位置*/  
      
    /*退出for循环，就是找到了插入的位置*/  
    /*注意：按道理来说，这句话可以放到下面注释了的那个位置也应该对的，但是就是不能。原因：你若理解了上面的第3条，就知道了。*/  
        first = first->next; /*无序链表中的节点离开，以便它插入到有序链表中。*/   
    
        if (q == head) /*插在第一个节点之前*/  
        {  
            head = t;  
        }  
        else /*p是q的前驱*/  
        {  
            p->next = t;  
        }  
        t->next = q; /*完成插入动作*/  
        /*first = first->next;*/  
    }  
    return head;  
}  

void listprintf(list *p){
    while(p != NULL){
        printf("no: %d, time: %d\n", p->no, p->creat_time);
        p = p->next;
    }
}

void main()
{
    list *head = NULL;
    list *p;
    int no;
    int i,time;
    //head = (list *)malloc(sizeof(list));
    //head->next = NULL;
    //head->no = 1;
    //head->creat_time = 21;

    for(i = 1; i < 6; i++){
        scanf("%d", &time);
        head = listadd(head,i,time);
    }
    
    listprintf(head);
    p = InsertSort(head);
    printf("sort:\n");
    listprintf(p);

}