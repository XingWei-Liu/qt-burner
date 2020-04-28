#ifndef P_IMAGE_H
#define P_IMAGE_H

#include <QWidget>
#include <QDialog>
#include <QComboBox>
#include <QCheckBox>
#include <QDebug>
#include <QFileDialog>
#include "property.h"
#include "burnerset.h"

namespace Ui {
class p_image;
}

class p_image : public QWidget
{
    Q_OBJECT

public:
    explicit p_image(QWidget *parent = nullptr);
    ~p_image();


//private slots:
Q_SLOT    void on_file_clicked();

Q_SLOT    void on_burner_setting_clicked();

Q_SLOT    void on_start_burner_clicked();

private:
    Ui::p_image *ui;
    class property pro;
    BurnerSet *burn_setting;
};

#endif // P_IMAGE_H
