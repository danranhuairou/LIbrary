#include "librarymain.h"

void main(void)                          //������
{
    User_head = (User *)malloc(sizeof(User));
    Reader_head=(Reader *)malloc(sizeof(Reader));
    Loan_head=(Loan_return *)malloc(sizeof(Loan_return));

    char se = '9';
    while (se != '0')
    {
        User_head->next = usr_load();
        Reader_head->next=red_load();
        Loan_head->next=Loan_load();
        login_ui();
        scanf(" %c", &se);
        getchar();
        switch (se)
        {
        case '1':
            login();                    //�����¼ϵͳ
            break;
        case '0':
            break;
        default:
            printf("������������ԣ�\n");
            break;
        }
    }
}
void mainsystem(User *ma)           //��ϵͳ
{
    char se='?';
    while(se!='0')
    {
        main_ui();
        scanf(" %c",&se);
        switch(se)
        {
            case '1':
            User_management(ma);break;
            case '2':
            Reader_management(ma);break;
            case '3':
            Book_management(ma);break;
            case '4':
            Book_circulation_management(ma);break;
            case '0':
            return;
            default:
            printf("������������ԣ�\n");
        }

    }
}
