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

    auto encryptvalue = crypto::encrypt(randomcode.toUtf8(), pinCode, pinCode);

    valueinbuttons.append(encryptvalue);
    addCard(encryptvalue);
}

void secondwindow::addCard(QString card)
{
    auto listItemW = new QListWidgetItem();
    auto itemW = new CardWidget(pinCode, card, this);

    listItemW->setSizeHint(itemW->sizeHint());

    ui->listWidget->addItem(listItemW);

    ui->listWidget->setItemWidget(listItemW, itemW);
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


