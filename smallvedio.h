#ifndef SMALLVEDIO_H
#define SMALLVEDIO_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>

namespace Ui {
class SmallVedio;
}

class SmallVedio : public QMainWindow
{
    Q_OBJECT

public:
    explicit SmallVedio(QWidget *parent = nullptr);
    ~SmallVedio();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SmallVedio *ui;
    QMediaPlayer *player;
    QMediaPlaylist *list;
    QVideoWidget *vedio;
    QString fileName;
};

#endif // SMALLVEDIO_H
