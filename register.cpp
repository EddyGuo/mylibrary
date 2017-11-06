#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::UsrRegister()
{
    if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()
            ||ui->lineEdit_3->text().isEmpty())
    {
        QMessageBox::critical(NULL,"Error","信息填写不完整！",QMessageBox::Yes);
        return;
    }

    if(ui->lineEdit_2->text().compare(ui->lineEdit_3->text())!=0)
    {
        QMessageBox::critical(NULL,"Error","输入密码不一致！",QMessageBox::Yes);
        return;
    }

    QSqlQuery query;
    query.exec("select id from user where id = '"+ui->lineEdit->text()+"'");
    if(query.next())
    {
        QMessageBox::critical(NULL,"Error","该用户名已被注册！",QMessageBox::Yes);
        return;
    }

    query.exec("insert into user values('"+ui->lineEdit->text()+"','"+ui->lineEdit_2
               ->text()+"','"+ui->lineEdit_4->text()+"',0,8)");
    if(query.isActive())
    {
        close();
        QMessageBox::about(0,"Register","注册成功！");
    }
    else
    {
        QMessageBox::critical(NULL,"Error","注册失败！",QMessageBox::Yes);
        return;
    }
}

void Register::on_pushButton_clicked()
{
    UsrRegister();
}
