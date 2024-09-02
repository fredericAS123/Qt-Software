#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QString errer;
    //操作数
    bool calculate(double operand, QString pendingOperator);
    //中止
    void abortOperation();
    //槽
    void connectSlots();
    QString pendingOperator;
    double result;
    bool waitForOperand;
    QString inToPost(QString infix) noexcept(false);
    double compute(QString s) noexcept(false);

protected:
    void setShortcutKeys();

private slots:
    void on_clearBtn_clicked();
    void on_clearAllBtn_clicked();
    void on_equalBtn_clicked();
    void digitClicked();
    void on_signBtn_clicked();
    void operatorClicked();
    void on_pointBtn_clicked();
};
#endif // WIDGET_H
