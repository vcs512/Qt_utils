#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <math.h>
#include <stdio.h>

#define FREQ 1e3
#define PI 3.14159265358979323846

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // display config
    fs = 51.2e3;
    vector_size = (int) (5.2e-3*fs);

    // generate signal
    update_counter = 0;
    sampled_sine = new QVector<double>(vector_size);
    sampled_sine->reserve(vector_size);

    for (int i=0; i<sampled_sine->size(); i++){
        sampled_sine[0][i] = (double) sin(2.0*PI*FREQ*1/fs*i);
    }

    // set timer
    timer = new QTimer(this);
    tick = clock();
    connect(timer,
            &QTimer::timeout,
            this,
            &MainWindow::update_plot);
    timer->start(40);

    // prepare plot
    ui->canvas->addGraph();
    ui->canvas->xAxis->setLabel("Time (s)");
    ui->canvas->yAxis->setLabel("Amplitude (mV)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_plot(void){
    // get how many samples to be updated
    clock_t tmp = tick;
    tick = clock();
    double meantime = (double) (tick-tmp) / CLOCKS_PER_SEC;
    //    printf("Passed %f s\n", meantime);
    long int samples_meantime = (long int) floor(meantime / (1/fs) );
    //    printf("Acquire %ld samples\n", samples_meantime);


    // get samples from buffer
    static QVector<double> ydata(vector_size);
    static QVector<double> xdata(vector_size);

    for (int i=0; i<samples_meantime; i++){
        ydata[ (update_counter+i) % vector_size] = sampled_sine[0][(update_counter+i) % vector_size];
        xdata[ (update_counter+i) % vector_size] = ((double)update_counter + i) * 1/fs;
    }

    // display update
    ui->canvas->graph(0)->setData(xdata, ydata);
    ui->canvas->graph(0)->rescaleAxes();
    ui->canvas->replot();

    // update counter to sync samples
    update_counter = update_counter + samples_meantime;

}
