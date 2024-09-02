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
    void setTrackPos(const QPoint &value);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
protected:
    void paintEvent(QPaintEvent *event);
    void draw(int flag,QPoint pos1,QPoint pos2);
private slots:
    void on_action_draw_line_triggered();

    void on_action_draw_circle_triggered();

    void on_action_draw_rect_triggered();

    void on_action_clear_triggered();

    void on_action_pen_color_triggered();

    void on_action_pen_thick_triggered();

    void on_action_pen_style_triggered();

    void on_action_brush_color_triggered();

    void on_action_triggered();

    void on_action_2_line_triggered();

    void on_action_2_circle_triggered();

    void on_action_2_rect_triggered();

private:
    QVector<QPoint> Poses;
    QVector<int> drawtype;
    QPoint trackPos;
    QPoint Pos1=QPoint(-1, -1);
    QPoint Pos2=QPoint(-1, -1);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
