#include"librarymain.h"

void Reader_management(User *us1)               //读者管理系统
{
    char jus[3]="2";
     if(strcmp(jus,us1->jus)!=0)
     {
        printf("你没有该权限\n");
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
             printf("输入错误，请再次输入！\n");
         }
     }
}
void readerinput()                      //读者信息输入 
{
    User *p=NULL;
    Reader *h=(Reader *)malloc(sizeof(Reader)),*pr=NULL;
    char user_name[20],readername[20],unit[20],phone[30],jus[10];
    printf("请输入要添加信息的读者号：");
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
        printf("读者号不存在！\n");
        return;
    }
    while(pr)
    {
        if(strcmp(pr->user_name,user_name)==0)
        {
            printf("读者号已存在！\n");
            return;
        }
        pr=pr->next;
    }
    strcpy(h->user_name,user_name);
    printf("请输入读者姓名：");
    gets(readername);
    strcpy(h->reader_name,readername);
    printf("情输入读者的单位：");
    gets(unit);
    strcpy(h->unit,unit);
    while(1)
    {
        printf("请输入读者手机号：");
        gets(phone);
        if(strlen(phone)==11)
        {
            break;
        }
        printf("手机号长度错误！\n");
    }
    strcpy(h->phone,phone);
    while(1)
    {
        printf("请输入读者身份：1.学生 2.教工\n");
        gets(jus);
        if(jus[0]=='1'||jus[0]=='2')
        {
            if(strlen(jus)==1)
            {
                break;
            }
        }
        printf("输入格式错误！\n");
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
    printf("输入成功！\n");
}
void readermodification()               //读者信息修改
{
    Reader *h=Reader_head->next;
    int s;
    char user_name[20],se='?',readername[20],unit[20],phone[30],jus[10];
    printf("请输入要修改信息的读者号：");
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
        printf("读者号不存在！\n");
        return;
    }
    printf("请输入要修改的内容：1.姓名 2.单位 3.电话 4.身份 5.已借书数 0.退出\n");
    scanf(" %c",&se);
    getchar();
    switch(se)
    {
        case '1':
            printf("姓名修改为：");
            gets(readername);
            strcpy(h->reader_name,readername);
            red_save();
            printf("修改成功！\n");
            break;
        case '2':
            printf("单位修改为：");
            gets(unit);
            strcpy(h->unit,unit);
            red_save();
            printf("修改成功！\n");
            break;
        case '3':
            printf("电话修改为：");
            while(1)
            {
                gets(phone);
                if(strlen(phone)==11)
                {
                    break;
                }
                printf("电话长度错误，请再次输入！\n");
            }
            strcpy(h->phone,phone);
            red_save();
            printf("修改成功！\n");
            break;
        case '4':
            while(1)
            {
                printf("身份修改为：（1.学生 2.教工）\n");
                gets(jus);
                if(jus[0]=='1'||jus[0]=='2')
                {
                    if(strlen(jus)==1)
                        break;
                }
                printf("输入错误，请再次输入！\n");
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
            printf("修改成功！\n");
            break;
        case '5':
            printf("已借书数修改为：");
            scanf("%d",&s);
            if(s>h->loanable)
            {
                printf("已借书数过大！\n");
                return;
            }   
            h->borrowed=s;
            printf("修改成功！\n");
            red_save();
            break;
        case '0':
            return;
        default:
            printf("输入有误！请再次输入。\n");
    }
}
void readerdeletion()                   //读者信息删除
{
    Reader *p=Reader_head->next,*pr=NULL;
    printf("请输入要删除的读者号：");
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
            printf("修改成功!\n");
        }
        if(flag==0)
        {
            printf("读者号不存在!\n");
        }
}
void findreader()                       //读者信息查询
{
    Reader *h=Reader_head->next;
    char username[20];
    printf("请输入要查询信息的读者号：");
    gets(username);
    while(h)
    {
        if(strcmp(h->user_name,username)==0)
        {
            printf("------------------------------------\n");
            printf("读者号：%s\n",h->user_name);
            printf("姓名：%s\n",h->reader_name);
            printf("单位：%s\n",h->unit);
            printf("电话：%s\n",h->phone);
            printf("可借书数：%d\n",h->loanable);
            printf("已借书数：%d\n",h->borrowed);
            printf("------------------------------------\n");
            return;
        }
        h=h->next;
    }
    printf("读者号不存在！\n");
}
void readerdisplay()                    //读者信息显示
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
    printf("读者号  姓名  单位       电话        可借书数  已借书数\n");
    printf("------------------------------------------------------------------\n");
    while(h){
        printf("%s\t%s\t%s\t%s\t%d\t%d\n",h->user_name,h->reader_name,h->unit,h->phone,h->loanable,h->borrowed);
        h=h->next;
    }
    printf("-------------------------------------------------------------------\n");
}
