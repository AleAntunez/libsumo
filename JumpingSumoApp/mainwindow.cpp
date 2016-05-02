#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <QPainter>
#include <opencv2/video/background_segm.hpp>
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    feed = new QJumpingSumoImageFeed();
    feed->start();
    connect(feed, SIGNAL(ready_frame(uchar*,int)), this, SLOT(ready_frame(uchar*,int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e){
    if (e->key() == Qt::Key_W){
        feed->c->move(50,0);
    }

    if (e->key() == Qt::Key_S){
        feed->c->move(-50,0);
    }

    if (e->key() == Qt::Key_A){
        feed->c->move(0,-25);
    }

    if (e->key() == Qt::Key_D){
        feed->c->move(0,25);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e){
    feed->c->move(0,0);
}

void MainWindow::ready_frame(uchar *bfr, int sz){

    ui->progressBar->setValue(feed->c->batteryLevel());
    QImage img = QImage::fromData((uchar*) bfr, sz);
    if (!img.isNull()){
        Mat mat(img.height(), img.width(), CV_8UC4,
                           const_cast<uchar*>(img.bits()),
                           img.bytesPerLine());

        Mat img_dst(mat);

        /* Image processing with OpenCV */

        /* Show the image */
        imshow("Jumping Sumo Vision", img_dst);
        setFocus();
    }
}

void MainWindow::on_pushButton_clicked()
{
    feed->c->highJump();
}

void MainWindow::on_pushButton_2_clicked()
{
    feed->c->longJump();
}
