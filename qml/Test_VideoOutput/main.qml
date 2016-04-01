import QtQuick 2.0
import QtMultimedia 5.0

Rectangle {
    width: 360
    height: 540

    VideoOutput{
        anchors.top: parent.top
        width: 360
        height: 180
        source: source_MediaObject
    }

    VideoOutput{
        anchors.centerIn: parent
        width: 360
        height: 180
        source: source_VideoSurface
    }

    VideoOutput{
        anchors.bottom: parent.bottom
        width: 360
        height: 180
        source: source_QVideoFrame
    }
}
