#ifndef CRC16_H
#define CRC16_H

#include <QObject>


class crc16 : public QObject
{
    Q_OBJECT
public:
    explicit crc16(QObject *parent = 0);

    unsigned short CRC16(unsigned char *pParaData,unsigned int nLen);
    unsigned char uchCRCHi;
    unsigned char uchCRCLo;

    unsigned char change_DEC_to_HEX(unsigned int data, unsigned char *h_buff);
    void char_string_right(unsigned char *s_chr,unsigned int s_len,unsigned char *t_chr,int t_len);

signals:

public slots:
};

#endif // CRC16_H
