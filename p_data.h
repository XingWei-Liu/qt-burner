#ifndef P_DATA_H
#define P_DATA_H

#include <QWidget>
#include <QFileSystemModel>
#include <QComboBox>
#include <QCheckBox>
#include <QStandardItem>
#include <QDialog>
#include <QList>
#include <QFileDialog>
#include <QLineEdit>
#include <QDebug>
#include <QStringList>
#include <QStandardItem>
#include <QInputDialog>
#include <QMessageBox>
#include <QCheckBox>
#include <QDebug>

#include "property.h"
#include "burnerset.h"
#include "burnclean.h"
#include "burnmd5.h"

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

private:
    Ui::p_data *ui;
    class property pro;
    BurnerSet *burn_setting;
    BurnClean *clean_dialog;
    BurnMd5 *check_dialog;
    QFileSystemModel *data_model;
    QList<QStandardItem *> items;
};

#endif // P_DATA_H
