#include "tabledelegate.h"

TableDelegate::TableDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void TableDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);
    QStyledItemDelegate::paint(painter, opt, index);
}
