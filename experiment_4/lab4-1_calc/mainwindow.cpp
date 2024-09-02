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
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setCurrentText("0");
    on_action_3_triggered(false);
    /*ui->lineEdit->setText("0");
    result = 0.0;*/
    waitForOperator = false;
    connectSlots();
    setShortcutKeys();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::abortOperation()
{
    setCurrentText("0");
    waitForOperator = true;
    statusBar()->showMessage(errer, 4000);

    /*ui->lineEdit->setText("0");
    waitForOperand=true;
    QMessageBox::warning(this,"运算错误",errer);*/

}



void MainWindow::digitClicked()
{
    QPushButton *digitBtn = static_cast<QPushButton*>(sender());
    QString value = digitBtn->text();
    QString current = currentText();
    if(current=="0" && value=="0")
        return;
    if(waitForOperator)
    {
        log.append(current + '\n');
        ui->textEdit->append(value);
        ui->textEdit->moveCursor(QTextCursor::End);
        waitForOperator = false;
    }
    else {
        if(current != "0")
            setCurrentText(current + value);
        else
            setCurrentText(value);
    }
}


void MainWindow::operatorClicked()
{
   QPushButton *clickedBtn = qobject_cast<QPushButton *>(sender());
   QString clickedOperator = clickedBtn->text();
   setCurrentText(currentText() + clickedOperator);
   waitForOperator = false;
   /* QPushButton *clickedBtn = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedBtn->text();
    if (waitForOperand)
    {
        ui->lineEdit->setText(clickedOperator);
        waitForOperand = false;
    }
    else
        ui->lineEdit->setText(ui->lineEdit->text() + clickedOperator);*/
}

  //去掉末尾字符
void MainWindow::on_clearBtn_clicked()
{

    //将当前显示的数归零
        setCurrentText("0");
        waitForOperator = false;
}

void MainWindow::on_clearAllBtn_clicked()//初始化
{
    //将当前显示的数据归零，并将之前保存的数据运算清除
        ui->textEdit->setText("0");
        waitForOperator = false;
    /*ui->lineEdit->setText("0");
    waitForOperand=true;
    result = 0.0 ;
    pendingOperator.clear();*/

}

void MainWindow::on_equalBtn_clicked()
{
    double result = 0.0;
        try
        {
            result = compute(inToPost(currentText()));
        }
        catch(const char *er)
        {
            errer = er;
            abortOperation();
            return;
        }
    log.append(currentText() + '\n');
    ui->textEdit->append(QString::number(result));
    ui->textEdit->moveCursor(QTextCursor::End);
    waitForOperator = true;
}

void MainWindow::on_signBtn_clicked()
{
    QString current = currentText();
        if (waitForOperator)
        {
            log.append(current + '\n');
            ui->textEdit->append("-");
            ui->textEdit->moveCursor(QTextCursor::End);
            waitForOperator = false;
        }
        else
        {
            if (current[0] == '-')
                current[0] = '+';
            else
                current[0] = '-';
            setCurrentText(current);
        }
       /*QString text = ui->lineEdit->text();
       QChar sign = text[text.size() - 1];
       //char allNum=0;
       int i=0;
       // current =infix[i].toLatin1();
       //char current=text[0].toLatin1();
       while(isdigit(text[i].toLatin1()))
       {i++;}
       if(i==text.size())//输入全是数字
       {
           text='-'+ui->lineEdit->text();
          // ui->lineEdit->setText('-'+ui->lineEdit->text());
       }
       else if(sign == '-')
       {
           text.remove(text.size() - 1, 1);
           text.append('+');
       }
       else
       {
           text.append('-');
       }
       ui->lineEdit->setText(text);*/

}




void MainWindow::on_pointBtn_clicked(){
    setCurrentText(currentText() + ".");
    waitForOperator = false;
}

