#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::UsrLogin()
{
   QSqlQuery query;
   query.exec("select pwd from user where id='"+ui->lineEdit->text()+"'");
   if(!query.isActive())
   {
       return;
   }

   if(query.next())
   {
       QString password=query.value(0).toString();
       if(QString::compare(password,ui->lineEdit_2->text())!=0)
       {
           QMessageBox::critical(NULL,"Error","密码错误！",QMessageBox::Yes);
           return;
       }
   }
   else
   {
       QMessageBox::critical(NULL,"Error","用户不存在！",QMessageBox::Yes);
       return;
   }
   close();
   QMessageBox::about(0,"Login","登陆成功！");
}

void Login::MngLogin()
{
    QSqlQuery query;
    query.exec("select pwd from manager where id='"+ui->lineEdit_3->text()+"'");
    if(!query.isActive())
    {
        return;
    }

    if(query.next())
    {
        QString password=query.value(0).toString();
        if(QString::compare(password,ui->lineEdit_4->text())!=0)
        {
            QMessageBox::critical(NULL,"Error","密码错误！",QMessageBox::Yes);
            return;
        }
    }
    else
    {
        QMessageBox::critical(NULL,"Error","管理员不存在！",QMessageBox::Yes);
        return;
    }
    close();
    QMessageBox::about(0,"Login","登陆成功！");
}

void Login::on_pushButton_clicked()
{
    UsrLogin();
}


void Login::on_pushButton_3_clicked()
{
    MngLogin();
}
