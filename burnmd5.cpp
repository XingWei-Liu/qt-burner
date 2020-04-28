#include "burnmd5.h"
#include "ui_burnmd5.h"

BurnMd5::BurnMd5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BurnMd5)
{
    ui->setupUi(this);

    check_dialog = new QDialog;
    check_dialog->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    check_dialog->setFixedSize(400, 400);

    QLabel *icon = new QLabel();
    icon->setFixedSize(30,30);
    icon->setStyleSheet("QLabel{background-image: url(:/new/prefix1/pic/logo.png);"
                        "background-color:rgb(233, 233, 233);"
                        "background-repeat: no-repeat;background-color:transparent;}");
    QLabel *title = new QLabel("kylin-burner");
    title->setFixedSize(80,30);
    title->setStyleSheet("QLabel{background-color:rgb(233, 233, 233);"
                         "background-repeat: no-repeat;"
                         "color:rgb(0, 0, 0);font: 14px;"
                         "background-color:transparent;}");
    QPushButton *close = new QPushButton();
    close->setFixedSize(30,30);
    close->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/pic/icon-关闭-默认.png);"
                         "border:none;background-color:rgb(233, 233, 233);"
                         "border-radius: 4px;background-color:transparent;}"
                          "QPushButton:hover{border-image: url(:/new/prefix1/pic/icon-关闭-悬停点击.png);"
                         "border:none;background-color:rgb(248, 100, 87);"
                         "border-radius: 4px;}");
    connect(close, &QPushButton::clicked, this, &BurnMd5::check_exit);

    QHBoxLayout *titlebar = new QHBoxLayout();
    titlebar->addWidget(icon);
    titlebar->addSpacing(10);
    titlebar->addWidget(title);
    titlebar->addStretch();
    titlebar->addWidget(close);
    QVBoxLayout *mainWidgetLayout = new QVBoxLayout(check_dialog);
    QLabel *check_label = new QLabel("check MD5");
    QLabel *check_label1 = new QLabel("choice check CD");
    check_combo = new QComboBox();
    md5_check = new QCheckBox();
    md5_check->setChecked(false);
    md5_check->setText("Checking discs with MD5 files");
    md5_file = new QLineEdit("");
    md5_file->setMaximumSize(300,30);
    choice = new QPushButton("file");
    md5_file->setEnabled(false);
    choice->setEnabled(false);
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    hLayout1->addWidget(md5_file);
    hLayout1->addWidget(choice);

    QHBoxLayout *hLayout = new QHBoxLayout();
    QPushButton *cancel = new QPushButton("cancel");
    QPushButton *ok = new QPushButton("ok");
    hLayout->addWidget(cancel);
    hLayout->addWidget(ok);

    mainWidgetLayout->addLayout(titlebar);
    mainWidgetLayout->addWidget(check_label);
    mainWidgetLayout->addSpacing(20);
    mainWidgetLayout->addWidget(check_label1);
    mainWidgetLayout->addWidget(check_combo);
    mainWidgetLayout->addSpacing(20);
    mainWidgetLayout->addWidget(md5_check);
    mainWidgetLayout->addLayout(hLayout1);
    mainWidgetLayout->addStretch();
    mainWidgetLayout->addLayout(hLayout);
    check_dialog->show();

    connect(md5_check, &QCheckBox::clicked, this, &BurnMd5::check_clicked);
    connect(choice, &QPushButton::clicked, this, &BurnMd5::file_clicked);
    connect(ok, &QPushButton::clicked, this, &BurnMd5::check_ok);
    connect(cancel, &QPushButton::clicked, this, &BurnMd5::check_exit);

}

BurnMd5::~BurnMd5()
{
    delete ui;
}

void BurnMd5::check_clicked()
{
    if(md5_check->isChecked()){
        md5_file->setEnabled(true);
        choice->setEnabled(true);
    }else{
        md5_file->setEnabled(false);
        choice->setEnabled(false);
    }
}

void BurnMd5::file_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, "open file dialog", "/home", "md5 file(*.md5)", 0, QFileDialog::DontUseNativeDialog);
    md5_file->setText(s);
}

void BurnMd5::check_ok()
{
    pro.set_check_disk(check_combo->currentText());
    pro.set_md5_check(md5_check->isChecked());
    pro.set_md5_file(md5_file->text());
    check_dialog->close();
}

void BurnMd5::check_exit()
{
    check_dialog->close();
}
