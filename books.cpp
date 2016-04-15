#include "books.h"

Books::Books()
{

}
Books::~Books(){

}

void Books::add_BookName(QString vBookName1){
    vBookName = vBookName1;
}

void Books::add_BookCode(QString vBookCode1){
    vBookCode = vBookCode1;
}

void Books::add_BookAuthor(QString vBookAuthor1){
    vBookAuthor = vBookAuthor1;
}

void Books::add_BookType(QString vBookType1){
    vBookType = vBookType1;
}

void Books::add_BookLocation(QString vBookLocation1){
    vBookLocation = vBookLocation1;
}

void Books::add_BookStatus(QString vBookStatus1){
    vBookStatus = vBookStatus1;
}

QString Books::get_BookName(){
    return vBookName;
}

QString Books::get_BookCode(){
    return vBookCode;
}

QString Books::get_BookAuthor(){
    return vBookAuthor;
}

QString Books::get_BookType(){
    return vBookType;
}

QString Books::get_BookLocation(){
    return vBookLocation;
}

QString Books::get_BookStatus(){
    return vBookStatus;
}
