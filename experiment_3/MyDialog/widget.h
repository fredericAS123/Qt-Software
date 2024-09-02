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

private slots:
    void on_filedialog_clicked();

    void on_colordialog_clicked();

    void on_typefacedialog_clicked();

    void on_inputdialog_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
