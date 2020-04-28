#include <QLabel>
#include <QMenu>
#include <QPushButton>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>
#include <QDialog>
#include <QComboBox>
#include <QCheckBox>
#include <QTextEdit>

#include "title_bar.h"


TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent)
{
    setFixedHeight(50);

    m_pIconLabel = new QLabel(this);
    m_pTitleLabel = new QLabel(this);
    m_pMenubutton = new QToolButton(this);
    m_pMinimizeButton = new QPushButton(this);
    m_pMaximizeButton = new QPushButton(this);
    m_pCloseButton = new QPushButton(this);

    m_pIconLabel->setFixedSize(35,35);
    m_pIconLabel->setStyleSheet("QLabel{background-image: url(:/new/prefix1/pic/logo.png);"
                                "background-color:rgb(255,255,255);"
                                "background-repeat: no-repeat;}");

    m_pTitleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    m_pMenubutton->setFixedSize(30, 30);
    m_pMinimizeButton->setFixedSize(30, 30);
    m_pMaximizeButton->setFixedSize(30, 30);
    m_pCloseButton->setFixedSize(30, 30);

//    m_pTitleLabel->setObjectName("whiteLabel");
    m_pMenubutton->setObjectName("menuButton");
    m_pMinimizeButton->setObjectName("minimizeButton");
    m_pMaximizeButton->setObjectName("maximizeButton");
    m_pCloseButton->setObjectName("closeButton");

    m_pMenubutton->setToolTip("Menu");
    m_pMinimizeButton->setToolTip("Minimize");
    m_pMaximizeButton->setToolTip("Maximize");
    m_pCloseButton->setToolTip("Close");

    m_pTitleLabel->setContentsMargins(8,0,0,0);
    m_pTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    m_pMenubutton->setStyleSheet("QToolButton{border-image: url(:/new/prefix1/pic/icon-设置-默认.png);"
                                 "border:none;background-color:rgb(255, 255, 255);"
                                 "border-radius: 4px;}"
                                "QToolButton:hover{border-image: url(:/new/prefix1/pic/icon-设置-悬停点击.png);"
                                 "border:none;background-color:rgb(61, 107, 229);"
                                 "border-radius: 4px;}"
                                "QToolButton:checked{border-image: url(:/new/prefix1/pic/icon-设置-悬停点击.png);"
                                 "border:none;background-color:rgb(50, 87, 202);"
                                 "border-radius: 4px;}"
                                 "QToolButton::menu-indicator{image:none;}");

    m_pMinimizeButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/pic/icon-最小化-默认.png);"
                                     "border:none;background-color:rgb(255, 255, 255);"
                                     "border-radius: 4px;}"
                                "QPushButton:hover{border-image: url(:/new/prefix1/pic/icon-最小化-悬停点击.png);"
                                     "border:none;background-color:rgb(61, 107, 229);"
                                     "border-radius: 4px;}"
                                "QPushButton:checked{border-image: url(:/new/prefix1/pic/icon-最小化-悬停点击.png);"
                                     "border:none;background-color:rgb(50, 87, 202);"
                                     "border-radius: 4px;}");

    m_pMaximizeButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/pic/icon-最大化-默认.png);"
                                     "border:none;background-color:rgb(255, 255, 255);"
                                     "border-radius: 4px;}"
                                "QPushButton:hover{border-image: url(:/new/prefix1/pic/icon-最大化-悬停点击.png);"
                                     "border:none;background-color:rgb(61, 107, 229);"
                                     "border-radius: 4px;}"
                                "QPushButton:checked{border-image: url(:/new/prefix1/pic/icon-最大化-悬停点击.png);"
                                     "border:none;background-color:rgb(50, 87, 202);"
                                     "border-radius: 4px;}");

    m_pCloseButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/pic/icon-关闭-默认.png);"
                                  "border:none;background-color:rgb(255, 255, 255);"
                                  "border-radius: 4px;}"
                                "QPushButton:hover{border-image: url(:/new/prefix1/pic/icon-关闭-悬停点击.png);"
                                  "border:none;background-color:rgb(248, 100, 87);"
                                  "border-radius: 4px;}"
                                "QPushButton:checked{border-image: url(:/new/prefix1/pic/icon-关闭-悬停点击.png);"
                                  "border:none;background-color:rgb(228, 236, 80);"
                                  "border-radius: 4px;}");

    QMenu *menu = new QMenu(this);  //新建菜单

    menu->addAction(QIcon(""),"popup",this,&TitleBar::popup);
    menu->addAction(QIcon(""),"clean",this,&TitleBar::clean);
    menu->addSeparator();
    menu->addAction(QIcon(""),"MD5",this,&TitleBar::md5);
    menu->addAction(QIcon(""),"filter",this, &TitleBar::filter);
    menu->addSeparator();
    menu->addAction(QIcon(""),"help",this,&TitleBar::help);
    menu->addAction(QIcon(""),"about",this,&TitleBar::about);

    menu->setStyleSheet("QMenu:hover{background-color:rgb(248, 100, 87);}");

    m_pMenubutton->setPopupMode(QToolButton::InstantPopup); //点击模式
    m_pMenubutton->setMenu(menu);  //下拉菜单


    QHBoxLayout *mainWidgetLayout = new QHBoxLayout(this);
    QWidget *mainWidget = new QWidget;
    QHBoxLayout *pLayout = new QHBoxLayout;

    mainWidgetLayout->addWidget(mainWidget);
    mainWidget->setLayout(pLayout);
    mainWidgetLayout->setMargin(0);
    pLayout->setContentsMargins(7,0,0,0);
    pLayout->setSpacing(0);
    mainWidget->setStyleSheet("QWidget{background-color:rgb(255,255,255);}");
    pLayout->addStretch();
    pLayout->addWidget(m_pMenubutton);
    pLayout->addWidget(m_pMinimizeButton);
    pLayout->addWidget(m_pMaximizeButton);
    pLayout->addWidget(m_pCloseButton);

    connect(m_pMenubutton, &QPushButton::clicked, this, &TitleBar::onClicked);
    connect(m_pMinimizeButton, &QPushButton::clicked, this, &TitleBar::onClicked);
    connect(m_pMaximizeButton, &QPushButton::clicked, this, &TitleBar::onClicked);
    connect(m_pCloseButton, &QPushButton::clicked, this, &TitleBar::onClicked);
}

