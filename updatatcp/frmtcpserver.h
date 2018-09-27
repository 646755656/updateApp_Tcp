#ifndef FRMTCPSERVER_H
#define FRMTCPSERVER_H

#include <QWidget>
#include "tcpserver.h"
#include "crc16.h"


#define ONELENGTH 1024       //默认单次发送长度


namespace Ui {
class frmTcpServer;
}

class frmTcpServer : public QWidget
{
    Q_OBJECT

public:
    explicit frmTcpServer(QWidget *parent = 0);
    ~frmTcpServer();

private:
    Ui::frmTcpServer *ui;

    bool isOk;
    TcpServer *tcpServer;

    qint64 upgradeSize;
    QString FilePath = nullptr;
    char * binByte = nullptr;
    QByteArray *sendHexByte = nullptr;                            //升级程序的16进制数据

    unsigned char terminalOnlineFlag = 0;           //终端在线标志
    unsigned char sendConnectOrderFlag = 0;         //发送终端连接命令标志
    unsigned int SeriesTimeout = 0;                 //串口判断超时
    unsigned int DelayTime = 0;                     //串口收到数据有延时时间
    unsigned char TimeoutNum = 0;                   //超时计数器
    unsigned short recLength = 0;                   //接收到的数据长度
    unsigned short allSendNum = 0;                  //共要发送升级程序的条书
    unsigned short lastLefByte = 0;                 //最后一条剩余的未发送数据的长度
    unsigned short oneSendLen = 0;                  //每条发送的数据长度
    unsigned char sendUpgradeProFlag = 0;           //发送终端升级的标志
    unsigned short sendingNum = 1;                   //当前正在发送的条数
    unsigned int recUpgradeTimeout = 0;             //接收升级超时定时
    unsigned char UpgradeTimeoutNum = 0;            //接收升级超时次数
    unsigned char TerminalAddr[20] = {0};           //终端地址
    unsigned char TerminalAddrLength = 0;                   //终端地址长度

    crc16 classCRC;//调用外部类成员时，实例化一个对象



    void initForm();
    void initConfig();
    void append(int type, const QString &data, bool clear = false);
    void sendConnectPro();
    void sendUpgradePro();




private slots:
    void clientConnected(const QString &ip, int port);
    void clientDisconnected(const QString &ip, int port);
    void sendData(const QString &ip, int port, const QString &data);
    void receiveData(const QString &ip, int port, const QString &data);

    void on_btnListen_clicked();
    void on_btnClear_clicked();
    void on_btnBrowser_clicked();
    void on_btnConnect_clicked();
    void on_btnUpgrate_clicked();
};

#endif // FRMTCPSERVER_H
