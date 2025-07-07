#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QColor>

/**
 * @brief Кастомная модель данных для таблицы 100x100 с подсветкой строк
 */
class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор модели
     * @param parent Родительский объект
     */
    explicit TableModel(QObject *parent = nullptr);
    ~TableModel() = default;

    /**
    * @brief Получить количество строк
    * @param parent Родительский индекс (не используется)
    * @return Количество строк в модели
    */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * @brief Получить количество столбцов
     * @param parent Родительский индекс (не используется)
     * @return Количество столбцов в модели
     */
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * @brief Получить данные для отображения
     * @param index Индекс запрашиваемых данных
     * @param role Роль данных
     * @return Запрошенные данные или пустой QVariant
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    /**
     * @brief Получить данные заголовков
     * @param section Номер секции
     * @param orientation Ориентация заголовка
     * @param role Роль данных
     * @return Данные заголовка или пустой QVariant
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    /**
     * @brief Устанавливает новые размеры таблицы
     * @param rows Новое количество строк (должно быть > 0)
     * @param columns Новое количество столбцов (должно быть > 0)
     * @note Метод автоматически обновляет представление таблицы.
     * @warning Изменение размеров сбрасывает все текущие данные.
     *
     * Пример использования:
     * @code
     * model->setDimensions(150, 50); // Таблица 150x50
     * @endcode
     */
    void setDimensions(int rows, int columns);

    /**
    * @brief Установить цвет подсветки
    * @param color Новый цвет подсветки
    */
    void setHighlightColor(const QColor &color);

    /**
     * @brief Установить интервал подсвечиваемых строк
     * @param interval Новый интервал (каждые N строк)
     */
    void setHighlightInterval(int interval);

    /**
     * @brief Получить текущий цвет подсветки
     * @return Цвет подсветки
     */
    QColor highlightColor() const;

    /**
     * @brief Получить текущий интервал подсветки
     * @return Интервал подсветки
     */
    int highlightInterval() const;


private:
    int m_rows = 100;    ///< Текущее количество строк
    int m_columns = 100; ///< Текущее количество столбцов
    QColor m_highlightColor = QColor(200, 230, 255);  ///< Цвет подсветки
    int m_highlightInterval = 10; ///< Интервал подсвечиваемых строк
};

#endif // TABLEMODEL_H
