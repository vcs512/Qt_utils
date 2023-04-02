#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,
            &QPushButton::clicked,
            this,
            &MainWindow::foo);

    connect(ui->comboBox,
            &QComboBox::currentTextChanged,
            this,
            &MainWindow::foo_arg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::foo(void){
    ui->label->setText("Clicked 1");
}

void MainWindow::foo_arg(QString s){
    ui->label_2->setText(s);
}
