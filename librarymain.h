#ifndef _STDIO_H_ 
#define _STDIO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//用户类型结构体
typedef struct usr
{
    char user_name[20];
    char user_passw[10];
    char jus[10];
    struct usr *next;
} User;
//读者类型结构体
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
//图书类型结构体
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
//书名索引
typedef struct bok_name
{
    char book_name[30];
    int pointer;
    int len;
}Book_name;
//作者索引
typedef struct bok_author
{
    char book_author[30];
    int pointer;
    int len;
}Book_author;
//出版社索引
typedef struct bok_press
{
    char book_press[30];
    int pointer;
    int len;
}Book_press;
//借还书结构体类型
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

//函数声明
void login_ui();//打印登录ui
void main_ui();//打印主系统ui
void User_ui();//打印用户ui
void Reader_ui();//打印读者ui
void Book_ui();//打印图书ui
void findbook_ui();//图书查询ui
void bookc_ui();//图书流通ui

User *usr_load();//用户文件读取
void usr_save();//用户文件储存
Reader *red_load();//读者文件读取
void red_save();//读者文件存放
int bok_load(int total);//图书文件读取
void bok_save(int total);//图书文件保存
int bok_name_load(int total1);//书名索引读取
void bok_name_save(int total1);//书名索引保存
int bok_author_load(int total2);//作者索引读取
void bok_author_save(int total2);//作者索引保存
int bok_press_load(int total3);//出版社索引读取
void bok_press_save(int total3);//出版社索引保存
Loan_return *Loan_load();//借书读取
void Loan_save();//借书保存

void login();//用户登录系统
int password(User *usp);//密码匹配
User *find_usr(char *Usr_nam);//用户匹配
void secret(char *s);//输出*****

void mainsystem(User *ma);//主系统

void User_management(User *us1);//用户管理系统
void User_input(User *un);//用户信息输入
void User_information_modification(User *un);//用户信息修改
void User_information_deletion(User *un);//用户信息删除
void User_information_display(User *un);//用户信息显示
void User_password_modification(User *un);//用户密码修改

void Reader_management(User *us1);//读者管理系统
void readerinput();//读者信息输入
void readermodification();//读者信息修改
void readerdeletion();//读者信息删除
void findreader();//读者信息查询
void readerdisplay();//读者信息显示

void Book_management(User *us1);//图书管理系统
void Book_input(User *un);//图书信息输入
void Book_modification(User *un);//图书信息修改
void Book_find();//图书信息查询
void numberfind();//按书号查询
void namefind();//按书名查询
void authorfind();//按作者查询
void pressfind();//按出版社查询
void Summary_statistics();//汇总统计

void Book_circulation_management(User *us1);//图书流通管理系统
void loan();//借书处理

//全局变量
User *User_head;//用户头指针
Reader *Reader_head;//读者头指针
Loan_return *Loan_head;
Book Book_head[20];//图书头指针
Book_name Name_head[20];//书名索引
Book_author Author_head[20];//作者索引
Book_press Press_head[20];//出版社索引
#endif