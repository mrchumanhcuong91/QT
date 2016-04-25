#include "workingxml.h"
WorkingXML::WorkingXML()
{

}
WorkingXML::~WorkingXML(){

}
QList<Books> WorkingXML::read_bookself(QString &fileName){
    QDomDocument myDocument;
    Books bookStore;
    QList<Books> Data;
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Error when open File xml";
    }
    else{
        if(!myDocument.setContent(&file)){
            qDebug()<<"Error when set content from xml 1 file";
        }
    }
    QDomElement root = myDocument.documentElement();
    QDomElement Parents = root.firstChild().toElement();
    while(!Parents.isNull()){
        bookStore.add_BookAuthor(Parents.attribute("Author"));
        bookStore.add_BookCode(Parents.attribute("Code"));
        bookStore.add_BookLocation(Parents.attribute("Location"));
        bookStore.add_BookName(Parents.attribute("Name"));
        bookStore.add_BookStatus(Parents.attribute("Status"));
        bookStore.add_BookType(Parents.attribute("Type"));
        Parents =Parents.nextSibling().toElement();
        Data.append(bookStore);
    }
    file.close();
    return Data;
}
int WorkingXML::write_bookself(Books &book,QString& xmlName){

    QDomDocument myDocument;
    QFile file(xmlName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Error when open File xml";
    }
    else{
        if(!myDocument.setContent(&file)){
            qDebug()<<"Error when set content from xml 1 file";
        }
    }
    QDomElement root = myDocument.documentElement();
    QDomElement data = myDocument.createElement("book");
    data.setAttribute("Name",book.get_BookName());
    data.setAttribute("Type",book.get_BookType());
    data.setAttribute("Author",book.get_BookAuthor());
    data.setAttribute("Status",book.get_BookStatus());
    data.setAttribute("Location",book.get_BookLocation());
    data.setAttribute("Code",book.get_BookCode());
//    r.appendChild(data);
    root.appendChild(data);
    file.close();
//    QFile file("/home/actiso/QT_project/library/books.xml");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        qDebug() <<" Error open file";
        return -1;
    }
    else{
        QTextStream Stream(&file);
        Stream << myDocument.toString();
        file.close();
        qDebug() <<" Finished";
    }
    return 0;
}
