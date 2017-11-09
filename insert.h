#ifndef INSERT_H
#define INSERT_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class Insert;
}

class Insert : public QDialog
{
    Q_OBJECT

public:
    explicit Insert(QWidget *parent = 0);
    ~Insert();

private:
    Ui::Insert *ui;

public:
    void BkInsert();

private slots:
    void on_pushButton_clicked();
};

#endif // INSERT_H
