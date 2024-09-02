#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
    double BMI_cal(double omiga,double h);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    QString log;
    QPoint Pos=QPoint(-1, -1);
};

#endif // MAINWINDOW_H
