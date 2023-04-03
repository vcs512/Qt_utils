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

QWidget* inported_ui::get_widget(void){
    return ui->widget;
}
