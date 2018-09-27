#include "frmtcpserver.h"
#include "ui_frmtcpserver.h"
#include "quiwidget.h"
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

frmTcpServer::frmTcpServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmTcpServer)
{
    ui->setupUi(this);

    initForm();
    ui->connectTerStatusLabe->setStyleSheet("font:bold;font-size:12px;/*font-family:宋体*/");
}

frmTcpServer::~frmTcpServer()
{
    delete ui;
}


void frmTcpServer::initForm()
{
    isOk = false;
    tcpServer = new TcpServer(this);
    connect(tcpServer, SIGNAL(clientConnected(QString, int)), this, SLOT(clientConnected(QString, int)));
    connect(tcpServer, SIGNAL(clientDisconnected(QString, int)), this, SLOT(clientDisconnected(QString, int)));
    connect(tcpServer, SIGNAL(sendData(QString, int, QString)), this, SLOT(sendData(QString, int, QString)));
    connect(tcpServer, SIGNAL(receiveData(QString, int, QString)), this, SLOT(receiveData(QString, int, QString)));

    QUIHelper::setLabStyle(ui->labCount, 3);

}

void frmTcpServer::append(int type, const QString &data, bool clear)
{
    static int currentCount = 0;
    static int maxCount = 100;

    if (clear)
    {
        ui->txtMain->clear();
        currentCount = 0;
        return;
    }

    if (currentCount >= maxCount) {
        ui->txtMain->clear();
        currentCount = 0;
    }

//    if (ui->ckShow->isChecked()) {
//        return;
//    }

    //过滤回车换行符
    QString strData = data;
    strData = strData.replace("\r", "");
    strData = strData.replace("\n", "");

    //不同类型不同颜色显示
    QString strType;
    if (type == 0)
    {
        strType = "发送";
        ui->txtMain->setTextColor(QColor("darkgreen"));
    }
    else
    {
        strType = "接收";
        ui->txtMain->setTextColor(QColor("red"));
    }

    strData = QString("时间[%1] %2: %3").arg(TIMEMS).arg(strType).arg(strData);
    ui->txtMain->append(strData);
    currentCount++;
}

void frmTcpServer::sendConnectPro()
{
    short i=0,pos=0;
    unsigned short sendLen = 0;              //发送终端连接的数据长度
    unsigned char sendBuf[50] = {0};         //


    sendBuf[sendLen++] = 0x3c;          //起始帧
    sendBuf[sendLen++] = 0x23;          //版本号

    pos = sendLen;
    sendBuf[sendLen++] = 0;             //数据总长度
    sendBuf[sendLen++] = 0;             //数据总长度

    sendBuf[sendLen++] = TerminalAddrLength;       //地址长度
    //地址
    for(i=0;i<TerminalAddrLength;i++)
        sendBuf[sendLen++] = TerminalAddr[i];

    sendBuf[sendLen++] = 1;     //帧号
    sendBuf[sendLen++] = 1;     //指令方向
    sendBuf[sendLen++] = 0xA1;  //指令码
    sendBuf[sendLen++] = 0x30;          //连接终端功能码
    sendBuf[sendLen++] = 2;     //指令版本
    unsigned char datalen = 0,transbuf[5]={0},desbuf[5]={0};

    //数据总长度
    datalen = classCRC.change_DEC_to_HEX(upgradeSize,transbuf);
    classCRC.char_string_right(transbuf,datalen,desbuf,4);
    sendBuf[sendLen++] = desbuf[0];
    sendBuf[sendLen++] = desbuf[1];
    sendBuf[sendLen++] = desbuf[2];
    sendBuf[sendLen++] = desbuf[3];

    //发送总次数
    sendBuf[sendLen++] = allSendNum;

    //单次发送数据长度
    datalen = classCRC.change_DEC_to_HEX(oneSendLen,transbuf);
    classCRC.char_string_right(transbuf,datalen,desbuf,2);
    sendBuf[sendLen++] = desbuf[0];
    sendBuf[sendLen++] = desbuf[1];

    //最后一次发送数据长度
    datalen = classCRC.change_DEC_to_HEX(lastLefByte,transbuf);
    classCRC.char_string_right(transbuf,datalen,desbuf,2);
    sendBuf[sendLen++] = desbuf[0];
    sendBuf[sendLen++] = desbuf[1];

    datalen = classCRC.change_DEC_to_HEX(sendLen + 3,transbuf);     //协议数据长度
    classCRC.char_string_right(transbuf,datalen,desbuf,2);
    sendBuf[pos] = desbuf[0];
    sendBuf[pos+1] = desbuf[1];

    //计算CRC
    classCRC.CRC16(&sendBuf[1],sendLen - 1);
    sendBuf[sendLen++] = classCRC.uchCRCLo;
    sendBuf[sendLen++] = classCRC.uchCRCHi;

    sendBuf[sendLen++] = 0x3e;      //协议尾
    ui->connectTerStatusLabe->setText((tr("设备未连接")));

}

