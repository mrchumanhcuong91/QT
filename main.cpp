#include "mainwindow.h"
#include "user.h"
#include "books.h"
#include <QApplication>
#include <QDebug>
#include<QList>
#include<QListIterator>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//MainWindow w;
   // w.show();
    Books book1,book2,book3;
    book1.add_BookName("Physics");
    book2.add_BookName("Math");
    book3.add_BookName("Chemistry");
    User vUser;
    vUser.add_UserBooks(book1);
    vUser.add_UserBooks(book2);
    vUser.add_UserBooks(book3);
    QList<Books> listBooks = vUser.get_Userbooks();
    QList<Books>::iterator item;
    for (item = listBooks.begin();item != listBooks.end();++item){
        qDebug()<< item->get_BookName();
    }
    return a.exec();
}
