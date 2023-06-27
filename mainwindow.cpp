#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encryption.h"
#include "qaesencryption.h"
#include <QMessageBox>
#include <QFile>
#include "QCryptographicHash"
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString pinCode = ui->pincode->text();

    QFile file("C:/201-351_Shchipunov/encoded.json");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QByteArray fromfile = file.readAll();
    file.close();
    QString decoded= crypto::decrypt(fromfile, pinCode, pinCode);
    if(pinCode == decoded)
    {
        NextWindow = new secondwindow(crypto::getKey((pinCode).toUtf8()));
        NextWindow->show();
        this->close();
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Пин-код неверный");
    }
}
