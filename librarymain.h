#ifndef _STDIO_H_ 
#define _STDIO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//�û����ͽṹ��
typedef struct usr
{
    char user_name[20];
    char user_passw[10];
    char jus[10];
    struct usr *next;
} User;
//�������ͽṹ��
typedef struct red
{
    char user_name[20];
    char reader_name[20];
    char unit[30];
    char phone[20];
    char jus[10];
    int loanable;
    int borrowed;
    struct red *next;
}Reader;
//ͼ�����ͽṹ��
typedef struct bok
{
    char book_number[20];
    char book_name[30];
    char book_author[20];
    char book_press[30];
    int collection;
    int lending;
    int pointer1;
    int pointer2;
    int pointer3;
}Book;
//��������
typedef struct bok_name
{
    char book_name[30];
    int pointer;
    int len;
}Book_name;
//��������
typedef struct bok_author
{
    char book_author[30];
    int pointer;
    int len;
}Book_author;
//����������
typedef struct bok_press
{
    char book_press[30];
    int pointer;
    int len;
}Book_press;
//�軹��ṹ������
typedef struct loan_return
{
    char Book_number[20];
    char User_number[30];
    int l_year;
    int l_month;
    int l_day;
    int r_year;
    int r_month;
    int r_day;
    char remarks[30];
    struct loan_return* next;
}Loan_return;

//��������
void login_ui();//��ӡ��¼ui
void main_ui();//��ӡ��ϵͳui
void User_ui();//��ӡ�û�ui
void Reader_ui();//��ӡ����ui
void Book_ui();//��ӡͼ��ui
void findbook_ui();//ͼ���ѯui
void bookc_ui();//ͼ����ͨui

User *usr_load();//�û��ļ���ȡ
void usr_save();//�û��ļ�����
Reader *red_load();//�����ļ���ȡ
void red_save();//�����ļ����
int bok_load(int total);//ͼ���ļ���ȡ
void bok_save(int total);//ͼ���ļ�����
int bok_name_load(int total1);//����������ȡ
void bok_name_save(int total1);//������������
int bok_author_load(int total2);//����������ȡ
void bok_author_save(int total2);//������������
int bok_press_load(int total3);//������������ȡ
void bok_press_save(int total3);//��������������
Loan_return *Loan_load();//�����ȡ
void Loan_save();//���鱣��

void login();//�û���¼ϵͳ
int password(User *usp);//����ƥ��
User *find_usr(char *Usr_nam);//�û�ƥ��
void secret(char *s);//���*****

void mainsystem(User *ma);//��ϵͳ

void User_management(User *us1);//�û�����ϵͳ
void User_input(User *un);//�û���Ϣ����
void User_information_modification(User *un);//�û���Ϣ�޸�
void User_information_deletion(User *un);//�û���Ϣɾ��
void User_information_display(User *un);//�û���Ϣ��ʾ
void User_password_modification(User *un);//�û������޸�

void Reader_management(User *us1);//���߹���ϵͳ
void readerinput();//������Ϣ����
void readermodification();//������Ϣ�޸�
void readerdeletion();//������Ϣɾ��
void findreader();//������Ϣ��ѯ
void readerdisplay();//������Ϣ��ʾ

void Book_management(User *us1);//ͼ�����ϵͳ
void Book_input(User *un);//ͼ����Ϣ����
void Book_modification(User *un);//ͼ����Ϣ�޸�
void Book_find();//ͼ����Ϣ��ѯ
void numberfind();//����Ų�ѯ
void namefind();//��������ѯ
void authorfind();//�����߲�ѯ
void pressfind();//���������ѯ
void Summary_statistics();//����ͳ��

void Book_circulation_management(User *us1);//ͼ����ͨ����ϵͳ
void loan();//���鴦��

//ȫ�ֱ���
User *User_head;//�û�ͷָ��
Reader *Reader_head;//����ͷָ��
Loan_return *Loan_head;
Book Book_head[20];//ͼ��ͷָ��
Book_name Name_head[20];//��������
Book_author Author_head[20];//��������
Book_press Press_head[20];//����������
#endif