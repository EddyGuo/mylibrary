#ifndef INSERT_H
#define INSERT_H

#include <QDialog>

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
};

#endif // INSERT_H
