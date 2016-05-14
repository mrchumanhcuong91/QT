#include "mainwindow.h"
#include "user.h"
#include "books.h"
#include "workingxml.h"
#include "system_library.h"

#include <QApplication>
#include <QDebug>
#include<QList>
#include<QListIterator>
#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    QString input ="Hoc";
//    int id =0;
//    Books *store = new Books[10];
//    if(system_library::searchBook(input,store)){
//        while(id<10){
//       qDebug()<<"Success main functions"<<store[id].get_BookName();
//       id++;
//        }
//    }else {
//        qDebug()<<"Fail main function";
//    }
//    system_library sys;
//    //QString UserName ="soichu";
//    //QString Password ="20021991";
//    //User cuongcm ;
//    if(sys.login_account(UserName,Password,cuongcm)){
//        qDebug()<<"Success"<<cuongcm.get_Name();
//    }else{
//        qDebug()<<"Fail";
//    }

    return a.exec();
}
