#include "tablewidgetpage.h"
#include "ui_tablewidgetpage.h"

TableWidgetPage::TableWidgetPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableWidgetPage)
{
    ui->setupUi(this);
    initHeader(QStringList() << "行号" << "内容");

    currentPageSum = 50;
    currentPage = 1;


    for (int i = 1; i <= 100000; i++) {
        QVariantList varList;
        varList << i << QString("测试");
        m_lDatas.push_back(varList);
    }
    addLogDatas(m_lDatas);
}

TableWidgetPage::~TableWidgetPage()
{
    delete ui;
}


void TableWidgetPage::updataPage()
{
    if (m_lDatas.size() <= 50) {
        pageSum = 1;
    }
    if ((m_lDatas.size() % 50) == 0) {
        pageSum = m_lDatas.size() / 50;

    }
    else {
        pageSum = (m_lDatas.size() / 50) + 1;
    }

    ui->label->setText(QString("%1/%2").arg(currentPage).arg(pageSum));
}

void TableWidgetPage::updataPageData()
{
    if (currentPage == 0) {
        return;
    }

    //获取具体下标 （当前页号*当前页的总数）-当前页的总数）= 某一页的第一个的具体数据下标
    int index = (currentPage * currentPageSum) - currentPageSum;


    //删除
    for(int row = ui->logTabWidget->rowCount() - 1;row >= 0; row--)
    {
        ui->logTabWidget->removeRow(row);
    }

    int i = 0;
    for (; index < m_lDatas.size(); ++index) {
        if (index >= (currentPage * currentPageSum)) {
            break;
        }

        int rowcount = ui->logTabWidget->rowCount();
        ui->logTabWidget->insertRow(rowcount);

        QVariantList varList = m_lDatas.at(index);

        for (int j = 0; j < varList.size(); ++j) {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setData(0, varList.at(j));
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->logTabWidget->setItem(i, j, item);
        }
        i++;
    }
}

void TableWidgetPage::initHeader(const QStringList &headers)
{
    ui->logTabWidget->setColumnCount(headers.size());
    ui->logTabWidget->setHorizontalHeaderLabels(headers);
    ui->logTabWidget->verticalHeader()->setHidden(false);

    ui->logTabWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->logTabWidget->setColumnWidth(0, 20);
    ui->logTabWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度

    QHeaderView *header = ui->logTabWidget->verticalHeader();
    header->setHidden(true);// 隐藏行号
}

void TableWidgetPage::addLogData(const QVariantList &data)
{
    m_lDatas.append(data);
    updataPageData();
    updataPage();
}

void TableWidgetPage::addLogDatas(const QList<QVariantList> &datas)
{
    //m_lDatas = datas;
    currentPage = 1;
    updataPageData();
    updataPage();
}


void TableWidgetPage::on_pushButton_3_clicked()
{
    //首页
    currentPage = 1;
    updataPageData();
    updataPage();
}

void TableWidgetPage::on_pushButton_clicked()
{
    //上一页
    if (currentPage == 1) {
        return;
    }

    currentPage--;
    updataPageData();
    updataPage();
}

void TableWidgetPage::on_pushButton_2_clicked()
{
    //下一页
    if (currentPage >= pageSum) {
        return;
    }
    currentPage++;
    updataPageData();
    updataPage();
}

void TableWidgetPage::on_pushButton_4_clicked()
{
    //尾页
    currentPage = pageSum;
    updataPageData();
    updataPage();

}

void TableWidgetPage::on_pushButton_5_clicked()
{
    //跳转
    if (ui->spinBox->value() > pageSum
            || currentPage == ui->spinBox->value()
            || ui->spinBox->value() == 0
            || pageSum == 1) {
        return;
    }
    currentPage = ui->spinBox->value();
    updataPageData();
    updataPage();
}


