#include"librarymain.h"

void User_management(User *us1)             //用户管理系统
{
    char se='?';
    while(se!='0')
    {
        User_ui();
        scanf(" %c",&se);
        getchar();
        switch(se)
        {
            case '1':
            User_input(us1);break;
            case '2':
            User_information_modification(us1);break; 
            case '3':
            User_information_deletion(us1);break;
            case '4':
            User_information_display(us1);break;
            case '5':
            User_password_modification(us1);break;
            case '0':
            return;
            default:
            printf("输入有误，请再输入一遍！\n");
        }
    }
}
void User_input(User *un)                               //用户信息输入
{
    char jus[3]="1";
    if(strcmp(un->jus,jus)!=0)
    {
        printf("你没有该权限！\n");
        return;
    }
    User *h=User_head->next;
    User *p=(User *)malloc(sizeof(User));
    p->next=NULL;
    while(h->next!=NULL)
    {
        h=h->next;
    }
    printf("要填加的读者号为：（长度为十位以内）");
    char user_name[20];
    while(1)
    {
        User *usr=User_head;
        gets(p->user_name);
        while(usr){
            if(strcmp(p->user_name,usr->user_name)==0)
            {
                printf("账号已经存在！\n");
                free(p);
                return;
            }
            usr=usr->next;        
        }
            if(strlen(p->user_name)<10&&strlen(p->user_name)>0)
            {
                break;
            }
            printf("Error!");
            
      
    }
    printf("注册密码为：（密码长度为六位）");
    while(1)
    {
        gets(p->user_passw);
        if(strlen(p->user_passw)==6)
        {
            break;
        }
        printf("输入格式错误！\n");
    }
    printf("确定密码为：");
    char user_passw2[10];
    int n=0;
    while(1)
    {
        gets(user_passw2);
        if(strcmp(user_passw2,p->user_passw)==0)
        {
            break;
        }
        n++;
        printf("你还有 %d 次机会\n",3-n);
        if(n==3)
        {
            free(p);
            printf("你没有机会!\n");
            return;
        }
    }
    printf("读者权限:0.普通用户 1.系统管理员 2.图书管理员\n");
    while(1)
    {
        gets(p->jus);
        if(p->jus[0]=='1'||p->jus[0]=='2'||p->jus[0]=='0')
        {
            if(strlen(p->jus)==1)
                break;
        }
        printf("输入错误!\n");
    }
    h->next=p;
    usr_save();
    return;
}
void User_information_modification(User *un)            //用户信息修改
{
    char jus[3]="1";
    if(strcmp(un->jus,jus)!=0)
    {
        printf("你没有该权限！\n");
        return;
    }
    printf("要修改的读者号:");
    char usr_nam[10];
    gets(usr_nam);
    User *p=User_head->next,*pr=User_head->next;
    while(p){
        if(strcmp(p->user_name,usr_nam)==0)
        {
            printf("修改内容为:\n1.读者号 2.密码 3.权限\n");
            char a;
            scanf(" %c",&a);
            getchar();
            switch (a)
            {
                case '1':
                printf("读者号修改为:(长度为十位数以内,不能重复)\n");
                char usr_name[10];
                while(1){
                    gets(usr_name);
                    while(pr){
                        if(strcmp(usr_name,pr->user_name)==0)
                        {
                            printf("读者号重复！\n");
                            return;
                        }
                        pr=pr->next;
                    }
                    if((strlen(usr_name)<10&&strlen(usr_name)>0))
                    {
                        strcpy(p->user_name,usr_name);
                        usr_save();
                        printf("修改成功！\n");
                        return;
                    }
                    printf("输入格式错误！\n");
                }
                break;
                case '2':
                printf("修改密码为:(密码长度为6位)");
                char usr_passw[10];
                while(1){
                    gets(usr_passw);
                    if(strlen(usr_passw)==6)
                    {
                        break;
                    }
                    printf("输入格式错误\n");
                }
                printf("确定密码：");
                char usr_passw2[10];
                int n=0;
                while(1){
                    gets(usr_passw2);
                    if(strcmp(usr_passw2,usr_passw)==0)
                    {
                        break;
                    }
                    if(n==2)
                    {
                        printf("错误！你没有机会了\n");
                        return;
                    }
                    n++;
                    printf("输入错误，你还有 %d 次机会!\n",3-n);
                }
                strcpy(p->user_passw,usr_passw);
                usr_save();
                printf("修改成功!\n");
                break;
                case '3':
                printf("权限修改为:\n(0.普通用户 1.系统管理员 2.图书管理员)\n");
                char user_jus[3],yn;
                while(1)
                {
                    gets(user_jus);
                    printf("确定要执行此操作吗?(Y/N):");
                    scanf(" %c",&yn);
                    getchar();
                    if(yn=='y'||yn=='Y')
                    {
                        if(user_jus[0]=='1'||user_jus[0]=='2'||user_jus[0]=='0')
                        {
                            if(strlen(user_jus)==1)
                            {
                                strcpy(p->jus,user_jus);
                                usr_save();
                                printf("修改成功！\n");
                                return;
                            }
                            
                        }
                        printf("输入格式错误！\n");
                    }
                    else if(yn=='N'||yn=='n')
                    {
                        return;
                    }
                    else
                    {
                        printf("格式有误！\n");
                    }
                }
                break;
                default:
                printf("格式有误！\n");
                break;
            }
        }
        p=p->next;
    }
    printf("账号不存在！\n");
}
void User_information_deletion(User *un)                //用户信息删除
{
    char jus[3]="1";
    if(strcmp(un->jus,jus)!=0)
    {
        printf("你没有该权限!\n");
        return;
    }
    User *p=User_head->next,*pr=NULL;
    printf("要删除的读者号为:");
    char usr_nam[10];
    int n=0,flag=0;
    gets(usr_nam);
    while(p){
            if(strcmp(usr_nam,p->user_name)==0)
            {
                if(p->jus[0]=='1')
		        {
			        printf("你不能删除！\n");
			        return;
		        }
                flag=1;
                if(n==0)
                {
                    User_head->next=p->next;
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
            usr_save();
            printf("删除成功!\n");
        }
        if(flag==0)
        {
            printf("账号不存在!\n");
        }
}
void User_information_display(User *un)                 //用户信息显示
{
    char jus[3]="1";
    if(strcmp(un->jus,jus)!=0)
    {
        printf("你没有该权限!\n");
        return;
    }
    User *p=User_head->next;
    printf("------------------------------------------------------------\n");
    printf("    读者号     |         密码         |        权限          \n");
    printf("------------------------------------------------------------\n");
    while(p){
        if(strlen(p->user_name)<=5)
        {
            printf("  %s\t\t\t%s\t\t\t%s\n",p->user_name,p->user_passw,p->jus);
        }
        else{
        printf("  %s\t\t%s\t\t\t%s\n",p->user_name,p->user_passw,p->jus);
        }
        p=p->next;
    }
    printf("------------------------------------------------------------\n");
}
void User_password_modification(User *un)               //用户密码修改
{
    printf("修改密码为:(长度为六位)");
                char usr_passw[10];
                while(1){
                    gets(usr_passw);
                    if(strlen(usr_passw)==6)
                    {
                        break;
                    }
                    printf("输入错误，请再次输入！\n");
                }
                printf("确定密码：");
                char usr_passw2[10];
                int n=0;
                while(1){
                    gets(usr_passw2);
                    if(strcmp(usr_passw2,usr_passw)==0)
                    {
                        break;
                    }
                    if(n==2)
                    {
                        printf("输入错误，你没有机会了！\n");
                        return;
                    }
                    n++;
                    printf("输入错误，你还有 %d 次机会!\n",3-n);
                }
                strcpy(un->user_passw,usr_passw);
                usr_save();
                printf("修改成功!\n");
}