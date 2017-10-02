/*************************************************************************
	> File Name: Josephus1.c
	> Author: 
	> Mail: 
	> Created Time: 五  9/22 14:39:32 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct chat
{
    int id;
    int passwd;
    struct chat *next;
}Jose;

Jose *create(Jose *phead,int n)
{
    phead = (Jose *)malloc(sizeof(Jose));
    phead->next = NULL;
    int i = 0;
    Jose *q = phead;
    Jose *p = phead;
    Jose *r;
    for(i = 0;i < n;i++)
    {
        if(i != 0){
        r = (Jose *)malloc(sizeof(Jose));
        r->id = i+1;
        printf("please input the password for NO.%d:",i);
        scanf("%d",&r->passwd);
        q -> next = r;
        r -> next = phead;
        q = r;
          
        }
        if(i == 0){
            phead -> id = i+1;
            printf("please input the password for NO.%d:",i);
            scanf("%d",&phead -> passwd);
            phead -> next = phead;
        }

    }
    return phead;
}

void prin(Jose *phead)
{
    printf("-------遍历链表-------\n");
    Jose *p = phead;
    while(p->next!=phead)
    {
        p = p->next;
        printf("%d\n",p->id);
    }
}

void Josephus(Jose *phead, int m)
{
    Jose *p = phead;
    Jose *pre = p;
    Jose *del = NULL;
    int flag = 1;
    while(flag)
    {
        for(int i=1;i<m;i++)
        {
            pre = p;
            p = p->next;
        }
        if(pre == p)
        {
            flag = 0;
        }
        else
        {
            del = p;
            m = p->passwd;
            pre->next = p->next;
            p = p->next;
            printf("delete:%d\n",del->passwd);
            free(del);
        }
       /* del = p;
        m = del->passwd;
        pre->next = p->next;
        p = pre;
        p = del->next;
        printf("被删除的节点是:%d\n",p->passwd);
        free(del);*/
    }
    printf("delete:%d\n",p ->passwd);
    free(p);
}
int main()
{
    int n;
    printf("please input the people of numbers:\n");
    scanf("%d",&n);
    Jose *phead = NULL;
    /*创建单向循环链表*/
    phead = create(phead,n);
    /*遍历打印单向循环链表*/
    //prin(phead);
    /*进行约瑟夫环问题*/
    int m = 0;
    printf("please input the init password:\n");
    scanf("%d",&m);
    Josephus(phead,m);
    return 0;
}
