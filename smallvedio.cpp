#include "smallvedio.h"
#include "ui_smallvedio.h"
#include <QFileDialog>

SmallVedio::SmallVedio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SmallVedio)
{
    ui->setupUi(this);
    this->setWindowTitle("小视频");
    player = new QMediaPlayer(this);
    list = new QMediaPlaylist(this);
    player->setPlaylist(list);
    vedio = new QVideoWidget(ui->label);
    vedio->resize(ui->label->size());
}

SmallVedio::~SmallVedio()
{
    delete ui;
}

void SmallVedio::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->close();
    player->stop();
    vedio->close();
}

void SmallVedio::on_pushButton_2_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
          tr("Open Vedio"), "/home/vedio", tr("Video Files (*.mp4 *.wav)"));
    player->setVideoOutput(vedio);
    vedio->show();
    player->setMedia(QUrl::fromLocalFile(fileName));
    player->play();
}
