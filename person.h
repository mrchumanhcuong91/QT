#ifndef PERSON_H
#define PERSON_H
#include<QtCore>
#include<QString>
class Person
{
protected:
    QString vName;
    int vAge;
    QString vSex;
public:
    Person();
    virtual ~Person();
    void add_Name(QString vName1);
    void add_Age(int vAge1);
    void add_vSex(QString vSex);
    QString get_Name();
    QString get_Sex();
    int get_Age();
};

#endif // PERSON_H
