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
            mount_flag = true;
        }
    }
    kylin_device_free(info, num); //释放内存

    qDebug() << ui->comboBox_2->currentText();
    qDebug() << "mount_flag :" << mount_flag;

    if(mount_flag)
        ui->treeView->setRootIndex(data_model->index(ui->comboBox_2->currentText()));
    //else
      //  ui->treeView->setRootIndex(data_model->index("/"));

//    data_model->setRootPath(ui->comboBox_2->currentText());
//    ui->treeView->setRootIndex(data_model->index(ui->comboBox_2->currentText()));
//    data_model->setRootPath("/home");
//        data_model->setRootPath(QDir::currentPath());
//        data_model->setRootPath("/home/test");



}

p_data::~p_data()
{
    delete ui;
}

void p_data::create_ui()
{
    ui->textBrowser->setMaximumSize(30,30);

    data_model = new QFileSystemModel;
    data_model->setRootPath(QDir::currentPath());
    ui->treeView->setModel(data_model);
    ui->treeView->setColumnWidth(0,400);
}

void p_data::on_add_clicked()
{
    qDebug() << __FUNCTION__ << __LINE__ <<  "-------------------";

    QString s = QFileDialog::getExistingDirectory(this, "open file dialog", "/home");


    QStringList files = QFileDialog::getOpenFileNames(
                            this,
                            "Select one or more files to open",
                            "/home",
                            "ALL(*.*)");

    for(int i=0;i<files.size();i++)
         {
//             ui->openEdits->append(filenames.at(i));

//            ui->treeView->s
         }

//    ui->treeView->a

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
    burn_setting = new QDialog();
    burn_setting->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    burn_setting->setFixedSize(400, 400);

    QLabel *icon = new QLabel();
    icon->setFixedSize(30,30);
    icon->setStyleSheet("QLabel{background-image: url(:/new/prefix1/pic/logo.png);background-color:rgb(233, 233, 233);background-repeat: no-repeat;}");
    QLabel *title = new QLabel("kylin-burner");
    title->setFixedSize(80,30);
    title->setStyleSheet("QLabel{background-color:rgb(233, 233, 233);background-repeat: no-repeat;color:rgb(0, 0, 0);font: 14px;}");
    QPushButton *close = new QPushButton();
    close->setFixedSize(30,30);
    close->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/pic/icon-关闭-默认.png);border:none;background-color:rgb(233, 233, 233);border-radius: 4px;}"
                                "QPushButton:hover{border-image: url(:/new/prefix1/pic/icon-关闭-悬停点击.png);border:none;background-color:rgb(248, 100, 87);border-radius: 4px;}");

    connect(close, &QPushButton::clicked, this, &p_data::setting_exit);

    QHBoxLayout *titlebar = new QHBoxLayout();
    titlebar->addWidget(icon);
    titlebar->addSpacing(10);
    titlebar->addWidget(title);
    titlebar->addStretch();
    titlebar->addWidget(close);

    QLabel *setting_label = new QLabel("burn setting");
    setting_label->setFixedSize(200,30);
    setting_label->setStyleSheet("QLabel{font: 24px ;color: #444444;}");

    QLabel *burn_speed = new QLabel("burn speed");
    speed = new QComboBox();
    QStringList list = {"max","1x", "2x","3x","4x"};
    speed->addItems(list);

    append = new QCheckBox("The next time you do not close the disc, you can add additional files (recommended)");
    append->setChecked(true);
    burn_proof = new QCheckBox("use Burn-Proof(recommended)");
    burn_proof->setChecked(true);
    simulation = new QCheckBox("Simulation before burning");
    simulation->setChecked(false);

    QLabel *tmpfile = new QLabel("burn speed");
    QLineEdit *tmp = new QLineEdit();

    QHBoxLayout *hLayout = new QHBoxLayout();
    QPushButton *cancel = new QPushButton("cancel");
    QPushButton *ok = new QPushButton("ok");
    hLayout->addStretch();
    hLayout->addWidget(cancel);
    hLayout->addWidget(ok);

    QVBoxLayout *mainLayout = new QVBoxLayout(burn_setting);
    mainLayout->addLayout(titlebar);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(setting_label);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(burn_speed);
    mainLayout->addWidget(speed);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(append);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(burn_proof);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(simulation);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(tmpfile);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(tmp);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(hLayout);
    mainLayout->addSpacing(20);

    connect(cancel, &QPushButton::clicked, this, &p_data::setting_exit);
    connect(ok, &QPushButton::clicked, this, &p_data::setting_ok);

    burn_setting->setModal(true);
    burn_setting->show();
    }else {
        QString s = QFileDialog::getOpenFileName(this, "open file dialog", "/home/test", "iso file(*.iso*.udf)");
        qDebug() << "filenames: " << s;
        ui->treeView->setRootIndex(data_model->index(s));
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

void p_data::setting_exit()
{
    burn_setting->close();
}
void p_data::setting_ok()
{
    pro.set_burn_speed(speed->currentText());
    pro.set_burn_append(append->isChecked());
    pro.set_burn_proof(burn_proof->isChecked());
    pro.set_simulation(simulation->isChecked());
    burn_setting->close();
}
