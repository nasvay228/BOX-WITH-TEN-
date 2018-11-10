#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer.setInterval(500);
    timer.start();
    connect(&timer, SIGNAL(timeout()),this,SLOT(back()));
    connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(move()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::move()
{
    int current = ui->progressBar->value();
    ui->progressBar->setValue(current+1);

}

void Widget::back()
{
    int current = ui->progressBar->value();
    ui->progressBar->setValue(current-1);
    if(current == 0){
        this->close();
    }
}
