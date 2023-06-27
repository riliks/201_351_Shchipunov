#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QRandomGenerator>
#include <qDebug>
#include <QString>



secondwindow::secondwindow(QString pinCode, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    ui->listWidget->clear();

    for (uint i = 0; i < size; i++) {
        adding();
    }
    this->pinCode = pinCode;
}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::adding() {

    QString randomcode;

    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (int i = 0; i < 4; ++i) {
        int randomIndex = rand() % characters.length();
        randomcode += characters[randomIndex];
    }

    QByteArray encryptvalue = crypto::encrypt(randomcode.toUtf8(), pinCode, pinCode);

    valueinbuttons.append(encryptvalue);
    addCard();
}

void secondwindow::addCard()
{
    QListWidgetItem* table = new QListWidgetItem();
    CardWidget* cards = new CardWidget(pinCode, valueinbuttons.last(), this);

    table->setSizeHint(cards->sizeHint());

    ui->listWidget->addItem(table);

    ui->listWidget->setItemWidget(table, cards);
}

void secondwindow::on_pushButton_clicked() {
    while (true) {
        auto randomIndex = QRandomGenerator::global()->bounded(uint(0), size);

        if (buttonsafter.contains(randomIndex)) {
            continue;
        }

        auto item = ui->listWidget->item(randomIndex);
        auto itemWidget = dynamic_cast<CardWidget*>(ui->listWidget->itemWidget(item));

        itemWidget->showcard();
        buttonsafter.append(randomIndex);
        size++;

        adding();

        break;
    }
}


