#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QString inToPost(QString infix) noexcept(false); //将表达式转化为后缀表达式
    double compute(QString s) throw(const char*); //计算后缀表达式
    void abortOperation();//连接信号和槽
    void connectSlots();
    bool waitForOperand;
    QString error;
    void setShortcutKeys();
    // 储存运算符
    QString pendingOperator;
    // 储存运算结果
    double result;
private slots:
    void on_clearBtn_cliced();
    void on_clearAllBtn_clicked();
    void on_equalBtn_clicked();
    void digitClicked();
    void on_signBtn_clicked();
    void operatorClicked();
    void on_pointBtn_clicked();
};

#endif // WIDGET_H
