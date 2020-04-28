#include "burnclean.h"
#include "ui_burnclean.h"

BurnClean::BurnClean(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BurnClean)
{
    ui->setupUi(this);
    clean_dialog = new QDialog;
    clean_dialog->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    clean_dialog->setFixedSize(400, 400);

    QLabel *icon = new QLabel();
    icon->setFixedSize(35,35);
    icon->setStyleSheet("QLabel{background-image: url(:/new/prefix1/pic/logo.png);"
                        "background-color:rgb(233, 233, 233);"
                        "background-repeat: no-repeat;background-color:transparent;}");
    QLabel *title = new QLabel("kylin-burner");
    title->setFixedSize(80,30);
    title->setStyleSheet("QLabel{background-color:rgb(233, 233, 233);"
                         "background-repeat: no-repeat;color:rgb(0, 0, 0);"
                         "font: 14px;background-color:transparent;}");
    QPushButton *close = new QPushButton();
    close->setFixedSize(30,30);
    close->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/pic/icon-关闭-默认.png);"
                         "border:none;background-color:rgb(233, 233, 233);"
                         "border-radius: 4px;background-color:transparent;}"
                         "QPushButton:hover{border-image: url(:/new/prefix1/pic/icon-关闭-悬停点击.png);"
                         "border:none;background-color:rgb(248, 100, 87);"
                         "border-radius: 4px;}");

    connect(close, &QPushButton::clicked, this, &BurnClean::clean_exit);

    QHBoxLayout *titlebar = new QHBoxLayout();
    titlebar->addWidget(icon);
    titlebar->addSpacing(10);
    titlebar->addWidget(title);
    titlebar->addStretch();
    titlebar->addWidget(close);

    QVBoxLayout *mainWidgetLayout = new QVBoxLayout(clean_dialog);
    QLabel *clean_label = new QLabel("clean");
    clean_label->setStyleSheet("QLabel{font: 24px ;color: #444444;}");
    QLabel *clean_label1 = new QLabel("add clean CD");
    clean_combo = new QComboBox();
    QLabel *prompt = new QLabel("");

    QHBoxLayout *hLayout = new QHBoxLayout();
    QPushButton *cancel = new QPushButton("cancel");
    QPushButton *ok = new QPushButton("ok");
    hLayout->addWidget(cancel);
    hLayout->addWidget(ok);

    mainWidgetLayout->addLayout(titlebar);
    mainWidgetLayout->addSpacing(10);
    mainWidgetLayout->addWidget(clean_label);
    mainWidgetLayout->addSpacing(20);
    mainWidgetLayout->addWidget(clean_label1);
    mainWidgetLayout->addWidget(clean_combo);
    mainWidgetLayout->addWidget(prompt);
    mainWidgetLayout->addStretch();
    mainWidgetLayout->addLayout(hLayout);

    clean_dialog->show();

    connect(close, &QPushButton::clicked, this, &BurnClean::clean_exit);
}

BurnClean::~BurnClean()
{
    delete ui;
}

void BurnClean::clean_ok()
{
    pro.set_clean_disk(clean_combo->currentText());
    clean_dialog->close();
}

void BurnClean::clean_exit()
{
    clean_dialog->close();
}


