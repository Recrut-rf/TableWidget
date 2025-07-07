#include <QScreen>
#include "tablewidget.h"
#include "ui_tablewidget.h"

TableWidget::TableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableWidget),
    model(new TableModel(this)),
    tableDelegate(new TableDelegate(this))
{
    ui->setupUi(this);

    // Устанавливаем заголовок окна
    this->setWindowTitle("Test Task");

    // Устанавливаем размер окна в 80% от размера экрана
    QRect screenGeometry = QGuiApplication::primaryScreen()->availableGeometry();
    int width = screenGeometry.width() * 0.8;
    int height = screenGeometry.height() * 0.8;
    this->resize(width, height);

    // Центрируем
    this->move((screenGeometry.width() - width) / 2, (screenGeometry.height() - height) / 2);

    ui->tableView->setModel(model);

    ui->tableView->setItemDelegate(tableDelegate);

    ui->tableView->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableView->verticalHeader()->setDefaultSectionSize(24);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
}

TableWidget::~TableWidget()
{
    delete ui;
}
