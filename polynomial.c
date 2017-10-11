/*************************************************************************
	> File Name: polynomial.c
	> Author:Jialuhu 
	> Mail: 
	> Created Time: 一 10/ 2 13:23:47 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial
{
    float coef;//系数
    int e;//指数
    struct polynomial *next;
}poly;

poly *sub(poly *pa, poly *pb);
poly *add(poly *pa, poly *pb);
/*建立多项式*/
poly *create(int n)
{
    poly *phead;
    poly *r;
    poly *stu;
    phead = (poly *)malloc(sizeof(poly));
    r = phead;
    for(int i=0; i<n; i++)
    {
        stu = (poly *)malloc(sizeof(poly));
        printf("请输入系数:\n");
        scanf("%f",&stu->coef);
        printf("请输入指数:\n");
        scanf("%d",&stu->e);
        r -> next = stu;
        r = stu;
    }
    stu -> next = NULL;
    return phead;
}

void prin(poly *phead)
{
    poly *p = phead->next;
    while(p)
    {
        printf("%f\t%d\n",p->coef,p->e);
        p = p->next;
    }
}
/*一元多项式的分解，并且打印*/
void explan_rin(poly *phead)
{
    int i=0;
    poly *p = phead->next;
    while(p!=NULL)
    {
        /*第一项时候的分解*/
        if(i==0)
        {
            if(p->coef == 0)
            {
                p = p->next;
                continue;
            }
            if(p->e==0)
            {
                printf("%f",p->coef);
            }
            if(p->e == 1)
            {
                printf("%fX",p->coef);
            }
            else{
                if(p->coef==1)
                {
                    printf("X^%d",p->e);
                }
                else{
                    printf("%fX^%d",p->coef,p->e);
                }
            }
            p = p->next;
            ++i;
            continue;
        }
        /*第二项及其之后的分解*/
        else{
            if(p->coef == 0)
            {
                p = p->next;
                continue;
            }
            else{
                /*系数大于零的时候*/
                if(p->coef > 0)
                {
                    if(p->e == 1&&p->coef==1)
                    {
                        printf("+X");
                    }
                    if(p->e==1&&p->coef!=1)
                    {
                        printf("+%fX",p->coef);
                    }
                    if(p->e == 0)
                    {
                        printf("+%f",p->coef);
                    }
                    else{
                        printf("+%fX^%d",p->coef,p->e);
                    }
                    ++i;
                    p = p->next;
                }
                /*系数小于零的时候*/
                if(p->coef<0)
                {
                    if(p->e==1&&p->coef==1)
                    {
                        printf("-X");
                    }
                    if(p->e==1&&p->coef!=1)
                    {
                        printf("-%fX",p->coef);
                    }
                    if(p->e==0)
                    {
                        printf("-%f",p->coef);
                    }
                    else{
                        printf("-%fX^%d",p->coef,p->e);
                    }
                    ++i;
                    p = p ->next;
                }
            }
            
        }
    }
}


void po_prin(poly *phead)
{
    poly *q = phead->next;
    int flag = 1;
    if(!q)
    {
        printf("0");
        printf("\n");
        return;
    }
    else{
        while(q)
        {
            if(flag!=1&&q->coef>0)
            {
                printf("+");
            }
            if(q->coef!=1 && q->coef!=-1)
            {
                printf("%g",q->coef);
                if(q->e==1)
                {
                    putchar('X');
                }
                else if(q->e)
                {
                    printf("X^%d",q->e);
                }
            }
            else{
                if(q->coef == 1)
                {
                    if(!q->e)
                    {
                        putchar('1');
                    }
                    else if(q->e==1) putchar('X');
                    else printf("X^%d",q->e);
                }
                if(q->coef == -1)
                {
                    if(!q->e) printf("-1");
                    else if(q->e == 1) printf("-X");
                    else printf("-X^%d",q->e);
                }
            }
            q = q->next;
            flag++;
        }
        printf("\n");
    }
}

/*多项式相加*/
poly *add(poly *pa, poly *pb)
{
    poly *a = pa->next;
    poly *b = pb->next;
    poly *pc,*qc,*head;
    pc = (poly *)malloc(sizeof(poly));
    pc->next = NULL;
    head = pc;
    while(a!=NULL && b!=NULL)
    {
        qc = (poly *)malloc(sizeof(poly));
        if(a->e < b->e)
        {
            qc -> e = a -> e;
            qc -> coef = a -> coef;
            a = a->next;
            printf("guize1\n");
            //continue;
        }
        else if(a->e == b->e)
        {
            qc -> e = a->e;
            qc -> coef = a->coef + b->coef;
            a = a->next;
            b = b->next;
           //continue;
        }
        else
        {
            qc -> e = b -> e;
            qc -> coef = b -> coef;
            b = b->next;
            //continue;
        }
        if(qc->coef != 0)
        {
            pc->next = qc;
            pc = qc;
            /*qc->next = pc->next;
            pc->next = qc;
            pc = qc;*/
        }
        else{
            free(qc);
        }
    }
    qc->next = NULL;
    while(a != NULL)
    {
        qc = (poly *)malloc(sizeof(poly));
        qc->e = a->e;
        qc->coef = a->coef;
        a = a->next;
            pc->next = qc;
            pc = qc;
        /*qc->next = pc->next;
        pc->next = qc;
        pc = qc;*/
    }
    while(b != NULL)
    {
        qc = (poly *)malloc(sizeof(poly));
        qc -> coef = b->coef;
        qc -> e = b->e;
        b = b->next;
            pc->next = qc;
            pc = qc;
        /*qc -> next = pc->next;
        pc ->next = qc;
        pc = qc;*/
    }
    qc->next = NULL;
    return head;
}

