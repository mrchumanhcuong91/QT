#ifndef WORKINGXML_H
#define WORKINGXML_H
#include "books.h"
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
    QList<Books> read_bookself(QString& fileName);
    int write_bookself(Books& book,QString& fileName);

};

#endif // WORKINGXML_H
