#ifndef QJUMPINGSUMOIMAGEFEED_H
#define QJUMPINGSUMOIMAGEFEED_H

#include <QObject>
#include <QThread>
#include <control.h>
#include <image.h>
#include <malloc/malloc.h>
#include <unistd.h>
#include <functional>
#include <QCamera>
#include <QCameraImageCapture>

class ImageProcessing : public sumo::Image
{
public:

    ImageProcessing(std::function<void(const struct sumo::image *img, const uint8_t *buffer, size_t size)> callback){
        this->functor = callback;
    }
    std::function<void(const struct sumo::image *img, const uint8_t *buffer, size_t size)> functor;
    void handleImage(const struct sumo::image *img, const uint8_t *buffer, size_t size){
        functor(img, buffer, size);
    }
};

class QJumpingSumoImageFeed : public QThread
{
    Q_OBJECT
public:
    sumo::Control *c;
    explicit QJumpingSumoImageFeed(QObject *parent = 0);
    void run();
    void handleImage(const struct sumo::image *img, const uint8_t *buffer, size_t size) {
        emit ready_frame((uchar*)buffer, size);
    }
signals:
    void ready_frame(uchar * bfr, int sz);

public slots:
};

#endif // QJUMPINGSUMOIMAGEFEED_H
