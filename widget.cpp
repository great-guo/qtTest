#include "widget.h"
#include "ui_widget.h"
#include "calculate.h"
#include "counttime.h"
#include "smallvedio.h"
#include "changenum.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("工具箱");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btn_cal_clicked()
{
    Calculate *cal = new Calculate(this);
    cal->show();
    this->hide();
}

void Widget::on_btn_countTime_clicked()
{
    countTime *cou = new countTime(this);
    cou->show();
    this->hide();
}

void Widget::on_btn_vedio_clicked()
{
    SmallVedio *small = new SmallVedio(this);
    small->show();
    this->hide();
}


void Widget::on_btn_chageNum_clicked()
{
    changeNum *change = new changeNum(this);
    change->show();
    this->hide();
}
