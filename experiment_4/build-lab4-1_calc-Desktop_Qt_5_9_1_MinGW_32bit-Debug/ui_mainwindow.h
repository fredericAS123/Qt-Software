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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_v;
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *clearBtn;
    QPushButton *clearAllBtn;
    QPushButton *leftBracketBtn;
    QPushButton *rightBracketBtn;
    QPushButton *powBtn;
    QPushButton *equalBtn;
    QPushButton *digitBtn1;
    QPushButton *digitBtn2;
    QPushButton *digitBtn3;
    QPushButton *addBtn;
    QPushButton *digitBtn4;
    QPushButton *digitBtn5;
    QPushButton *digitBtn6;
    QPushButton *subtractionBtn;
    QPushButton *digitBtn7;
    QPushButton *digitBtn8;
    QPushButton *digitBtn9;
    QPushButton *multiplicationBtn;
    QPushButton *pointBtn;
    QPushButton *digitBtn0;
    QPushButton *signBtn;
    QPushButton *divisionBtn;
    QPushButton *sinBtn;
    QPushButton *cosBtn;
    QPushButton *logBtn;
    QPushButton *lnBtn;
    QPushButton *binBtn;
    QPushButton *gcdBtn;
    QPushButton *lcmBtn;
    QPushButton *DateBtn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(646, 680);
        action_v = new QAction(MainWindow);
        action_v->setObjectName(QStringLiteral("action_v"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_3->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 491, 171));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 180, 491, 431));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        clearBtn = new QPushButton(layoutWidget);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));

        gridLayout->addWidget(clearBtn, 0, 0, 1, 2);

        clearAllBtn = new QPushButton(layoutWidget);
        clearAllBtn->setObjectName(QStringLiteral("clearAllBtn"));

        gridLayout->addWidget(clearAllBtn, 0, 2, 1, 2);

        leftBracketBtn = new QPushButton(layoutWidget);
        leftBracketBtn->setObjectName(QStringLiteral("leftBracketBtn"));

        gridLayout->addWidget(leftBracketBtn, 1, 0, 1, 1);

        rightBracketBtn = new QPushButton(layoutWidget);
        rightBracketBtn->setObjectName(QStringLiteral("rightBracketBtn"));

        gridLayout->addWidget(rightBracketBtn, 1, 1, 1, 1);

        powBtn = new QPushButton(layoutWidget);
        powBtn->setObjectName(QStringLiteral("powBtn"));

        gridLayout->addWidget(powBtn, 1, 2, 1, 1);

        equalBtn = new QPushButton(layoutWidget);
        equalBtn->setObjectName(QStringLiteral("equalBtn"));

        gridLayout->addWidget(equalBtn, 1, 3, 1, 1);

        digitBtn1 = new QPushButton(layoutWidget);
        digitBtn1->setObjectName(QStringLiteral("digitBtn1"));

        gridLayout->addWidget(digitBtn1, 2, 0, 1, 1);

        digitBtn2 = new QPushButton(layoutWidget);
        digitBtn2->setObjectName(QStringLiteral("digitBtn2"));

        gridLayout->addWidget(digitBtn2, 2, 1, 1, 1);

        digitBtn3 = new QPushButton(layoutWidget);
        digitBtn3->setObjectName(QStringLiteral("digitBtn3"));

        gridLayout->addWidget(digitBtn3, 2, 2, 1, 1);

        addBtn = new QPushButton(layoutWidget);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        gridLayout->addWidget(addBtn, 2, 3, 1, 1);

        digitBtn4 = new QPushButton(layoutWidget);
        digitBtn4->setObjectName(QStringLiteral("digitBtn4"));

        gridLayout->addWidget(digitBtn4, 3, 0, 1, 1);

        digitBtn5 = new QPushButton(layoutWidget);
        digitBtn5->setObjectName(QStringLiteral("digitBtn5"));

        gridLayout->addWidget(digitBtn5, 3, 1, 1, 1);

        digitBtn6 = new QPushButton(layoutWidget);
        digitBtn6->setObjectName(QStringLiteral("digitBtn6"));

        gridLayout->addWidget(digitBtn6, 3, 2, 1, 1);

        subtractionBtn = new QPushButton(layoutWidget);
        subtractionBtn->setObjectName(QStringLiteral("subtractionBtn"));

        gridLayout->addWidget(subtractionBtn, 3, 3, 1, 1);

        digitBtn7 = new QPushButton(layoutWidget);
        digitBtn7->setObjectName(QStringLiteral("digitBtn7"));

        gridLayout->addWidget(digitBtn7, 4, 0, 1, 1);

        digitBtn8 = new QPushButton(layoutWidget);
        digitBtn8->setObjectName(QStringLiteral("digitBtn8"));

        gridLayout->addWidget(digitBtn8, 4, 1, 1, 1);

        digitBtn9 = new QPushButton(layoutWidget);
        digitBtn9->setObjectName(QStringLiteral("digitBtn9"));

        gridLayout->addWidget(digitBtn9, 4, 2, 1, 1);

        multiplicationBtn = new QPushButton(layoutWidget);
        multiplicationBtn->setObjectName(QStringLiteral("multiplicationBtn"));

        gridLayout->addWidget(multiplicationBtn, 4, 3, 1, 1);

        pointBtn = new QPushButton(layoutWidget);
        pointBtn->setObjectName(QStringLiteral("pointBtn"));

        gridLayout->addWidget(pointBtn, 5, 0, 1, 1);

        digitBtn0 = new QPushButton(layoutWidget);
        digitBtn0->setObjectName(QStringLiteral("digitBtn0"));

        gridLayout->addWidget(digitBtn0, 5, 1, 1, 1);

        signBtn = new QPushButton(layoutWidget);
        signBtn->setObjectName(QStringLiteral("signBtn"));

        gridLayout->addWidget(signBtn, 5, 2, 1, 1);

        divisionBtn = new QPushButton(layoutWidget);
        divisionBtn->setObjectName(QStringLiteral("divisionBtn"));

        gridLayout->addWidget(divisionBtn, 5, 3, 1, 1);

        sinBtn = new QPushButton(layoutWidget);
        sinBtn->setObjectName(QStringLiteral("sinBtn"));

        gridLayout->addWidget(sinBtn, 6, 0, 1, 1);

        cosBtn = new QPushButton(layoutWidget);
        cosBtn->setObjectName(QStringLiteral("cosBtn"));

        gridLayout->addWidget(cosBtn, 6, 1, 1, 1);

        logBtn = new QPushButton(layoutWidget);
        logBtn->setObjectName(QStringLiteral("logBtn"));

        gridLayout->addWidget(logBtn, 6, 2, 1, 1);

        lnBtn = new QPushButton(layoutWidget);
        lnBtn->setObjectName(QStringLiteral("lnBtn"));

        gridLayout->addWidget(lnBtn, 6, 3, 1, 1);

        binBtn = new QPushButton(layoutWidget);
        binBtn->setObjectName(QStringLiteral("binBtn"));

        gridLayout->addWidget(binBtn, 7, 0, 1, 1);

        gcdBtn = new QPushButton(layoutWidget);
        gcdBtn->setObjectName(QStringLiteral("gcdBtn"));

        gridLayout->addWidget(gcdBtn, 7, 1, 1, 1);

        lcmBtn = new QPushButton(layoutWidget);
        lcmBtn->setObjectName(QStringLiteral("lcmBtn"));

        gridLayout->addWidget(lcmBtn, 7, 2, 1, 1);

        DateBtn = new QPushButton(layoutWidget);
        DateBtn->setObjectName(QStringLiteral("DateBtn"));

        gridLayout->addWidget(DateBtn, 7, 3, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 8, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 9, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 10, 0, 1, 2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 11, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 646, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_v);
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addAction(action_3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_v->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\350\256\260\345\275\225", Q_NULLPTR));
        action_3->setText(QApplication::translate("MainWindow", "\347\247\221\345\255\246\350\256\241\347\256\227\345\231\250", Q_NULLPTR));
        clearBtn->setText(QApplication::translate("MainWindow", "clear", Q_NULLPTR));
        clearAllBtn->setText(QApplication::translate("MainWindow", "ClearAll", Q_NULLPTR));
        leftBracketBtn->setText(QApplication::translate("MainWindow", "(", Q_NULLPTR));
        rightBracketBtn->setText(QApplication::translate("MainWindow", ")", Q_NULLPTR));
        powBtn->setText(QApplication::translate("MainWindow", "^", Q_NULLPTR));
        equalBtn->setText(QApplication::translate("MainWindow", "=", Q_NULLPTR));
        digitBtn1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        digitBtn2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        digitBtn3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        addBtn->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        digitBtn4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        digitBtn5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        digitBtn6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        subtractionBtn->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        digitBtn7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        digitBtn8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        digitBtn9->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        multiplicationBtn->setText(QApplication::translate("MainWindow", "*", Q_NULLPTR));
        pointBtn->setText(QApplication::translate("MainWindow", ".", Q_NULLPTR));
        digitBtn0->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        signBtn->setText(QApplication::translate("MainWindow", "+/-", Q_NULLPTR));
        divisionBtn->setText(QApplication::translate("MainWindow", "/", Q_NULLPTR));
        sinBtn->setText(QApplication::translate("MainWindow", "sin", Q_NULLPTR));
        cosBtn->setText(QApplication::translate("MainWindow", "cos", Q_NULLPTR));
        logBtn->setText(QApplication::translate("MainWindow", "lg", Q_NULLPTR));
        lnBtn->setText(QApplication::translate("MainWindow", "ln", Q_NULLPTR));
        binBtn->setText(QApplication::translate("MainWindow", "Bin", Q_NULLPTR));
        gcdBtn->setText(QApplication::translate("MainWindow", "gcd", Q_NULLPTR));
        lcmBtn->setText(QApplication::translate("MainWindow", "lcm", Q_NULLPTR));
        DateBtn->setText(QApplication::translate("MainWindow", "Date", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "gcd:\346\234\200\345\244\247\345\205\254\347\272\246\346\225\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "lcm:\346\234\200\345\260\217\345\205\254\345\200\215\346\225\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "lg:\350\276\223\345\205\245\346\240\274\345\274\217\357\274\232lg a(b)", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Data\350\276\223\345\205\245\346\240\274\345\274\217\344\270\272\357\274\232\"yyyy/M/d\"", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\350\217\234\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
