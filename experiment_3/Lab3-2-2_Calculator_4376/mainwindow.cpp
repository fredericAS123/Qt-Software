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
#include<QClipboard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("0");
    result = 0.0;
    waitForOperand = true;
    connectSlots();
    setShortcutKeys();
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::abortOperation()
{

    ui->lineEdit->setText("0");
    waitForOperand=true;
    QMessageBox::warning(this,"运算错误",errer);

}



void MainWindow::digitClicked()
{
    QPushButton *digitBtn = static_cast<QPushButton*>(sender());//获取发生源
    QString value = digitBtn->text();

    if(ui->lineEdit->text()=="0"&&value=="0")
        return;
    if(waitForOperand)
    {
        ui->lineEdit->setText(value);//覆盖
        waitForOperand=false;//初始化后 输入符号后
    }
    else {

            ui->lineEdit->setText(ui->lineEdit->text()+value);//往后叠加

    }
}


void MainWindow::operatorClicked()
{

    QPushButton *clickedBtn = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedBtn->text();
    if (waitForOperand)
    {
        ui->lineEdit->setText(clickedOperator);
        waitForOperand = false;
    }
    else
        ui->lineEdit->setText(ui->lineEdit->text() + clickedOperator);
}

  //去掉末尾字符
void MainWindow::on_clearBtn_clicked()
{

       QString str = ui->lineEdit->text();
       if (str != "0")
       {
           ui->lineEdit->setText(str.left(str.count() - 1));
       }
}

void MainWindow::on_clearAllBtn_clicked()//初始化
{
    ui->lineEdit->setText("0");
    waitForOperand=true;
    result = 0.0 ;
    pendingOperator.clear();

}

void MainWindow::on_equalBtn_clicked()
{
    double result = 0.0;
        try
        {
            result = compute(inToPost(ui->lineEdit->text()));
        }
        catch(const char *er)
        {
            errer = er;
            abortOperation();
            return;
        }
        ui->lineEdit->setText(ui->lineEdit->text() + '=' + QString::number(result));
        waitForOperand = true;
}

void MainWindow::on_signBtn_clicked()
{
    QString text = ui->lineEdit->text();
       QChar sign = text[text.size() - 1];
       if(sign == '-')
       {
           text.remove(text.size() - 1, 1);
       }
       else
       {
           text.append('-');
       }
       ui->lineEdit->setText(text);

}




void MainWindow::on_pointBtn_clicked(){
    if (waitForOperand)
            ui->lineEdit->setText("0");
        ui->lineEdit->setText(ui->lineEdit->text() + ".");
        waitForOperand = false;
}

void MainWindow::setShortcutKeys()
{

    Qt::Key key[23] = {
        Qt::Key_0,          Qt::Key_1,          Qt::Key_2,          Qt::Key_3,
        Qt::Key_4,          Qt::Key_5,          Qt::Key_6,          Qt::Key_7,
        Qt::Key_8,          Qt::Key_9,
        Qt::Key_Plus,       Qt::Key_Minus,      Qt::Key_Asterisk,   Qt::Key_Slash,
        Qt::Key_Equal,      Qt::Key_Period,     Qt::Key_Backspace,  Qt::Key_M,
        Qt::Key_ParenLeft,  Qt::Key_ParenRight, Qt::Key_AsciiCircum,Qt::Key_S,
        Qt::Key_C
    };
    QPushButton *btn[23] = {
        ui->digitBtn0,      ui->digitBtn1,          ui->digitBtn2,          ui->digitBtn3,
        ui->digitBtn4,      ui->digitBtn5,          ui->digitBtn6,          ui->digitBtn7,
        ui->digitBtn8,      ui->digitBtn9,
        ui->addBtn,         ui->subtractionBtn,     ui->multiplicationBtn,  ui->divisionBtn,
        ui->equalBtn,       ui->pointBtn,           ui->clearBtn,           ui->signBtn,
        ui->leftBracketBtn, ui->rightBracketBtn,    ui->powBtn,             ui->sinBtn,
        ui->cosBtn
    };

    for (int i = 0; i < 23; i++)
        btn[i]->setShortcut(QKeySequence(key[i]));
    ui->clearAllBtn->setShortcut(QKeySequence("Ctrl+Backspace"));
}

