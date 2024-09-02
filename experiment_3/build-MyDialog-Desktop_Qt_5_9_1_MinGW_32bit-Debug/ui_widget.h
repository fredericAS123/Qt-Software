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
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *filedialog;
    QPushButton *colordialog;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *typefacedialog;
    QPushButton *inputdialog;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(387, 375);
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        filedialog = new QPushButton(Widget);
        filedialog->setObjectName(QStringLiteral("filedialog"));

        horizontalLayout->addWidget(filedialog);

        colordialog = new QPushButton(Widget);
        colordialog->setObjectName(QStringLiteral("colordialog"));

        horizontalLayout->addWidget(colordialog);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        typefacedialog = new QPushButton(Widget);
        typefacedialog->setObjectName(QStringLiteral("typefacedialog"));

        horizontalLayout_2->addWidget(typefacedialog);

        inputdialog = new QPushButton(Widget);
        inputdialog->setObjectName(QStringLiteral("inputdialog"));

        horizontalLayout_2->addWidget(inputdialog);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        filedialog->setText(QApplication::translate("Widget", "\346\226\207\344\273\266\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        colordialog->setText(QApplication::translate("Widget", "\351\242\234\350\211\262\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        typefacedialog->setText(QApplication::translate("Widget", "\345\255\227\344\275\223\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        inputdialog->setText(QApplication::translate("Widget", "\350\276\223\345\205\245\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
