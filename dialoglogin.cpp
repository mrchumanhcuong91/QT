#include "dialoglogin.h"
#include "ui_dialoglogin.h"
#include "system_library.h"
#include "mainwindow.h"
#include <QMessageBox>
DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::on_bLogin_clicked()
{
    QString InputUserName = ui->mEditUserName->text();
    QString InputPassWord = ui->mEditPassword->text();
    qDebug() <<InputPassWord<<InputUserName;
    system_library Object;
    User datauser;
    if(Object.login_account(InputUserName,InputPassWord,datauser)){
       qDebug() <<"Login successfull";
        emit this->tranfer_user(datauser);

    }  else{
         qDebug() <<"Login Fail";
    }
}
