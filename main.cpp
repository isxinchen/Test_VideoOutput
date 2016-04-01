#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include <QQmlContext>
#include <QMediaPlayer>
#include <private/qmemoryvideobuffer_p.h>
#include <QDebug>

#include "source_mediaobject.h"
#include "source_videosurface.h"
#include "source_qvideoframe.h"


/**
 * Generate Picture contains Gray Bar changing from Black to White in YUV420P Format
 *
 * @param width     the width of picture.
 * @param height    the height of picture.
 * @param barnum    the number of Bars in the picture.
 * @param ymin      the minimum value of luminance.
 * @param ymax      the maximum value of luminance.
 * @return 0 if finished, -1 if there are errors.
 */
int gen_yuv420p_graybar(int width, int height,int barnum,unsigned char ymin,unsigned char ymax, QByteArray& yuvData){

    int barwidth;
    float lum_inc;
    unsigned char lum_temp;
    int uv_width,uv_height;
    unsigned char *data_yuv=NULL;
    int t=0,i=0,j=0;
    int offset_u = 0, offset_v = 0;

    //Check
    if(width<=0||height<=0||barnum<=0){
        printf("Error: Width, Height or Bar Number cannot be 0 or negative number!\n");
        printf("Default Param is used.\n");
        width=640;
        height=480;
        barnum=10;
    }
    if(width%barnum!=0){
        printf("Warning: Width cannot be divided by Bar Number without remainder!\n");
    }
    barwidth=width/barnum;
    lum_inc=((float)(ymax-ymin))/((float)(barnum-1));
    uv_width=width/2;
    uv_height=height/2;

    offset_u = width*height;
    offset_v = width*height + uv_width*uv_height;

    data_yuv = (unsigned char *)malloc(width*height + uv_width*uv_height*2);


    //Output Info
    qDebug() << ("Y, U, V value from picture's left to right:\n");
    for(t=0;t<(width/barwidth);t++){
        lum_temp=ymin+(char)(t*lum_inc);
        qDebug() << lum_temp << ", 128, 128";
    }
    //Gen Data
    for(j=0;j<height;j++){
        for(i=0;i<width;i++){
            t=i/barwidth;
            lum_temp=ymin+(char)(t*lum_inc);
            data_yuv[j*width+i]=lum_temp;
        }
    }
    for(j=0;j<uv_height;j++){
        for(i=0;i<uv_width;i++){
            data_yuv[offset_u + j*uv_width+i]=128;
        }
    }
    for(j=0;j<uv_height;j++){
        for(i=0;i<uv_width;i++){
            data_yuv[offset_v + j*uv_width+i]=128;
        }
    }

    yuvData.resize(width * height + uv_width*uv_height*2);
    yuvData.replace(0, width * height + uv_width*uv_height*2, (const char *)data_yuv, width * height + uv_width*uv_height*2);

    free(data_yuv);
    qDebug() << ("Finish generate!\n");
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;

    Source_MediaObject source_MediaObject;
    Source_VideoSurface source_VideoSurface;
    Source_QVideoFrame source_QVideoFrame;
    QMediaPlayer player1, player2;

    viewer.rootContext()->setContextProperty("source_MediaObject", &source_MediaObject);
    viewer.rootContext()->setContextProperty("source_VideoSurface", &source_VideoSurface);
    viewer.rootContext()->setContextProperty("source_QVideoFrame", &source_QVideoFrame);

    source_MediaObject.setMediaObject(&player1);//界面显示之前

    viewer.setMainQmlFile(QStringLiteral("qml/Test_VideoOutput/main.qml"));
    viewer.showExpanded();

    player2.setVideoOutput(source_VideoSurface.videoSurface());//界面显示之后
    player1.setMedia(QUrl("file:///home/chenxin/Videos/001.mp4"));
    player2.setMedia(QUrl("file:///home/chenxin/Videos/001.mp4"));
    player1.play();
    player2.play();

    QByteArray videoData;
    gen_yuv420p_graybar(1280, 720, 10, 16, 235, videoData);
    QMemoryVideoBuffer* buf = new QMemoryVideoBuffer(videoData, 1280);
    QVideoFrame frame((QAbstractVideoBuffer*)buf, QSize(1280, 720), QVideoFrame::Format_YUV420P);

    source_QVideoFrame.present(frame);

    return app.exec();
}

