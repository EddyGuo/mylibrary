#include "insert.h"
#include "ui_insert.h"

Insert::Insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Insert)
{
    ui->setupUi(this);
}

Insert::~Insert()
{
    delete ui;
}

void Insert::BkInsert()
{
    if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()||
            ui->lineEdit_3->text().isEmpty()||ui->lineEdit_4->text().isEmpty()
            ||ui->lineEdit_5->text().isEmpty()||ui->spinBox->text()==0)
    {
        QMessageBox::critical(NULL,"Error","信息不完整！",QMessageBox::Yes);
        return;
    }

    QSqlQuery query;
    query.exec("select id from book where id='"+ui->lineEdit->text()+"'");
    if(query.next())
    {
        QMessageBox::critical(NULL,"Error","重复录入！",QMessageBox::Yes);
        return;
    }

    query.exec("insert into book values('"+
               ui->lineEdit->text()+"','"+
               ui->lineEdit_2->text()+"','"+
               ui->lineEdit_3->text()+"','"+
               ui->lineEdit_5->text()+"','"+
               ui->lineEdit_4->text()+"',1,'"+
               ui->spinBox->text()+"','"+ui->spinBox->text()+"')");
    if(query.isActive())
    {
        QMessageBox::about(0,"Insert","已录入！");
    }
    else
    {
        QMessageBox::critical(NULL,"Error","失败！",QMessageBox::Yes);
        return;
    }

}

void Insert::on_pushButton_clicked()
{
    BkInsert();
}
