#include "admin.h"

Admin::Admin()
{

}
Admin::~Admin(){

}
void Admin::add_Admin_UserName(QString UserName1){
    vAdminUserName = UserName1;
}
void Admin::add_Admin_PassWord(QString PassWord1){
    vAdminPassWord = PassWord1;
}
void Admin::add_EmployeeCode(QString EmployeeCode1){
    vEmployeeCode = EmployeeCode1;
}
QString Admin::get_Admin_EmployeeCode(){
    return vEmployeeCode;
}
QString Admin::get_Admin_PassWord(){
    return vAdminPassWord;
}
QString Admin::get_Admin_UserName(){
    return vAdminUserName;
}