void frmTcpServer::sendUpgradePro()
{
    unsigned short i = 0, pos = 0;
    unsigned char sendBuf[1200] = {0};
    unsigned short sendLen = 0;              //发送升级程序的数据长度
    unsigned char datalen = 0, transbuf[5] = {0}, desbuf[5] = {0};
    unsigned short length = 0;
    char * Byte = nullptr;

    if(sendingNum > allSendNum)     //发送完毕
    {
        sendUpgradeProFlag = 0;
        return;
    }
//    QString count = QString().sprintf("发送第%d条",sendingNum);
//    ui->connectTerStatusLabe->setText(count);

    if(sendingNum < allSendNum)
        length = oneSendLen;
    else
        length = lastLefByte + 2;   //添加2个字节的结束标志，用来检查程序的完整
#if 1
    QFile upgradeFile(FilePath);
    bool openOK = upgradeFile.open(QIODevice::ReadOnly);
    if(openOK)//文件打开
    {
        QDataStream outdata(&upgradeFile);
        outdata.setVersion(QDataStream::Qt_5_6);
        Byte = new char[1100];

        int seekpos = (sendingNum - 1) * oneSendLen;
        upgradeFile.seek(seekpos);
        outdata.readRawData(Byte,length);//读出文件到缓存
        upgradeFile.close();
    }
#endif

    //发送第一条
    sendBuf[sendLen++] = 0x3c;          //起始帧
    sendBuf[sendLen++] = 0x23;          //版本号

    pos = sendLen;
    sendBuf[sendLen++] = 0;             //数据总长度
    sendBuf[sendLen++] = 0;             //数据总长度

    sendBuf[sendLen++] = TerminalAddrLength;       //地址长度
    //地址
    for(i=0;i<TerminalAddrLength;i++)
        sendBuf[sendLen++] = TerminalAddr[i];

    sendBuf[sendLen++] = 1;     //帧号
    sendBuf[sendLen++] = 1;     //指令方向
    sendBuf[sendLen++] = 0xA1;  //指令码
    sendBuf[sendLen++] = 0x32;          //连接终端功能码
    sendBuf[sendLen++] = 2;     //指令版本

    datalen = classCRC.change_DEC_to_HEX(sendingNum,transbuf);  //当前正在发送的第几条
    classCRC.char_string_right(transbuf,datalen,desbuf,2);
    sendBuf[sendLen++] = desbuf[0];
    sendBuf[sendLen++] = desbuf[1];

    datalen = classCRC.change_DEC_to_HEX(length,transbuf);  //数据段长度
    classCRC.char_string_right(transbuf,datalen,desbuf,2);
    sendBuf[sendLen++] = desbuf[0];
    sendBuf[sendLen++] = desbuf[1];

    //升级程序部分
#if 1
    if(sendingNum < allSendNum)                     //不是最后一次发送
    {
        for(i = 0; i < oneSendLen; i++)
            sendBuf[sendLen++] = Byte[i];
    }
    else if(sendingNum == allSendNum)               //最后一次
    {
        for(i=0;i<lastLefByte;i++)
            sendBuf[sendLen++] = Byte[i];
        sendBuf[sendLen++] = 0xAA;      //最后添加两个字节的结束标志
        sendBuf[sendLen++] = 0xAA;
    }
#else
    unsigned int startByte = (sendingNum - 1) * oneSendLen;
    if(sendingNum < allSendNum)                     //不是最后一次发送
    {
        for(i = 0; i < oneSendLen; i++)
            sendBuf[sendLen++] = binByte[startByte + i];
    }
    else if(sendingNum == allSendNum)               //最后一次
    {
        for(i=0;i<lastLefByte;i++)
            sendBuf[sendLen++] = binByte[startByte + i];
        sendBuf[sendLen++] = 0xAA;      //最后添加两个字节的结束标志
        sendBuf[sendLen++] = 0xAA;
    }
#endif
    datalen = classCRC.change_DEC_to_HEX(sendLen + 3,transbuf);     //协议数据长度
    classCRC.char_string_right(transbuf,datalen,desbuf,2);
    sendBuf[pos] = desbuf[0];
    sendBuf[pos+1] = desbuf[1];

    //计算CRC
    classCRC.CRC16(&sendBuf[1],sendLen - 1);
    sendBuf[sendLen++] = classCRC.uchCRCLo;
    sendBuf[sendLen++] = classCRC.uchCRCHi;

    sendBuf[sendLen++] = 0x3e;      //协议尾

//    my_serialport->clear();
//    my_serialport->write((char*)sendBuf,sendLen);

    ui->sendingNumEdit->setText(QString::number(sendingNum));
    recUpgradeTimeout = 0;
    recLength = 0;

}

