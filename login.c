//登录系统
#include "librarymain.h"

void login()                        //登录系统
{
    User *us = NULL;
    char s = '1';
    char usr_nam[20];
    printf("读者号:");
    gets(usr_nam);
    us = find_usr(usr_nam);         //找到账号函数
    if (us == NULL)                             
    {
        printf("账号不存在！\n");      
        return;
    }
    printf("密码：");
    if (password(us) == 0)          //找到账号密码
    {
        return;
    }
    printf("\n登录成功!\n");
    mainsystem(us);                 //进入主系统
}

User *find_usr(char *Usr_nam)               //匹配账号
{
    User *usn = User_head;
    while (usn)
    {
        if (strcmp(Usr_nam, usn->user_name) == 0)
        {
            break;
        }
        usn = usn->next;
    }
    return usn;
}
int password(User *usp)                     //匹配密码
{
    int n = 3;
    char usr_passw[10];
    while (n != 0)
    {
        secret(usr_passw);
        if (strcmp(usp->user_passw, usr_passw) == 0)
        {
            break;
        }
        n--;
        printf("\n你还有 %d 机会。\n", n);
    }
    return n;
}
void secret(char *s) //输出*****
{
    int i = 0;
    while (i < 10)
    {
        s[i] = getch();
        if (i == 0 && s[i] == '\b')
        {
            i = 0;
            s[i] = '\0';
            continue;
        }
        else if (s[i] == '\b')
        {
            printf("\b \b");
            s[i] = '\0';
            i = i - 1;
            continue;
        }
        else if (s[i] == '\n' || s[i] == '\r')
        {
            s[i] = '\0';
            break;
        }
        else
        printf("*");
        i++;
    }
}