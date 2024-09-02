#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0)
    {
        ui->motionlabel->setText("wheel up roll");
    }
    else
    {
        ui->motionlabel->setText("wheel down roll");
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pos =event->globalPos();
    // 设置 postlabel 标签的文本
    ui->postlabel->setText(
        // 创建一个 QString 对象，格式化为 "(x, y)"，其中 x 和 y 是 pos 的坐标
        QString("(%1,%2)") // 初始化一个包含占位符的 QString 对象
            .arg(pos.rx()) // 将第一个占位符 %1 替换为 pos 的 x 坐标
            .arg(pos.ry()) // 将第二个占位符 %2 替换为 pos 的 y 坐标
    );

}
