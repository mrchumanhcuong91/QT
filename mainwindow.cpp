#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialoglogin.h"
#include "system_library.h"
#include <QPushButton>
#include <QMessageBox>

#include "workingxml.h"
QString FileNameBookSelf ="/home/actiso/QT_project/library/books.xml";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->myWidget =new QListWidget;
    this->item = new QListWidgetItem;
    this->yourBooks = new QListWidget;
    QPixmap pix("/home/actiso/QT_project/library/background.jpeg");
    pix = pix.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette Qpush;
    Qpush.setBrush(QPalette::Background,pix);
    this->setPalette(Qpush);
    QPixmap TopLable("/home/actiso/QT_project/library/topImage.png");
    ui->label->setPixmap(TopLable);
    ui->label_Hi->hide();
    //connect click on item of this->widget with the slot
    QObject::connect(this->myWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,
                     SLOT(ItemListWidget_click(QListWidgetItem*)));
    QObject::connect(this->yourBooks,SIGNAL(itemClicked(QListWidgetItem*)),this,
                     SLOT(ItemListYourBooks_click(QListWidgetItem*)));

}
MainWindow::~MainWindow()
{
    delete ui;
}
//void MainWindow::add_data_for_User(User &userdata){
//    *user =userdata;
//}
User MainWindow::get_data_user(){
    return user;
}

void MainWindow::on_mRegistation_clicked()
{
    Register = new DialogRegister();
    Register->show();
}
void MainWindow::recieve_user(User &user){
    if(user.get_Name()!=""){
        this->user =user;
        ui->label_Hi->setText("Welcome "+ user.get_Name());
        ui->label_Hi->setStyleSheet("QLabel { background-color : blue; color : red; }");
        ui->label_Hi->show();
        ui->bViewBooks->setEnabled(true);
        ui->bsearchBooks->setEnabled(true);
        ui->bYourBooks->setEnabled(true);

        //ui->bFindAdvance->setEnabled(true);


    }
}

void MainWindow::on_mLogin_clicked()
{
    mDialogLogin = new DialogLogin();
    QObject::connect(mDialogLogin,SIGNAL(tranfer_user(User&)),this,SLOT(recieve_user(User&)));
    mDialogLogin->show();

}
//void MainWindow::click_login(){
//    qDebug()<<"Login click";
//}
void MainWindow::display_button(){
    ui->bHelp->setText("Welcome CuongCM");
}

void MainWindow::on_bViewBooks_clicked()
{
    //ui->vUserdisplay->removeWidget(this->yourBooks);
    qDebug() <<" viewBOOKs";
    if(this->myWidget->count()!=0){
        this->myWidget->clear();
    }
    ui->vUserdisplay->removeWidget(this->myWidget);

    QListWidget widget ;
    QList<Books> Data = WorkingXML::read_bookself(FileNameBookSelf);
    QList<Books>::iterator points;
    for(points=Data.begin();points!=Data.end();points++){
        this->myWidget->addItem(points->get_BookName());

        //qDebug() <<points->get_BookName();
    }
    ui->vUserdisplay->addWidget(this->myWidget);
}

void MainWindow::on_bsearchBooks_clicked()
{
    Books *bookSearch = new Books[100];
    QString nameBook =ui->lineEditSearch->text();
    if(!system_library::searchBook(nameBook,bookSearch)){
       QMessageBox::information(this,"Message","Not Found");
    }else{
        if(this->myWidget->count()!=0){
            this->myWidget->clear();
        }
        ui->vUserdisplay->removeWidget(this->myWidget);
        while(bookSearch->get_BookName() !=""){
            this->myWidget->addItem(bookSearch->get_BookName());
            bookSearch++;
        }
        ui->vUserdisplay->addWidget(this->myWidget);
    }
}
void MainWindow::ItemListWidget_click(QListWidgetItem *item){
    ui->bBorrows->setEnabled(true);
    this->nameItem =item->text();
}
void MainWindow::ItemListYourBooks_click(QListWidgetItem *item){
    ui->bRemoveYourBooks->setEnabled(true);
    this->nameItem = item->text();
    this->item =item;
}

void MainWindow::on_bBorrows_clicked()
{
    this->yourBooks->addItem(this->nameItem);
}

void MainWindow::on_bYourBooks_clicked()
{
    ui->vUserdisplay->removeWidget(this->myWidget);
    ui->vUserdisplay->addWidget(this->yourBooks);
    ui->bBorrows->setEnabled(false);
}

void MainWindow::on_bRemoveYourBooks_clicked()
{
    ui->vUserdisplay->removeWidget(this->yourBooks);
    this->yourBooks->takeItem(this->yourBooks->row(this->item));
    ui->vUserdisplay->addWidget(this->yourBooks);
    ui->bRemoveYourBooks->setEnabled(false);
}

void MainWindow::on_bHelp_clicked()
{
//      delete this->item;
//      delete &(this->user);
//      delete this->myWidget;
//      delete this->yourBooks;
    ui->bBorrows->setEnabled(false);
    ui->bYourBooks->setEnabled(false);
    ui->bViewBooks->setEnabled(false);
    ui->bRemoveYourBooks->setEnabled(false);
}
