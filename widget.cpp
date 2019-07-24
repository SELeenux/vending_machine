#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ChangeMoney(int num){
    money += num;
    if (money < 0) money = 0;
    if (money < 100)
        ui->pbCoffe->setEnabled(false);
    if (money < 150)
        ui->pbTea->setEnabled(false);
    if (money < 200)
        ui->pbCoke->setEnabled(false);
    ui->lcdNumber->display(money);
}

void Widget::on_pb10_clicked()
{
    ChangeMoney(10);
}

void Widget::on_pb50_clicked()
{
    ChangeMoney(50);
}

void Widget::on_pb100_clicked()
{
    ChangeMoney(100);
}

void Widget::on_pb500_clicked()
{
    ChangeMoney(500);
}

void Widget::on_pbCoffe_clicked()
{
    ChangeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
     ChangeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    ChangeMoney(-200);
}

void Widget::on_pbReturn_clicked()
{
    int co10=0, co50=0, co100=0, co500=0;
    QString str;

    co500 = money/500;
    money %= 500;
    co100 = money/100;
    money %= 100;
    co50 = money/50;
    money %= 50;
    co10 = money/10;
    money %= 10;

    str.sprintf("10 : %d\n 50 : %d\n100 : %d\n500 : %d\n", co10, co50, co100, co500);
    QMessageBox msg;
    msg.information(nullptr, "return", str);
    ui->lcdNumber->display(money);
}
