#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
#include<QMouseEvent>
#include<QtMath>
#include<QDebug>
#include"QColorDialog"
#include"QInputDialog"
QPaintEvent *event;
int flag;
int dis;
QColor Pen_color=Qt::black;
QColor back_color=Qt::white;
int Pen_thick;
enum Qt::PenStyle pen_style=Qt::SolidLine;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), back_color);
    painter.setPen(Qt::red);//设置线条和形状轮廓

//按下鼠标瞬间，pos1记录按下的位置，并设置外圈为黑色，填充颜色为白色
     if(Pos1!=QPoint(-1, -1))
     {
     painter.setBrush(Qt::white);//设置填充颜色
      painter.setPen(Qt::black);
     painter.drawEllipse(Pos1,5, 5);

     }
//松开鼠标瞬间，pos2记录松开的位置，并填充为红色，且上述过程无记忆，事件发生后立即更新。
     if(Pos2!=QPoint(-1, -1))
     {
        painter.setBrush(Qt::red);
         painter.setPen(Qt::red);
        painter.drawEllipse(Pos2,5, 5);//椭圆尺寸
        painter.setBrush(back_color);
        painter.setPen(QPen(Pen_color,Pen_thick,pen_style));

       //通过鼠标点选pos1,pos2：
     switch(flag){

     case 1:

         painter.drawLine(Pos1, Pos2);
         break;
     case 2:
         if(Pos1!=QPoint(-1, -1) && Pos2!=QPoint(-1, -1))
         {
            dis=qSqrt((Pos2.x()-Pos1.x())*(Pos2.x()-Pos1.x())+(Pos2.y()-Pos1.y())*(Pos2.y()-Pos1.y()));
            painter.drawEllipse(Pos1,dis,dis);//绘制圆
         }
         break;
     case 3:
         if(Pos1!=QPoint(-1, -1) && Pos2!=QPoint(-1, -1))
         {
            painter.drawRect(Pos1.x(),Pos1.y(),Pos2.x()-Pos1.x(),Pos2.y()-Pos1.y());
         }//矩形
         break;
     case 4:
         if(Pos1!=QPoint(-1, -1) && Pos2!=QPoint(-1, -1))
         {
            painter.drawEllipse(Pos1,Pos2.x()-Pos1.x(),Pos2.y()-Pos1.y());//椭圆
         }
         break;
     case 5:
           Pos1=QPoint(-1, -1);
           Pos2=QPoint(-1, -1);
           drawtype.clear();
           Poses.clear();
           update();//update() 时，系统会将该窗口标记为需要重绘。这并不会立即重绘窗口，而是安排在下一个事件循环时执行。
           break;
     }

     }

     //通过键盘输入pos1,pos2：
     int j=0;
    for(int i=0;i<Poses.length(); i=i+2)
    {
        if(i<Poses.length()-1)
        {
            switch(drawtype[j]){
            case 1:
                 painter.drawLine(Poses[i], Poses[i+1]);
                 j++;
                break;
            case 2:

                //dis=qSqrt(QPoint::dotProduct(Poses[i], Poses[i+1]));
                dis=qSqrt((Poses[i+1].x()-Poses[i].x())*(Poses[i+1].x()-Poses[i].x())+
                        (Poses[i+1].y()-Poses[i].y())*(Poses[i+1].y()-Poses[i].y()));
                qDebug()<<"pi"<<Poses[i];
                qDebug()<<"pi+1"<<Poses[i+1];
                qDebug()<<dis;
                painter.drawEllipse(Poses[i],dis,dis);
                j++;
                break;
            case 3:
                painter.drawRect(Poses[i].x(),Poses[i].y(),Poses[i+1].x()-Poses[i].x(),Poses[i+1].y()-Poses[i].y());
                j++;
                break;
            case 4:

                 painter.drawEllipse(Poses[i],Poses[i+1].x()-Poses[i].x(),Poses[i+1].y()-Poses[i].y());
                 j++;
                break;
            case 5://清零
              Pos1=QPoint(-1, -1);
              Pos2=QPoint(-1, -1);
              drawtype.clear();
              Poses.clear();
              j=0;
              update();
              break;

            }


        }

    }



}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
          Pos1=event->pos();
          Poses.push_back(Pos1);
          Pos2=QPoint(-1, -1);
          update();
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    Pos2 = event->pos();//获取事件的position
    update();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
     Pos2=event->pos();
     qDebug()<<Pos2;
     qDebug()<<Pos1;
     Poses.push_back(Pos2);
     drawtype.push_back(flag);
     update();
}

