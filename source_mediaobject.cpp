#include "source_mediaobject.h"
#include <QDebug>

Source_MediaObject::Source_MediaObject(QObject *parent) :
    QObject(parent)
{
}

QMediaObject* Source_MediaObject::mediaObject()
{
    qDebug() << Q_FUNC_INFO;
    return m_MediaObject;
}

void Source_MediaObject::setMediaObject(QMediaObject* mediaObject)
{
    qDebug() << Q_FUNC_INFO;
    m_MediaObject = mediaObject;
    emit mediaObjectChanged();
}
