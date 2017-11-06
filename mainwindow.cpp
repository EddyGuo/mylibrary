#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dbCreat();
    ui->pushButton_11->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->tabWidget->removeTab(2);
    ui->tabWidget->removeTab(1);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(ui->tab,"图书信息");
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

bool MainWindow::dbConnect()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if(!db.open())
    {
        qDebug() << "Database Error!";
        return false;
    }
    return true;
}

bool MainWindow::dbCreat()
{
    if(dbConnect()){
        QSqlTableModel *BkModel=new QSqlTableModel;
        BkModel->setTable("book");
        BkModel->setSort(BkId,Qt::AscendingOrder);
        BkModel->setHeaderData(BkId, Qt::Horizontal, "ISBN");
        BkModel->setHeaderData(BkName, Qt::Horizontal, "书名");
        BkModel->setHeaderData(BkAuthor,Qt::Horizontal,"作者");
        BkModel->setHeaderData(BkPub, Qt::Horizontal, "出版社");
        BkModel->setHeaderData(BkPubDate, Qt::Horizontal, "出版日期");
        BkModel->setHeaderData(BkAvail, Qt::Horizontal, "是否可借");
        BkModel->setHeaderData(BkStore, Qt::Horizontal, "库存");
        BkModel->setHeaderData(BkTotal, Qt::Horizontal, "总数");
        BkModel->select();
        ui->tableView->setModel(BkModel);

        QSqlTableModel *UsrModel=new QSqlTableModel;
        UsrModel->setTable("user");
        UsrModel->setSort(UsrId,Qt::AscendingOrder);
        UsrModel->setHeaderData(UsrId, Qt::Horizontal, "ID");
        UsrModel->setHeaderData(UsrPwd, Qt::Horizontal, "密码");
        UsrModel->setHeaderData(UsrEmail, Qt::Horizontal, "邮箱");
        UsrModel->setHeaderData(UsrLoan, Qt::Horizontal, "已借数量");
        UsrModel->setHeaderData(UsrMax, Qt::Horizontal, "可借数量");
        UsrModel->select();
        ui->tableView_2->setModel(UsrModel);

           qDebug() << "Database Create Sucessfully!";
           return true;
       }
       else{
           qDebug() << "Database Create Failed!";
           return false;
       }

}

void MainWindow::on_pushButton_9_clicked()
{
    Login *log=new Login(this);
    log->exec();
}

void MainWindow::on_pushButton_10_clicked()
{
    Register *reg=new Register(this);
    reg->exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    Insert *insert=new Insert(this);
    insert->exec();
}
