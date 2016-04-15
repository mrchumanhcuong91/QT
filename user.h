#ifndef USER_H
#define USER_H
#include<QString>
#include<QList>
#include"books.h"
#include "person.h"
//class Person;
class User : public Person{
public:
    User();
    virtual ~User();
    void add_StudentCode(QString vStudentCode1);
    void add_Class(QString vClass1);
    void add_UserName(QString vUserName1);
    void add_PassWord(QString vPassWord1);
    void add_UserBooks(const Books& book);
    QString get_StudentCode();
    QString get_Class();
    QString get_UserName();
    QString get_PassWord();
    QList<Books> get_Userbooks();
private:
    QString vStudentCode;
    QString vClass;
    QList<Books> userBooks;
    QString vUserName;
    QString vPassWord;

};

#endif // USER_H
