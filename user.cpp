#include "user.h"

User::User()
{
    //userBooks = new QList<Books>();
}
User::~User(){

}

void User::add_StudentCode(QString vStudentCode1){
    vStudentCode = vStudentCode1;
}

void User::add_Class(QString vClass1){
    vClass = vClass1;
}

void User::add_UserName(QString vUserName1){
    vUserName = vUserName1;
}

void User::add_PassWord(QString vPassWord1){
    vPassWord = vPassWord1;
}

void User::add_UserBooks(const Books& book){
    userBooks.append(book);
}
void User::add_BookBag(QString bagBook){
    vBookBag = bagBook;
}

QString User::get_StudentCode(){
    return vStudentCode;
}

QString User::get_Class(){
    return vClass;
}

QString User::get_UserName(){
    return vUserName;
}

QString User::get_PassWord(){
    return vPassWord;
}
QString User::get_BookBag(){
    return vBookBag;
}

QList<Books> User::get_Userbooks(){
    return userBooks;
}
