#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "dialogregister.h"
#include "dialoglogin.h"
#include "user.h"
class DialogLogin;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void static add_data_for_User(User& userdata);
    User get_data_user();
//signals:
//     void click_login();
private slots:
    void on_mRegistation_clicked();

    void on_mLogin_clicked();
    void on_bViewBooks_clicked();

    void on_bsearchBooks_clicked();

public slots:
    void display_button();
    void recieve_user(User& user);
private:
    User user;
    QListWidget *myWidget;
    Ui::MainWindow *ui;
    DialogRegister *Register;
    DialogLogin *mDialogLogin;
};

#endif // MAINWINDOW_H
