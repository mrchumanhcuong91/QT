#ifndef ADMIN_H
#define ADMIN_H
#include<QtCore>
#include<QString>
#include "person.h"
class Admin : public Person
{
public:
    Admin();
    virtual ~Admin();
    void add_Admin_UserName(QString UserName1);
    void add_Admin_PassWord(QString PassWord1);
    void add_EmployeeCode(QString EmployeeCode1);
    QString get_Admin_UserName();
    QString get_Admin_PassWord();
    QString get_Admin_EmployeeCode();
private:
    QString vAdminUserName;
    QString vAdminPassWord;
    QString vEmployeeCode;
};

#endif // ADMIN_H
