/********************************************************************************
** Form generated from reading UI file 'frmtcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMTCPSERVER_H
#define UI_FRMTCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmTcpServer
{
public:
    QWidget *widget;
    QHBoxLayout *layTcpServer;
    QPushButton *btnUpgrate;
    QTextEdit *txtMain;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *labListenPort;
    QLineEdit *txtListenPort;
    QPushButton *btnListen;
    QPushButton *btnSave;
    QPushButton *btnClear;
    QLabel *labCount;
    QListWidget *listWidget;
    QCheckBox *ckAll;
    QPushButton *btnBrowser;
    QPushButton *btnConnect;
    QLineEdit *browseFileEdit;
    QLabel *labListenPort_2;
    QLabel *labListenPort_4;
    QLineEdit *fileSizeEdit;
    QLabel *labListenPort_3;
    QLabel *labListenPort_5;
    QLineEdit *oneSizeEdit;
    QLabel *labListenPort_6;
    QLabel *labListenPort_7;
    QLineEdit *sendingNumEdit;
    QLabel *labListenPort_8;
    QLabel *labListenPort_9;
    QLabel *labListenPort_10;
    QLineEdit *sendAllNumEdit;
    QLabel *labListenPort_11;
    QLineEdit *termialAddrEdit;
    QLabel *connectTerStatusLabe;

    void setupUi(QWidget *frmTcpServer)
    {
        if (frmTcpServer->objectName().isEmpty())
            frmTcpServer->setObjectName(QStringLiteral("frmTcpServer"));
        frmTcpServer->resize(519, 481);
        widget = new QWidget(frmTcpServer);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 900, 606, 23));
        layTcpServer = new QHBoxLayout(widget);
        layTcpServer->setObjectName(QStringLiteral("layTcpServer"));
        layTcpServer->setContentsMargins(0, 0, 0, 0);
        btnUpgrate = new QPushButton(frmTcpServer);
        btnUpgrate->setObjectName(QStringLiteral("btnUpgrate"));
        btnUpgrate->setGeometry(QRect(330, 450, 80, 23));
        btnUpgrate->setMinimumSize(QSize(80, 0));
        btnUpgrate->setMaximumSize(QSize(80, 16777215));
        txtMain = new QTextEdit(frmTcpServer);
        txtMain->setObjectName(QStringLiteral("txtMain"));
        txtMain->setGeometry(QRect(10, 11, 321, 341));
        txtMain->setReadOnly(true);
        frame = new QFrame(frmTcpServer);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(340, 11, 170, 341));
        frame->setMinimumSize(QSize(170, 0));
        frame->setMaximumSize(QSize(170, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(9, 9, 9, 9);
        labListenPort = new QLabel(frame);
        labListenPort->setObjectName(QStringLiteral("labListenPort"));

        verticalLayout_3->addWidget(labListenPort);

        txtListenPort = new QLineEdit(frame);
        txtListenPort->setObjectName(QStringLiteral("txtListenPort"));

        verticalLayout_3->addWidget(txtListenPort);

        btnListen = new QPushButton(frame);
        btnListen->setObjectName(QStringLiteral("btnListen"));

        verticalLayout_3->addWidget(btnListen);

        btnSave = new QPushButton(frame);
        btnSave->setObjectName(QStringLiteral("btnSave"));

        verticalLayout_3->addWidget(btnSave);

        btnClear = new QPushButton(frame);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        verticalLayout_3->addWidget(btnClear);

        labCount = new QLabel(frame);
        labCount->setObjectName(QStringLiteral("labCount"));
        labCount->setMinimumSize(QSize(0, 25));
        labCount->setFrameShape(QFrame::Box);
        labCount->setFrameShadow(QFrame::Sunken);
        labCount->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labCount);

        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_3->addWidget(listWidget);

        ckAll = new QCheckBox(frame);
        ckAll->setObjectName(QStringLiteral("ckAll"));

        verticalLayout_3->addWidget(ckAll);

        btnBrowser = new QPushButton(frmTcpServer);
        btnBrowser->setObjectName(QStringLiteral("btnBrowser"));
        btnBrowser->setGeometry(QRect(430, 360, 80, 23));
        btnBrowser->setMinimumSize(QSize(80, 0));
        btnBrowser->setMaximumSize(QSize(80, 16777215));
        btnConnect = new QPushButton(frmTcpServer);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(230, 450, 80, 23));
        btnConnect->setMinimumSize(QSize(80, 0));
        btnConnect->setMaximumSize(QSize(80, 16777215));
        browseFileEdit = new QLineEdit(frmTcpServer);
        browseFileEdit->setObjectName(QStringLiteral("browseFileEdit"));
        browseFileEdit->setEnabled(true);
        browseFileEdit->setGeometry(QRect(70, 360, 351, 20));
        browseFileEdit->setReadOnly(false);
        labListenPort_2 = new QLabel(frmTcpServer);
        labListenPort_2->setObjectName(QStringLiteral("labListenPort_2"));
        labListenPort_2->setGeometry(QRect(10, 360, 81, 21));
        labListenPort_4 = new QLabel(frmTcpServer);
        labListenPort_4->setObjectName(QStringLiteral("labListenPort_4"));
        labListenPort_4->setGeometry(QRect(190, 390, 41, 21));
        fileSizeEdit = new QLineEdit(frmTcpServer);
        fileSizeEdit->setObjectName(QStringLiteral("fileSizeEdit"));
        fileSizeEdit->setEnabled(false);
        fileSizeEdit->setGeometry(QRect(70, 390, 101, 20));
        labListenPort_3 = new QLabel(frmTcpServer);
        labListenPort_3->setObjectName(QStringLiteral("labListenPort_3"));
        labListenPort_3->setGeometry(QRect(10, 390, 61, 21));
        labListenPort_5 = new QLabel(frmTcpServer);
        labListenPort_5->setObjectName(QStringLiteral("labListenPort_5"));
        labListenPort_5->setGeometry(QRect(260, 390, 81, 21));
        oneSizeEdit = new QLineEdit(frmTcpServer);
        oneSizeEdit->setObjectName(QStringLiteral("oneSizeEdit"));
        oneSizeEdit->setEnabled(true);
        oneSizeEdit->setGeometry(QRect(340, 390, 101, 20));
        labListenPort_6 = new QLabel(frmTcpServer);
        labListenPort_6->setObjectName(QStringLiteral("labListenPort_6"));
        labListenPort_6->setGeometry(QRect(460, 390, 41, 21));
        labListenPort_7 = new QLabel(frmTcpServer);
        labListenPort_7->setObjectName(QStringLiteral("labListenPort_7"));
        labListenPort_7->setGeometry(QRect(10, 420, 61, 21));
        sendingNumEdit = new QLineEdit(frmTcpServer);
        sendingNumEdit->setObjectName(QStringLiteral("sendingNumEdit"));
        sendingNumEdit->setEnabled(false);
        sendingNumEdit->setGeometry(QRect(70, 420, 101, 20));
        labListenPort_8 = new QLabel(frmTcpServer);
        labListenPort_8->setObjectName(QStringLiteral("labListenPort_8"));
        labListenPort_8->setGeometry(QRect(190, 420, 41, 21));
        labListenPort_9 = new QLabel(frmTcpServer);
        labListenPort_9->setObjectName(QStringLiteral("labListenPort_9"));
        labListenPort_9->setGeometry(QRect(260, 420, 71, 21));
        labListenPort_10 = new QLabel(frmTcpServer);
        labListenPort_10->setObjectName(QStringLiteral("labListenPort_10"));
        labListenPort_10->setGeometry(QRect(460, 420, 41, 21));
        sendAllNumEdit = new QLineEdit(frmTcpServer);
        sendAllNumEdit->setObjectName(QStringLiteral("sendAllNumEdit"));
        sendAllNumEdit->setEnabled(false);
        sendAllNumEdit->setGeometry(QRect(340, 420, 101, 20));
        labListenPort_11 = new QLabel(frmTcpServer);
        labListenPort_11->setObjectName(QStringLiteral("labListenPort_11"));
        labListenPort_11->setGeometry(QRect(10, 450, 61, 21));
        termialAddrEdit = new QLineEdit(frmTcpServer);
        termialAddrEdit->setObjectName(QStringLiteral("termialAddrEdit"));
        termialAddrEdit->setEnabled(true);
        termialAddrEdit->setGeometry(QRect(80, 450, 141, 20));
        connectTerStatusLabe = new QLabel(frmTcpServer);
        connectTerStatusLabe->setObjectName(QStringLiteral("connectTerStatusLabe"));
        connectTerStatusLabe->setGeometry(QRect(420, 450, 91, 21));

        retranslateUi(frmTcpServer);

        QMetaObject::connectSlotsByName(frmTcpServer);
    } // setupUi

    void retranslateUi(QWidget *frmTcpServer)
    {
        frmTcpServer->setWindowTitle(QApplication::translate("frmTcpServer", "Form", 0));
        btnUpgrate->setText(QApplication::translate("frmTcpServer", "\345\234\250\347\272\277\345\215\207\347\272\247", 0));
        labListenPort->setText(QApplication::translate("frmTcpServer", "\347\233\221\345\220\254\347\253\257\345\217\243", 0));
        btnListen->setText(QApplication::translate("frmTcpServer", "\347\233\221\345\220\254", 0));
        btnSave->setText(QApplication::translate("frmTcpServer", "\344\277\235\345\255\230", 0));
        btnClear->setText(QApplication::translate("frmTcpServer", "\346\270\205\347\251\272", 0));
        labCount->setText(QApplication::translate("frmTcpServer", "\345\205\261 0 \344\270\252\350\277\236\346\216\245", 0));
        ckAll->setText(QApplication::translate("frmTcpServer", "\345\257\271\345\205\250\351\203\250\345\256\242\346\210\267\347\253\257\345\217\221\351\200\201", 0));
        btnBrowser->setText(QApplication::translate("frmTcpServer", "\346\265\217\350\247\210", 0));
        btnConnect->setText(QApplication::translate("frmTcpServer", "\350\277\236\346\216\245\350\256\276\345\244\207", 0));
        labListenPort_2->setText(QApplication::translate("frmTcpServer", "\345\215\207\347\272\247\346\226\207\344\273\266", 0));
        labListenPort_4->setText(QApplication::translate("frmTcpServer", "Bytes", 0));
        labListenPort_3->setText(QApplication::translate("frmTcpServer", "\346\226\207\344\273\266\345\244\247\345\260\217", 0));
        labListenPort_5->setText(QApplication::translate("frmTcpServer", "\345\215\225\346\254\241\345\217\221\351\200\201\351\225\277\345\272\246", 0));
        labListenPort_6->setText(QApplication::translate("frmTcpServer", "Bytes", 0));
        labListenPort_7->setText(QApplication::translate("frmTcpServer", "\346\255\243\345\217\221\351\200\201\347\254\254", 0));
        labListenPort_8->setText(QApplication::translate("frmTcpServer", "\346\235\241", 0));
        labListenPort_9->setText(QApplication::translate("frmTcpServer", "\345\205\261\345\217\221\351\200\201", 0));
        labListenPort_10->setText(QApplication::translate("frmTcpServer", "\346\235\241", 0));
        labListenPort_11->setText(QApplication::translate("frmTcpServer", "\350\256\276\345\244\207\347\274\226\345\217\267", 0));
        connectTerStatusLabe->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class frmTcpServer: public Ui_frmTcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMTCPSERVER_H