void frmTcpServer::clientConnected(const QString &ip, int port)
{
    QString str = QString("%1:%2").arg(ip).arg(port);
    ui->listWidget->addItem(str);
    ui->labCount->setText(QString("共 %1 个连接").arg(ui->listWidget->count()));
}

void frmTcpServer::clientDisconnected(const QString &ip, int port)
{
    int row = -1;
    QString str = QString("%1:%2").arg(ip).arg(port);
    for (int i = 0; i < ui->listWidget->count(); i++)
    {
        if (ui->listWidget->item(i)->text() == str)
        {
            row = i;
            break;
        }
    }

    ui->listWidget->takeItem(row);
    ui->labCount->setText(QString("共 %1 个连接").arg(ui->listWidget->count()));
}

void frmTcpServer::sendData(const QString &ip, int port, const QString &data)
{
    QString str = QString("[%1:%2] %3").arg(ip).arg(port).arg(data);
    bool error = (data.contains("下线") || data.contains("离线"));
    append(error ? 1 : 0, str);
}

void frmTcpServer::receiveData(const QString &ip, int port, const QString &data)
{
    QString str = QString("[%1:%2] %3").arg(ip).arg(port).arg(data);
    append(1, str);
}




void frmTcpServer::on_btnListen_clicked()
{
    if (ui->btnListen->text() == "监听")
    {
        isOk = tcpServer->start();
        if (isOk)
        {
            append(0, "监听成功");
            ui->btnListen->setText("关闭");
        }
    }
    else
    {
        isOk = false;
        tcpServer->stop();
        ui->btnListen->setText("监听");
    }
}

void frmTcpServer::on_btnClear_clicked()
{
    append(0, "", true);
}

