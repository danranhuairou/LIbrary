#include "librarymain.h"
void login_ui()             //登录ui
{
    printf("*******************\n");
    printf("    1.登录\n");
    printf("    0.退出\n");
    printf("*******************\n");
}
void main_ui()              //主系统ui  
{
    printf("****************************\n");
    printf("    1.用户管理\n");
    printf("    2.读者管理\n");
    printf("    3.图书管理\n");
    printf("    4.图书流通管理\n");
    printf("    0.登出\n");
    printf("****************************\n");
}
void User_ui()              //用户管理ui  
{
    printf("**************************************\n");
    printf("    1.用户信息输入\n");
    printf("    2.用户信息修改\n");
    printf("    3.用户信息删除\n");
    printf("    4.用户信息显示\n");
    printf("    5.用户密码修改\n");
    printf("    0.返回主菜单\n");
    printf("**************************************\n");
}
void Reader_ui()            //读者管理ui
{
    printf("**************************************\n");
    printf("  1. 读者信息输入\n");
    printf("  2. 读者信息修改\n");
    printf("  3. 读者信息删除\n");
    printf("  4. 读者信息查询\n");
    printf("  5. 读者信息显示\n");
    printf("  0. 返回主菜单\n");
    printf("**************************************\n");
}
void Book_ui()              //图书管理ui
{
    printf("**************************************\n");
    printf("  1. 图书信息输入\n");
    printf("  2. 图书信息修改\n");
    printf("  3. 图书信息查询\n");
    printf("  4. 汇总统计\n");
    printf("  0. 返回主菜单\n");
    printf("**************************************\n");
}
void findbook_ui()          //图书查询ui
{
    printf("**************************************\n");
    printf("  1. 按书号查询\n");
    printf("  2. 按书名查询\n");
    printf("  3. 按作者查询\n");
    printf("  4. 按出版社查询\n");
    printf("  0. 返回主菜单\n");
    printf("**************************************\n");
}
void bookc_ui()
{
    printf("**************************************\n");
    printf("  1. 借书处理\n");
    printf("  2. 还书处理\n");
    printf("  3. 流通记录\n");
    printf("  0. 返回主菜单\n");
    printf("**************************************\n");
}