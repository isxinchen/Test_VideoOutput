#ifndef SOURCE_VIDEOSURFACE_H
#define SOURCE_VIDEOSURFACE_H

#include <QObject>
#include <QAbstractVideoSurface>

class Source_VideoSurface : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ videoSurface WRITE setVideoSurface NOTIFY videoSurfaceChanged)
public:
    explicit Source_VideoSurface(QObject *parent = 0);

    QAbstractVideoSurface* videoSurface();
    void setVideoSurface(QAbstractVideoSurface*);
signals:
    void videoSurfaceChanged();

public slots:

private:
    QAbstractVideoSurface* m_VideoSurface;

};

#endif // SOURCE_VIDEOSURFACE_H
