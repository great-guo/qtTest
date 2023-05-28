#include "calculate.h"
#include "ui_calculate.h"
#include <QDebug>


Calculate::Calculate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculate)
{
    ui->setupUi(this);
    this->setWindowTitle("计算器");
    style = 0;
    connect(ui->btn_0,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_1,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_2,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_3,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_4,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_5,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_6,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_7,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_8,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_9,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_jia,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_jian,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_cheng,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_chu,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_res,&QPushButton::clicked,this,&Calculate::getText);
    connect(ui->btn_clean,&QPushButton::clicked,this,&Calculate::getText);
}

Calculate::~Calculate()
{
    delete ui;
}

void Calculate::getText(){
    QPushButton *btn = dynamic_cast<QPushButton *>(sender());
    QString ch = btn->text();
    qDebug() << ch;
    if(QString("1234567890").indexOf(ch) >= 0){
        getNum(ch);
    }
    else if(QString("+-/*").indexOf(ch) >= 0){
        getStyle(ch);
        qDebug() << style;
    }
    else if(ch == "AC"){
        firstNum.clear();
        secondNum.clear();
        style = 0;
        ui->lineEdit->setText("0");
    }
    else if(ch == "="){
        getRes();
    }
}

void Calculate::getNum(QString ch){
    if(style == 0){
        firstNum.append(ch);
        ui->lineEdit->setText(firstNum);
    }
    else{
        secondNum.append(ch);
        ui->lineEdit->setText(secondNum);
    }
}

void Calculate::getStyle(QString ch){
    switch (ch.at(0).toLatin1()) {
        case '+' :
            style = 1;
            break;
        case '-' :
            style = 2;
            break;
        case '*' :
            style = 3;
            break;
        case '/' :
            style = 4;
            break;
        default:
            break;
    }
}

void Calculate::getRes(){
    QString res;
    switch(style){
    case 1:
        res = firstNum+" + "+secondNum+" = "+QString::number(firstNum.toInt()+secondNum.toInt());
        break;
    case 2:
        res = firstNum+" - "+secondNum+" = "+QString::number(firstNum.toInt()-secondNum.toInt());
        break;
    case 3:
        res = firstNum+" * "+secondNum+" = "+QString::number(firstNum.toInt()*secondNum.toInt());
        break;
    case 4:
        res = firstNum+" / "+secondNum+" = "+QString::number(firstNum.toInt()/secondNum.toInt());
        break;
    }
    ui->lineEdit->setText(res);
    firstNum.clear();
    secondNum.clear();
    style = 0;
}

void Calculate::on_btn_back_clicked()
{
    this->parentWidget()->show();
    this->close();
}
