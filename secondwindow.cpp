#include "promocodes.h"
#include "ui_promocodes.h"
#include <QRandomGenerator>
#include <qDebug>
#include <QString>



promocodes::promocodes(QString pinCode, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::promocodes)
{
    ui->setupUi(this);
    initPromo();
    this->pinCode = pinCode;
}

promocodes::~promocodes()
{
    delete ui;
}

void promocodes::initPromo()
{
    ui->listWidget->clear();

    for (uint i = 0; i < fieldSize; i++) {
        addpromo();
    }
}

void promocodes::addCard(QString promo)
{
    auto listItemW = new QListWidgetItem();
    auto itemW = new CardWidget(pinCode, promo, this);

    listItemW->setSizeHint(itemW->sizeHint());

    ui->listWidget->addItem(listItemW);
    ui->listWidget->setItemWidget(listItemW, itemW);
}
}


