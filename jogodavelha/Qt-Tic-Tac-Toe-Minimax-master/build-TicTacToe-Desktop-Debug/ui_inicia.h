/********************************************************************************
** Form generated from reading UI file 'inicia.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIA_H
#define UI_INICIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inicia
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *inicia)
    {
        if (inicia->objectName().isEmpty())
            inicia->setObjectName(QStringLiteral("inicia"));
        inicia->resize(400, 300);
        pushButton = new QPushButton(inicia);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 100, 101, 23));
        pushButton_2 = new QPushButton(inicia);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 170, 101, 23));

        retranslateUi(inicia);

        QMetaObject::connectSlotsByName(inicia);
    } // setupUi

    void retranslateUi(QWidget *inicia)
    {
        inicia->setWindowTitle(QApplication::translate("inicia", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("inicia", "player start", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("inicia", "computer start", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class inicia: public Ui_inicia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIA_H
