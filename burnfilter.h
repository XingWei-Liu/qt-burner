#ifndef BURNFILTER_H
#define BURNFILTER_H

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
class BurnFilter;
}

class BurnFilter : public QDialog
{
    Q_OBJECT

public:
    explicit BurnFilter(QWidget *parent = nullptr);
    ~BurnFilter();

    QCheckBox *hide_check;
    QCheckBox *link_check;
    QCheckBox *deform_link;

    Q_SLOT void filter_exit();

private:
    Ui::BurnFilter *ui;
    class property pro;

    QDialog *filter_dialog;
};

#endif // BURNFILTER_H
