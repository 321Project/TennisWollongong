#include "addteamdialog.h"
#include "ui_addteamdialog.h"

addTeamDialog::addTeamDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addTeamDialog)
{
    ui->setupUi(this);
}

addTeamDialog::~addTeamDialog()
{
    delete ui;
}

void addTeamDialog::on_divisionSearch_clicked()
{
    divisionselector = new DivisionSelector(this);
    divisionselector->open();

    QObject::connect(divisionselector, SIGNAL(sendID(QString)),this,SLOT(getDivID(QString)));
}

void addTeamDialog::on_compSearch_clicked()
{
    compselector = new CompSelector(this);
    compselector->open();

    QObject::connect(compselector, SIGNAL(sendID(QString)),this,SLOT(getCompID(QString)));
}

void addTeamDialog::on_venueSearch_clicked()
{
    venueselector = new VenueSelector(this);
    venueselector->open();

    QObject::connect(venueselector, SIGNAL(sendID(QString)),this,SLOT(getVenueID(QString)));
}

void addTeamDialog::getDivID(QString id)
{
    ui->divisionID->setText(id);
}
void addTeamDialog::getCompID(QString id)
{
    ui->compID->setText(id);
}
void addTeamDialog::getVenueID(QString id)
{
    ui->venueID->setText(id);
}

void addTeamDialog::on_apply_clicked()
{
    Team t = Team(ui->teamName->text(),ui->divisionID->text(),ui->compID->text(), ui->venueID->text());

    if(Team::verifyTeam(t))
    {
        QMessageBox msgBox;
        msgBox.setText("Are you sure?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret) {
          case QMessageBox::Save:
        {
            //Save was clicked
            //TODO proper id
            Team::addTeam(t);
            emit sendRefresh("TEAM");
            addTeamDialog::close();
            break;
        }
          case QMessageBox::Cancel:
              // Cancel was clicked
              break;
          default:
              // should never be reached
              break;
        }
    }
}

void addTeamDialog::on_cancel_clicked()
{
    addTeamDialog::close();
}


