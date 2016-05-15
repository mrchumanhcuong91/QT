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

    void on_bBorrows_clicked();

    void on_bYourBooks_clicked();

    void on_bRemoveYourBooks_clicked();

    void on_bHelp_clicked();

public slots:
    void display_button();
    void recieve_user(User& user);
    void ItemListWidget_click(QListWidgetItem* item);
    void ItemListYourBooks_click(QListWidgetItem* item);
private:
    User user;
    QString nameItem;
    QListWidget *myWidget;
    QListWidget *yourBooks;
    QListWidgetItem *item;
    Ui::MainWindow *ui;
    DialogRegister *Register;
    DialogLogin *mDialogLogin;
};

#endif // MAINWINDOW_H
