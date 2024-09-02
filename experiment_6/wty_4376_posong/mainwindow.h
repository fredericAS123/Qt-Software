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
    void on_pushButton_2_clicked();

    void on_color_triggered();

private:
    Ui::MainWindow *ui;
    QString error;
    double factorial(int k);
    double poisson(double lambda, int k);
    QPoint Pos=QPoint(-1, -1);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

};

#endif // MAINWINDOW_H
