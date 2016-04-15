#include "person.h"

Person::Person()
{
}
Person::~Person(){

}
void Person::add_Age(int vAge1){
    vAge = vAge1;
}
void Person::add_Name(QString vName1){
    vName = vName1;
}
void Person::add_vSex(QString vSex1){
    vSex = vSex1;
}
QString Person::get_Name(){
    return vName;
}
QString Person::get_Sex(){
    return vSex;
}
int Person::get_Age(){
    return vAge;
}
