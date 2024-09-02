/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *widget_3;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button9;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(422, 300);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 50, 20);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setCheckable(false);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout_2->addWidget(pushButton_6);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(Widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        button7 = new QPushButton(widget_3);
        button7->setObjectName(QStringLiteral("button7"));
        button7->setGeometry(QRect(30, 10, 93, 28));
        button8 = new QPushButton(widget_3);
        button8->setObjectName(QStringLiteral("button8"));
        button8->setGeometry(QRect(140, 30, 93, 28));
        button9 = new QPushButton(widget_3);
        button9->setObjectName(QStringLiteral("button9"));
        button9->setGeometry(QRect(260, 50, 93, 28));

        verticalLayout->addWidget(widget_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", " Widget_QBoxLayout", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "4376", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "\347\216\213\350\205\276\350\266\212", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Widget", "\347\224\267", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Widget", "six", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Widget", "five", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Widget", "four", Q_NULLPTR));
        button7->setText(QApplication::translate("Widget", "seven", Q_NULLPTR));
        button8->setText(QApplication::translate("Widget", "eight", Q_NULLPTR));
        button9->setText(QApplication::translate("Widget", "nine", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
