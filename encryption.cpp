#include "encryption.h"
#include "QCryptographicHash"
#include "QDebug"

QAESEncryption crypto::encryption(QAESEncryption::AES_256, QAESEncryption::CBC);

QByteArray crypto::getKey(QString plainKey) {
    QByteArray keyByteArray = plainKey.toUtf8();
    QByteArray resKey = QCryptographicHash::hash(keyByteArray, QCryptographicHash::Sha256).toBase64();
    return resKey;
}

QByteArray crypto::encrypt(QByteArray text, QString key, QString iv) {
    QByteArray encodedText = crypto::encryption.encode(text, crypto::getKey(key), QCryptographicHash::hash((iv.toLocal8Bit()), QCryptographicHash::Md5));
    return encodedText.toHex();
}

QString crypto::decrypt(QByteArray text, QString key, QString iv) {
    auto textFromHex = QByteArray::fromHex(text);
    auto k = crypto::getKey(key);
    auto i =  QCryptographicHash::hash((iv.toLocal8Bit()), QCryptographicHash::Md5);
    QByteArray decodedByteText = crypto::encryption.decode(textFromHex, k, i);

    auto withoutPad = crypto::encryption.removePadding(decodedByteText);
    QString decodedText = QString(withoutPad);
    return decodedText;
}





