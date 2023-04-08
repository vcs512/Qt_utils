#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdio.h>
#include <time.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    // connect timeout signal
    connect(timer,
            &QTimer::timeout,
            this,
            &MainWindow::update_timed
            );

    // start timer
    timer->start(40);  //ms
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_timed(void){
    static int counter = 0;

// //    counter = 53 :: Sat Apr 08 21:47:52 2023
//    time_t tick = time(NULL);
//    struct tm* time_ptr = gmtime(&tick);
//    printf("counter = %d :: %s",
//           counter,
//           asctime(time_ptr));

    static clock_t click;
    click = clock();
    double time_passed = ((float) click) / CLOCKS_PER_SEC;
    printf("counter = %d,"
           " passed %f s\n",
           counter,
           time_passed);



    counter++;
}
