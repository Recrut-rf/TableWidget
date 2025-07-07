#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include "tablemodel.h"

namespace Ui {
class TableWidget;
}

class TableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TableWidget(QWidget *parent = nullptr);
    ~TableWidget();

    void setTableDimensions(int rows, int columns);
    void setHighlightColor(const QColor &color);
    void setHighlightInterval(int interval);
    void setDefaultSectionSize(int width, int height = -1);

private:
    Ui::TableWidget *ui;
    TableModel *m_model;

    void resizeToScreen(double ratio);
};

#endif // TABLEWIDGET_H