poly *sub(poly *pa, poly *pb)
{
    poly *h = pb;
    poly *p = pb->next;
    poly *pd;
    while(p)
    {
        p->coef = -1*p->coef;
        p = p->next;
    }
    pd = add(pa,h);
    for(p=h->next;p;p=p->next)
    {
        p->coef = -1*p->coef;
    }
    return pd;
}

poly *dao(poly *phead)
{
    poly *stu,*pheadc,*q;
    poly *p = phead->next;
    q = (poly *)malloc(sizeof(poly));
    q->next = NULL;
    pheadc = q;
    while(p)
    {
        stu = (poly *)malloc(sizeof(poly));
        if(p->e == 0)
        {
            p = p->next;
            continue;
        }
        else{
            stu -> e = p->e-1;
            stu -> coef = (p->coef)*(p->e);
            p = p->next;
        }
        q->next = stu;
        q = stu;
    }
    stu->next = NULL;
    return pheadc;
}

void menu()
{
    poly *a,*b;
    system("echo '\033[;34m\n欢迎来到一元多项式计算器\033[0m'|pv -qL 10\n");
    int choice = 0;
    printf("|----------------------------------------|\n");
    printf("|-----------------1、求导----------------|\n");
    printf("|-----------------2、加法----------------|\n");
    printf("|-----------------3、减法----------------|\n");
    printf("|----------------------------------------|\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            int n,choice;
            int flag = 1;
            poly *pheada;
            do{
                printf("请输入要输入总共的项数:\n");
                scanf("%d",&n);
                pheada = create(n);
                printf("求导如下：\n");
                poly *q,*p;
                q = dao(pheada);
                po_prin(q);
            /*po_prin(q);
            p = dao(b);
            po_prin(p);*/
                printf("继续请输入1，不继续请输入0\n");
                scanf("%d",&flag);
            }while(flag);
            break;
        }
        case 2:
        {
            int n;
            int flag = 1;
            poly *pheada,*pheadb;
            poly *q;
            do{
                for(int i = 0;i<2;i++)
                {
                    printf("请输入第%d个式子\n",i+1);
                    printf("请输入要输入总共的项数:\n");
                    scanf("%d",&n);
                    if(i==0)
                    {
                        pheada = create(n);
                        po_prin(pheada);
                    }
                    else{
                        pheadb = create(n);
                        po_prin(pheadb);
                    }
                }
                printf("求和如下：\n");
                q = add(pheada,pheadb);
                po_prin(q);
                printf("继续请输入1，结束请输入0:\n");
                scanf("%d",&flag);
            }while(flag);
            break;
        }
        case 3:
        {
            int n;
            int flag = 1;
            int choice = 0;
            poly *pheada,*pheadb;
            poly *q;
            do{
                for(int i=0;i<2;i++)
                {
                    printf("请输入第%d个式子\n",i+1);
                    printf("请输入要输入总共的项数:\n");
                    scanf("%d",&n);
                    if(i==0)
                    {
                        pheada = create(n);
                        po_prin(pheada);
                    }
                    else{
                        pheadb = create(n);
                        po_prin(pheadb);
                    }
                    printf("相减如下：\n");
                    q =  sub(pheada,pheadb);
                    po_prin(q);
                    printf("继续请输入1，结束请输入0:\n");
                    scanf("%d",&flag);
                }
            }while(flag);
            /*printf("相减如下:\n");
            q=sub(a,b);
            po_prin(q);*/
            break;
        }
    }


}
int main()
{
    poly *pheada;
    poly *pheadb;
    poly *c,*k,*d,*r;
    int n;
    //phead = (poly *)malloc(sizeof(poly));
    //printf("please input the n:\n");
   // scanf("%d",&n);
   // pheada = create(n);
 /*   printf("求导得出：\n");
    r = dao(pheada);
    po_prin(r);
    prin(pheada);*/
    printf("\n");
 //   explan_rin(phead);
    /*printf("please input the n:\n");
    scanf("%d",&n);
    pheadb = create(n);
    printf("两个式子如下：\n");
    po_prin(pheada);
    po_prin(pheadb);
   d = dao(pheadb);
    printf("求导得出：\n");
    po_prin(d);
    prin(pheadb);
    po_prin(pheada);
    printf("\n");
    po_prin(pheadb);
    printf("\n");
    c = add(pheada,pheadb);
    printf("相加:\n");
    po_prin(c);
    printf("相减：\n");
    k = sub(pheada,pheadb);
    po_prin(k);*/
    menu();
}
