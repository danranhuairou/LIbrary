//��¼ϵͳ
#include "librarymain.h"

void login()                        //��¼ϵͳ
{
    User *us = NULL;
    char s = '1';
    char usr_nam[20];
    printf("���ߺ�:");
    gets(usr_nam);
    us = find_usr(usr_nam);         //�ҵ��˺ź���
    if (us == NULL)                             
    {
        printf("�˺Ų����ڣ�\n");      
        return;
    }
    printf("���룺");
    if (password(us) == 0)          //�ҵ��˺�����
    {
        return;
    }
    printf("\n��¼�ɹ�!\n");
    mainsystem(us);                 //������ϵͳ
}

User *find_usr(char *Usr_nam)               //ƥ���˺�
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
int password(User *usp)                     //ƥ������
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
        printf("\n�㻹�� %d ���ᡣ\n", n);
    }
    return n;
}
void secret(char *s) //���*****
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