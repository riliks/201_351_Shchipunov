#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include "button.h"
#include <QString>
#include "encryption.h"

namespace Ui {
class secondwindow;
}

class secondwindow : public QWidget
{
    Q_OBJECT

public:
    explicit secondwindow(QString pinCode, QWidget *parent = nullptr);
    ~secondwindow();
    QString pinCode;

signals:
    void firstWindow();
private slots:
    void adding();
    void addCard();
    void on_pushButton_clicked();

private:
    QVector<uint> buttonsafter;
    Ui::secondwindow *ui;
    QVector<QString> valueinbuttons;
    uint size=12;

};

#endif // SECONDWINDOW_H
