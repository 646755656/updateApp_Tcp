#include "frmmain.h"
#include <QApplication>
#include "quiwidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/other/main.ico"));

    QFont font;
    font.setFamily(QUIConfig::FontName);
    font.setPixelSize(QUIConfig::FontSize);
    a.setFont(font);

    //设置编码以及加载中文翻译文件
    QUIHelper::setCode();
    QUIHelper::setTranslator(":/other/qt_zh_CN.qm");
    QUIHelper::setTranslator(":/other/widgets.qm");
    QUIHelper::initRand();

//    App::Intervals << "1" << "10" << "20" << "50" << "100" << "200" << "300" << "500" << "1000" << "1500" << "2000" << "3000" << "5000" << "10000";
//    App::ConfigFile = QString("%1/%2.ini").arg(QUIHelper::appPath()).arg(QUIHelper::appName());
//    App::readConfig();
//    App::readSendData();
//    App::readDeviceData();

    frmmain w;
    w.show();

    return a.exec();
}
