#ifndef CHELMETTIP_H
#define CHELMETTIP_H

#include <QWidget>

namespace Ui {
class CHelmetTip;
}

class CHelmetTip : public QWidget
{
    Q_OBJECT

public:
    explicit CHelmetTip(QString str,QWidget *parent = nullptr);
    ~CHelmetTip();
public slots:
    void onTimeupDestroy();
private:
    Ui::CHelmetTip *ui;
};

#endif // CHELMETTIP_H
