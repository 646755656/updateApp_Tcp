#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>

namespace Ui {
class frmmain;
}

class frmmain : public QWidget
{
    Q_OBJECT

public:
    explicit frmmain(QWidget *parent = 0);
    ~frmmain();

private:
    Ui::frmmain *ui;
};

#endif // FRMMAIN_H
