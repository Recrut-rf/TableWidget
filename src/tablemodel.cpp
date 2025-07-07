#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_rows;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_columns;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() ||
            index.row() >= m_rows ||
            index.column() >= m_columns)
        return QVariant();

    if (role == Qt::DisplayRole) {
        return QString("I:%1,%2").arg(index.column() + 1).arg(index.row() + 1);
    }
    else if (role == Qt::BackgroundRole &&
             (index.row() + 1) % m_highlightInterval == 0) {
        return m_highlightColor;
    }
    else if (role == Qt::TextAlignmentRole) {
        return Qt::AlignCenter;
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

void TableModel::setDimensions(int rows, int columns)
{
    // Валидация входных данных
    if (rows <= 0 || columns <= 0) {
        qWarning() << "Некорректные размеры таблицы:" << rows << "x" << columns;
        return;
    }

    // Уведомляем view о начале изменения модели
    beginResetModel();

    // Обновляем размеры
    m_rows = rows;
    m_columns = columns;

    // Уведомляем view о завершении изменений
    endResetModel();

    qDebug() << "Размеры таблицы изменены на:" << m_rows << "x" << m_columns;
}

void TableModel::setHighlightColor(const QColor &color)
{
    m_highlightColor = color;
    emit dataChanged(index(0, 0), index(m_rows - 1, m_columns - 1),
                     {Qt::BackgroundRole});
}

void TableModel::setHighlightInterval(int interval)
{
    if (interval > 0 && interval != m_highlightInterval) {
        m_highlightInterval = interval;
        emit dataChanged(index(0, 0), index(m_rows - 1, m_columns - 1),
                         {Qt::BackgroundRole});
    }
}

QColor TableModel::highlightColor() const
{
    return m_highlightColor;
}

int TableModel::highlightInterval() const
{
    return m_highlightInterval;
}
