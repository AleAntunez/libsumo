#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qjumpingsumoimagefeed.h>
#include <QImage>
#include <QKeyEvent>

#include <QGraphicsPathItem>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QJumpingSumoImageFeed *feed;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void ready_frame(uchar* bfr, int sz);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
