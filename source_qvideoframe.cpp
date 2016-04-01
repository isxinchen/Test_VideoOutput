#include "source_qvideoframe.h"
#include <QDebug>

Source_QVideoFrame::Source_QVideoFrame(QObject *parent) :
    QObject(parent)
{
}

QAbstractVideoSurface* Source_QVideoFrame::videoSurface()
{
    qDebug() << Q_FUNC_INFO << "------------------------";
    return m_VideoSurface;
}

void Source_QVideoFrame::setVideoSurface(QAbstractVideoSurface* videoSurface)
{
    qDebug() << Q_FUNC_INFO << "------------------------";
    m_VideoSurface = videoSurface;
    emit videoSurfaceChanged();
}

void Source_QVideoFrame::present(QVideoFrame &frame)
{
    qDebug() << Q_FUNC_INFO;
    m_VideoFrame = frame;

    QSize qsize(1280, 720);

    QVideoSurfaceFormat now(qsize, QVideoFrame::Format_YUV420P);
    if(!m_VideoSurface->isActive() )
    {
        m_format = now;
        m_VideoSurface->start(m_format);
    }

    if(m_VideoSurface){
        qDebug() << Q_FUNC_INFO << "------------------------";
        m_VideoSurface->present(frame);
    }
}
