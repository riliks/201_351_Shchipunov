#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include "encryption.h"

namespace Ui {
class CardWidget;
}

class CardWidget : public QWidget {
   Q_OBJECT

public:
   explicit CardWidget(QString pinCode, const QString promo, QWidget *parent = nullptr);
   ~CardWidget();

   QString promo = "";
   QString pinCode;
   void showcard();

private:
   Ui::CardWidget *ui;
};

#endif  // BUTTON_H
