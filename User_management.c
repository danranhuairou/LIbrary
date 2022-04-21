#include"librarymain.h"

void User_management(User *us1)             //�û�����ϵͳ
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
            printf("����������������һ�飡\n");
        }
    }
}
void User_input(User *un)                               //�û���Ϣ����
{
    char jus[3]="1";
    if(strcmp(un->jus,jus)!=0)
    {
        printf("��û�и�Ȩ�ޣ�\n");
        return;
    }
    User *h=User_head->next;
    User *p=(User *)malloc(sizeof(User));
    p->next=NULL;
    while(h->next!=NULL)
    {
        h=h->next;
    }
    printf("Ҫ��ӵĶ��ߺ�Ϊ��������Ϊʮλ���ڣ�");
    char user_name[20];
    while(1)
    {
        User *usr=User_head;
        gets(p->user_name);
        while(usr){
            if(strcmp(p->user_name,usr->user_name)==0)
            {
                printf("�˺��Ѿ����ڣ�\n");
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
    printf("ע������Ϊ�������볤��Ϊ��λ��");
    while(1)
    {
        gets(p->user_passw);
        if(strlen(p->user_passw)==6)
        {
            break;
        }
        printf("�����ʽ����\n");
    }
    printf("ȷ������Ϊ��");
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
        printf("�㻹�� %d �λ���\n",3-n);
        if(n==3)
        {
            free(p);
            printf("��û�л���!\n");
            return;
        }
    }
    printf("����Ȩ��:0.��ͨ�û� 1.ϵͳ����Ա 2.ͼ�����Ա\n");
    while(1)
    {
        gets(p->jus);
        if(p->jus[0]=='1'||p->jus[0]=='2'||p->jus[0]=='0')
        {
            if(strlen(p->jus)==1)
                break;
        }
        printf("�������!\n");
    }
    h->next=p;
    usr_save();
    return;
}
void User_information_modification(User *un)            //�û���Ϣ�޸�
{
    char jus[3]="1";
    if(strcmp(un->jus,jus)!=0)
    {
        printf("��û�и�Ȩ�ޣ�\n");
        return;
    }
    printf("Ҫ�޸ĵĶ��ߺ�:");
    char usr_nam[10];
    gets(usr_nam);
    User *p=User_head->next,*pr=User_head->next;
    while(p){
        if(strcmp(p->user_name,usr_nam)==0)
        {
            printf("�޸�����Ϊ:\n1.���ߺ� 2.���� 3.Ȩ��\n");
            char a;
            scanf(" %c",&a);
            getchar();
            switch (a)
            {
                case '1':
                printf("���ߺ��޸�Ϊ:(����Ϊʮλ������,�����ظ�)\n");
                char usr_name[10];
                while(1){
                    gets(usr_name);
                    while(pr){
                        if(strcmp(usr_name,pr->user_name)==0)
                        {
                            printf("���ߺ��ظ���\n");
                            return;
                        }
                        pr=pr->next;
                    }
                    if((strlen(usr_name)<10&&strlen(usr_name)>0))
                    {
                        strcpy(p->user_name,usr_name);
                        usr_save();
                        printf("�޸ĳɹ���\n");
                        return;
                    }
                    printf("�����ʽ����\n");
                }
                break;
                case '2':
                printf("�޸�����Ϊ:(���볤��Ϊ6λ)");
                char usr_passw[10];
                while(1){
                    gets(usr_passw);
                    if(strlen(usr_passw)==6)
                    {
                        break;
                    }
                    printf("�����ʽ����\n");
                }
                printf("ȷ�����룺");
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
                        printf("������û�л�����\n");
                        return;
                    }
                    n++;
                    printf("��������㻹�� %d �λ���!\n",3-n);
                }
                strcpy(p->user_passw,usr_passw);
                usr_save();
                printf("�޸ĳɹ�!\n");
                break;
                case '3':
                printf("Ȩ���޸�Ϊ:\n(0.��ͨ�û� 1.ϵͳ����Ա 2.ͼ�����Ա)\n");
                char user_jus[3],yn;
                while(1)
                {
                    gets(user_jus);
                    printf("ȷ��Ҫִ�д˲�����?(Y/N):");
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
                                printf("�޸ĳɹ���\n");
                                return;
                            }
                            
                        }
                        printf("�����ʽ����\n");
                    }
                    else if(yn=='N'||yn=='n')
                    {
                        return;
                    }
                    else
                    {
                        printf("��ʽ����\n");
                    }
                }
                break;
                default:
                printf("��ʽ����\n");
                break;
            }
        }
        p=p->next;
    }
    printf("�˺Ų����ڣ�\n");
}
void User_information_deletion(User *un)                //�û���Ϣɾ��
{
    char jus[3]="1";
    if(strcmp(un->jus,jus)!=0)
    {
        printf("��û�и�Ȩ��!\n");
        return;
    }
    User *p=User_head->next,*pr=NULL;
    printf("Ҫɾ���Ķ��ߺ�Ϊ:");
    char usr_nam[10];
    int n=0,flag=0;
    gets(usr_nam);
    while(p){
            if(strcmp(usr_nam,p->user_name)==0)
            {
                if(p->jus[0]=='1')
		        {
			        printf("�㲻��ɾ����\n");
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
            printf("ɾ���ɹ�!\n");
        }
        if(flag==0)
        {
            printf("�˺Ų�����!\n");
        }
}
void User_information_display(User *un)                 //�û���Ϣ��ʾ
{
    char jus[3]="1";
    if(strcmp(un->jus,jus)!=0)
    {
        printf("��û�и�Ȩ��!\n");
        return;
    }
    User *p=User_head->next;
    printf("------------------------------------------------------------\n");
    printf("    ���ߺ�     |         ����         |        Ȩ��          \n");
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
void User_password_modification(User *un)               //�û������޸�
{
    printf("�޸�����Ϊ:(����Ϊ��λ)");
                char usr_passw[10];
                while(1){
                    gets(usr_passw);
                    if(strlen(usr_passw)==6)
                    {
                        break;
                    }
                    printf("����������ٴ����룡\n");
                }
                printf("ȷ�����룺");
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
                        printf("���������û�л����ˣ�\n");
                        return;
                    }
                    n++;
                    printf("��������㻹�� %d �λ���!\n",3-n);
                }
                strcpy(un->user_passw,usr_passw);
                usr_save();
                printf("�޸ĳɹ�!\n");
}