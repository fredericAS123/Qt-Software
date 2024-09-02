#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QKeyEvent>
#include <QShortcut>
#include <complex>
#include <QtCore/qmath.h>
#include<QDebug>
#include <map>
#include <stack>
#include <cmath>
#include"QClipboard"
#include <QTextBlock>
#include <QScrollBar>
#include <QDateTime>
#include <QPainter>
#include <QPaintEvent>
#include<QMouseEvent>
#include<QtMath>
#include<QDebug>
#include"QColorDialog"
#include"QInputDialog"
#include<QDateTime>
QPaintEvent *event;
QColor Pen_color_0=QColor(0,0,255);
QColor Pen_color_1=QColor(0,255,0);
QColor Pen_color_2=QColor(255,255,0);
QColor Pen_color_3=QColor(255,0,0);
QColor Pen_color_4=QColor(255,0,255);
QPen Pen_0(Pen_color_0,7);
QPen Pen_1(Pen_color_1,7);
QPen Pen_2(Pen_color_2,7);
QPen Pen_3(Pen_color_3,7);
QPen Pen_4(Pen_color_4,7);
int checked=5;
double omiga_glo=0,h_glo=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::BMI_cal(double omiga,double h){
    double h_m=h/100;
    double BMI=omiga/pow(h_m,2);
    return BMI;
}

void MainWindow::on_pushButton_clicked()
{
    QString omiga_get,h_get,a_get;
    omiga_get=ui->weight->text();
    h_get=ui->height->text();
    a_get=ui->age->text();
    double omiga_cal=omiga_get.toDouble();
    double h_cal=h_get.toDouble();
    double age=a_get.toDouble();
    if(omiga_cal<=0 || h_cal<=0){
    QMessageBox::warning(this,"错误","身高体重不能为非正数");
    }
    else if(age<17){
        QMessageBox::warning(this,"提醒","BMI分类不适用于青少年");
    }
    else{
        double BMI=BMI_cal(omiga_cal,h_cal);
        ui->BMI->setText(QString::number(BMI));
        if(BMI<=18.5){
            ui->conclusion->setText("您的BMI评价结论为：偏瘦");
            ui->suggestion->setText("补充蛋白质！");
            checked=0;
            update();
        }
        else if(BMI>18.5 && BMI<=24){
            ui->conclusion->setText("您的BMI评价结论为：正常");
            ui->suggestion->setText("继续保持！");
            checked=1;
            update();
        }
        else if(BMI>24 && BMI<=27){
            ui->conclusion->setText("您的BMI评价结论为：偏胖");
            ui->suggestion->setText("适量多摄入蔬菜水果");
            checked=2;
            update();
        }
        else if(BMI>27 && BMI<=30){
            ui->conclusion->setText("您的BMI评价结论为：肥胖");
            ui->suggestion->setText("控制饮食，多运动！");
            checked=3;
            update();
        }
        else if(BMI>30){
            ui->conclusion->setText("您的BMI评价结论为：重度肥胖");
            ui->suggestion->setText("开始减肥！");
            checked=4;
            update();
        }
        QDateTime dt=QDateTime::currentDateTime();
        QString dt_str=dt.toString();
        log.append(dt_str+',');
        log.append(QString::number(BMI)+ '\n');
        ui->history->setText(log);
        ui->history->moveCursor(QTextCursor::End);
        update();
    }
}

void MainWindow::on_clear_clicked()
{
    log.clear();
    checked=5;
    ui->history->setText(log);
    ui->BMI->setText(" ");
    update();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
     Pos=event->pos();
     qDebug()<<Pos;
}
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    if(checked==5){
        painter.setPen(Qt::NoPen);
    }
    else if(checked==0){
       painter.setPen(Pen_0);
       update();
    }
    else if(checked==1){
        painter.setPen(Pen_1);
        update();
    }
    else if(checked==2){
        painter.setPen(Pen_2);
        update();
    }
    else if(checked==3){
        painter.setPen(Pen_3);
        update();
    }
    else if(checked==4){
        painter.setPen(Pen_4);
        update();
    }
//    QPoint pos1=(16,630);
//    QPoint pos2=(600,630);
    painter.drawLine(16,630,600,630);
    update();
}