void MainWindow::on_action_draw_line_triggered()
{
    flag=1;

}


void MainWindow::on_action_draw_circle_triggered()
{
    flag=2;

}


void MainWindow::on_action_draw_rect_triggered()
{
    flag=3;

}


void MainWindow::on_action_clear_triggered()
{
    flag=5;

}


void MainWindow::on_action_pen_color_triggered()
{
    Pen_color =QColorDialog::getColor(Qt::black,this,"颜色对话框",QColorDialog::ShowAlphaChannel);
}


void MainWindow::on_action_pen_thick_triggered()
{
   Pen_thick = QInputDialog::getInt(this, "边框粗细选择", "请输入1到10之间的数值", 4, 1, 10, 1);
}


void MainWindow::on_action_pen_style_triggered()
{
    QStringList items;
    items << "Qt::SolidLine" << "Qt::DashLine"<< "Qt::DotLine"
          << "Qt::DashDotLine"<< "Qt::DashDotDotLine" << "Qt::CustomDashLine";

    QString input=QInputDialog::getItem(this, "条目输入对话框", "请选择或输入一个条目", items, 0, true);
  if(input== "Qt::SolidLine") pen_style = Qt::SolidLine;
  else if(input== "Qt::DashLine") pen_style = Qt::DashLine;
  else if(input== "Qt::DotLine") pen_style = Qt::DotLine;
  else if(input== "Qt::DashDotLine") pen_style = Qt::DashDotLine;
  else if(input== "Qt::DashDotDotLine") pen_style = Qt::DashDotDotLine;
  else if(input== "Qt::CustomDashLine") pen_style = Qt::CustomDashLine;
}


void MainWindow::on_action_brush_color_triggered()
{
     back_color =QColorDialog::getColor(Qt::white,this,"颜色对话框",QColorDialog::ShowAlphaChannel);
}


void MainWindow::on_action_triggered()//椭圆
{
     flag=4;
}


void MainWindow::on_action_2_line_triggered()
{
    flag=1;
    Pos1.setX(QInputDialog::getInt(this, "x1", "请输入1到1000之间的数值", 400, 0, 1000, 10));
    Pos1.setY(QInputDialog::getInt(this, "y1", "请输入1到1000之间的数值", 400, 0, 1000, 10));
    Poses.push_back(Pos1);
    Pos2.setX(QInputDialog::getInt(this, "x2", "请输入1到1000之间的数值", 600, 0, 1000, 10));
    Pos2.setY(QInputDialog::getInt(this, "y2", "请输入1到1000之间的数值", 600, 0, 1000, 10));
    Poses.push_back(Pos2);
    drawtype.push_back(flag);
    update();
}


void MainWindow::on_action_2_circle_triggered()
{
    flag=2;
    Pos1.setX(QInputDialog::getInt(this, "x1", "请输入1到1000之间的数值", 400, 0, 1000, 100));
    Pos1.setY(QInputDialog::getInt(this, "y1", "请输入1到1000之间的数值", 400, 0, 1000, 100));
    Poses.push_back(Pos1);
    Pos2.setX(QInputDialog::getInt(this, "x2", "请输入1到1000之间的数值", 500, 0, 1000, 100));
    Pos2.setY(QInputDialog::getInt(this, "y2", "请输入1到1000之间的数值", 500, 0, 1000, 100));
    Poses.push_back(Pos2);
    drawtype.push_back(flag);
    update();
}


void MainWindow::on_action_2_rect_triggered()
{

    flag=3;
    Pos1.setX(QInputDialog::getInt(this, "x1", "请输入1到1000之间的数值", 40, 0, 1000, 100));
    Pos1.setY(QInputDialog::getInt(this, "y1", "请输入1到1000之间的数值", 40, 0, 1000, 100));
    Poses.push_back(Pos1);
    Pos2.setX(QInputDialog::getInt(this, "x2", "请输入1到1000之间的数值", 100, 0, 1000, 10));
    Pos2.setY(QInputDialog::getInt(this, "y2", "请输入1到1000之间的数值", 100, 0, 1000, 10));
    Poses.push_back(Pos2);
    drawtype.push_back(flag);
    update();
}



