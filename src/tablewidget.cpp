#include "tablewidget.h"
#include "ui_tablewidget.h"

#include <QScreen>
#include <QHeaderView>

TableWidget::TableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableWidget),
    m_model(new TableModel(this))
{
    ui->setupUi(this);

    // Window setup
    setWindowTitle("Test Task");
    resizeToScreen(0.8);  // 80% of screen size

    // Table setup
    ui->tableView->setModel(m_model);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableView->verticalHeader()->setDefaultSectionSize(24);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
}

TableWidget::~TableWidget()
{
    delete ui;
}

void TableWidget::setTableDimensions(int rows, int columns)
{
    m_model->setDimensions(rows, columns);
}

void TableWidget::setHighlightColor(const QColor &color)
{
    m_model->setHighlightColor(color);
}

void TableWidget::setHighlightInterval(int interval)
{
    m_model->setHighlightInterval(interval);
}

void TableWidget::setDefaultSectionSize(int width, int height)
{
    ui->tableView->horizontalHeader()->setDefaultSectionSize(width);
    if (height > 0) {
        ui->tableView->verticalHeader()->setDefaultSectionSize(height);
    }
}

void TableWidget::resizeToScreen(double ratio)
{
    QRect screenGeometry = QGuiApplication::primaryScreen()->availableGeometry();
    int width = screenGeometry.width() * ratio;
    int height = screenGeometry.height() * ratio;
    resize(width, height);
    move((screenGeometry.width() - width) / 2,
         (screenGeometry.height() - height) / 2);
}
