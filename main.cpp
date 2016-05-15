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

    return a.exec();
}
