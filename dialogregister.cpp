#include "dialogregister.h"
#include "ui_dialogregister.h"
#include "system_library.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
DialogRegister::DialogRegister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRegister)
{
    ui->setupUi(this);
}

DialogRegister::~DialogRegister()
{
    delete ui;
}

void DialogRegister::on_pushButton_clicked()
{
    QString inputUserName = ui->mEditUserName->text();
    QString inputPassWord = ui->mEditPassword->text();
    system_library ObjectSys;
    if(ObjectSys.register_account(inputUserName,inputPassWord)){
        QMessageBox::information(this,"Message","Successfull");
    }else{
        QMessageBox::information(this,"Message","Register Fail");
    }

}
