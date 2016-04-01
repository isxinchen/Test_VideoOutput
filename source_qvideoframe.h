#ifndef SOURCE_QVIDEOFRAME_H
#define SOURCE_QVIDEOFRAME_H

#include <QObject>
#include <QAbstractVideoSurface>
#include <QVideoSurfaceFormat>
#include <QVideoFrame>

class Source_QVideoFrame : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ videoSurface WRITE setVideoSurface NOTIFY videoSurfaceChanged)
public:
    explicit Source_QVideoFrame(QObject *parent = 0);

    QAbstractVideoSurface* videoSurface();
    void setVideoSurface(QAbstractVideoSurface*);
    void present(QVideoFrame&);
signals:
    void videoSurfaceChanged();

public slots:

private:
    QAbstractVideoSurface* m_VideoSurface;
    QVideoFrame m_VideoFrame;
    QVideoSurfaceFormat m_format;

};

#endif // SOURCE_QVIDEOFRAME_H
