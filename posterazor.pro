TARGET = PosteRazor

QT += widgets

CONFIG += c++11 release

win32:DEFINES -= \
    UNICODE

macx:QMAKE_INFO_PLIST = \
    Info.plist

macx:ICON = \
    src/posterazor.icns

macx:CONFIG += \
    x86 ppc

macx:QMAKE_MAC_SDK = \
    /Developer/SDKs/MacOSX10.4u.sdk

macx:QMAKE_MACOSX_DEPLOYMENT_TARGET = \
    10.3

RC_FILE += \
    src/posterazor.rc

# Uncomment the following line in order to build PosteRazor with FreeImage
#DEFINES += FREEIMAGE_LIB

# Poppler-Qt5 is the library we require to be able to process PDF files as input
# Comment the following line in order to build PosteRazor without Poppler-Qt5
exists( /usr/include/poppler/qt5/poppler-qt5.h ) {
    DEFINES += POPPLER_QT5_LIB
}

DEFINES += QT_NO_CAST_FROM_ASCII

SOURCES += \
    src/main.cpp

contains (DEFINES, POPPLER_QT5_LIB) {
    unix:INCLUDEPATH += \
        /usr/include/poppler/qt5

    unix:LIBS += \
        -lpoppler-qt5
}

contains (DEFINES, FREEIMAGE_LIB) {
    SOURCES += \
        src/imageloaderfreeimage.cpp

    HEADERS += \
        src/imageloaderfreeimage.h

    win32:INCLUDEPATH += \
        src/thirdparty/FreeImage/Dist

    win32:LIBS += \
        src/thirdparty/FreeImage/Dist/FreeImage.lib

    macx: INCLUDEPATH += \
        /usr/local/include

    unix:LIBS += \
        -lfreeimage
}

include (src/posterazor.pri)

unix {
    isEmpty(PREFIX) {
        PREFIX = /usr
    }

    target.path = $$PREFIX/bin

    shortcutfiles.files = resources/posterazor.desktop
    shortcutfiles.path = $$PREFIX/share/applications/
    data.files += resources/posterazor.png
    data.path = $$PREFIX/share/pixmaps/

    INSTALLS += shortcutfiles
    INSTALLS += data
}

INSTALLS += target

DISTFILES += \
    resources/posterazor.desktop \
    resources/posterazor.png