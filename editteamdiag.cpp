#include "editteamdiag.h"
#include "ui_editteamdiag.h"

EditTeamDiag::EditTeamDiag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditTeamDiag)
{
    ui->setupUi(this);
}

EditTeamDiag::~EditTeamDiag()
{
    delete ui;
}

void EditTeamDiag::on_search_clicked()
{
    id = ui->id->text();

    Team t = Team::getTeam(id);

    ui->compID->setText(t.comp_id);
    ui->divisionID->setText(t.division_id);
    ui->teamName->setText(t.name);
    ui->venueID->setText(t.venue_id);
}

void EditTeamDiag::on_apply_clicked()
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
                    //TODO proper id
                    Team::editTeam(t, id);
                    emit sendRefresh("TEAM");

                    // Save was clicked
                    EditTeamDiag::close();
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

void EditTeamDiag::on_divisionSearch_clicked()
{
    divisionselector = new DivisionSelector(this);
    divisionselector->open();

    QObject::connect(divisionselector, SIGNAL(sendID(QString)),this,SLOT(getDivID(QString)));
}

void EditTeamDiag::on_compSearch_clicked()
{
    compselector = new CompSelector(this);
    compselector->open();

    QObject::connect(compselector, SIGNAL(sendID(QString)),this,SLOT(getCompID(QString)));
}

void EditTeamDiag::getDivID(QString id)
{
    ui->divisionID->setText(id);
}
void EditTeamDiag::getCompID(QString id)
{
    ui->compID->setText(id);
}

void EditTeamDiag::search(QString teamID)
{
    ui->id->setText(teamID);
    on_search_clicked();
}

void EditTeamDiag::on_cancel_clicked()
{
    this->close();
}

void EditTeamDiag::on_venueSearch_clicked()
{
    venueselector = new VenueSelector(this);
    venueselector->open();

    QObject::connect(venueselector, SIGNAL(sendID(QString)),this,SLOT(getVenueID(QString)));
}
void EditTeamDiag::getVenueID(QString id)
{
    ui->venueID->setText(id);
}

