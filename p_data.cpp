#include "p_data.h"
#include "ui_p_data.h"

extern "C"{
#include "kylin_api.h"
}

p_data::p_data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::p_data)
{
    ui->setupUi(this);
    QVariant v(0);
    create_ui();

    KylinDeviceInfo info[KYLIN_MAXNUM_DEVICE] = {0}; //运行结束，记得free
    int num = kylin_get_device_info(info);

    bool mount_flag=false;
    for(int i=0; i<num; i++)
    {
        printf("info[%d].drive_name :%s \n", i, info[i].drive_name);
        printf("info[%d].mountpoint :%s \n\n", i, info[i].mountpoint);

        if(info[i].drive_name)
            ui->comboBox->addItem(info[i].drive_name);

        if(info[i].mountpoint)
        {
            ui->comboBox_2->addItem(info[i].mountpoint);
            clean_dialog->clean_combo->addItem(info[i].mountpoint);
            check_dialog->check_combo->addItem(info[i].mountpoint);
            mount_flag = true;
        }
    }
    kylin_device_free(info, num); //释放内存

    if(mount_flag)
        ui->treeView->setRootIndex(data_model->index(ui->comboBox_2->currentText()));
    //else
      //  ui->treeView->setRootIndex(data_model->index("/"));

    if(num == 0){
        //ui->comboBox->setItemData(2, v, Qt::UserRole - 1);
        ui->burner_setting->setText("choose path");
        ui->start_burner->setText("create iso");
        ui->comboBox_2->setEditable(true);
    }else{
        ui->burner_setting->setText("burner setting");
        ui->start_burner->setText("start burner");
    }
}

p_data::~p_data()
{
    delete ui;
}

void p_data::create_ui()
{
    data_model = new QFileSystemModel;
    data_model->setRootPath(QDir::currentPath());
    ui->treeView->setModel(data_model);
    ui->treeView->setColumnWidth(0,400);

}

void p_data::on_add_clicked()
{
    qDebug() << __FUNCTION__ << __LINE__ <<  "-------------------";

    QString s = QFileDialog::getOpenFileName(this, "open file dialog", "/home", "ALL(*.*)", 0, QFileDialog::DontUseNativeDialog);

    qDebug() << "filenames: " << s;

    ui->treeView->setRootIndex(data_model->index(s));
}

void p_data::on_mkdir_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if (!index.isValid()) {
        return;
    }
    QString dirName = QInputDialog::getText(this,
                                            tr("Create Directory"),
                                            tr("Directory name"));
    if (!dirName.isEmpty()) {
        if (!data_model->mkdir(index, dirName).isValid()) {
            QMessageBox::information(this,
                                     tr("Create Directory"),
                                     tr("Failed to create the directory"));
        }
    }
}

void p_data::on_del_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
        if (!index.isValid()) {
            return;
        }
        bool ok;
        if (data_model->fileInfo(index).isDir()) {
            ok = data_model->rmdir(index);
        } else {
            ok = data_model->remove(index);
        }
        if (!ok) {
            QMessageBox::information(this,
                             tr("Remove"),
                             tr("Failed to remove %1").arg(data_model->fileName(index)));
        }
}

void p_data::on_clean_clicked()
{

}

void p_data::on_burner_setting_clicked()
{
    if (ui->burner_setting->text() == "burner setting"){
        burn_setting = new BurnerSet();
        burn_setting->saveCD->setVisible(false);
        burn_setting->setModal(true);
//        burn_setting->show();
    }else {
        QString s = QFileDialog::getOpenFileName(this, "open file dialog", "/home", "iso file(*.iso *.udf)", 0, QFileDialog::DontUseNativeDialog);
        qDebug() << "filenames: " << s;
        ui->comboBox_2->setCurrentText(s);
    }
}

void p_data::on_start_burner_clicked()
{

    qDebug("%s %d %d %d", pro.get_burn_speed().toLatin1().data(), pro.get_burn_append(), pro.get_burn_proof(), pro.get_simulation());
    if (ui->burner_setting->text() == "burner setting")
    {
        pro.set_burn_disk(ui->comboBox_2->currentText());

    }else {
        pro.set_copy_iso(ui->comboBox_2->currentText());

    }
}
