#include <QVBoxLayout>
#include <QPixmap>
#include <QIcon>
#include <QTableWidget>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QEvent>

#include "widget.h"
#include "ui_widget.h"
#include "title_bar.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    create_ui();

    ui->setupUi(this);

    this->setWindowTitle("Kylin-burner");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::create_ui()
{
    TitleBar *pTitleBar = new TitleBar(this);
    installEventFilter(this);

    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(255, 255, 255));
    setAutoFillBackground(true);
    setPalette(pal);

    tabWidget = new QStackedWidget(this);

    QLabel *label = new QLabel();
    label->setMinimumSize(125, 600);
    label->setStyleSheet("QLabel{background-image: url(:/new/prefix1/pic/icon-侧边背景.png);"
                         "background-position: top;"
                         "border:none;"
                         "background-repeat:repeat-xy;}");
    label->setScaledContents(true);

    pIconLabel = new QLabel(this);
    pTitleLabel = new QLabel(this);
    pIconLabel->setFixedSize(35,35);
    pIconLabel->setStyleSheet("QLabel{background-image: url(:/new/prefix1/pic/logo.png);"
                              "background-color:transparent;"
                              "background-repeat: no-repeat;}");
    pTitleLabel->setContentsMargins(0,0,0,0);
    pTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    pTitleLabel->setObjectName("whiteLabel");
    pTitleLabel->setMinimumSize(100,35);
    pTitleLabel->setStyleSheet("QLabel{background-color:transparent;background-repeat: no-repeat;font: 12px;}");


    data_burner = new QPushButton();
    data_burner->setText("data burner");
    data_burner->setFixedSize(115, 50);
    data_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-数据刻录-默认.png);"
                               "background-color:rgba(87, 137, 217,0.2);"
                               "background-repeat: no-repeat;"
                               "background-position:left;"
                               "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                           "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-数据刻录-悬停点击.png);"
                               "background-color:rgba(87, 137, 217,0.15);"
                               "background-repeat: no-repeat;"
                               "background-position:left;"
                               "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                           "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-数据刻录-悬停点击.png);"
                               "background-color:rgba(87, 137, 217, 0.2);"
                               "background-repeat: no-repeat;"
                               "background-position:left;"
                               "border:none;color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}");

    image_burner = new QPushButton();
    image_burner->setText("image burner");
    image_burner->setFixedSize(115, 50);
    image_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-镜像刻录-默认.png);"
                                "background-color: transparent;"
                                "background-repeat: no-repeat;"
                                "background-position:left;"
                                "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                           "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                "background-color:rgba(87, 137, 217, 0.15);"
                                "background-repeat: no-repeat;"
                                "background-position:left;"
                                "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                           "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                "background-color:rgba(87, 137, 217, 0.2);"
                                "background-repeat: no-repeat;"
                                "background-position:left;"
                                "border:none;"
                                "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align: right;}");
    copy_image = new QPushButton();
    copy_image->setText("copy image");
    copy_image->setFixedSize(115, 50);
    copy_image->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-光盘复制-默认.png);"
                              "background-color:transparent;"
                              "background-repeat: no-repeat;"
                              "background-position:left;"
                              "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                           "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                              "background-color:rgba(87, 137, 217, 0.15);"
                              "background-repeat: no-repeat;"
                              "background-position:left;"
                              "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                           "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                              "background-color:rgba(87, 137, 217, 0.2);"
                              "background-repeat: no-repeat;"
                              "background-position:left;"
                              "border:none;"
                              "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}");

    QHBoxLayout *hLayout1 = new QHBoxLayout();
    hLayout1->addSpacing(13);
    hLayout1->addWidget(pIconLabel);
    hLayout1->addSpacing(6);
    hLayout1->addWidget(pTitleLabel);

    QVBoxLayout *vLayout1 = new QVBoxLayout();
    vLayout1->addSpacing(12);
    vLayout1->addLayout(hLayout1);
    vLayout1->addSpacing(46);
    vLayout1->addWidget(data_burner);
    vLayout1->addSpacing(20);
    vLayout1->addWidget(image_burner);
    vLayout1->addSpacing(20);
    vLayout1->addWidget(copy_image);
    vLayout1->addStretch();

    vLayout1->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    label->setLayout(vLayout1);

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(pTitleBar);
    vLayout->addWidget(tabWidget);

    QHBoxLayout *pLayout = new QHBoxLayout();
    pLayout->setSpacing(0);
    pLayout->addWidget(label);
    pLayout->addLayout(vLayout);
    pLayout->setSpacing(0);
    pLayout->setMargin(0);
    setLayout(pLayout);

    data_page = new p_data(this);
    image_page = new p_image(this);
    copy_page = new p_copy(this);

    connect(data_burner, &QPushButton::clicked, this, &Widget::on_data_burner_clicked);
    connect(image_burner, &QPushButton::clicked, this, &Widget::on_image_burner_clicked);
    connect(copy_image, &QPushButton::clicked, this, &Widget::on_copy_image_clicked);

    tabWidget->addWidget(data_page);
    tabWidget->addWidget(image_page);
    tabWidget->addWidget(copy_page);
    tabWidget->setCurrentWidget(data_page);

    tabWidget->showFullScreen();
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type())
    {
    case QEvent::WindowTitleChange:
    {
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            pTitleLabel->setText(pWidget->windowTitle());
            return true;
        }
    }
    case QEvent::WindowIconChange:
    {
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            QIcon icon = pWidget->windowIcon();
            pIconLabel->setPixmap(icon.pixmap(pIconLabel->size()));
            return true;
        }
    }
    case QEvent::WindowStateChange:

    default:
         return QWidget::eventFilter(obj, event);

     }
     return QWidget::eventFilter(obj, event);
}

