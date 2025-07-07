#ifndef TABLEDELEGATE_H
#define TABLEDELEGATE_H

#include <QStyledItemDelegate>

// Если в будущем понадобится сложная отрисовка
class TableDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit TableDelegate(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;
};

#endif // TABLEDELEGATE_H
