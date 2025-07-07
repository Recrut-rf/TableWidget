#ifndef TABLEDELEGATE_H
#define TABLEDELEGATE_H

#include <QStyledItemDelegate>

class TableDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit TableDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;

    void setHighlightColor(const QColor &color);
    QColor highlightColor() const;

private:
    QColor m_customHighlightColor;
    bool m_useCustomHighlight = false;
};
#endif // TABLEDELEGATE_H
