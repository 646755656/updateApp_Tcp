#include "frmmain.h"
#include "ui_frmmain.h"

frmmain::frmmain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmmain)
{
    ui->setupUi(this);
//    setWindowIcon(QIcon(":/image/main.ico"));
    setWindowTitle(QString("出水口在线升级工具TCP版本"));

    ui->tabWidget->setCurrentIndex(0);

}

frmmain::~frmmain()
{
    delete ui;
}
