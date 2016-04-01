# Add more folders to ship with the application, here
folder_01.source = qml/Test_VideoOutput
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01
QT += multimedia multimedia-private
# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    source_mediaobject.cpp \
    source_videosurface.cpp \
    source_qvideoframe.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    source_mediaobject.h \
    source_videosurface.h \
    source_qvideoframe.h
