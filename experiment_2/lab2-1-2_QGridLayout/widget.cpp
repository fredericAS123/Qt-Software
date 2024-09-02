#include "widget.h"
#include "ui_widget.h"

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
//ui->setup(this);
//QGridLayout *gLayout= new QGridLayout;
//void QGridLayout::addWiget(QWidget *widget, int row, int column) or void QGridLayout::addWiget(QWidget *widget, int rowfrom, int rowend, int columnfrom, int columnend);
//ui->widget->setLayout(gLayout)
