#include "librarymain.h"

void Book_circulation_management(User *us1)
{
    char jus[3]="2";
     if(strcmp(jus,us1->jus)!=0)
     {
        printf("��û�и�Ȩ��\n");
        return;
     }
     char s='?';
     while(s!='0')
     {
         bookc_ui();
         scanf(" %c",&s);
         getchar();
         switch(s)
         {
             case '1':
             loan();break;
             default:
             printf("�����ʽ����\n");
         }
     }
}
void loan()
{
    int total=0,flag=0,i=0;
    total=bok_load(total);
    char number[20];
    printf("������Ҫ�����ţ�");
    gets(number);
    for(i=0;i<=total;i++)
    {
        if(strcmp(Book_head[i].book_number,number)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("����Ų����ڣ�\n");
        return;
    }
    if(Book_head[i].collection==Book_head[i].lending)
    {
        printf("�����ѱ�����\n");
        return;
    }
    printf("������Ҫ��Ķ��ߺţ�");
    char user_name[20];
    Reader *p=Reader_head->next;
    gets(user_name);
    while(p)
    {
        if(strcmp(p->user_name,user_name)==0)
        {
            flag=0;
            break;
        }
        p=p->next;
    }
    if(flag==1)
    {
        printf("�ö��ߺŲ����ڣ�\n");
        return;
    }
    if(p->loanable<=p->borrowed)
    {
        printf("�ɽ����������\n");
        return;
    }
    Loan_return *t1=Loan_head->next;
    while(t1)
    {
        if(strcmp(t1->Book_number,number)==0&&strcmp(t1->User_number,user_name)==0)
        {
            if(t1->r_day==0)
            {
                printf("�������ڽ����У������ظ��裡\n");
                return;
            }
        }
        t1=t1->next;
    }
    char s='?';
    printf("�Ƿ�Ҫִ�иò�����(y/n)");
    while(s!='y'&&s!='Y')
    {
        scanf(" %c",&s);
        getchar();
        switch(s)
        {
            case 'y':
            break;
            case 'Y':
            break;
            case 'n':
            return;break;
            case 'N':
            return;break;
            default:
            printf("�����ʽ����\n");
        }
    }
    Loan_return *t=Loan_head->next,*pr=(Loan_return *)malloc(sizeof(Loan_return));
    pr->next=NULL;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=pr;
    printf("������Ҫ����ʱ�����ڣ�\n");
    printf("************************\n");
    printf("�꣺\n");
    printf("1. 2022�� 2. 2023��\n");
    char se='?';
    while(se!='1'&&se!='2')
    {
        scanf(" %c",&se);
        switch(se)
        {
            case '1':
            pr->l_year=2022;break;
            case '2':
            pr->l_year=2023;break;
            default:
            printf("�������\n");
        }
    }
    int m=0;
    printf("�£�");
    while(m<=0||m>=12)
    {
        scanf("%d",&m);
        if(m<0||m>=12)
        {
            printf("��������\n");
        }
    }
    int d=0,k;
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
        k=31;
    }
    if(m==4||m==6||m==9||m==11)
    {
        k=30;
    }
    if(m==2)
    {
        k=28;
    }
    printf("�գ�");
    while(d<=0||d>=k)
    {
        scanf("%d",&d);
        if(d<=0||d>=k)
        {
            printf("��������\n");
        }
    }
    char marks[30];
    printf("�����뱸ע������������������ޣ����û�������ޣ�\n");\
    getchar();
    gets(marks);
    strcpy(pr->Book_number,number);
    strcpy(pr->User_number,user_name);
    pr->l_month=m;
    pr->l_day=d;
    pr->r_year=0;
    pr->r_month=0;
    pr->r_day=0;
    strcpy(pr->remarks,marks);
    Loan_save();
    p->borrowed++;
    red_save();
    Book_head[i].lending++;
    bok_save(total);
    printf("����ɹ���\n");
}