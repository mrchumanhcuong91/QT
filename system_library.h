#ifndef SYSTEM_LIBRARY_H
#define SYSTEM_LIBRARY_H
#include "books.h"
#include "user.h"
#include "workingxml.h"
#include <QRegExp>

#include <QtAlgorithms>
class system_library
{
private:
    Books vBooks;
    User vUser;
public:
    system_library();
    virtual ~system_library();
    bool register_account(QString& UserName,QString& PassWord);
    bool login_account(QString& UserName,QString& PassWord,User& user);
    bool logout_account(User& user);
    QList<Books> viewBook(QString& fileNameBooks);
    bool static searchBook(QString& bookName,Books* book);
    bool static getBookFromBookself(QList<QString>& bookName,Books* book);
    bool Admin_add_Book(Books& bookAdd,QString& store);
    bool Admin_removeBook(Books& bookNameRemove);
    bool borrowBook(Books& bookNameBorrow,QString& userBag);
    bool user_remove_book_bag(QString& bookName,QString& userBag);
    bool static findAdvance(QString& pattern,QString Text);
};

#endif // SYSTEM_LIBRARY_H
