#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
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
    void on_action_triggered();
};
#endif // WIDGET_H

