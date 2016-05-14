#include "workingxml.h"
#include "stdlib.h"
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
    QString bookPattern = "/home/actiso/QT_project/library/bookuser.xml";
    QString bookself ="/home/actiso/QT_project/library/books.xml";
    QFile Object;
    if(xmlName !=bookself){
        Object.copy(bookPattern,xmlName);
    }
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
    root.appendChild(data);
    file.close();
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
QList<User> WorkingXML::read_users(QString& fileName){
    QDomDocument myDocument;
    User user;
    QList<User> Data;
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
        //int intVar = atoi(Parents.attribute("Age"));
        //user.add_Age(intVar);
        user.add_Class(Parents.attribute("Class"));
        user.add_Name(Parents.attribute("Name"));
        user.add_PassWord(Parents.attribute("PassWord"));
        user.add_StudentCode(Parents.attribute("StudentCode"));
        user.add_UserName(Parents.attribute("UserName"));
        user.add_BookBag(Parents.attribute("Bag"));
        Parents =Parents.nextSibling().toElement();
        Data.append(user);
    }
    file.close();
    return Data;
}
bool WorkingXML::write_users(User& user){

    QDomDocument myDocument;
    QString listUser ="/home/actiso/QT_project/library/users.xml";
    QFile file(listUser);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Error when open File xml";
        return false;
    }
    else{
        if(!myDocument.setContent(&file)){
            qDebug()<<"Error when set content from xml 1 file";
            return false;
        }
    }
    QDomElement root = myDocument.documentElement();
    QDomElement data = myDocument.createElement("book");
    data.setAttribute("Name",user.get_Name());
    data.setAttribute("Age",user.get_Age());
    data.setAttribute("UserName",user.get_UserName());
    data.setAttribute("PassWord",user.get_PassWord());
    data.setAttribute("Bag",user.get_BookBag());
    data.setAttribute("Class",user.get_Class());
    root.appendChild(data);
    file.close();
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        qDebug() <<" Error open file";
        return false;
    }
    else{
        QTextStream Stream(&file);
        Stream << myDocument.toString();
        file.close();
        qDebug() <<" Finished";
    }
    return true;
}
bool WorkingXML::removeBookfromFile(QString& bookRemove,QString &fileName){
    QDomDocument myDocument;
    //open file
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Error when open File xml";
    }
    else{
        if(!myDocument.setContent(&file)){
            qDebug()<<"Error when set content from xml 1 file";
        }
    }
    QDomNodeList Nodes = myDocument.elementsByTagName("book");
    for(int i =0;i<Nodes.length();i++){
        qDebug()<<Nodes.at(i).toElement().attribute("Name");
        if(Nodes.at(i).toElement().attribute("Name")==bookRemove){
            myDocument.documentElement().removeChild(Nodes.at(i));
        }
    }
    file.close();
    //open file and overwrite
    if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate)){
        qDebug() <<" Error open file";
        return false;
    }else{
        QTextStream Stream(&file);
        Stream << myDocument.toString();
        file.close();
        qDebug() <<" Finished";
    }
    return true;

}
