#include "source_videosurface.h"
#include <QDebug>

Source_VideoSurface::Source_VideoSurface(QObject *parent) :
    QObject(parent)
{
}

QAbstractVideoSurface* Source_VideoSurface::videoSurface()
{
    qDebug() << Q_FUNC_INFO;
    return m_VideoSurface;
}

void Source_VideoSurface::setVideoSurface(QAbstractVideoSurface* videoSurface)
{
    qDebug() << Q_FUNC_INFO;
    m_VideoSurface = videoSurface;
    emit videoSurfaceChanged();
}
