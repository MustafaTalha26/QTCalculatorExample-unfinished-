#include "calculator.h"
#include "./ui_calculator.h"

double calcValue = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->screen->setText(QString::number(calcValue));

    QPushButton *numButtons[10];
    for(int i = 0; i < 10; i++) {
        QString buttonName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(buttonName);
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed()));
    }
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumPressed() {
    QPushButton *button = (QPushButton *)sender();
    QString butval = button->text();
    QString displayval = ui->screen->text();
    if(displayval.toDouble() == 0 || displayval.toDouble() == 0.0) {
        ui->screen->setText(butval);
    } else {
        QString newVal = displayval + butval;
        double dblNewVal = newVal.toDouble();
        ui->screen->setText(QString::number(dblNewVal, 'g', 16));
    }
}
