#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);

    // белый фон окна
    this->setAutoFillBackground(true);

    QPalette palette = this->palette();

    palette.setColor(QPalette::Window, Qt::white);

    this->setPalette(palette);

    // размер окна
    resize(1100, 700);

    // стиль поля вывода
    ui->resultTextEdit->setStyleSheet(
        "QTextEdit {"
        "background-color: black;"
        "color: white;"
        "border: 1px solid gray;"
        "font-size: 12pt;"
        "}"
        );

    // стиль таблицы
    ui->treeTableWidget->setStyleSheet(

        "QTableWidget {"
        "background-color: black;"
        "color: white;"
        "gridline-color: gray;"
        "border: 1px solid gray;"
        "selection-background-color: rgb(60, 60, 60);"
        "selection-color: white;"
        "}"

        "QTableWidget::item {"
        "padding: 5px;"
        "}"

        "QHeaderView::section {"
        "background-color: rgb(30, 30, 30);"
        "color: white;"
        "border: 1px solid gray;"
        "padding: 4px;"
        "}"
        );

    // отключаем выделение строк
    ui->treeTableWidget->setSelectionMode(
        QAbstractItemView::NoSelection
        );

    // скрываем рамку фокуса
    ui->treeTableWidget->setFocusPolicy(Qt::NoFocus);

    // стиль кнопок
    QString buttonStyle =

        "QPushButton {"
        "background-color: black;"
        "color: white;"
        "border: 1px solid gray;"
        "padding: 5px;"
        "border-radius: 5px;"
        "}"

        "QPushButton:hover {"
        "background-color: rgb(40, 40, 40);"
        "}"

        "QPushButton:pressed {"
        "background-color: rgb(70, 70, 70);"
        "}";

    ui->insertButton->setStyleSheet(buttonStyle);
    ui->removeButton->setStyleSheet(buttonStyle);
    ui->searchButton->setStyleSheet(buttonStyle);

    ui->preorderButton->setStyleSheet(buttonStyle);
    ui->inorderButton->setStyleSheet(buttonStyle);
    ui->postorderButton->setStyleSheet(buttonStyle);

    ui->balanceButton->setStyleSheet(buttonStyle);

    ui->verticalPrintButton->setStyleSheet(buttonStyle);
    ui->horizontalPrintButton->setStyleSheet(buttonStyle);

    ui->leavesButton->setStyleSheet(buttonStyle);
    ui->resetButton->setStyleSheet(buttonStyle);

    // исходное дерево для варианта 17
    tree.insert(8.5);
    tree.insert(4.2);
    tree.insert(12.7);
    tree.insert(2.1);
    tree.insert(6.3);
    tree.insert(10.4);
    tree.insert(15.8);
    tree.insert(1.0);
    tree.insert(3.6);
    tree.insert(5.5);
    tree.insert(7.9);

    tree.saveOriginal();

    ui->resultTextEdit->setText(
        "Лабораторная работа №1\n"
        "Бинарное дерево поиска\n\n"
        "Вариант 17\n"
        "Тип информационного поля: double\n"
        "Индивидуальное задание: найти количество листьев в дереве."
        );

    fillTreeTable();
}

MainWindow::~MainWindow() {
    delete ui;
}

QString MainWindow::keyToString(double key) {
    return QString::number(key, 'g', 6);
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);

    // сглаживание
    painter.setRenderHint(QPainter::Antialiasing);

    vector<VisualNode> nodes = tree.getVisualNodes();

    // рисование ребер
    for (int i = 0; i < nodes.size(); i++) {

        if (nodes[i].hasParent) {

            QPoint parentPoint;

            for (int j = 0; j < nodes.size(); j++) {

                if (nodes[j].key == nodes[i].parentKey) {
                    parentPoint = nodes[j].position;
                    break;
                }
            }

            // черная линия
            painter.setPen(Qt::black);

            painter.drawLine(parentPoint, nodes[i].position);
        }
    }

    // рисование узлов
    for (int i = 0; i < nodes.size(); i++) {

        QPoint point = nodes[i].position;

        // черная заливка
        painter.setBrush(Qt::black);

        // черный контур
        painter.setPen(Qt::black);

        // круг узла
        painter.drawEllipse(
            point.x() - 22,
            point.y() - 22,
            44,
            44
            );

        QRect rect(
            point.x() - 22,
            point.y() - 22,
            44,
            44
            );

        // белый текст
        painter.setPen(Qt::white);

        painter.drawText(
            rect,
            Qt::AlignCenter,
            keyToString(nodes[i].key)
            );
    }
}

