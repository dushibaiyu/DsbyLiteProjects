#-------------------------------------------------
#
# Project created by QtCreator 2015-08-24T14:25:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LogoCheck
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    objectmat.cpp
#    ewrr.cpp

HEADERS  += mainwindow.h \
    objectmat.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$(OPENCV)/include/
DEPENDPATH += $$(OPENCV)/x86/vc10/bin/

LIBS += -L$$(OPENCV)/x86/vc10/lib/

win32:CONFIG(release, debug|release): LIBS +=  -lopencv_core300 -lopencv_highgui300 -lopencv_xfeatures2d300 -lopencv_ximgproc300 -lopencv_calib3d300 -lopencv_flann300
else:win32:CONFIG(debug, debug|release): LIBS += -lopencv_core300d -lopencv_highgui300d -lopencv_xfeatures2d300d -lopencv_ximgproc300d -lopencv_calib3d300d -lopencv_flann300d

win32:CONFIG(release, debug|release): LIBS +=  -lopencv_features2d300 -lopencv_imgcodecs300 -lopencv_line_descriptor300 -lopencv_objdetect300 -lopencv_ccalib300
else:win32:CONFIG(debug, debug|release): LIBS += -lopencv_features2d300d -lopencv_imgcodecs300d -lopencv_line_descriptor300d -lopencv_objdetect300d -lopencv_ccalib300d


win32:CONFIG(release, debug|release): LIBS +=  -lopencv_imgproc300
else:win32:CONFIG(debug, debug|release): LIBS += -lopencv_imgproc300d
