#include "mainwindow.h"
#include "ui_mainwindow.h"
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

bool MainWindow::check_pin(QString pinCode)
{
    QFile file("C:/201-351_Shchipunov/encoded.json");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QByteArray readedText = file.readAll();
    file.close();
    return pinCode == decodedText;
}

