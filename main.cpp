#include "mainwindow.h"
#include "user.h"
#include "books.h"
#include "workingxml.h"

#include <QApplication>
#include <QDebug>
#include<QList>
#include<QListIterator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//MainWindow w;
   // w.show();
//    QDomDocument myDocument;
    int status;
    Books book1;
    book1.add_BookName("Giai tich 12");
    book1.add_BookType("Math");
    book1.add_BookAuthor("Phan Huy Khai");
    book1.add_BookLocation("3th floor");
    book1.add_BookStatus("Yes");
    book1.add_BookCode("TVDT-03XYZ");

//    User vUser;
//    vUser.add_UserBooks(book1);
//    vUser.add_UserBooks(book2);
//    vUser.add_UserBooks(book3);
//    QList<Books> listBooks = vUser.get_Userbooks();
//    QList<Books>::iterator item;
//    for (item = listBooks.begin();item != listBooks.end();++item){
//        qDebug()<< item->get_BookName();
//    }
    WorkingXML xmlWork;

    QList<Books> BookStore ;
    QString nameFile = "/home/actiso/QT_project/library/bookuser1.xml";
    BookStore = xmlWork.read_bookself(nameFile);
                //        status = xmlWork.write_bookself(book1);
//    status = xmlWork.write_bookself(book1,nameFile);
//    status = xmlWork.write_bookself(book3);

//    if(BookStore==NULL){
//        qDebug() << "Error assign QList Value";
//    }
    QList<Books>::iterator id;
    for (id =BookStore.begin();id != BookStore.end();id++){
        qDebug()<<"Name of book\n"<<id->get_BookName()<<"\n";
    }


//    return a.exec();
}
