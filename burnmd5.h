#ifndef BURNMD5_H
#define BURNMD5_H

#include "property.h"

//#include <QDialog>
//#include <QWidget>
//#include <QLabel>
//#include <QPushButton>
//#include <QHBoxLayout>
//#include <QVBoxLayout>
//#include <QComboBox>
//#include <QCheckBox>
//#include <QLineEdit>
#include <QFileDialog>

namespace Ui {
class BurnMd5;
}

class BurnMd5 : public QDialog
{
    Q_OBJECT

public:
    explicit BurnMd5(QWidget *parent = nullptr);
    ~BurnMd5();

    QComboBox *check_combo;
    QCheckBox *md5_check;
    QLineEdit *md5_file;
    QPushButton *choice;

Q_SLOT void check_clicked();
Q_SLOT void check_ok();
Q_SLOT void check_exit();
Q_SLOT void file_clicked();

private:
    Ui::BurnMd5 *ui;
    class property pro;
    QDialog *check_dialog;
};

#endif // BURNMD5_H