void Widget::on_data_burner_clicked()
{
    tabWidget->setCurrentWidget(data_page);
    data_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-数据刻录-悬停点击.png);"
                               "background-color:rgba(87, 137, 217, 0.2);"
                               "background-repeat: no-repeat;"
                               "background-position:left;"
                               "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                               "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                    "background-color:rgba(87, 137, 217, 0.15);"
                                    "background-repeat: no-repeat;"
                                    "background-position:left;"
                                    "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                               "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                    "background-color:rgba(87, 137, 217, 0.2);"
                                    "background-repeat: no-repeat;"
                                    "background-position:left;"
                                    "border:none;"
                                    "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}");
    image_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-镜像刻录-默认.png);"
                                "background-color:transparent;"
                                "background-repeat: no-repeat;"
                                "background-position:left;"
                                "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                                "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                     "background-color:rgba(87, 137, 217, 0.15);"
                                     "background-repeat: no-repeat;"
                                     "background-position:left;"
                                     "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                                "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                     "background-color:rgba(87, 137, 217, 0.2);"
                                     "background-repeat: no-repeat;"
                                     "background-position:left;"
                                     "border:none;"
                                     "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}");
    copy_image->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-光盘复制-默认.png);"
                              "background-color:transparent;"
                              "background-repeat: no-repeat;"
                              "background-position:left;"
                              "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                              "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                                 "background-color:rgba(87, 137, 217, 0.15);"
                                 "background-repeat: no-repeat;"
                                 "background-position:left;"
                                 "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                              "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                                 "background-color:rgba(87, 137, 217, 0.2);"
                                 "background-repeat: no-repeat;"
                                 "background-position:left;"
                                 "border:none;"
                                 "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}");
}

void Widget::on_image_burner_clicked()
{
    tabWidget->setCurrentWidget(image_page);
    data_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-数据刻录-默认.png);"
                               "background-color:transparent;"
                               "background-repeat: no-repeat;"
                               "background-position:left;"
                               "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                               "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                    "background-color:rgba(87, 137, 217, 0.15);"
                                    "background-repeat: no-repeat;"
                                    "background-position:left;"
                                    "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                               "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                    "background-color:rgba(87, 137, 217, 0.2);"
                                    "background-repeat: no-repeat;"
                                    "background-position:left;"
                                    "border:none;"
                                    "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}");
    image_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                "background-color:rgba(87, 137, 217, 0.2);"
                                "background-repeat: no-repeat;"
                                "background-position:left;"
                                "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                                "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                     "background-color:rgba(87, 137, 217, 0.15);"
                                     "background-repeat: no-repeat;"
                                     "background-position:left;"
                                     "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                                "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                     "background-color:rgba(87, 137, 217, 0.2);"
                                     "background-repeat: no-repeat;"
                                     "background-position:left;"
                                     "border:none;"
                                     "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}");
    copy_image->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-光盘复制-默认.png);"
                              "background-color:transparent;"
                              "background-repeat: no-repeat;"
                              "background-position:left;"
                              "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                              "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                                 "background-color:rgba(87, 137, 217, 0.15);"
                                 "background-repeat: no-repeat;"
                                 "background-position:left;"
                                 "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                              "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                                 "background-color:rgba(87, 137, 217, 0.2);"
                                 "background-repeat: no-repeat;"
                                 "background-position:left;"
                                 "border:none;"
                                 "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}");
}

void Widget::on_copy_image_clicked()
{
    tabWidget->setCurrentWidget(copy_page);
    data_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-数据刻录-默认.png);"
                               "background-color:transparent;"
                               "background-repeat: no-repeat;"
                               "background-position:left;"
                               "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                               "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                    "background-color:rgba(87, 137, 217, 0.15);"
                                    "background-repeat: no-repeat;"
                                    "background-position:left;"
                                    "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                               "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                    "background-color:rgba(87, 137, 217, 0.2);"
                                    "background-repeat: no-repeat;"
                                    "background-position:left;"
                                    "border:none;"
                                    "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}");
    image_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-镜像刻录-默认.png);"
                                "background-color:transparent;"
                                "background-repeat: no-repeat;"
                                "background-position:left;"
                                "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                                "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                     "background-color:rgba(87, 137, 217, 0.15);"
                                     "background-repeat: no-repeat;"
                                     "background-position:left;"
                                     "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                                "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                     "background-color:rgba(87, 137, 217, 0.2);"
                                     "background-repeat: no-repeat;"
                                     "background-position:left;"
                                     "border:none;"
                                     "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}");
    copy_image->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                              "background-color:rgba(87, 137, 217, 0.2);"
                              "background-repeat: no-repeat;"
                              "background-position:left;"
                              "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                              "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                                 "background-color:rgba(87, 137, 217, 0.15);"
                                 "background-repeat: no-repeat;"
                                 "background-position:left;"
                                 "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}"
                              "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                                 "background-color:rgba(87, 137, 217, 0.2);"
                                 "background-repeat: no-repeat;"
                                 "background-position:left;"
                                 "border:none;"
                                 "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;text-align:right;}");
}
