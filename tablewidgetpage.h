#ifndef TABLEWIDGETPAGE_H
#define TABLEWIDGETPAGE_H

#include <QWidget>

namespace Ui {
class TableWidgetPage;
}

class TableWidgetPage : public QWidget
{
    Q_OBJECT

public:
    explicit TableWidgetPage(QWidget *parent = nullptr);
    ~TableWidgetPage();

private:
    Ui::TableWidgetPage *ui;


public:

    void updataPage();
    void updataPageData();

    void initHeader(const QStringList &headers);

    void addLogData(const QVariantList &data);

    void addLogDatas(const QList<QVariantList> &datas);
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    QList<QVariantList> m_lDatas;
    int currentPageSum;
    int pageSum;
    int currentPage;
};

#endif // TABLEWIDGETPAGE_H
