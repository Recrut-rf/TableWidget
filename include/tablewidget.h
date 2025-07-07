#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include "tablemodel.h"
#include "tabledelegate.h"

namespace Ui {
class TableWidget;
}

class TableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TableWidget(QWidget *parent = nullptr);
    ~TableWidget();

private:
    Ui::TableWidget *ui;
    TableModel *model;
    TableDelegate *tableDelegate;
};

#endif // TABLEWIDGET_H
