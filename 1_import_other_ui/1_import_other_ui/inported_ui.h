#ifndef INPORTED_UI_H
#define INPORTED_UI_H

#include <QWidget>
#include <QString>

namespace Ui {
class inported_ui;
}

class inported_ui : public QWidget
{
    Q_OBJECT

public:
    explicit inported_ui(QWidget *parent = nullptr);
    ~inported_ui();
    QWidget* get_widget(void);

public slots:
    void change_label(QString s);

public:
    Ui::inported_ui *ui;
};

#endif // INPORTED_UI_H
