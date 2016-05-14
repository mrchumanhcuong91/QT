#include "system_library.h"

system_library::system_library()
{

}
system_library::~system_library(){

}
bool system_library::register_account(QString &UserName, QString &PassWord){
    QString fileName = "/home/actiso/QT_project/library/users.xml";
    // check if duplicate
    QList<User> Userlist;
    //QList<User> read_users(QString& fileName);
    Userlist = WorkingXML::read_users(fileName);
    QList<User>::iterator points;
    for(points=Userlist.begin();points!=Userlist.end();points++){
        if (points->get_UserName()==UserName){
            qDebug() << "UserName has existed !!! please use other UserName";
            return false;
        }
    }
    //register UserName and PassWord to the xml File
    User user;
    user.add_UserName(UserName);
    user.add_PassWord(PassWord);
    //add to list user
    if(!WorkingXML::write_users(user)){
        qDebug() << "Error when write to User File";
        return false;
    }
    else{
        return true;
    }

}
bool system_library::login_account(QString &UserName, QString &PassWord,User& user){
    QString fileName = "/home/actiso/QT_project/library/users.xml";
    // check if duplicate
    QList<User> Userlist;
    Userlist = WorkingXML::read_users(fileName);
    QList<User>::iterator points;
    for(points=Userlist.begin();points!=Userlist.end();points++){
        if ((points->get_UserName()==UserName&&points->get_PassWord()==PassWord)){
            user = *points;
            return true;
        }
    }
return false;
}
QList<Books> system_library::viewBook(QString &fileNameBooks){
    return WorkingXML::read_bookself(fileNameBooks);
}
bool system_library::searchBook(QString &bookName, Books *book){
    QString fileName = "/home/actiso/QT_project/library/books.xml";
    // check if duplicate
    bool checkResult =false;
    QList<Books> booklist;
    booklist = WorkingXML::read_bookself(fileName);
    QList<Books>::iterator points;
    for(points=booklist.begin();points!=booklist.end();points++){
        if(system_library::findAdvance(bookName,points->get_BookName())){
           *book =*points;
            qDebug()<<book->get_BookName();
            checkResult =true;
            book++;
        }

//        if ((points->get_BookName()==bookName)){
//            qDebug()<<points->get_BookAuthor();
//            *book =*points;

        }
    return checkResult;
    }


bool system_library::Admin_add_Book(Books &bookAdd, QString& store){
    if(WorkingXML::write_bookself(bookAdd,store)==-1){
        return false;
    }else{
        return true;
    }
}
bool system_library::Admin_removeBook(Books &bookNameRemove){

}
bool system_library::borrowBook(Books &bookNameBorrow,QString& userBag){
    //open bag book
    //add new book in the book list
    if(WorkingXML::write_bookself(bookNameBorrow,userBag)==-1){
       return false;
    }else{
        return true;
    }
}
bool system_library::user_remove_book_bag(QString& bookName, QString &userBag){
    if(WorkingXML::removeBookfromFile(bookName,userBag)){
        return true;
    }else{
        return false;
    }
}
bool system_library::findAdvance(QString& pattern,QString Text){
    //split pattern to create right grammar regular expression
    QString patternMatch;
    QRegExp reg("[ ]");
    QStringList list = pattern.split(reg,QString::SkipEmptyParts);
    for(int i=0;i<list.size();i++){
        patternMatch += list.at(i)+QString(".+");
    }
    QRegExp rx(patternMatch);
    if(rx.indexIn(Text)!=-1){
        return true;
    }else{
        return false;
    }


}