void MainWindow::fillTreeTable() {

    vector<VisualNode> nodes = tree.getVisualNodes();

    // очищаем таблицу
    ui->treeTableWidget->clearContents();
    ui->treeTableWidget->setRowCount(0);
    ui->treeTableWidget->clear();

    // размер таблицы
    ui->treeTableWidget->setColumnCount(3);
    ui->treeTableWidget->setRowCount(nodes.size());

    // заголовки
    QStringList headers;

    headers << "Ключ"
            << "Родитель"
            << "Уровень";

    ui->treeTableWidget
        ->setHorizontalHeaderLabels(headers);

    // скрываем вертикальные номера
    ui->treeTableWidget
        ->verticalHeader()
        ->setVisible(false);

    // заполнение таблицы
    for (int i = 0; i < nodes.size(); i++) {

        QString parentValue;

        if (nodes[i].hasParent) {
            parentValue = keyToString(nodes[i].parentKey);
        }
        else {
            parentValue = "Корень";
        }

        QTableWidgetItem *keyItem =
            new QTableWidgetItem(
                keyToString(nodes[i].key)
                );

        QTableWidgetItem *parentItem =
            new QTableWidgetItem(parentValue);

        QTableWidgetItem *levelItem =
            new QTableWidgetItem(
                QString::number(nodes[i].level)
                );

        // выравнивание текста
        keyItem->setTextAlignment(Qt::AlignCenter);
        parentItem->setTextAlignment(Qt::AlignCenter);
        levelItem->setTextAlignment(Qt::AlignCenter);

        ui->treeTableWidget->setItem(
            i,
            0,
            keyItem
            );

        ui->treeTableWidget->setItem(
            i,
            1,
            parentItem
            );

        ui->treeTableWidget->setItem(
            i,
            2,
            levelItem
            );
    }

    // растягиваем таблицу
    ui->treeTableWidget
        ->horizontalHeader()
        ->setSectionResizeMode(
            QHeaderView::Stretch
            );

    ui->treeTableWidget->viewport()->update();
}

void MainWindow::on_insertButton_clicked() {

    bool ok;

    double key = QInputDialog::getDouble(
        this,
        "Вставка узла",
        "Ключ узла:",
        0,
        -999999,
        999999,
        2,
        &ok
        );

    if (!ok) {
        return;
    }

    bool added = tree.insert(key);

    if (added) {
        ui->resultTextEdit->setText(
            "Узел добавлен: " + keyToString(key)
            );
    }
    else {
        ui->resultTextEdit->setText(
            "Узел с таким ключом уже есть: " + keyToString(key)
            );
    }

    fillTreeTable();
    update();
}

void MainWindow::on_removeButton_clicked() {

    bool ok;

    double key = QInputDialog::getDouble(
        this,
        "Удаление узла",
        "Ключ узла:",
        0,
        -999999,
        999999,
        2,
        &ok
        );

    if (!ok) {
        return;
    }

    bool removed = tree.remove(key);

    if (removed) {
        ui->resultTextEdit->setText(
            "Узел удален: " + keyToString(key)
            );
    }
    else {
        ui->resultTextEdit->setText(
            "Узел не найден: " + keyToString(key)
            );
    }

    fillTreeTable();
    update();
}

void MainWindow::on_searchButton_clicked() {

    bool ok;

    double key = QInputDialog::getDouble(
        this,
        "Поиск узла",
        "Ключ узла:",
        0,
        -999999,
        999999,
        2,
        &ok
        );

    if (!ok) {
        return;
    }

    bool found = tree.search(key);

    if (found) {
        ui->resultTextEdit->setText(
            "Элемент найден: " + keyToString(key)
            );
    }
    else {
        ui->resultTextEdit->setText(
            "Элемент не найден: " + keyToString(key)
            );
    }
}

void MainWindow::on_preorderButton_clicked() {

    QString result = tree.preorder();

    ui->resultTextEdit->setText(result);
}

void MainWindow::on_inorderButton_clicked() {

    QString result = tree.inorder();

    ui->resultTextEdit->setText(result);
}

void MainWindow::on_postorderButton_clicked() {

    QString result = tree.postorder();

    ui->resultTextEdit->setText(result);
}

void MainWindow::on_balanceButton_clicked() {

    tree.balance();

    ui->resultTextEdit->setText(
        "Дерево сбалансировано."
        );

    fillTreeTable();
    update();
}

void MainWindow::on_verticalPrintButton_clicked() {

    QString result = tree.verticalPrint();

    ui->resultTextEdit->setText(result);
}

void MainWindow::on_horizontalPrintButton_clicked() {

    QString result = tree.horizontalPrint();

    ui->resultTextEdit->setText(result);
}

void MainWindow::on_leavesButton_clicked() {

    int leaves = tree.countLeaves();

    QString result;

    result += "Количество листьев в дереве\n\n";
    result += "Лист — это узел без левого и правого потомка.\n\n";
    result += "Количество листьев: ";
    result += QString::number(leaves);

    ui->resultTextEdit->setText(result);
}


void MainWindow::on_resetButton_clicked() {

    tree.restoreOriginal();

    fillTreeTable();
    ui->treeTableWidget->repaint();

    ui->resultTextEdit->setText(
        "Дерево возвращено к исходному состоянию."
        );

    update();
}
