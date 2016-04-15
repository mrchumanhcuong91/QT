#ifndef BOOKS_H
#define BOOKS_H
#include<QString>

class Books
{
public:
    Books();
    virtual ~Books();
    void add_BookName(QString vBookName1);
    void add_BookCode(QString vBookCode1);
    void add_BookAuthor(QString vBookAuthor1);
    void add_BookType(QString vBookType1);
    void add_BookLocation(QString vBookLocation1);
    void add_BookStatus(QString vBookStatus1);
    QString get_BookName();
    QString get_BookCode();
    QString get_BookAuthor();
    QString get_BookType();
    QString get_BookLocation();
    QString get_BookStatus();
private:
    QString vBookName;
    QString vBookCode;
    QString vBookAuthor;
    QString vBookType;
    QString vBookLocation;
    QString vBookStatus;
};

#endif // BOOKS_H
