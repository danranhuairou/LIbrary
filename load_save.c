#include "librarymain.h"

User *usr_load()                    //用户文件读取
{
    FILE *fp;
    User *h = NULL, *t = NULL, *p = NULL;
    if ((fp = fopen("usr.txt", "r")) == NULL)
    {
        printf("Open usr.txt error!");
        exit(0);
    }
    while (!feof(fp))
    {
        p = (User *)malloc(sizeof(User));
        p->next = NULL;
        fscanf(fp, "%s", p->user_name);
        fscanf(fp, "%s", p->user_passw);
        fscanf(fp, "%s", p->jus);
        if (h == NULL)
        {
            h = p;
        }
        else
        {
            t->next = p;
        }
        t = p;
    }
    fclose(fp);
    return h;
}
void usr_save()                     //用户文件保存
{
    FILE *fp=fopen("usr.txt","w");
    if(fp==NULL)
    {
        printf("Error!");
        exit(1);
    }
    User *p=User_head->next;
    while(p!=NULL)
    {
        fprintf(fp,"%s ",p->user_name);
        fprintf(fp,"%s ",p->user_passw);
        if(p->next==NULL)
        {
            fprintf(fp,"%s",p->jus);
            break;
        }
        fprintf(fp,"%s\n",p->jus);
        p=p->next;
    }
    fclose(fp);
}
Reader *red_load()                  //读者信息保存
{
    FILE *fp;
    Reader *h=NULL,*p=NULL,*t=NULL;
    if((fp=fopen("red.txt","r"))==NULL)
    {
        printf("Error!\n");
        exit(1);
    }
    while(!feof(fp))
    {
        h=(Reader *)malloc(sizeof(Reader));
        h->next=NULL;
        fscanf(fp,"%s",h->user_name);
        fscanf(fp,"%s",h->reader_name);
        fscanf(fp,"%s",h->unit);
        fscanf(fp,"%s",h->phone);
        fscanf(fp,"%d",&h->loanable);
        fscanf(fp,"%d",&h->borrowed);
        fscanf(fp,"%s",h->jus);
        if(p==NULL)
        {
            p=h;
        }
        else
        {
            t->next=h;
        }
        t=h;
    }
    fclose(fp);
    return p;
}
void red_save()                     //读者文件保存
{
    FILE *fp;
    if((fp=fopen("red.txt","w"))==NULL)
    {
        printf("error!\n");
        exit(1);
    }
    Reader *p=Reader_head->next;
    while(p!=NULL)
    {
         
        fprintf(fp,"%s ",p->user_name);
        fprintf(fp,"%s ",p->reader_name);
        fprintf(fp,"%s ",p->unit);
        fprintf(fp,"%s ",p->phone);
        fprintf(fp,"%d ",p->loanable);
        fprintf(fp,"%d ",p->borrowed);
        if(p->next==NULL)
        {
            fprintf(fp,"%s",p->jus);
            break;
        }
        fprintf(fp,"%s\n",p->jus);
        p=p->next;
    }
    fclose(fp);
}
int bok_load(int total)                     //图书文件读取
{
    FILE *fp;
    if((fp=fopen("bok.txt","r"))==NULL)
    {
        printf("打开失败！\n");
        exit(1);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s",Book_head[total].book_number);
        fscanf(fp,"%s",Book_head[total].book_name);
        fscanf(fp,"%s",Book_head[total].book_author);
        fscanf(fp,"%s",Book_head[total].book_press);
        fscanf(fp,"%d",&Book_head[total].collection);
        fscanf(fp,"%d",&Book_head[total].lending);
        fscanf(fp,"%d",&Book_head[total].pointer1);
        fscanf(fp,"%d",&Book_head[total].pointer2);
        fscanf(fp,"%d",&Book_head[total].pointer3);
        total++;
    }
    total--;
    fclose(fp);
    return total;
}
void bok_save(int total)                     //图书文件保存
{
    FILE *fp;
    if((fp=fopen("bok.txt","w"))==NULL)
    {
        printf("打开失败！\n");
        exit(1);
    }
    for(int i=0;i<=total;i++)
    {
        fprintf(fp,"%s ",Book_head[i].book_number);
        fprintf(fp,"%s ",Book_head[i].book_name);
        fprintf(fp,"%s ",Book_head[i].book_author);
        fprintf(fp,"%s ",Book_head[i].book_press);
        fprintf(fp,"%d ",Book_head[i].collection);
        fprintf(fp,"%d ",Book_head[i].lending);
        fprintf(fp,"%d ",Book_head[i].pointer1);
        fprintf(fp,"%d ",Book_head[i].pointer2);
        if(i==total)
        {
            fprintf(fp,"%d",Book_head[i].pointer3);
            break;
        }
        fprintf(fp,"%d\n",Book_head[i].pointer3);
    }
    fclose(fp);
}
int bok_name_load(int total1)
{
    FILE *fp;
    if((fp=fopen("bok_name.txt","r"))==NULL)
    {
        printf("打开失败！\n");
        exit(1);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s",Name_head[total1].book_name);
        fscanf(fp,"%d",&Name_head[total1].pointer);
        fscanf(fp,"%d",&Name_head[total1].len);
        total1++;
    }
    total1--;
    fclose(fp);
    return total1;
}
void bok_name_save(int total1)
{
    FILE *fp;
    if((fp=fopen("bok_name.txt","w"))==NULL)
    {
        printf("打开失败！\n");
        exit(1);
    }
    for(int i=0;i<=total1;i++)
    {
        fprintf(fp,"%s ",Name_head[i].book_name);
        fprintf(fp,"%d ",Name_head[i].pointer);
        if(i==total1)
        {
            fprintf(fp,"%d",Name_head[i].len);
            break;
        }
        fprintf(fp,"%d\n",Name_head[i].len);
    }
    fclose(fp);
}
int bok_author_load(int total2)
{
    FILE *fp;
    if((fp=fopen("bok_author.txt","r"))==NULL)
    {
        printf("打开失败！\n");
        exit(1);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s",Author_head[total2].book_author);
        fscanf(fp,"%d",&Author_head[total2].pointer);
        fscanf(fp,"%d",&Author_head[total2].len);
        total2++;
    }
    total2--;
    fclose(fp);
    return total2;
}
void bok_author_save(int total2)
{
    FILE *fp;
    if((fp=fopen("bok_author.txt","w"))==NULL)
    {
        printf("打开失败！\n");
        exit(1);
    }
    for(int i=0;i<=total2;i++)
    {
        fprintf(fp,"%s ",Author_head[i]);
        fprintf(fp,"%d ",Author_head[i].pointer);
        if(i==total2)
        {
            fprintf(fp,"%d",Author_head[i].len);
            break;
        }
        fprintf(fp,"%d\n",Author_head[i].len);
    }
    fclose(fp);
}
int bok_press_load(int total3)
{
    FILE *fp;
    if((fp=fopen("bok_press.txt","r"))==NULL)
    {
        printf("打开失败！\n");
        exit(1);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s",Press_head[total3].book_press);
        fscanf(fp,"%d",&Press_head[total3].pointer);
        fscanf(fp,"%d",&Press_head[total3].len);
        total3++;
    }
    total3--;
    fclose(fp);
    return total3;
}
void bok_press_save(int total3)
{
    FILE *fp;
    if((fp=fopen("bok_press.txt","w"))==NULL)
    {
        printf("打开失败！\n");
        exit(1);
    }
    for(int i=0;i<=total3;i++)
    {
        fprintf(fp,"%s ",Press_head[i].book_press);
        fprintf(fp,"%d ",Press_head[i].pointer);
        if(i==total3)
        {
            fprintf(fp,"%d",Press_head[i].len);
            break;
        }
        fprintf(fp,"%d\n",Press_head[i].len);
    }
    fclose(fp);
}
Loan_return *Loan_load()
{
    FILE *fp;
    Loan_return *h = NULL, *t = NULL, *p = NULL;
    if ((fp = fopen("lod.txt", "r")) == NULL)
    {
        printf("Open usr.txt error!");
        exit(0);
    }
    while(!feof(fp))
    {
        p = (Loan_return *)malloc(sizeof(Loan_return));
        p->next = NULL;
        fscanf(fp,"%s %s %d %d %d %d %d %d %s",p->Book_number,p->User_number,&p->l_year,&p->l_month,&p->l_day,&p->r_year,&p->r_month,&p->r_day,p->remarks);
        if (h == NULL)
        {
            h = p;
        }
        else
        {
            t->next = p;
        }
        t = p;
    }
    fclose(fp);
    return h;
}
void Loan_save()
{
    FILE *fp=fopen("lod.txt","w");
    if(fp==NULL)
    {
        printf("Error!");
        exit(1);
    }
    Loan_return *p=Loan_head->next;
    while(1)
    {
        if(p->next==NULL)
        {
            fprintf(fp,"%s %s %d %d %d %d %d %d %s",p->Book_number,p->User_number,p->l_year,p->l_month,p->l_day,p->r_year,p->r_month,p->r_day,p->remarks);
            break;
        }
        fprintf(fp,"%s %s %d %d %d %d %d %d %s\n",p->Book_number,p->User_number,p->l_year,p->l_month,p->l_day,p->r_year,p->r_month,p->r_day,p->remarks);
        p=p->next;
    }
    fclose(fp);
}