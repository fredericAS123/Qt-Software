#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QHBoxLayout *hLayout = new QHBoxLayout();//水平布局QHBoxLayout(| | |),垂直布局QVBoxLayout(三)
    hLayout->addWidget(ui->button7,0,Qt::AlignTop);
    hLayout->addWidget(ui->button8,0);
    hLayout->addWidget(ui->button9,0,Qt::AlignBottom);
    ui->widget_3->setLayout(hLayout);
}
Widget::~Widget()
{
    delete ui;
}
