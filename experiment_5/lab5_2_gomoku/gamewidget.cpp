#include "gamewidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>

gamewidget::gamewidget(QWidget *parent)
    : QWidget{parent}
{

    setWindowTitle("五子棋");
    // 创建一个垂直布局作为主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    // 创建并初始化棋盘控件
    boardWidget = new BoardWidget(this);
    // 创建一个水平布局，用于放置按钮
    QHBoxLayout *hLayout = new QHBoxLayout();
    // 创建并初始化"重新开始"按钮
    QPushButton *newGame = new QPushButton("重新开始");
    // 创建并初始化"悔棋"按钮
    QPushButton *undoBtn = new QPushButton("悔棋");
    // 将按钮添加到水平布局中
    hLayout->addWidget(newGame);
    hLayout->addWidget(undoBtn);
    // 在按钮布局后添加一个伸展区，确保按钮左对齐
    hLayout->addStretch();
    // 将水平布局添加到主布局中
    mainLayout->addLayout(hLayout);
    // 将棋盘控件添加到主布局中
    mainLayout->addWidget(boardWidget);
    // 将主布局设置为窗口的布局
    setLayout(mainLayout);

    connect(newGame, &QPushButton::clicked, boardWidget, &BoardWidget::initBoard);
    connect(undoBtn, &QPushButton::clicked, boardWidget, &BoardWidget::undo);
    connect(boardWidget, &BoardWidget::gameOver, this, &gamewidget::showWinner);
}

void gamewidget::showWinner(int winner)//gameOver和该函数通过槽函数相连，gameOver中0（false）为黑方，1（true）为白方。
{
    if (winner != 2)
    {
        QString playerName = (winner == BoardWidget::WHITE_PLAYER) ? "白方" : "黑方";
        QMessageBox::information(this, "游戏结束", tr("恭喜%1获胜！！").arg(playerName), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, "游戏结束", "和棋！", QMessageBox::Ok);
    }
}

