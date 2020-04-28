#include "p_copy.h"
#include "ui_p_copy.h"

p_copy::p_copy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::p_copy)
{
    ui->setupUi(this);
}

p_copy::~p_copy()
{
    delete ui;
}

void p_copy::on_file_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, "open file dialog", "/home/test"," iso file(*.iso *.udf) ", 0, QFileDialog::DontUseNativeDialog);
    ui->lineEdit_2->setText(s);
}

void p_copy::on_create_clicked()
{
    pro.set_copy_disk(ui->comboBox_2->currentText());
    pro.set_copy_iso(ui->lineEdit_2->text());
    pro.set_copy_to_disk(ui->comboBox->currentText());
}

void p_copy::on_burn_setting_clicked()
{
    burn_setting = new BurnerSet();
    burn_setting->saveCD->setVisible(false);
    burn_setting->append->setChecked(false);
    burn_setting->burn_proof->setChecked(false);
    burn_setting->setModal(true);
//    burn_setting->show();
}

void p_copy::on_radioButton_clicked()
{
    if(ui->radioButton->isChecked()){
        ui->comboBox->setEnabled(true);
        ui->burn_setting->setEnabled(true);
        ui->lineEdit_2->setEnabled(false);
        ui->file->setEnabled(false);
    }
}

void p_copy::on_radioButton_2_clicked()
{
    if(ui->radioButton_2->isChecked()){
        ui->lineEdit_2->setEnabled(true);
        ui->file->setEnabled(true);
        ui->comboBox->setEnabled(false);
        ui->burn_setting->setEnabled(false);
    }
}