void MainWindow::setShortcutKeys()
{

    Qt::Key key[28] = {
        Qt::Key_0,          Qt::Key_1,          Qt::Key_2,          Qt::Key_3,
        Qt::Key_4,          Qt::Key_5,          Qt::Key_6,          Qt::Key_7,
        Qt::Key_8,          Qt::Key_9,
        Qt::Key_Plus,       Qt::Key_Minus,      Qt::Key_Asterisk,   Qt::Key_Slash,
        Qt::Key_Equal,      Qt::Key_Period,     Qt::Key_Backspace,  Qt::Key_Q,
        Qt::Key_ParenLeft,  Qt::Key_ParenRight, Qt::Key_AsciiCircum,Qt::Key_S,
        Qt::Key_C,          Qt::Key_G,          Qt::Key_N,          Qt::Key_B,
        Qt::Key_D,          Qt::Key_M

    };
    QPushButton *btn[28] = {
        ui->digitBtn0,      ui->digitBtn1,          ui->digitBtn2,          ui->digitBtn3,
        ui->digitBtn4,      ui->digitBtn5,          ui->digitBtn6,          ui->digitBtn7,
        ui->digitBtn8,      ui->digitBtn9,
        ui->addBtn,         ui->subtractionBtn,     ui->multiplicationBtn,  ui->divisionBtn,
        ui->equalBtn,       ui->pointBtn,           ui->clearBtn,           ui->signBtn,
        ui->leftBracketBtn, ui->rightBracketBtn,    ui->powBtn,             ui->sinBtn,
        ui->cosBtn,         ui->logBtn,             ui->lnBtn,              ui->binBtn,
        ui->gcdBtn,         ui->lcmBtn
    };

    for (int i = 0; i < 28; i++)
        btn[i]->setShortcut(QKeySequence(key[i]));
    ui->clearAllBtn->setShortcut(QKeySequence("Ctrl+Backspace"));
    ui->DateBtn->setShortcut(QKeySequence("Ctrl+shift"));
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

    QPushButton *operatorBtns[7] = {
        ui->addBtn,         ui->subtractionBtn,     ui->multiplicationBtn,  ui->divisionBtn,
        ui->leftBracketBtn, ui->rightBracketBtn,    ui->powBtn
    };
    for (auto btn : operatorBtns)
        connect(btn, &QPushButton::clicked, this, &MainWindow::operatorClicked);

    QPushButton *specialOperatorBtns[8] = {
            ui->sinBtn,         ui->cosBtn,                 ui->lnBtn,
            ui->logBtn,         ui->binBtn,                 ui->gcdBtn,
            ui->lcmBtn,         ui->DateBtn
        };
    for (auto btn : specialOperatorBtns)
        connect(btn, &QPushButton::clicked, this, &MainWindow::specialOperatorClicked);


}



