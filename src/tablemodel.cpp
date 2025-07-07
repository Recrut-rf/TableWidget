#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return ROWS;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return COLS;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        // Формат: "X.Y" (столбец.строка)
        return QString("l:%1,%2").arg(index.column() + 1).arg(index.row() + 1);
    }
    else if (role == Qt::BackgroundRole && (index.row() + 1) % 10 == 0) {
        return highlightColor; // Подсветка каждой 10-й строки
    }

    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        return QString("H:%1").arg(section + 1);
    } else {
        return QString("V:%1").arg(section + 1);
    }
}
