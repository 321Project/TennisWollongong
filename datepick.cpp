#include "datepick.h"
#include "ui_datepick.h"

DatePick::DatePick(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DatePick)
{
    ui->setupUi(this);
    ui->calendarWidget->setSelectedDate(QDate::currentDate().addDays(-1));
}

DatePick::~DatePick()
{
    delete ui;
}

void DatePick::on_calendarWidget_selectionChanged()
{
    QDate dob =  ui->calendarWidget->selectedDate();
    emit sendDate(dob.toString("dd/MM/yyyy"));

    DatePick::close();
}
