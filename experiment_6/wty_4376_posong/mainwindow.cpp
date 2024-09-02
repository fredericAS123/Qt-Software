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
QPaintEvent *event;
int checked=0;
double lm=0;
double k1=0;
QColor Pen_color=Qt::black;
//enum Qt::PenStyle pen_style=Qt::SolidLine;
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

double MainWindow::factorial(int k){
    int i;
    int total=k;
    double fac=1.0;
    for(i=0;i<total;i++){
        fac*=k;
        k=k-1;
    }
    return fac;
}
double MainWindow::poisson(double lambda, int k){
    double fac=factorial(k);
    double p=pow(lambda,k);
    double lambda_neg=-lambda;
    double e=exp(lambda_neg);
    double result=e*p/fac;
    return result;
}



void MainWindow::on_pushButton_clicked()
{
    QString lambda_get,k_get;
    lambda_get=ui->lambda->text();
    k_get=ui->k->text();
    double lambda_cal=lambda_get.toDouble();
    double k_cal=k_get.toDouble();
    if(lambda_cal<0||k_cal<0){
        QMessageBox::warning(this,"参数错误","参数不能为负");
    }
    else{
    lm=lambda_cal;
    k1=k_cal;
    double poss=poisson(lambda_cal,k_cal);
    ui->cal->setText(QString::number(poss));
    update();}
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
     Pos=event->pos();
     qDebug()<<Pos;
}
void MainWindow::on_pushButton_2_clicked()
{
    checked=1;
    update();//无论如何，要加update()!!!!! 及时更新屏幕显示
    qDebug()<<checked;

}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    if(checked==1){
        painter.setPen(Qt::black);}
    else{painter.setPen(Qt::NoPen);}
    painter.drawRect(33,284,466,138);
    if(checked==1){
        QPen Pen(Pen_color,6);
        painter.setPen(Pen);
        qDebug()<<lm;
        for(int j=0;j<9;j++){
            double length=poisson(lm,j);
            QPoint pos_dra0=QPoint(-1,-1);
            pos_dra0.setX(33 + 47 * j);
            pos_dra0.setY(422);
            QPoint pos_dra=QPoint(-1,-1);
            pos_dra.setX(33 + 47 * j);
            pos_dra.setY(422-300*length);
            painter.drawLine(pos_dra0,pos_dra);
    }
}
}


void MainWindow::on_color_triggered()
{
    Pen_color =QColorDialog::getColor(Qt::black,this,"颜色对话框",QColorDialog::ShowAlphaChannel);
    update();
}
