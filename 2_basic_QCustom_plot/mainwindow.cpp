#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QtMath>
#include <math.h>

#define N 10000
#define PI 3.14159265358979323846
#define FREQ 1
#define FS 1000

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // add a graph
    ui->customPlot->addGraph();

    QVector <double> time(N);
    QVector <double> sampled_sine(N);
    for (size_t i=0; i<N; i++){
        time[i] = (double)i;
        sampled_sine[i] = (double) sin(2*PI*FREQ*1/FS*i);
    }

    // set data
    ui->customPlot->graph(0)->setData(time, sampled_sine);

    // customize axis
    ui->customPlot->graph(0)->rescaleAxes();
    ui->customPlot->xAxis->setLabel("X label");
    ui->customPlot->yAxis->setLabel("Y label");

    // ask to show
    ui->customPlot->replot();

}

MainWindow::~MainWindow()
{
    delete ui;
}

