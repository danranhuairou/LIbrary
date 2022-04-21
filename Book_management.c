#include "librarymain.h"

void Book_management(User *us1)
{
    char se='?';
    while(se!='0')
    {
        Book_ui();
        scanf(" %c",&se);
        getchar();
        switch(se)
        {
            case '0':
            return;
            case '1':
            Book_input(us1);break;
            case '2':
            Book_modification(us1);break;
            case '3':
            Book_find();break;
            case '4':
            Summary_statistics();break;
            default:
            printf("输入格式错误！\n");
        }
    }
}
void Book_input(User *un)
{
    int total=0,total1=0,total2=0,total3=0;
    total=bok_load(total);
    total1=bok_name_load(total1);
    total2=bok_author_load(total2);
    total3=bok_press_load(total3);
    int i;
    char jus[3]="2";
    if(strcmp(jus,un->jus)!=0)
    {
        printf("你没有该权限！\n");
        return;
    }
    printf("请输入要添加的书号：（长度为四位）");
    char number[30];
    while(1)
    {
        gets(number);
        for(i=0;i<=total;i++)
        {
            if(strcmp(number,Book_head[i].book_number)==0)
            {
                break;
            }
        }
        if(i>total)
        {
            if(strlen(number)==4)
            {
                break;
            }
            printf("格式错误！\n");
            continue;
        }
        printf("书名号已存在！\n");
    }
    char name[30];
    printf("请输入书名：");
    gets(name);
    char author[30];
    printf("请输入作者：");
    gets(author);
    char press[30];
    printf("请输入出版社：");
    gets(press);
    int c;
    printf("请输入藏书数：");
    scanf("%d",&c);
    int l;
    printf("请输入借出数：");
    scanf("%d",&l);
    int pointer1=0,pointer2=0,pointer3=0;
    total++;
    int flag1=-1;
    for(i=total1;i>=0;i--)
    {
        if(strcmp(name,Name_head[i].book_name)==0)
        {
            pointer1=Name_head[i].pointer;
            Name_head[i].pointer=total+1;
            Name_head[i].len++;
            flag1=0;
            break;
        }
    }
    if(flag1==-1)
    {
        total1++;
        strcpy(Name_head[total1].book_name,name);
        Name_head[total1].pointer=total+1;
        Name_head[total1].len=1;
    }
    int flag2=-1;
    for(i=total2;i>=0;i--)
    {
        if(strcmp(author,Author_head[i].book_author)==0)
        {
            pointer2=Author_head[i].pointer;
            Author_head[i].pointer=total+1;
            Author_head[i].len++;
            flag2=0;
            break;
        }
    }
    if(flag2==-1)
    {
        total2++;
        strcpy(Author_head[total2].book_author,author);
        Author_head[total2].pointer=total+1;
        Author_head[total2].len=1;
    }
    int flag3=-1;
    for(i=total3;i>=0;i--)
    {
        if(strcmp(press,Press_head[i].book_press)==0)
        {
            pointer3=Press_head[i].pointer;
            Press_head[i].pointer=total+1;
            Press_head[i].len++;
            flag3=0;
            break;
        }
    }
    if(flag3==-1)
    {
        total3++;
        strcpy(Press_head[total3].book_press,press);
        Press_head[total3].pointer=total+1;
        Press_head[total3].len=1;
    }
    strcpy(Book_head[total].book_number,number);
    strcpy(Book_head[total].book_name,name);
    strcpy(Book_head[total].book_author,author);
    strcpy(Book_head[total].book_press,press);
    Book_head[total].collection=c;
    Book_head[total].lending=l;
    Book_head[total].pointer1=pointer1;
    Book_head[total].pointer2=pointer2;
    Book_head[total].pointer3=pointer3;
    bok_save(total);
    bok_name_save(total1);
    bok_author_save(total2);
    bok_press_save(total3);
}
void Book_modification(User *un)
{
    char jus[3]="2",number[10],s;
    if(strcmp(jus,un->jus)!=0)
    {
        printf("你没有该权限！\n");
        return;
    }
    int total=0,i,flag=0;
    total=bok_load(total);
    printf("请输入要修改的书号：");
    gets(number);
    for(i=0;i<=total;i++)
    {
        if(strcmp(Book_head[i].book_number,number)==0)
        {
            printf("要修改的内容为：1.藏书量 2.借出数\n");
            scanf(" %c",&s);
            getchar();
            switch(s)
            {
                case '1':
                printf("藏书量修改为：");
                scanf("%d",&Book_head[i].collection);
                printf("修改成功！\n");
                bok_save(total);
                break;
                case '2':
                printf("借出量改为：");
                scanf("%d",&Book_head[i].lending);
                printf("修改成功！\n");
                bok_save(total);
                break;
                default:
                printf("输入错误！\n");
            }
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("读者号不存在！\n");
    }
}
void Book_find()
{
    char se='?';
    while(se!=0)
    {
        findbook_ui();
        scanf(" %c",&se);
        getchar();
        switch(se)
        {
            case '0':
            return;
            case '1':
            numberfind();break;
            case '2':
            namefind();break;
            case '3':
            authorfind();break;
            case '4':
            pressfind();break;
            default:
            printf("输入格式错误！\n");
        }
    }
}
void numberfind()
{
    int total=0,flag=0,i;
    char number[100];
    total=bok_load(total);
    printf("请输入要查询的书号：\n");
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
        printf("账号不存在!\n");
        return;
    }
    printf("----------------------------------------------\n");
    printf("书号：%s\n",Book_head[i].book_number);
    printf("书名：%s\n",Book_head[i].book_name);
    printf("作者：%s\n",Book_head[i].book_author);
    printf("出版社：%s\n",Book_head[i].book_press);
    printf("藏书量：%d\n",Book_head[i].collection);
    printf("借出数：%d\n",Book_head[i].lending);
    printf("-----------------------------------------------\n");
}
void namefind()
{
    int total1=0,total=0,i,flag=0,pointer1;
    char name[100];
    total=bok_load(total);
    total1=bok_name_load(total1);
    printf("请输入要查询的书名：");
    gets(name);
    for(i=0;i<=total1;i++)
    {
        if(strcmp(Name_head[i].book_name,name)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("图书馆没有此书！\n");
        return;
    }
    pointer1=Name_head[i].pointer-1;
    printf("----------------------------------------\n");
    printf("书号  书名  作者  出版社  藏书量  借出数  \n");
    printf("----------------------------------------\n");
    for(int l=0;l<Name_head[i].len;l++)
    {
        printf("%s  %s  %s  %s  %d  %d\n",Book_head[pointer1].book_number,Book_head[pointer1].book_name,Book_head[pointer1].book_author,Book_head[pointer1].book_press,Book_head[pointer1].collection,Book_head[pointer1].lending);
        pointer1=Book_head[pointer1].pointer1-1;
    }
    printf("-----------------------------------------\n");
}
void authorfind()
{
    int total2=0,total=0,i,flag=0,pointer2;
    char author[100];
    total=bok_load(total);
    total2=bok_author_load(total2);
    printf("请输入要查询的作者：");
    gets(author);
    for(i=0;i<=total2;i++)
    {
        if(strcmp(Author_head[i].book_author,author)==0)\
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("图书馆没有此书！\n");
        return;
    }
    pointer2=Author_head[i].pointer-1;
    printf("----------------------------------------\n");
    printf("书号  书名  作者  出版社  藏书量  借出数  \n");
    printf("----------------------------------------\n");
    for(int l=0;l<Author_head[i].len;l++)
    {
        printf("%s  %s  %s  %s  %d  %d\n",Book_head[pointer2].book_number,Book_head[pointer2].book_name,Book_head[pointer2].book_author,Book_head[pointer2].book_press,Book_head[pointer2].collection,Book_head[pointer2].lending);
        pointer2=Book_head[pointer2].pointer2-1;
    }
    printf("-----------------------------------------\n");
}
void pressfind()
{
    int total3=0,total=0,i,flag=0,pointer3;
    char press[100];
    total=bok_load(total);
    total3=bok_press_load(total3);
    printf("请输入要查询的出版社：");
    gets(press);
    for(i=0;i<=total3;i++)
    {
        if(strcmp(Press_head[i].book_press,press)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("图书馆没有此书！\n");
        return;
    }
    pointer3=Press_head[i].pointer-1;
    printf("----------------------------------------\n");
    printf("书号  书名  作者  出版社  藏书量  借出数  \n");
    printf("----------------------------------------\n");
    for(int l=0;l<Press_head[i].len;l++)
    {
        printf("%s  %s  %s  %s  %d  %d\n",Book_head[pointer3].book_number,Book_head[pointer3].book_name,Book_head[pointer3].book_author,Book_head[pointer3].book_press,Book_head[pointer3].collection,Book_head[pointer3].lending);
        pointer3=Book_head[pointer3].pointer3-1;
    }
    printf("-----------------------------------------\n");
}
void Summary_statistics()
{
    int total=0,flag=0;
    total=bok_load(total);
    for(int i=1;i<=total;i++)
    {
        if(Book_head[i].lending>Book_head[flag].lending)
        {
            flag=i;
        }
    }
    printf("-----------------------------\n");
    printf("图书馆总共有 %d 本图书\n",total+1);
    printf("最热门图书书号： %s 《 %s 》\n",Book_head[flag].book_number,Book_head[flag].book_name);
    printf("-----------------------------\n");
}

