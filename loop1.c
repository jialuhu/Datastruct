/*************************************************************************
	> File Name: loop1.c
	> Author: 
	> Mail: 
	> Created Time: 日 10/ 1 21:55:57 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct chat
{
    int a;
    struct chat *next;
}chat;
void prin(chat *phead);
/*带头节点单向循环链表*/
int create(int n)
{
    int i = 0;
    chat *p;
    chat *r;
    chat *stu;
    r = (chat *)malloc(sizeof(chat));
    p = r;
    for(i=0; i < n; i++)
    {
        stu = (chat *)malloc(sizeof(chat));
        printf("please input the a:\n");
        scanf("%d",&stu->a);
        r->next = stu;
        r = stu;
    }
    printf("r:%d\n",r->a);
    stu->next = p->next;
    printf("99\n");
    printf("r:%d\n",r->next);
    printf("r:%d\n",p->next);
    //prin(p);
    printf("99\n");
    return 0;
}

void prin(chat *phead)
{
    chat *q = phead;
    while(q)
    {
        printf("a:%d\n",q->a);
        q = q->next;
    }
}

int main()
{
    int n;
    printf("please input the n :\n");
    scanf("%d",&n);
    create(n);
}
