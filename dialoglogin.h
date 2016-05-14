#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H
#include "mainwindow.h"
#include "user.h"
#include <QDialog>
class MainWindow;
namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = 0);
    ~DialogLogin();
//    void add_user(User& userCache);
signals:
    void tranfer_user(User& user);
private slots:
    void on_bLogin_clicked();

private:
    Ui::DialogLogin *ui;
};

#endif // DIALOGLOGIN_H
