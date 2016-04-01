#ifndef SOURCE_MEDIAOBJECT_H
#define SOURCE_MEDIAOBJECT_H

#include <QObject>
#include <QMediaObject>

class Source_MediaObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QMediaObject* mediaObject READ mediaObject WRITE setMediaObject NOTIFY mediaObjectChanged)
public:
    explicit Source_MediaObject(QObject *parent = 0);

    QMediaObject* mediaObject();
    void setMediaObject(QMediaObject*);
signals:
    void mediaObjectChanged();

public slots:

private:
    QMediaObject* m_MediaObject;

};

#endif // SOURCE_MEDIAOBJECT_H
