# Signals and slots

## ./Headers/mainwindow.h:

Add a new slot functions "foo" and "foo_arg" under "private slots":
    
    #ifndef MAINWINDOW_H
    #define MAINWINDOW_H

    #include <QMainWindow>

    QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
    QT_END_NAMESPACE

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:                                  // added section
        void foo(void);
        void foo_arg(QString s);

    private:
        Ui::MainWindow *ui;
    };
    #endif // MAINWINDOW_H



## ./Sources/mainwindow.cpp
### Constructor:
The signal automatically passes its arguments to the slot

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


### Method:
Arguments must match the type of signal passed

    void MainWindow::foo(void){
        ui->label->setText("Clicked 1");
    }

    void MainWindow::foo_arg(QString s){
        ui->label_2->setText(s);
    }

