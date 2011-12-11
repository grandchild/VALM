#-------------------------------------------------
#
# Project created by QtCreator 2011-12-11T03:17:03
#
#-------------------------------------------------

QT       += opengl svg

TARGET = AVS3_gui_qt_default
TEMPLATE = lib

DEFINES += AVS3_GUI_QT_DEFAULT_LIBRARY

SOURCES += avs3_gui_qt_default.cpp

HEADERS += avs3_gui_qt_default.h\
        AVS3_gui_qt_default_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE68A6ED4
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = AVS3_gui_qt_default.dll
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
