#-------------------------------------------------
#
# Project created by QtCreator 2020-03-03T13:58:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH +=/usr/include/glib-2.0/
INCLUDEPATH +=/usr/include/gtk-3.0/
INCLUDEPATH +=/usr/include/pango-1.0/
INCLUDEPATH +=/usr/include/cairo/
INCLUDEPATH +=/usr/include/gdk-pixbuf-2.0/
INCLUDEPATH +=/usr/include/atk-1.0/
INCLUDEPATH +=/usr/include/gstreamer-1.0/
INCLUDEPATH +=/usr/lib/x86_64-linux-gnu/glib-2.0/include
#INCLUDEPATH +=/usr/include/kylin_include/

LIBS +=-lgobject-2.0
LIBS +=-lglib-2.0
LIBS +=-pthread
LIBS +=-lgthread-2.0

#LIBS += -L/usr/lib/kylin_so/
LIBS += -L $$PWD/kylin_so/libburner-burn3.so.1.2.0
LIBS += -L $$PWD/kylin_so/libburner-media3.so.1.2.0
LIBS += -L $$PWD/kylin_so/libburner-utils3.so.1.2.0

TARGET = burner-test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

PKGCONFIG +=gtk+-3.0

CONFIG += c++11 link_pkgconfig no_keywords

SOURCES += \
    burnclean.cpp \
    burnerset.cpp \
    burnfilter.cpp \
    burnmd5.cpp \
        main.cpp \
        widget.cpp \
    title_bar.cpp \
    p_data.cpp \
    p_image.cpp \
    p_copy.cpp \
    property.cpp \
    kylin_api.c

HEADERS += \
    burnclean.h \
    burnerset.h \
    burnfilter.h \
    burnmd5.h \
        widget.h \
    title_bar.h \
    p_data.h \
    p_image.h \
    p_copy.h \
    property.h \
    so/config.h \
    kylin_api.h \
    kylin_include/burner-blank-dialog.h \
    kylin_include/burner-burn-dialog.h \
    kylin_include/burner-burn-lib.h \
    kylin_include/burner-burn-options.h \
    kylin_include/burner-burn.h \
    kylin_include/burner-drive-selection.h \
    kylin_include/burner-drive.h \
    kylin_include/burner-enums.h \
    kylin_include/burner-error.h \
    kylin_include/burner-media.h \
    kylin_include/burner-medium-monitor.h \
    kylin_include/burner-medium-selection.h \
    kylin_include/burner-medium.h \
    kylin_include/burner-session-cfg.h \
    kylin_include/burner-session-span.h \
    kylin_include/burner-session.h \
    kylin_include/burner-status.h \
    kylin_include/burner-sum-dialog.h \
    kylin_include/burner-tags.h \
    kylin_include/burner-tool-dialog.h \
    kylin_include/burner-track-data-cfg.h \
    kylin_include/burner-track-data.h \
    kylin_include/burner-track-disc.h \
    kylin_include/burner-track-image-cfg.h \
    kylin_include/burner-track-image.h \
    kylin_include/burner-track-stream-cfg.h \
    kylin_include/burner-track-stream.h \
    kylin_include/burner-track-type.h \
    kylin_include/burner-track.h \
    kylin_include/burner-units.h \
    kylin_include/burner-volume.h \
    kylin_include/config.h

FORMS += \
    burnclean.ui \
    burnerset.ui \
    burnfilter.ui \
    burnmd5.ui \
        widget.ui \
    p_data.ui \
    p_image.ui \
    p_copy.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/kylin_so/release/ -lburner-media3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/kylin_so/debug/ -lburner-media3
else:unix: LIBS += -L$$PWD/kylin_so/ -lburner-media3

INCLUDEPATH += $$PWD/kylin_so
DEPENDPATH += $$PWD/kylin_so

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/kylin_so/release/ -lburner-utils3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/kylin_so/debug/ -lburner-utils3
else:unix: LIBS += -L$$PWD/kylin_so/ -lburner-utils3

INCLUDEPATH += $$PWD/kylin_so
DEPENDPATH += $$PWD/kylin_so

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/kylin_so/release/ -lburner-burn3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/kylin_so/debug/ -lburner-burn3
else:unix: LIBS += -L$$PWD/kylin_so/ -lburner-burn3

INCLUDEPATH += $$PWD/kylin_so
DEPENDPATH += $$PWD/kylin_so

RC_FILE = ico.rc

DISTFILES += \
    ico.rc