void frmTcpServer::on_btnBrowser_clicked()
{
    //获取升级文件（bin）名称
     QString upgradeFileName = QFileDialog::getOpenFileName(this,"OpenFile",QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),tr("升级文件 (*.bin *.hex);;所有文件(*.*)"));//获取桌面路径
     if(upgradeFileName.isNull())//未点击文件
     {
 //        QMessageBox::information(this,"错误",QWidget::tr("请选择文件"));
         return;
     }
     if(upgradeFileName.isEmpty())//未点击文件
     {
         QMessageBox::information(this,"错误",QWidget::tr("请选择文件"));
         return;
     }

     QFile *upgradeFile = new QFile;
     upgradeFile->setFileName(upgradeFileName);
     bool openOK = upgradeFile->open(QIODevice::ReadOnly);
     if(openOK)//文件打开
    {
        QString *programHex;
        QString toBeShow;

        QFileInfo upgradeInfo = QFileInfo(upgradeFileName);
        upgradeSize = upgradeInfo.size();
        ui->browseFileEdit->clear();
        FilePath = upgradeInfo.absoluteFilePath();
        ui->browseFileEdit->setText(FilePath);    //显示路径

        ui->fileSizeEdit->clear();
        ui->fileSizeEdit->setText(QString::number(upgradeSize/*,10*/)); //  显示文件大小

        QDataStream outdata(upgradeFile);
        outdata.setVersion(QDataStream::Qt_5_6);
 #if 1
        binByte = new char[upgradeSize];
        outdata.readRawData(binByte,upgradeSize);//读出文件到缓存
        sendHexByte = new QByteArray(binByte,upgradeSize);//格式转换
        programHex = new QString(sendHexByte->toHex ().toUpper ());//toUpper把小写字母转化成大写
//        ui->displayBinEdit->appendPlainText(*programHex);//直接显示，没有空格
        for(/*auto*/QString::iterator it = programHex->begin(); it != programHex->end(); ++it)//运行结果和ultra打开的结果一致
        {
            toBeShow.append(*it++).append(*it).append(" ");
        }
        ui->txtMain->append(toBeShow);//plaintext中显示数据
#else
        binByte = new char[8192];
        int count = upgradeSize / 8192;
        int leftlen = upgradeSize % 8192;
        if(leftlen > 0)
            count ++;
        QString::iterator it;
        int readlen = 0;
        for(int i = 0; i < count; i++)
        {
            if(i < count - 1)
                readlen = 8192;
            else
                readlen = leftlen;

            upgradeFile->seek(i * 8192);
            outdata.readRawData(binByte,readlen);//读出文件到缓存
            sendHexByte = new QByteArray(binByte,readlen);//格式转换
            programHex = new QString(sendHexByte->toHex ().toUpper ());//toUpper把小写字母转化成大写
            for(/*auto*/it = programHex->begin(); it != programHex->end(); ++it)//运行结果和ultra打开的结果一致
            {
                toBeShow.append(*it++).append(*it).append(" ");
            }
            ui->txtMain->append(toBeShow);//plaintext中显示数据
        }
#endif
        upgradeFile->close();
        delete upgradeFile;
    }
    else//打开失败
    {
        QMessageBox::information(this,QWidget::tr("错误"),QWidget::tr("打开文件失败")+upgradeFile->errorString());
        return;
    }
}

void frmTcpServer::on_btnConnect_clicked()
{
    QString sendAddressString = ui->termialAddrEdit->text();

    if(sendAddressString.isEmpty())
    {
//        QMessageBox::warning(this,tr("错误"),tr("请输入终端地址"));
//        return;
        sendAddressString = "80808080";
    }
    TerminalAddrLength = sendAddressString.size();
    unsigned char i = 0;
    for(i = 0;i < TerminalAddrLength; i++)
         TerminalAddr[i] = sendAddressString.at(i).toLatin1();

    if(upgradeSize == 0)    //未打开文件
    {
        QMessageBox::warning(this,tr("错误"),tr("请选择升级程序"));
        return;
    }
    //获取单次发送长度
    if(ui->oneSizeEdit->text().isEmpty())
    {
        oneSendLen = ONELENGTH;
        ui->oneSizeEdit->setText(QString::number(oneSendLen));      //显示
    }
    else
        oneSendLen  = ui->oneSizeEdit->text().toShort();

    allSendNum = (unsigned short)(upgradeSize / oneSendLen);
    lastLefByte = upgradeSize % oneSendLen;
    if(lastLefByte > 0)
        allSendNum ++;
    ui->sendAllNumEdit->setText(QString::number(allSendNum));      //显示

    TimeoutNum = 0;

    sendConnectPro();

}

void frmTcpServer::on_btnUpgrate_clicked()
{
    //确定打开升级程序
    if(upgradeSize == 0)
    {
        QMessageBox::warning(this,tr("错误"),tr("请先打开升级程序"));
        return;
    }
    //判断是否已连接
    if(terminalOnlineFlag != 1)
    {
        QMessageBox::warning(this,tr("错误"),tr("请先连接终端设备"));
        return;
    }

    //获取单次发送长度
    if(ui->oneSizeEdit->text().isEmpty())
    {
        oneSendLen = ONELENGTH;
        ui->oneSizeEdit->setText(QString::number(oneSendLen));      //显示
    }
    else
        oneSendLen  = ui->oneSizeEdit->text().toShort();

    allSendNum = 0;
    allSendNum = (unsigned short)(upgradeSize / oneSendLen);
    lastLefByte = upgradeSize % oneSendLen;
    if(lastLefByte > 0)
        allSendNum ++;
    ui->sendAllNumEdit->setText(QString::number(allSendNum));      //显示

    sendUpgradeProFlag = 1;                                     //发送升级程序标志

    UpgradeTimeoutNum = 0;
    sendingNum = 1;
    sendUpgradePro();                                          //发送第1条

}
