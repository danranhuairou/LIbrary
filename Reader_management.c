#include"librarymain.h"

void Reader_management(User *us1)               //���߹���ϵͳ
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
         Reader_ui();
         scanf(" %c",&s);
         getchar();
         switch(s)
         {
             case '1':
             readerinput();break;
             case '2':
             readermodification();break;
             case '3':
             readerdeletion();break;
             case '4':
             findreader();break;
             case '5':
             readerdisplay();break;
             case '0':return;
             default:
             printf("����������ٴ����룡\n");
         }
     }
}
void readerinput()                      //������Ϣ���� 
{
    User *p=NULL;
    Reader *h=(Reader *)malloc(sizeof(Reader)),*pr=NULL;
    char user_name[20],readername[20],unit[20],phone[30],jus[10];
    printf("������Ҫ�����Ϣ�Ķ��ߺţ�");
    gets(user_name);
    p=User_head->next;
    while(p!=NULL)
    {
        if(strcmp(p->user_name,user_name)==0)
        {
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("���ߺŲ����ڣ�\n");
        return;
    }
    while(pr)
    {
        if(strcmp(pr->user_name,user_name)==0)
        {
            printf("���ߺ��Ѵ��ڣ�\n");
            return;
        }
        pr=pr->next;
    }
    strcpy(h->user_name,user_name);
    printf("���������������");
    gets(readername);
    strcpy(h->reader_name,readername);
    printf("��������ߵĵ�λ��");
    gets(unit);
    strcpy(h->unit,unit);
    while(1)
    {
        printf("����������ֻ��ţ�");
        gets(phone);
        if(strlen(phone)==11)
        {
            break;
        }
        printf("�ֻ��ų��ȴ���\n");
    }
    strcpy(h->phone,phone);
    while(1)
    {
        printf("�����������ݣ�1.ѧ�� 2.�̹�\n");
        gets(jus);
        if(jus[0]=='1'||jus[0]=='2')
        {
            if(strlen(jus)==1)
            {
                break;
            }
        }
        printf("�����ʽ����\n");
    }
    strcpy(h->jus,jus);
    pr=Reader_head;
    while(pr->next!=NULL)
    {
        pr=pr->next;
    }
    if(h->jus[0]=='2')
    {
        h->loanable=10;
    }
    else
    {
        h->loanable=5;
    }
    h->borrowed=0;
    pr->next=h;
    h->next=NULL;
    red_save();
    printf("����ɹ���\n");
}
void readermodification()               //������Ϣ�޸�
{
    Reader *h=Reader_head->next;
    int s;
    char user_name[20],se='?',readername[20],unit[20],phone[30],jus[10];
    printf("������Ҫ�޸���Ϣ�Ķ��ߺţ�");
    gets(user_name);
    while(h)
    {
        if(strcmp(h->user_name,user_name)==0)
        {
            break;
        }
        h=h->next;
    }
    if(h==NULL)
    {
        printf("���ߺŲ����ڣ�\n");
        return;
    }
    printf("������Ҫ�޸ĵ����ݣ�1.���� 2.��λ 3.�绰 4.��� 5.�ѽ����� 0.�˳�\n");
    scanf(" %c",&se);
    getchar();
    switch(se)
    {
        case '1':
            printf("�����޸�Ϊ��");
            gets(readername);
            strcpy(h->reader_name,readername);
            red_save();
            printf("�޸ĳɹ���\n");
            break;
        case '2':
            printf("��λ�޸�Ϊ��");
            gets(unit);
            strcpy(h->unit,unit);
            red_save();
            printf("�޸ĳɹ���\n");
            break;
        case '3':
            printf("�绰�޸�Ϊ��");
            while(1)
            {
                gets(phone);
                if(strlen(phone)==11)
                {
                    break;
                }
                printf("�绰���ȴ������ٴ����룡\n");
            }
            strcpy(h->phone,phone);
            red_save();
            printf("�޸ĳɹ���\n");
            break;
        case '4':
            while(1)
            {
                printf("����޸�Ϊ����1.ѧ�� 2.�̹���\n");
                gets(jus);
                if(jus[0]=='1'||jus[0]=='2')
                {
                    if(strlen(jus)==1)
                        break;
                }
                printf("����������ٴ����룡\n");
            }
            strcpy(h->jus,jus);
            if(h->jus[0]=='1')
            {
                h->loanable=5;
            }
            else
            {
                h->loanable=10;
            }
            red_save();
            printf("�޸ĳɹ���\n");
            break;
        case '5':
            printf("�ѽ������޸�Ϊ��");
            scanf("%d",&s);
            if(s>h->loanable)
            {
                printf("�ѽ���������\n");
                return;
            }   
            h->borrowed=s;
            printf("�޸ĳɹ���\n");
            red_save();
            break;
        case '0':
            return;
        default:
            printf("�����������ٴ����롣\n");
    }
}
void readerdeletion()                   //������Ϣɾ��
{
    Reader *p=Reader_head->next,*pr=NULL;
    printf("������Ҫɾ���Ķ��ߺţ�");
    char usr_nam[10];
    int n=0,flag=0;
    gets(usr_nam);
    while(p){
            if(strcmp(usr_nam,p->user_name)==0)
            {
                flag=1;
                if(n==0)
                {
                    Reader_head->next=p->next;
                    free(p);
                    break;
                }
                else
                {
                    if(p->next==NULL)
                    {
                        pr->next=NULL;
                        free(p);
                        break;
                    }
                    pr->next=p->next;
                    free(p);
                    break;
                }
            }
            n++;
            pr=p;
            p=p->next;
        }
        if(flag==1){
            red_save();
            printf("�޸ĳɹ�!\n");
        }
        if(flag==0)
        {
            printf("���ߺŲ�����!\n");
        }
}
void findreader()                       //������Ϣ��ѯ
{
    Reader *h=Reader_head->next;
    char username[20];
    printf("������Ҫ��ѯ��Ϣ�Ķ��ߺţ�");
    gets(username);
    while(h)
    {
        if(strcmp(h->user_name,username)==0)
        {
            printf("------------------------------------\n");
            printf("���ߺţ�%s\n",h->user_name);
            printf("������%s\n",h->reader_name);
            printf("��λ��%s\n",h->unit);
            printf("�绰��%s\n",h->phone);
            printf("�ɽ�������%d\n",h->loanable);
            printf("�ѽ�������%d\n",h->borrowed);
            printf("------------------------------------\n");
            return;
        }
        h=h->next;
    }
    printf("���ߺŲ����ڣ�\n");
}
void readerdisplay()                    //������Ϣ��ʾ
{
    Reader *p=Reader_head,*h=NULL,*t=NULL,*pr=NULL,*tr=NULL;
    while(p!=NULL)
    {
        Reader *pr=(Reader *)malloc(sizeof(Reader));
        pr->next=NULL;
        if(h==NULL)
        {
            h=pr;
            t=pr;
        }
        else
        {
            strcpy(pr->user_name,p->user_name);
            strcpy(pr->reader_name,p->reader_name);
            strcpy(pr->unit,p->unit);
            strcpy(pr->phone,p->phone);
            pr->loanable=p->loanable;
            pr->borrowed=p->borrowed;
            t=h->next;
            tr=h;
            while(t!=NULL&&strcmp(t->reader_name,pr->reader_name)<0)
            {
                t=t->next;
                tr=tr->next;
            }
            pr->next=t;
            tr->next=pr;
        }
        p=p->next;
    }
    h=h->next;
    printf("------------------------------------------------------------------\n");
    printf("���ߺ�  ����  ��λ       �绰        �ɽ�����  �ѽ�����\n");
    printf("------------------------------------------------------------------\n");
    while(h){
        printf("%s\t%s\t%s\t%s\t%d\t%d\n",h->user_name,h->reader_name,h->unit,h->phone,h->loanable,h->borrowed);
        h=h->next;
    }
    printf("-------------------------------------------------------------------\n");
}
