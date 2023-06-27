    #ifndef PROMOCODES_H
#define PROMOCODES_H

#include <QWidget>
#include "cardwidget.h"
#include <QString>
#include "crypto.h"

namespace Ui {
class promocodes;
}

class promocodes : public QWidget
{
    Q_OBJECT

public:
    explicit promocodes(QString pinCode, QWidget *parent = nullptr);
    ~promocodes();
    QString pinCode;

signals:
    void firstWindow();
private slots:
    void initPromo();
    void addCard(QString promo);
    void on_pushButton_clicked();

private:
    Ui::promocodes *ui;
    QVector<QString> promos;
    QVector<uint> openedPromos;

    uint fieldSize = 9;

};

#endif // PROMOCODES_H