void MainWindow::connectSlots()
{
    QPushButton *digitBtns[10] = {
        ui->digitBtn0,      ui->digitBtn1,          ui->digitBtn2,          ui->digitBtn3,
        ui->digitBtn4,      ui->digitBtn5,          ui->digitBtn6,          ui->digitBtn7,
        ui->digitBtn8,      ui->digitBtn9
    };
    for (auto btn : digitBtns)
        connect(btn, &QPushButton::clicked, this, &MainWindow::digitClicked);
    QPushButton *operatorBtns[9] = {
        ui->addBtn,         ui->subtractionBtn,     ui->multiplicationBtn,  ui->divisionBtn,
        ui->leftBracketBtn, ui->rightBracketBtn,    ui->powBtn,ui->sinBtn,  ui->cosBtn
    };
    for (auto btn : operatorBtns)
        connect(btn, &QPushButton::clicked, this, &MainWindow::operatorClicked);
}



QString MainWindow::inToPost(QString infix) noexcept(false)
{
    std::stack<char> stack;
    char current = 0;//读入的字符
    QString postfix;//写入后缀表达式的字符串

    std::map<char,int> priority;//运算符号优先级表
    priority['+'] = 0;
    priority['-'] = 0;
    priority['*'] = 1;
    priority['/'] = 1;
    priority['^'] = 2;
    priority['s'] = 2;
    priority['c'] = 2;

    for(int i = 0; i < infix.length() ;++i)//逐个读取中缀表达式字符串中的字符
    {
        // 将 infix 字符串的第 i 个字符转换为 Latin-1 编码，并将其存储在 current 变量中
        current = infix[i]  // 访问 infix 字符串的第 i 个字符，这是一个 QChar 对象
                     .toLatin1();  // 将 QChar 对象转换为 8 位 Latin-1 编码字符，并返回该字符

        if(isdigit(current))//如果是数字直接输出
        {
            postfix.push_back(current);
            continue;
        }
        switch(current)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case 's':
        case 'c':
            //postfix.push_back('#');
            if(i > 0)    //如果运算符的前一项不是右括号则说明前一个数字输入完毕，用#标识前面几个字符组成一个数字
             {
                if (infix[i-1] != ')')
                    postfix.push_back('#');
                /*if(infix[i-1].isDigit())
                    postfix.push_back('#');
                else
                    throw "expression is illegality";*/
            }
            else
                postfix.push_back('#');
            if(!stack.empty())//比较目前符号与栈顶符号优先级，低于则出栈，并输出字符串
            {
                char tempTop=stack.top();
                while(tempTop != '(' && priority[current]<=priority[tempTop])
                {
                    stack.pop();
                    postfix.push_back(tempTop);
                    if(stack.empty())
                        break;
                    tempTop=stack.top();
                }
            }
            stack.push(current);//符号全部出栈或者遇到了'('或者大于栈顶符号的优先级，将新符号压入栈中
            break;
        case '.':
            postfix.push_back(current);
            break;
        case '%':
            postfix.push_back(current);
            break;
        case '(':
            stack.push(current);//左括号直接入栈
            break;
        case ')':
            postfix.push_back('#');//右括号说明前方数字输入完成，标识一下
            char tempTop;
            tempTop=stack.top();
            while(tempTop !='(')//直到栈顶元素是左括号才停止循环
            {
                stack.pop();
                postfix.push_back(tempTop);
                tempTop=stack.top();
            }
            stack.pop();
            break;
        default:
            throw "expression has illegality character";
            break;
        }
    }
    if(infix[infix.size()-1] != ')')
    {
        if(infix[infix.size()-1].isDigit())
            postfix.push_back('#');
        else
            throw "expression is illegality";
    }
    while(!stack.empty())
    {
        char tempOut=stack.top();
        stack.pop();
        postfix.push_back(tempOut);
    }
    return postfix;
}

double MainWindow::compute(QString s) noexcept(false)
{
    std::stack<double> stack;
    QString str;// 暂时存储多位数的各位
    double curr;//遇到#后curr=str.toDouble();

    double  temNum1;
    double  temNum2;
    for(auto i = s.begin();i != s.end(); i++)
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
            stack.push(temNum2 + temNum1);
            break;
        case '-':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum2 - temNum1);
            break;
        case '*':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum2 * temNum1);
            break;
        case '/':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(temNum2 / temNum1);
            break;
        case '^':
            temNum1=stack.top();
            stack.pop();
            temNum2=stack.top();
            stack.pop();
            stack.push(pow(temNum2, temNum1));
            break;
        case 's':
            temNum1=stack.top();
            stack.pop();
            stack.push(qSin(temNum1/180*3.1415926));
            break;
        case 'c':
            temNum1=stack.top();
            stack.pop();
            stack.push(qCos(temNum1/180*3.1415926));
            break;
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

void MainWindow::on_action_triggered()
{
    QClipboard *board =QApplication::clipboard();
    QString text =board->text();
    ui->lineEdit->setText(text);
}
