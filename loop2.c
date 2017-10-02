/*************************************************************************
	> File Name: loop2.c
	> Author: 
	> Mail: 
	> Created Time: 一 10/ 2 12:02:48 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct chat
{
    int a;
    struct chat *next;
}chat;

void prin(chat *phead);

/*不带头节点的单向循环链表*/
void create(int n)
{
    chat *phead;
    chat *r;
    chat *stu;
    for(int i = 0; i< n ;i++)
    {
        if(i == 0)
        {
            phead = (chat *)malloc(sizeof(chat));
            r = phead;
            printf("please input the a:\n");
            scanf("%d",&phead -> a);
            phead -> next = phead;
        }
        else
        {
            stu = (chat *)malloc(sizeof(chat));
            printf("please input th a:\n");
            scanf("%d",&stu->a);
            r -> next = stu;
            r = stu;
        }
    }
    stu->next = phead;
    prin(phead);
}

void prin(chat *phead)
{
    chat *p = phead;
    while(p)
    {
        printf("a:%d\n",p->a);
        p = p->next;
    }
}

int main()
{
    int n;
    printf("please input the n:\n");
    scanf("%d",&n);
    create(n);
}

