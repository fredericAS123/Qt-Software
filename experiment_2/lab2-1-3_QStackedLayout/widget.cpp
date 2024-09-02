#include "widget.h"
#include "ui_widget.h"
#include <QListWidget>
#include<QLabel>
#include<QStackedLayout>
#include<QObject>
#include<QListWidget>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QListWidget *listWidget=new QListWidget();
    listWidget->addItem("One");
    listWidget->addItem("Two");
    listWidget->addItem("Three");
    //QListWidget 的默认排列方式是垂直排列，即列表中的项目一个接一个地垂直堆叠

    QWidget *widget1=new QWidget();
    QWidget *widget2=new QWidget();
    QWidget *widget3=new QWidget();

    QLabel *label1=new QLabel("4376",widget1);
    QLabel *label2=new QLabel("王腾越",widget2);
    QLabel *label3=new QLabel("男",widget3);

    QStackedLayout *sLayout=new QStackedLayout();//三页
    sLayout->addWidget(widget1);
    sLayout->addWidget(widget2);
    sLayout->addWidget(widget3);

    QHBoxLayout *hLayout=new QHBoxLayout();
    hLayout->addWidget(listWidget);//添加一个窗口部件
    hLayout->addLayout(sLayout);//添加一个布局

    setLayout(hLayout);
    // 连接 listWidget 的 currentRowChanged 信号到 sLayout 的 setCurrentIndex 槽
    QObject::connect(
        listWidget, // 发射信号的对象
        &QListWidget::currentRowChanged, // 需要连接的信号，当 QListWidget 中当前行改变时发射
        sLayout, // 接收信号的对象
        &QStackedLayout::setCurrentIndex // 需要连接的槽，当信号发射时调用此槽函数
    );





}

Widget::~Widget()
{
    delete ui;
}
