#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
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
    bool waitForOperator;
    QString inToPost(QString infix) noexcept(false) ;
    double compute(QString s) noexcept(false);
    //获取当前表达式的值
    QString currentText();
    //设置当前行的值
    void setCurrentText(QString text);
    QString log;                //历史记录

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
    void on_action_v_triggered();
    void on_action_triggered();
    void on_action_2_triggered();
    void on_action_3_triggered(bool checked);
    void specialOperatorClicked();
    void on_action_3_triggered();
};
#endif // MAINWINDOW_H
