#ifndef BURNCLEAN_H
#define BURNCLEAN_H

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

namespace Ui {
class BurnClean;
}

class BurnClean : public QDialog
{
    Q_OBJECT

public:
    explicit BurnClean(QWidget *parent = nullptr);
    ~BurnClean();

    QComboBox *clean_combo;
Q_SLOT void clean_ok();
Q_SLOT void clean_exit();

private:
    Ui::BurnClean *ui;
    class property pro;
    QDialog *clean_dialog;
};

#endif // BURNCLEAN_H
