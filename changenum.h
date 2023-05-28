#ifndef CHANGENUM_H
#define CHANGENUM_H

#include <QMainWindow>

namespace Ui {
class changeNum;
}

class changeNum : public QMainWindow
{
    Q_OBJECT

public:
    explicit changeNum(QWidget *parent = nullptr);
    ~changeNum();

    void getNum();
private slots:
    void on_btn_back_clicked();


    void on_btn_cal_clicked();

    void on_btn_reset_clicked();

private:
    Ui::changeNum *ui;
    QString inputNum;
    QString style;
};

#endif // CHANGENUM_H
