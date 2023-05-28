#include "changenum.h"
#include "ui_changenum.h"
#include <QDebug>

changeNum::changeNum(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::changeNum)
{
    ui->setupUi(this);
    this->setWindowTitle("进制转换器");
    style = "2";
    connect(ui->comboBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
        [=](const QString &text){
        style = text;
        qDebug() << style; });
}

changeNum::~changeNum()
{
    delete ui;
}


void changeNum::on_btn_back_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void changeNum::on_btn_cal_clicked()
{
    inputNum = ui->lineEdit->text();
    /*if(style == "2"){
        bool ok;
        int value = inputNum.toInt(&ok,2);
        ui->line_2->setText(QString::number(value,2));
        ui->line_8->setText(QString::number(value,8));
        ui->line_10->setText(QString::number(value,10));
        ui->line_16->setText(QString::number(value,16));
    }
    else if(style == "8"){
        bool ok;
        int value = inputNum.toInt(&ok,8);
        ui->line_2->setText(QString::number(value,2));
        ui->line_8->setText(QString::number(value,8));
        ui->line_10->setText(QString::number(value,10));
        ui->line_16->setText(QString::number(value,16));
    }
    else if(style == "10"){
        bool ok;
        int value = inputNum.toInt(&ok,10);
        ui->line_2->setText(QString::number(value,2));
        ui->line_8->setText(QString::number(value,8));
        ui->line_10->setText(QString::number(value,10));
        ui->line_16->setText(QString::number(value,16));
    }
    else{
        bool ok;
        int value = inputNum.toInt(&ok,16);
        ui->line_2->setText(QString::number(value,2));
        ui->line_8->setText(QString::number(value,8));
        ui->line_10->setText(QString::number(value,10));
        ui->line_16->setText(QString::number(value,16));
    }*/
    bool ok,ok_1;
    int value = inputNum.toInt(&ok,style.toInt(&ok_1,10));
    qDebug() << ok << " " << ok_1;
    ui->line_2->setText(QString::number(value,2));
    ui->line_8->setText(QString::number(value,8));
    ui->line_10->setText(QString::number(value,10));
    ui->line_16->setText(QString::number(value,16));

}

void changeNum::on_btn_reset_clicked()
{
    inputNum.clear();
    ui->lineEdit->clear();
    style = "2";
    ui->comboBox->setCurrentIndex(0);
    ui->line_2->clear();
    ui->line_8->clear();
    ui->line_10->clear();
    ui->line_16->clear();
}
