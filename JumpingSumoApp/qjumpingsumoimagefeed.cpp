#include "qjumpingsumoimagefeed.h"
#include <QBuffer>

QJumpingSumoImageFeed::QJumpingSumoImageFeed(QObject *parent) : QThread(parent)
{

}

void QJumpingSumoImageFeed::run(){
    ImageProcessing *img = new ImageProcessing([this](const struct sumo::image *img, const uint8_t *buffer, size_t size){
        handleImage(img, buffer, size);
    });
    c = new sumo::Control(img);
    if (!c->open()){
        return;
    }
    while(true){}
    c->close();
}
