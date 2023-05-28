#include "counttime.h"
#include "ui_counttime.h"

countTime::countTime(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::countTime),
    mTime(0,0,0,0)
{
    ui->setupUi(this);
    this->setWindowTitle("计时器");
    connect(&mTimer,&QTimer::timeout,this,&countTime::updateTime);
}

countTime::~countTime()
{
    delete ui;
}

void countTime::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void countTime::updateTime(){
    mTime = mTime.addMSecs(1);
    ui->label->setText(mTime.toString("hh:mm:ss:zzz"));
}

void countTime::on_btn_start_clicked()
{
    mTimer.start(1);
}

void countTime::on_pushButton_5_clicked()
{
    mTimer.stop();
}

void countTime::on_btn_reset_clicked()
{
    mTime.setHMS(0,0,0,0);
    ui->label->setText("00:00:00:000");
}

void countTime::on_btn_count_clicked()
{
    QString text = ui->label->text();
    ui->textBrowser->append(text);
}

void countTime::on_pushButton_2_clicked()
{
    ui->textBrowser->clear();
}
