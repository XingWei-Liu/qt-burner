#ifndef P_COPY_H
#define P_COPY_H

#include <QWidget>
#include <QDialog>
#include <QComboBox>
#include <QCheckBox>
#include <QDebug>
#include <QFileDialog>
#include "property.h"
#include "burnerset.h"

namespace Ui {
class p_copy;
}

class p_copy : public QWidget
{
    Q_OBJECT

public:
    explicit p_copy(QWidget *parent = nullptr);
    ~p_copy();

//private slots:

Q_SLOT    void on_file_clicked();

Q_SLOT    void on_create_clicked();

Q_SLOT    void on_burn_setting_clicked();

Q_SLOT    void on_radioButton_clicked();

Q_SLOT    void on_radioButton_2_clicked();

private:
    Ui::p_copy *ui;
    class property pro;
    BurnerSet *burn_setting;

};

#endif // P_COPY_H
