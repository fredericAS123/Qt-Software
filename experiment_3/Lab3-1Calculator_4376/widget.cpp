#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include <QKeyEvent>
#include <QShortcut>
#include <complex>
#include <QtCore/qmath.h>
#include<QDebug>
#include <map>
#include <stack>
#include <cmath>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{


    waitForOperand=true;
    connectSlots();
    setShortcutKeys();
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::abortOperation()
{
    ui->lineEdit->setText("0");
    waitForOperand=true;
    QMessageBox::warning(this,"运算错误",error);
}
void Widget::on_clearBtn_cliced()
{
    //去掉末尾字符
    QString str =ui->lineEdit->text();
    if(str!=0)
    {
        ui->lineEdit->setText(str.left(str.count() - 1));
    }
}

void Widget::on_clearAllBtn_clicked()//初始化
{
    ui->lineEdit->setText("0");
    waitForOperand=true;
    result = 0.0 ;
    pendingOperator.clear();

}

void Widget::digitClicked()
{
    QPushButton *digitBtn=static_cast<QPushButton*>(sender());
    QString value=digitBtn->text();
    if(ui->lineEdit->text()=="0"&&value=="0")
        return ;
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
void Widget::on_equalBtn_clicked()
{
    double result=0.0;
    try
    {
        result=compute(inToPost(ui->lineEdit->text()));
    }
    catch(const char *er)
    {
        error=er;
        abortOperation();
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text()+'='+QString::number(result));
    waitForOperand=true;
}
void Widget::on_signBtn_clicked()
{
    QString text=ui->lineEdit->text();
    QChar sign=text[text.size()-1];
    if(sign=='-')
    {
        text.remove(text.size()-1,1);
    }
    else
    {
        text.append('-');
    }
    ui->lineEdit->setText(text);
}
void Widget::operatorClicked()
{
    QPushButton *clickedBtn=qobject_cast<QPushButton*>(sender());
    QString clickedOperator=clickedBtn->text();
    ui->lineEdit->setText(ui->lineEdit->text()+clickedOperator);
}
void Widget::on_pointBtn_clicked()
{
    if(waitForOperand)
        ui->lineEdit->setText("0");
    ui->lineEdit->setText(ui->lineEdit->text()+".");
    waitForOperand=false;
}
void Widget::setShortcutKeys()
{
    Qt::Key key[24] = {
        Qt::Key_0,          Qt::Key_1,          Qt::Key_2,          Qt::Key_3,
        Qt::Key_4,          Qt::Key_5,          Qt::Key_6,          Qt::Key_7,
        Qt::Key_8,          Qt::Key_9,
        Qt::Key_Plus,       Qt::Key_Minus,      Qt::Key_Asterisk,   Qt::Key_Slash,
        Qt::Key_Equal,      Qt::Key_Period,     Qt::Key_Backspace,  Qt::Key_M,
        Qt::Key_ParenLeft,  Qt::Key_ParenRight, Qt::Key_AsciiCircum,Qt::Key_S,
        Qt::Key_C,          Qt::Key_L
    };
    QPushButton *btn[24] = {
        ui->digitBtn0,      ui->digitBtn1,          ui->digitBtn2,          ui->digitBtn3,
        ui->digitBtn4,      ui->digitBtn5,          ui->digitBtn6,          ui->digitBtn7,
        ui->digitBtn8,      ui->digitBtn9,
        ui->addBtn,         ui->subtractionBtn,     ui->multiplicationBtn,  ui->divisionBtn,
        ui->equalBtn,       ui->pointBtn,           ui->clearBtn,           ui->signBtn,
        ui->leftBracketBtn, ui->rightBracketBtn,    ui->powBtn,             ui->sinBtn,
        ui->cosBtn,         ui->logBtn
    };
    for(int i=0;i<24;i++)
        btn[i]->setShortcut(QKeySequence(key[i]));
    ui->clearAllBtn->setShortcut(QKeySequence("Ctrl+Backspace"));
}
void Widget::connectSlots()
{
    QPushButton *digitBtns[10] = {
        ui->digitBtn0,      ui->digitBtn1,          ui->digitBtn2,          ui->digitBtn3,
        ui->digitBtn4,      ui->digitBtn5,          ui->digitBtn6,          ui->digitBtn7,
        ui->digitBtn8,      ui->digitBtn9
    };
    for(auto btn:digitBtns)
        connect(btn,&QPushButton::clicked,this,&Widget::digitClicked);
    QPushButton *operatorBtns[10] = {
        ui->addBtn,         ui->subtractionBtn,     ui->multiplicationBtn,  ui->divisionBtn,
        ui->leftBracketBtn, ui->rightBracketBtn,    ui->powBtn,             ui->sinBtn,
        ui->cosBtn,         ui->logBtn
    };
    for (auto btn : operatorBtns)
        connect(btn, &QPushButton::clicked, this, &Widget::operatorClicked);
}
QString Widget::inToPost(QString infix) noexcept(false)
{
    std::stack<char> stack;  // 定义一个字符类型的栈，用于存放运算符
    char current = 0;  // 定义一个字符变量，用于存放当前读取的字符
    QString postfix;  // 定义一个字符串变量，用于存放后缀表达式

    std::map<char,int> priority;  // 定义一个字符到整型的映射，用于存放运算符的优先级
    priority['+'] = 0;  // 加法的优先级为0
    priority['-'] = 0;  // 减法的优先级为0
    priority['*'] = 1;  // 乘法的优先级为1
    priority['/'] = 1;  // 除法的优先级为1
    priority['^'] = 2;  // 幂运算的优先级为2
    priority['s'] = 2;  // sin函数的优先级为2
    priority['c'] = 2;  //cos函数的优先级为2
    priority['l'] = 2;  // ln函数的优先级为2

    for(int i = 0; i < infix.length() ;++i)  // 遍历中缀表达式字符串
    {
        current =infix[i].toLatin1();  // 将当前字符转换为ASCII码
        if(isdigit(current))  // 如果当前字符是数字
        {
            postfix.push_back(current);  // 直接将数字添加到后缀表达式字符串中
            continue;  // 继续下一次循环
        }
        switch(current)  // 根据当前字符进行分支处理
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case 's':
        case 'c':
        case 'l':
            // 如果运算符的前一项不是右括号，则说明前一个数字输入完毕，用#标识前面几个字符组成一个数字
            if(infix[i-1]!=')')
            {
                if(infix[i-1].isDigit())
                    postfix.push_back('#');
                else
                    throw "expression is illegality";
            }
            if(!stack.empty())  // 如果栈不为空
            {
                char tempTop=stack.top();  // 获取栈顶元素
                while(tempTop != '(' && priority[current]<=priority[tempTop])  // 如果栈顶元素不是左括号且当前运算符的优先级小于等于栈顶元素的优先级
                {
                    stack.pop();  // 弹出栈顶元素
                    postfix.push_back(tempTop);  // 将栈顶元素添加到后缀表达式字符串中
                    if(stack.empty())  // 如果栈为空，跳出循环
                        break;
                    tempTop=stack.top();  // 获取新的栈顶元素
                }
            }
            stack.push(current);  // 将当前运算符压入栈中
            break;
        case '.':
            postfix.push_back(current);  // 如果当前字符是小数点，直接添加到后缀表达式字符串中
            break;
        case '%':
            postfix.push_back(current);  // 如果当前字符是百分号，直接添加到后缀表达式字符串中
            break;
        case '(':
            stack.push(current);  // 如果当前字符是左括号，直接压入栈中
            break;
        case ')':
            postfix.push_back('#');  // 如果当前字符是右括号，说明前方数字输入完成，标识一下
            char tempTop;
            tempTop=stack.top();
            while(tempTop !='(')  // 直到栈顶元素是左括号才停止弹出运算符
            {
                stack.pop();  // 弹出栈顶元素
                postfix.push_back(tempTop);  // 将栈顶元素添加到后缀表达式字符串中
                tempTop=stack.top();  // 获取新的栈顶元素
            }
            stack.pop();  // 弹出左括号
            break;
        default:
            throw "expression has illegality character";  // 如果当前字符不是有效的字符，抛出异常
            break;
        }
    }
    if(infix[infix.size()-1] != ')')  // 如果表达式的最后一个字符不是右括号
    {
        if(infix[infix.size()-1].isDigit())  // 如果最后一个字符是数字
            postfix.push_back('#');  // 用#标识一下
        else
            throw "expression is illegality";  // 否则抛出异常
    }
    while(!stack.empty())
    {
        char tempOut=stack.top();
        stack.pop();
        postfix.push_back(tempOut);
    }
    return postfix;
}
double Widget::compute(QString s) throw(const char*)
{
    std::stack<double> stack;
    QString str;
    double curr;

    double temNum1;
    double temNum2;
    for(auto i=s.begin();i!=s.end();i++)
    {
        if((*i).isDigit())
        {
            str.push_back(*i);
            continue;
        }
        switch((*i).toLatin1())
        {
        case '+':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum1+temNum2);
            break;
        case '-':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum1-temNum2);
            break;
       case '*':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum1*temNum2);
            break;
        case '/':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum1/temNum2);
            break;
        case '^':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(pow(temNum2,temNum1));
            break;
        case 's':
            temNum1=stack.top();
            stack.pop();
            stack.push(qSin(temNum1/180*3.1415926));
            break;
//        case 'l':
//            temNum1=stack.top();
//            stack.pop();
//            temNum2=stack.top();
//            stack.pop();
//            stack.push(qLog(temNum2, temNum1));
//            break;
        case 'c':
            temNum1=stack.top();
            stack.pop();
            stack.push(qCos(temNum1/180*3.1415926));
        case '.':
            str.push_back(*i);
            break;
        case '#':
            curr =str.toDouble();//字符串转换为浮点型
            str.clear();
            stack.push(curr);
            break;
        case '%':
            curr = stack.top();
            stack.pop();
            curr*=0.01;
            stack.push(curr);
            break;
        default:
            throw "expression has illegality character";
            break;

        }
    }
    curr=stack.top();
    return curr;
}
