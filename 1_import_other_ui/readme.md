# Import other .ui files

## Create new .ui and .h
Right click in Forms >> Add New ... >> Qt >> Qt Designer Form Class
Type of class: Widget

## Add to GUI (just show)
### ./Forms/mainwindow.ui
Add a dummy "Graphics View" >> Promote to ...

    Promoted class name = imported_ui
    Header file = imported_ui.h

## Add to GUI - contact it
Use a widget to catch all your new .ui and a public method for returning it:

### ./Sources/imported_ui.cpp

    #include "inported_ui.h"
    #include "ui_inported_ui.h"

    #include <stdio.h>

    inported_ui::inported_ui(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::inported_ui)
    {
        ui->setupUi(this);
    }

    inported_ui::~inported_ui()
    {
        delete ui;
    }

    void inported_ui::change_label(QString s){
        ui->label->setText(s);
        printf("worked");
    }

    QWidget* inported_ui::get_widget(void){           // calling external
        return ui->widget;
    }


### ./Sources/mainwindow.cpp
Constructor must create a pointer to the object:

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


# Reference:
https://www.youtube.com/watch?v=6ywH0fXdHsY