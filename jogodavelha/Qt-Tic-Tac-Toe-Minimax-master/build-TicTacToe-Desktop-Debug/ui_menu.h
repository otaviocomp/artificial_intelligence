/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *dificil;
    QPushButton *facil;

    void setupUi(QWidget *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(400, 300);
        label = new QLabel(menu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 30, 191, 31));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label_2 = new QLabel(menu);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 70, 161, 16));
        dificil = new QPushButton(menu);
        dificil->setObjectName(QStringLiteral("dificil"));
        dificil->setGeometry(QRect(160, 180, 80, 23));
        facil = new QPushButton(menu);
        facil->setObjectName(QStringLiteral("facil"));
        facil->setGeometry(QRect(160, 140, 80, 23));

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("menu", "tictactoe (jogo da velha)", Q_NULLPTR));
        label_2->setText(QApplication::translate("menu", "selecione a dificuldade", Q_NULLPTR));
        dificil->setText(QApplication::translate("menu", "dif\303\255cil", Q_NULLPTR));
        facil->setText(QApplication::translate("menu", "f\303\241cil", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
