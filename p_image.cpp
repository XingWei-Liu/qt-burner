#include "p_image.h"
#include "ui_p_image.h"

p_image::p_image(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::p_image)
{
    ui->setupUi(this);
}

p_image::~p_image()
{
    delete ui;
}


void p_image::on_file_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, "open file dialog", "/home","iso file(*.iso *.udf)", 0, QFileDialog::DontUseNativeDialog);
    ui->lineEdit->setText(s);
}

void p_image::on_burner_setting_clicked()
{
    burn_setting = new BurnerSet();
    burn_setting->saveCD->setEnabled(false);
    burn_setting->append->setChecked(false);
    burn_setting->setModal(true);
//    burn_setting->show();
}

void p_image::on_start_burner_clicked()
{
    pro.set_burn_iso(ui->lineEdit->text());
    pro.set_burn_disk(ui->comboBox->currentText());
}

