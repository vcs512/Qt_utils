#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>

#include <time.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void update_plot(void);

private:
    Ui::MainWindow *ui;

    QTimer* timer;
    QVector<double>* sampled_sine;

    clock_t tick;
    unsigned long int update_counter;

    int vector_size;
    double fs;

};
#endif // MAINWINDOW_H
