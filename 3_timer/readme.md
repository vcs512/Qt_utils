# Timers in Qt
## .pro
    QT += core

## .h
    #include <QTimer>

## .cpp
    QTimer *timer = new QTimer(this);
    connect(timer,
            &QTimer::timeout,
            this,
            &MainWondow::slot_function);
    timer->start(1000); // ms


# Reference
https://doc.qt.io/qt-5/qtimer.html

https://stackoverflow.com/questions/11651852/how-to-use-qtimer

timer.h: https://www.geeksforgeeks.org/time-h-header-file-in-c-with-examples/