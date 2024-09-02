#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include<cmath>
#include <QtCore/qmath.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit->setText("0");
    result=0.0;
    waitForOperand=true;
    setShortcutKeys();
    connectSlots();
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::calculate(double operand,QString pendingOperator)
{
    if(pendingOperator=="+")
    {
        result+=operand;
    }
    else if(pendingOperator=="-")
    {
        result-=operand;
    }
    else if(pendingOperator=="*")
    {
        result*=operand;
    }
    else if(pendingOperator=="/")
    {
        if(operand==0.0)
            return false;
        result/=operand;
    }
    else if(pendingOperator=="sin")
    {
        result=sin(operand*3.1415926/180);
    }
    else if(pendingOperator=="cos")
    {
        result=cos(operand*3.1415926/180);
    }
    else if(pendingOperator=="exp")
    {
        result=qExp(operand);
    }
    return true;
}
void Widget::abortOperation()
{
    result=0.0;
    pendingOperator.clear();
    ui->lineEdit->setText("0");
    waitForOperand=true;
    QMessageBox::warning(this,"运算错误","除数不能为零");
}
void Widget::connectSlots()//1,新建指针指向ui某按键；2,使用connect函数，将QPushButton::clicked和Widget中定义的某功能函数链接
{
    QPushButton *digitBtns[10]={
        ui->digitBtn0, ui->digitBtn1, ui->digitBtn2, ui->digitBtn3,
        ui->digitBtn4, ui->digitBtn5, ui->digitBtn6, ui->digitBtn7,
        ui->digitBtn8, ui->digitBtn9
    };
    for(auto btn:digitBtns)
        connect(btn,&QPushButton::clicked,this,&Widget::digitClicked);
    QPushButton *operatorBtns[7]={
        ui->addBtn, ui->subtractionBtn, ui->mulBtn, ui->divisionBtn,
        ui->sinBtn, ui->cosBtn, ui->expBtn
    };
    for(auto btn:operatorBtns)
        connect(btn,&QPushButton::clicked,this,&Widget::operatorClicked);
    QPushButton *equalBtn=ui->equalBtn;
    connect(equalBtn,&QPushButton::clicked,this,&Widget::on_equalBtn_clicked);
    QPushButton *clearBtn=ui->clearBtn;
    connect(clearBtn,&QPushButton::clicked,this,&Widget::on_clearBtn_cliced);
    QPushButton *clearAllBtn=ui->clearAllBtn;
    connect(clearAllBtn,&QPushButton::clicked,this,&Widget::on_clearAllBtn_clicked);
    QPushButton *signBtn=ui->signBtn;
    connect(signBtn,&QPushButton::clicked,this,&Widget::on_signBtn_clicked);
    QPushButton *pointBtn=ui->pointBtn;
    connect(pointBtn,&QPushButton::clicked,this,&Widget::on_point_clicked);
}
void Widget::digitClicked()
{
    QPushButton *digitBtn=static_cast<QPushButton*>(sender());
    QString value=digitBtn->text();
    if(ui->lineEdit->text()=="0"&&value=="0")
        return;
    if(waitForOperand)
    {
        ui->lineEdit->setText(value);
        waitForOperand=false;
    }
    else
    {
        ui->lineEdit->setText(ui->lineEdit->text()+value);
    }
}
void Widget::on_clearBtn_cliced()
{
    //当前显示归零
    ui->lineEdit->setText("0");
    waitForOperand=true;
}
void Widget::on_clearAllBtn_clicked()
{
    //当前显示数归零，且将之前的保存的数据清零
    ui->lineEdit->setText("0");
    waitForOperand=true;
    result=0.0;
    pendingOperator.clear();
}
void Widget::on_equalBtn_clicked()
{
    double operand=ui->lineEdit->text().toDouble();
    if(pendingOperator.isEmpty())
        return;
    if(!calculate(operand,pendingOperator))
    {
        abortOperation();
        return;
    }

    ui->lineEdit->setText(QString::number(result));//result在calculate更新值
    pendingOperator.clear();
    result=0.0;
    waitForOperand=true;
}
void Widget::on_signBtn_clicked()// +/-符号的实现
{
    QString text=ui->lineEdit->text();
    double value=text.toDouble();
    if(value>0)
    {
        text.prepend('-');
    }
    else if(value<0)
    {
        text.remove(0,1);
    }
    ui->lineEdit->setText(text);
}
void Widget::operatorClicked()
{
    QPushButton *clickedBtn=qobject_cast<QPushButton *>(sender());
    QString clickedOperator=clickedBtn->text();
    double operand =ui->lineEdit->text().toDouble();
    if(!pendingOperator.isEmpty())
    {
        if(!calculate(operand,pendingOperator))
        {
            abortOperation();
            return;
        }
    ui->lineEdit->setText(QString::number(result));
}
    else
    {
    result=operand;
    }
    pendingOperator=clickedOperator;
    waitForOperand=true;
}
void Widget::on_point_clicked()
{
    if(waitForOperand)
    {
        ui->lineEdit->setText("0");
    }
    if(!ui->lineEdit->text().contains('.'))
        ui->lineEdit->setText(ui->lineEdit->text()+".");
    waitForOperand=false;
}
void Widget::setShortcutKeys()
{

    Qt::Key key[21] = {
        Qt::Key_0,          Qt::Key_1,          Qt::Key_2,          Qt::Key_3,
        Qt::Key_4,          Qt::Key_5,          Qt::Key_6,          Qt::Key_7,
        Qt::Key_8,          Qt::Key_9,
        Qt::Key_Plus,       Qt::Key_Minus,      Qt::Key_Asterisk,   Qt::Key_Slash,
        Qt::Key_Equal,      Qt::Key_Period,     Qt::Key_Backspace,  Qt::Key_M,
        Qt::Key_S,          Qt::Key_C,           Qt::Key_E
    };
    QPushButton *btn[21] = {
        ui->digitBtn0,      ui->digitBtn1,          ui->digitBtn2,          ui->digitBtn3,
        ui->digitBtn4,      ui->digitBtn5,          ui->digitBtn6,          ui->digitBtn7,
        ui->digitBtn8,      ui->digitBtn9,
        ui->addBtn,         ui->subtractionBtn,     ui->mulBtn,             ui->divisionBtn,
        ui->equalBtn,       ui->pointBtn,           ui->clearBtn,           ui->signBtn,
        ui->sinBtn,         ui->cosBtn,             ui->expBtn

    };

    for (int i = 0; i < 21; i++)
        btn[i]->setShortcut(QKeySequence(key[i]));
    ui->clearAllBtn->setShortcut(QKeySequence("Ctrl+Backspace"));
}