QString MainWindow::inToPost(QString infix) noexcept(false)
{
    std::stack<char> stack;
    char current = 0;//读入的字符
    QString postfix;//写入后缀表达式的字符串
    QDate d1;
    QDate d2;
    int tempint;
    std::map<char,int> priority;//运算符号优先级表
    priority['+'] = 0;
    priority['-'] = 0;
    priority['*'] = 1;
    priority['/'] = 1;
    priority['^'] = 2;
    priority['s'] = 3;
    priority['c'] = 3;
    priority['n'] = 3;
    priority['g'] = 3;
    priority['B'] = 3;
    priority['d'] = 3;//公约数
    priority['m'] = 3;//公倍数
    for(int i = 0; i < infix.length() ;++i)//逐个读取中缀表达式字符串中的字符
    {

        current =infix[i].toLatin1();
        if(isdigit(current))//如果是数字直接输出
        {
            postfix.push_back(current);

            continue;
        }
        if(current=='D')
        {
            QString Date;
            int j = i+4;

            while(isdigit(infix[j].toLatin1())||infix[j].toLatin1()=='/')
            {
                Date.push_back(infix[j].toLatin1());
                j++;
                //if(~isdigit(infix[j].toLatin1()) && infix[j].toLatin1()!='/')
                //{throw " Date输入格式错误 ";}
            }
            i=j-1;
            d1 = QDate::fromString(Date,"yyyy/M/d");
            d2 = QDate::currentDate();
            tempint = d1.daysTo(d2);
            postfix.push_back(QString::number(tempint));
            qDebug() << "d2 - d1=" << tempint;
            continue;
        }

        switch(current)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            //postfix.push_back('#');
            if(i > 0)    //如果运算符的前一项不是右括号则说明前一个数字输入完毕，用#标识前面几个字符组成一个数字
             {
                if (infix[i-1] != ')')
                    postfix.push_back('#');
            }
            else
                postfix.push_back('#');//i=0
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
        case 's':
        case 'c':
        case 'B':
                    if(i > 0 && infix[i-1].isDigit())
                        throw "表达式非法";
                    if(!stack.empty())//比较目前符号与栈顶符号优先级，低于则出栈，并输出字符串
                    {
                        char tempTop=stack.top();
                        while(tempTop != '(' && priority[current]<priority[tempTop])
                        {
                            stack.pop();
                            postfix.push_back(tempTop);
                            if(stack.empty())
                                break;
                            tempTop=stack.top();
                        }
                    }
                    stack.push(current);
                    i+=2;
                    break;
        case 'l':
                    //if(infix[i-1].isDigit())
                        //throw "表达式非法";

                    if(!stack.empty())//比较目前符号与栈顶符号优先级，低于则出栈，并输出字符串
                    {
                        char tempTop=stack.top();

                        while(tempTop != '(' && priority[infix[i+1].toLatin1()] < priority[tempTop])
                        {
                            stack.pop();
                            postfix.push_back(tempTop);
                            if(stack.empty())
                                break;
                            tempTop=stack.top();
                        }
                    }
                    if(infix[i+1].toLatin1()=='n' || infix[i+1].toLatin1()=='g')
                    {stack.push(infix[i+1].toLatin1());i++;}
                    else if(infix[i+1].toLatin1()=='c' && infix[i+2].toLatin1()=='m')
                    {stack.push(infix[i+2].toLatin1());i=i+2;}//lcm push 'm'
                    break;

        case 'g'://gcd

                    if(!stack.empty())//比较目前符号与栈顶符号优先级，低于则出栈，并输出字符串
                    {
                        char tempTop=stack.top();

                        while(tempTop != '(' && priority[infix[i+2].toLatin1()] < priority[tempTop])
                        {
                            stack.pop();
                            postfix.push_back(tempTop);
                            if(stack.empty())
                                break;
                            tempTop=stack.top();
                        }
                    }
                    stack.push(infix[i+2].toLatin1());//d
                    i=i+2;//gcd
                    break;


        case '.':
            postfix.push_back(current);
            break;
        case '%':
            postfix.push_back(current);
            break;
        case '(':
            postfix.push_back('#');
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
    QString str;
    QString str1;
    double curr;

    double  temNum1;
    double  temNum2;
    int tempint;
    int intnum1;
    int mul;

    std::vector <int> a;
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
            if(temNum1==0){
                 throw "除数不能为0";
                break;
            }

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
        case 'n':
                   temNum1 = stack.top();
                   stack.pop();
                   stack.push(std::log(temNum1));
                   break;
        case 'g':
                   temNum1 = stack.top();
                   stack.pop();
                   temNum2=stack.top();
                   stack.pop();
                   if(temNum1<=0){
                        throw "数字必须大于0";
                       break;
                   }
                   if(temNum2<=0){
                        throw "数字必须大于0";
                       break;
                   }
                   stack.push(std::log10(temNum2)/std::log10(temNum1));
                   break;
        case 'B':

                   intnum1 = stack.top();
                   if(intnum1!=stack.top()){throw "二进制转换仅支持整数";break;}
                   stack.pop();
                   str1=str1.setNum(intnum1,2);

                  /*while ( intnum1>0)   //循环过程的始终，判断n是否能被2除尽
                       {
                       tempint=intnum1 / 2;
                       if(tempint*2==intnum1){ a.push_back(0);}
                       else{ a.push_back(1);}
                             //用数组存储每次除以2之后的余数，即断定奇偶性，对应二进制位上数值
                        j = j+1;
                        intnum1 =  intnum1/2;
                       }
                    for(; j > 0; j--)
                    {
                        str1.push_back(a[j-1]);
                    }*/

                   stack.push(str1.toInt());
                   break;
        case 'd'://最大公约数
                    int r;
                    tempint = stack.top();
                    stack.pop();
                    intnum1=stack.top();
                    stack.pop();

                    if(tempint<=0){
                         throw "数字必须大于0";
                        break;
                    }
                    if(intnum1<=0){
                         throw "数字必须大于0";
                        break;
                    }
                    r = tempint % intnum1;
                   while (r!=0){
                        tempint = intnum1;
                        intnum1 = r;
                        r = tempint % intnum1;
                    }//欧几里得算法，这是一种计算两个整数最大公约数的经典算法。在每次迭代中，将 intnum1 赋值给 tempint，将 r 赋值给 intnum1，然后计算新的 r。当 r 为0时，循环结束，此时 intnum1 就是两个整数的最大公约数

                    stack.push(intnum1);
                    break;
        case 'm':

            tempint = stack.top();
            stack.pop();
            intnum1=stack.top();
            stack.pop();
            mul=tempint*intnum1;
            if(tempint<=0){
                 throw "数字必须大于0";
                break;
            }
            if(intnum1<=0){
                 throw "数字必须大于0";
                break;
            }
            r = tempint % intnum1;
           while (r!=0){
                tempint = intnum1;
                intnum1 = r;
                r = tempint % intnum1;
            }//intnum1为最大公约数

            stack.push(mul/intnum1);
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

QString MainWindow::currentText()//获取当前表达式的值
{
    QTextDocument *document = ui->textEdit->document();
    QTextBlock block = document->lastBlock();//文本块
    qDebug()<<block.text();
    return block.text();
}

void MainWindow::setCurrentText(QString text) //将文本编辑框中的最后一行替换为传入的新文本，如果文本编辑框为空或没有换行符，则将整个文本编辑框的内容替换为传入的新文本
{
    QString allText = ui->textEdit->toPlainText();
    // toPlainText()函数返回文本编辑框中的文本，不包括任何格式信息。
    int pos = allText.lastIndexOf('\n');
    // 使用lastIndexOf('\n')查找字符串中最后一个换行符的位置。
    // 如果字符串中有换行符，pos将是一个大于或等于0的整数，否则为-1。

    if(pos >= 0)
        allText.replace(allText.lastIndexOf('\n') + 1, allText.size(), text);
        // 调用replace()函数来替换从最后一个换行符之后直到字符串末尾的所有文本。

    else
        allText = text;
        // 如果没有找到换行符（即文本编辑框为空或没有换行符），则将整个allText设置为参数text。

    ui->textEdit->setText(allText);
    // 将修改后的文本设置回文本编辑框，这会更新用户界面上的显示。

    ui->textEdit->moveCursor(QTextCursor::End);
    // 调用moveCursor()函数将文本光标移动到文本编辑框的末尾。
    // QTextCursor::End是一个枚举值，表示光标移动到文本的末尾。
}

void MainWindow::on_action_v_triggered()
{
    QClipboard *board = QApplication::clipboard();
        QString text = board->text();
        ui->textEdit->append(text);
}


void MainWindow::on_action_triggered()
{

    ui->textEdit->setText(log);
    setCurrentText("0");
    waitForOperator = false;
}


void MainWindow::on_action_2_triggered()
{
    log.clear();
}




void MainWindow::on_action_3_triggered(bool checked)
{
    if(checked)
        {
            //ui->percentBtn->show();
            ui->sinBtn->show();
            ui->cosBtn->show();
           // ui->tanBtn->show();
            ui->lnBtn->show();
            ui->logBtn->show();
            ui->binBtn->show();
            ui->lcmBtn->show();
            ui->gcdBtn->show();
            ui->label->show();
            ui->label_2->show();
            ui->label_3->show();
            ui->label_4->show();
            ui->DateBtn->show();

        }
        else
        {
            //ui->percentBtn->hide();
            ui->sinBtn->hide();
            ui->cosBtn->hide();
           // ui->tanBtn->hide();
            ui->lnBtn->hide();
            ui->logBtn->hide();
            ui->binBtn->hide();
            ui->lcmBtn->hide();
            ui->gcdBtn->hide();
            ui->label->hide();
            ui->label_2->hide();
            ui->label_3->hide();
            ui->label_4->hide();
            ui->DateBtn->hide();
        }
}

void MainWindow::specialOperatorClicked()
{
    // 使用 static_cast 将 sender() 返回的 QObject* 指针转换为 QPushButton* 指针
    QPushButton *specialOperatorBtn = static_cast<QPushButton*>(sender());

    QString value = specialOperatorBtn->text();
    QString current = currentText();
    if(waitForOperator)
    {
        log.append(current + '\n');
        ui->textEdit->append(value);
        waitForOperator = false;
    }
    else
    {
        if(current != "0")
            setCurrentText(current + value);
        else
            setCurrentText(value);
    }
}
