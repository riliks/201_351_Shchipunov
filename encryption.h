#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "QByteArray"
#include "QString"
#include "qaesencryption.h"

class crypto
{
public:
    crypto();
    static QByteArray getKey(QString plainKey);
    static QByteArray getIV(QString plainIV);
    static QByteArray encrypt(QByteArray text, QString key, QString iv);
    static QString decrypt(QByteArray text, QString key, QString iv);
    static QAESEncryption encryption;
};

#endif // ENCRYPTION_H
