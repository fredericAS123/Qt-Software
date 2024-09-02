#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "boardwidget.h"

class gamewidget : public QWidget
{
    Q_OBJECT
public:
    explicit gamewidget(QWidget *parent = 0);


private:
    void showWinner(int winner);

private:
    BoardWidget *boardWidget;

};

#endif // GAMEWIDGET_H
