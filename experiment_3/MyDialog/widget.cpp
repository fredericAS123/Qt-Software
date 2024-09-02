#include "widget.h"
#include "ui_widget.h"
#include<QDialog>
#include<QDebug>
#include<QColorDialog>//颜色对话框
#include<QFileDialog>//文件对话框
#include<QFontDialog>//字体对话框
#include<QInputDialog>//输入对话框
#include "dialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QDialog *dialog = new QDialog(this);
    //dialog->show();//非模态对话框
    dialog->exec(); //模态对话框
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_filedialog_clicked()
{
    QString fileName= QFileDialog::getOpenFileName(this,"文件对话框","D:","图片文件（*png * jpg);;文本文件(*txt)");
    qDebug()<<"fileName:"<<fileName;
}

void Widget::on_colordialog_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red,this,"颜色对话框",QColorDialog::ShowAlphaChannel);
    qDebug()<<"color:"<<color;
}

void Widget::on_typefacedialog_clicked()
{
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok)
    {
        ui->typefacedialog->setFont(font);
        qDebug()<<"选择的字体为："<<font;
    }
    else
        qDebug()<<"没有选择字体";
}

void Widget::on_inputdialog_clicked()
{
    bool ok;
    QString name =QInputDialog::getText(this,"输入对话框","请输入用户名",QLineEdit::Normal,"admin",&ok);
    if(ok)
    {
        qDebug()<<"name:"<<name;
    }
    int intNum = QInputDialog::getInt(this,"整数输入对话框","请输入-1000到1000之间的数值",100,-1000,1000,10,&ok);
    if(ok)
    {
        qDebug()<<"intNum:"<<intNum;
    }
    double doubleNum = QInputDialog::getDouble(this,"浮点型输入对话框","请输入-1000到1000的数值",0.00,-1000,1000,2,&ok);
    if(ok)
    {
        qDebug()<<"doubleNum:"<<doubleNum;
    }
    QStringList items;
    items<<"条目1"<<"条目2";
    QString item =QInputDialog::getItem(this,"条目输入对话框","请选择或输入一个条目",items,0,true,&ok);
    if(ok)
    {
        qDebug()<<"items:"<<items;
    }
}
