#ifndef WORKINGXML_H
#define WORKINGXML_H
#include "books.h"
#include "user.h"
#include <QCoreApplication>
#include <QtCore>
#include <QtXml/QDomDocument>
#include <QDebug>
#include <QXmlReader>
#include <QDomNamedNodeMap>
class WorkingXML
{
public:
    WorkingXML();
    virtual ~WorkingXML();
    static QList<Books> read_bookself(QString& fileName);
    static int write_bookself(Books& book,QString& fileName);
    static QList<User> read_users(QString& fileName);
    static bool write_users(User& user);
    static bool refresh_xml();
    static bool removeBookfromFile(QString& bookRemove,QString& fileName);

};

#endif // WORKINGXML_H
