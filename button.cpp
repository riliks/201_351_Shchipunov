#include "button.h"

#include "ui_button.h"

CardWidget::CardWidget(QString pinCode, const QString promo, QWidget* parent)
    : QWidget(parent), ui(new Ui::CardWidget) {
  ui->setupUi(this);

  ui->promoButton->setText("???");
  this->promo = promo;
  this->pinCode = pinCode;

}

CardWidget::~CardWidget() {
  delete ui;
}

void CardWidget::showcard() {
  QString decrPromo = crypto::decrypt(promo.toUtf8(), pinCode, pinCode);
  ui->promoButton->setText(decrPromo);
  ui->promoButton->setStyleSheet("border-color:rgb(21, 134, 255); background-color:rgb(135, 235, 255); border: 1px;");
}
