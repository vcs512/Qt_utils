/********************************************************************************
** Form generated from reading UI file 'inported_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPORTED_UI_H
#define UI_INPORTED_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inported_ui
{
public:
    QWidget *widget;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *inported_ui)
    {
        if (inported_ui->objectName().isEmpty())
            inported_ui->setObjectName(QString::fromUtf8("inported_ui"));
        inported_ui->resize(400, 300);
        widget = new QWidget(inported_ui);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 20, 191, 141));
        widget1 = new QWidget(widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 40, 92, 42));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);


        retranslateUi(inported_ui);

        QMetaObject::connectSlotsByName(inported_ui);
    } // setupUi

    void retranslateUi(QWidget *inported_ui)
    {
        inported_ui->setWindowTitle(QApplication::translate("inported_ui", "Form", nullptr));
        pushButton->setText(QApplication::translate("inported_ui", "Imported_button", nullptr));
        label->setText(QApplication::translate("inported_ui", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inported_ui: public Ui_inported_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPORTED_UI_H
