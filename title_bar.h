#ifndef TITLE_BAR_H
#define TITLE_BAR_H
#include <QWidget>
#include <QToolButton>
//#include <QLabel>
//#include <QPushButton>
//#include <QComboBox>
//#include <QCheckBox>
//#include <QLineEdit>

#include "property.h"
#include "burnclean.h"
#include "burnmd5.h"
#include "burnfilter.h"

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = 0);
    ~TitleBar();

protected:

    // 双击标题栏进行界面的最大化/还原
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

    // 进行鼠界面的拖动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    // 进行最小化、最大化/还原、关闭操作
Q_SLOT    void onClicked();
Q_SLOT    void popup();
Q_SLOT    void clean();
Q_SLOT    void md5();
Q_SLOT    void filter();
Q_SLOT    void help();
Q_SLOT    void about();

private:
    QPoint mLastMousePosition;
    bool mMoving;
    // 最大化/还原
    void updateMaximize();

private:
    class property pro;
    BurnClean *clean_dialog;
    BurnMd5 *check_dialog;
    BurnFilter *filter_dialog;

    QLabel *m_pIconLabel;
    QLabel *m_pTitleLabel;
    QToolButton *m_pMenubutton;
    QPushButton *m_pMinimizeButton;
    QPushButton *m_pMaximizeButton;
    QPushButton *m_pCloseButton;
};
#endif // TITLE_BAR_H