TitleBar::~TitleBar()
{

}


void TitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    Q_EMIT m_pMaximizeButton->clicked();
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        QWidget *pWindow = this->window();
        pWindow->move(pWindow->pos() + (event->globalPos() - mLastMousePosition));
        mLastMousePosition = event->globalPos();
    }
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = true;
        mLastMousePosition = event->globalPos();
    }
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}

void TitleBar::onClicked()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        if (pButton == m_pMinimizeButton)
        {
            pWindow->showMinimized();
            updateMaximize();
        }
        else if (pButton == m_pMaximizeButton)
        {
            pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();
            updateMaximize();
        }
        else if (pButton == m_pCloseButton)
        {
            pWindow->close();
        }
    }
}

void TitleBar::updateMaximize()
{
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        bool bMaximize = pWindow->isMaximized();
        if (bMaximize)
        {
            m_pMaximizeButton->setToolTip(tr("Restore"));
            m_pMaximizeButton->setProperty("maximizeProperty", "restore");
        }
        else
        {
            m_pMaximizeButton->setProperty("maximizeProperty", "maximize");
            m_pMaximizeButton->setToolTip(tr("Maximize"));
        }

        m_pMaximizeButton->setStyle(QApplication::style());
    }
}

void TitleBar::popup()
{

}
void TitleBar::clean()
{
    clean_dialog =new BurnClean();
    clean_dialog->setModal(true);
//    clean_dialog->show();
}
void TitleBar::md5()
{
    check_dialog = new BurnMd5();
    check_dialog->setModal(true);
//    check_dialog->show();
}
void TitleBar::filter()
{
    filter_dialog = new BurnFilter();
    filter_dialog->setModal(true);
//    filter_dialog->show();

}
void TitleBar::help()
{

}
void TitleBar::about()
{

}

