#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    inported_ui* imported(new inported_ui);
    ui->verticalLayout->addWidget(imported->get_widget());

    connect(ui->comboBox,
            &QComboBox::currentTextChanged,
            imported,
            &inported_ui::change_label);
}

MainWindow::~MainWindow()
{
    delete ui;
}

