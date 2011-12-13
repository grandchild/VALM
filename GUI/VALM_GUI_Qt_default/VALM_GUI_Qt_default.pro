#-------------------------------------------------
#
# Project created by QtCreator 2011-12-11T06:55:04
#
#-------------------------------------------------

QT       += network svg

TARGET = VALM_GUI_Qt_default
TEMPLATE = lib

DEFINES += VALM_GUI_QT_DEFAULT_LIBRARY

SOURCES += valm_gui_qt_default.cpp

HEADERS += valm_gui_qt_default.h\
        VALM_GUI_Qt_default_global.h \
    ../VALM_gui.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEBA83251
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = VALM_GUI_Qt_default.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

