#ifndef CALCULATE_H
#define CALCULATE_H

#include <QMainWindow>

namespace Ui {
class Calculate;
}

class Calculate : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculate(QWidget *parent = nullptr);
    ~Calculate();

    void getNum(QString ch);
    void getStyle(QString ch);
    void getRes();
private slots:
    void on_btn_back_clicked();

    void getText();
private:
    Ui::Calculate *ui;
    QString firstNum,secondNum;
    int style;
};

#endif // CALCULATE_H
