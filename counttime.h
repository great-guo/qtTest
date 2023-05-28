#ifndef COUNTTIME_H
#define COUNTTIME_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>

namespace Ui {
class countTime;
}

class countTime : public QMainWindow
{
    Q_OBJECT

public:
    explicit countTime(QWidget *parent = nullptr);
    ~countTime();

private slots:
    void on_pushButton_clicked();

    void on_btn_start_clicked();

    void updateTime();
    void on_pushButton_5_clicked();

    void on_btn_reset_clicked();

    void on_btn_count_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::countTime *ui;
    QTimer mTimer;
    QTime mTime;
};

#endif // COUNTTIME_H
