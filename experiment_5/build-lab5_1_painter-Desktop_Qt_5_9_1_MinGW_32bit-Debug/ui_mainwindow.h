/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_draw_line;
    QAction *action_draw_circle;
    QAction *action_draw_rect;
    QAction *action;
    QAction *action_2_line;
    QAction *action_2_circle;
    QAction *action_2_rect;
    QAction *action_pen_color;
    QAction *action_pen_thick;
    QAction *action_pen_style;
    QAction *action_brush_color;
    QAction *action_clear;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(596, 499);
        action_draw_line = new QAction(MainWindow);
        action_draw_line->setObjectName(QStringLiteral("action_draw_line"));
        action_draw_circle = new QAction(MainWindow);
        action_draw_circle->setObjectName(QStringLiteral("action_draw_circle"));
        action_draw_rect = new QAction(MainWindow);
        action_draw_rect->setObjectName(QStringLiteral("action_draw_rect"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2_line = new QAction(MainWindow);
        action_2_line->setObjectName(QStringLiteral("action_2_line"));
        action_2_circle = new QAction(MainWindow);
        action_2_circle->setObjectName(QStringLiteral("action_2_circle"));
        action_2_rect = new QAction(MainWindow);
        action_2_rect->setObjectName(QStringLiteral("action_2_rect"));
        action_pen_color = new QAction(MainWindow);
        action_pen_color->setObjectName(QStringLiteral("action_pen_color"));
        action_pen_thick = new QAction(MainWindow);
        action_pen_thick->setObjectName(QStringLiteral("action_pen_thick"));
        action_pen_style = new QAction(MainWindow);
        action_pen_style->setObjectName(QStringLiteral("action_pen_style"));
        action_brush_color = new QAction(MainWindow);
        action_brush_color->setObjectName(QStringLiteral("action_brush_color"));
        action_clear = new QAction(MainWindow);
        action_clear->setObjectName(QStringLiteral("action_clear"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 596, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_draw_line);
        menu->addAction(action_draw_circle);
        menu->addAction(action_draw_rect);
        menu->addAction(action_2_line);
        menu->addAction(action_2_circle);
        menu->addAction(action_2_rect);
        menu->addAction(action_clear);
        menu_2->addAction(action_pen_color);
        menu_2->addAction(action_pen_thick);
        menu_2->addAction(action_pen_style);
        menu_2->addAction(action_brush_color);
        mainToolBar->addAction(action_draw_line);
        mainToolBar->addAction(action_draw_circle);
        mainToolBar->addAction(action_draw_rect);
        mainToolBar->addAction(action);
        mainToolBar->addAction(action_clear);
        mainToolBar->addAction(action_2_line);
        mainToolBar->addAction(action_2_circle);
        mainToolBar->addAction(action_2_rect);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_draw_line->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277", Q_NULLPTR));
        action_draw_circle->setText(QApplication::translate("MainWindow", "\345\234\206", Q_NULLPTR));
        action_draw_rect->setText(QApplication::translate("MainWindow", "\347\237\251\345\275\242", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\346\244\255\345\234\206", Q_NULLPTR));
        action_2_line->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277_2", Q_NULLPTR));
        action_2_circle->setText(QApplication::translate("MainWindow", "\345\234\206_2", Q_NULLPTR));
        action_2_rect->setText(QApplication::translate("MainWindow", "\347\237\251\345\275\242_2", Q_NULLPTR));
        action_pen_color->setText(QApplication::translate("MainWindow", "\350\276\271\346\241\206\351\242\234\350\211\262", Q_NULLPTR));
        action_pen_thick->setText(QApplication::translate("MainWindow", "\350\276\271\346\241\206\347\262\227\347\273\206", Q_NULLPTR));
        action_pen_style->setText(QApplication::translate("MainWindow", "\350\276\271\346\241\206\346\240\267\345\274\217", Q_NULLPTR));
        action_brush_color->setText(QApplication::translate("MainWindow", "\350\203\214\346\231\257\351\242\234\350\211\262", Q_NULLPTR));
        action_clear->setText(QApplication::translate("MainWindow", "\346\270\205\351\233\266", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\347\273\230\345\210\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
