#include "tabledelegate.h"

TableDelegate::TableDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
    // Инициализация по умолчанию
}

void TableDelegate::paint(QPainter *painter,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);

    // Кастомная логика рендеринга
    if (m_useCustomHighlight && (index.row() + 1) % 10 == 0) {
        opt.backgroundBrush = m_customHighlightColor;
    }

    QStyledItemDelegate::paint(painter, opt, index);
}

QSize TableDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
}

void TableDelegate::setHighlightColor(const QColor &color)
{
    m_customHighlightColor = color;
    m_useCustomHighlight = true;
}

QColor TableDelegate::highlightColor() const
{
    return m_customHighlightColor;
}
