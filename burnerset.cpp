#include "burnerset.h"
#include "ui_burnerset.h"

BurnerSet::BurnerSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BurnerSet)
{
    ui->setupUi(this);
    burn_setting = new QDialog();
    burn_setting->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    burn_setting->setFixedSize(400, 400);

    QLabel *icon = new QLabel();
    icon->setFixedSize(30,30);
    icon->setStyleSheet("QLabel{background-image: url(:/new/prefix1/pic/logo.png);"
                        "background-color:rgb(233, 233, 233);"
                        "background-repeat: no-repeat;background-color:transparent;}");
    QLabel *title = new QLabel("kylin-burner");
    title->setFixedSize(80,30);
    title->setStyleSheet("QLabel{background-color:rgb(233, 233, 233);"
                         "background-repeat: no-repeat;"
                         "color:rgb(0, 0, 0);font: 14px;background-color:transparent;}");
    QPushButton *close = new QPushButton();
    close->setFixedSize(30,30);
    close->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/pic/icon-关闭-默认.png);"
                         "border:none;background-color:rgb(233, 233, 233);border-radius: 4px;}"
                         "QPushButton:hover{border-image: url(:/new/prefix1/pic/icon-关闭-悬停点击.png);"
                         "border:none;background-color:rgb(248, 100, 87);border-radius: 4px;}");

    connect(close, &QPushButton::clicked, this, &BurnerSet::setting_exit);

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

    saveCD = new QCheckBox("Burn image files directly without saving to disc");
    saveCD->setChecked(true);
    append = new QCheckBox("The next time you do not close the disc, you can add additional files (recommended)");
    append->setChecked(true);
    burn_proof = new QCheckBox("use Burn-Proof(recommended)");
    burn_proof->setChecked(true);
    simulation = new QCheckBox("Simulation before burning");
    simulation->setChecked(false);

    QLabel *tmpfile = new QLabel("tmp file");
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
    mainLayout->addWidget(saveCD);
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
    burn_setting->show();

    connect(cancel, &QPushButton::clicked, this, &BurnerSet::setting_exit);
    connect(ok, &QPushButton::clicked, this, &BurnerSet::setting_ok);
}

BurnerSet::~BurnerSet()
{
    delete ui;
}

void BurnerSet::setting_exit()
{
    burn_setting->close();
}
void BurnerSet::setting_ok()
{
    pro.set_burn_speed(speed->currentText());
    pro.set_burn_append(append->isChecked());
    pro.set_burn_proof(burn_proof->isChecked());
    pro.set_simulation(simulation->isChecked());
    burn_setting->close();
}
