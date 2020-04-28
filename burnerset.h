#ifndef BURNERSET_H
#define BURNERSET_H

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
class BurnerSet;
}

class BurnerSet : public QDialog
{
    Q_OBJECT

public:
    explicit BurnerSet(QWidget *parent = nullptr);
    ~BurnerSet();

    QComboBox *speed;
    QCheckBox *saveCD;
    QCheckBox *append;
    QCheckBox *burn_proof;
    QCheckBox *simulation;

Q_SLOT  void setting_exit();
Q_SLOT  void setting_ok();

private:
    Ui::BurnerSet *ui;
    class property pro;
    QDialog *burn_setting;

};

#endif // BURNERSET_H
