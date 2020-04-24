#ifndef P_DATA_H
#define P_DATA_H

#include <QWidget>
#include <QFileSystemModel>
#include <QComboBox>
#include <QCheckBox>
#include <QStandardItem>

#include "property.h"

namespace Ui {
class p_data;
}

class p_data : public QWidget
{
    Q_OBJECT

public:
    explicit p_data(QWidget *parent = nullptr);
    ~p_data();

    void create_ui();

Q_SLOT  void on_add_clicked();
Q_SLOT  void on_mkdir_clicked();
Q_SLOT  void on_del_clicked();
Q_SLOT  void on_clean_clicked();
Q_SLOT  void on_burner_setting_clicked();
Q_SLOT  void on_start_burner_clicked();
Q_SLOT  void setting_exit();
Q_SLOT  void setting_ok();

private:
    Ui::p_data *ui;
    class property pro;
    QFileSystemModel *data_model;
    QDialog *burn_setting;
    QComboBox *speed;
    QCheckBox *append;
    QCheckBox *burn_proof;
    QCheckBox *simulation;

    QList<QStandardItem *> items;
};

#endif // P_DATA_H
