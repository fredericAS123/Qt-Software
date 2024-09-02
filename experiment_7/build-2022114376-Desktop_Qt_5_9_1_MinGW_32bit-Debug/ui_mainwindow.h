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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QRadioButton *man;
    QRadioButton *radioButton_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QSpinBox *age;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QSpinBox *height;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QDoubleSpinBox *weight;
    QPushButton *pushButton;
    QLineEdit *BMI;
    QLineEdit *conclusion;
    QPushButton *clear;
    QTextEdit *history;
    QLineEdit *suggestion;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(614, 644);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 165, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        man = new QRadioButton(widget);
        man->setObjectName(QStringLiteral("man"));

        horizontalLayout->addWidget(man);

        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 40, 611, 266));
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        age = new QSpinBox(widget_3);
        age->setObjectName(QStringLiteral("age"));

        verticalLayout->addWidget(age);


        verticalLayout_5->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        height = new QSpinBox(widget_4);
        height->setObjectName(QStringLiteral("height"));
        height->setMaximum(1002);
        height->setSingleStep(1);

        verticalLayout_2->addWidget(height);


        verticalLayout_5->addWidget(widget_4);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_4->addWidget(label_5);

        weight = new QDoubleSpinBox(widget_5);
        weight->setObjectName(QStringLiteral("weight"));
        weight->setMaximum(1000);

        verticalLayout_4->addWidget(weight);


        verticalLayout_5->addWidget(widget_5);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_5->addWidget(pushButton);

        BMI = new QLineEdit(centralWidget);
        BMI->setObjectName(QStringLiteral("BMI"));
        BMI->setGeometry(QRect(10, 310, 591, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        BMI->setFont(font);
        conclusion = new QLineEdit(centralWidget);
        conclusion->setObjectName(QStringLiteral("conclusion"));
        conclusion->setGeometry(QRect(10, 380, 591, 31));
        clear = new QPushButton(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(10, 550, 591, 28));
        history = new QTextEdit(centralWidget);
        history->setObjectName(QStringLiteral("history"));
        history->setGeometry(QRect(10, 420, 581, 121));
        suggestion = new QLineEdit(centralWidget);
        suggestion->setObjectName(QStringLiteral("suggestion"));
        suggestion->setGeometry(QRect(300, 20, 291, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 614, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BMI\350\256\241\347\256\227\345\231\250\357\274\2102022114376\357\274\211", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        man->setText(QApplication::translate("MainWindow", "\347\224\267", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "\345\245\263", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\271\264\351\276\204\357\274\210\345\262\201\357\274\211:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\350\272\253\351\253\230\357\274\210\345\216\230\347\261\263\357\274\211:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\344\275\223\351\207\215\357\274\210\345\205\254\346\226\244\357\274\211:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227BMI\346\214\207\346\225\260", Q_NULLPTR));
        BMI->setText(QApplication::translate("MainWindow", "BMI\357\274\232", Q_NULLPTR));
        clear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
