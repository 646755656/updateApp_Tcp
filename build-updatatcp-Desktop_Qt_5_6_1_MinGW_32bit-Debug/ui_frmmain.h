/********************************************************************************
** Form generated from reading UI file 'frmmain.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAIN_H
#define UI_FRMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "frmtcpserver.h"

QT_BEGIN_NAMESPACE

class Ui_frmmain
{
public:
    QTabWidget *tabWidget;
    frmTcpServer *tabTCP;
    QWidget *tabSeries;

    void setupUi(QWidget *frmmain)
    {
        if (frmmain->objectName().isEmpty())
            frmmain->setObjectName(QStringLiteral("frmmain"));
        frmmain->resize(540, 527);
        tabWidget = new QTabWidget(frmmain);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 531, 521));
        tabWidget->setTabPosition(QTabWidget::South);
        tabTCP = new frmTcpServer();
        tabTCP->setObjectName(QStringLiteral("tabTCP"));
        tabWidget->addTab(tabTCP, QString());
        tabSeries = new QWidget();
        tabSeries->setObjectName(QStringLiteral("tabSeries"));
        tabWidget->addTab(tabSeries, QString());

        retranslateUi(frmmain);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmmain);
    } // setupUi

    void retranslateUi(QWidget *frmmain)
    {
        frmmain->setWindowTitle(QApplication::translate("frmmain", "frmmain", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabTCP), QApplication::translate("frmmain", "TCP\346\234\215\345\212\241\347\253\257", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabSeries), QApplication::translate("frmmain", "\344\270\262\345\217\243", 0));
    } // retranslateUi

};

namespace Ui {
    class frmmain: public Ui_frmmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
