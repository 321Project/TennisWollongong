#ifndef EDITTEAMDIAG_H
#define EDITTEAMDIAG_H

#include <QDialog>
#include "team.h"
#include "divisionselector.h"
#include "compselector.h"
#include "venueselector.h"

namespace Ui {
class EditTeamDiag;
}

class EditTeamDiag : public QDialog
{
    Q_OBJECT

public:
    explicit EditTeamDiag(QWidget *parent = 0);
    ~EditTeamDiag();

private slots:
    void on_search_clicked();

    void on_apply_clicked();
    void on_divisionSearch_clicked();

    void on_compSearch_clicked();
    void getDivID(QString);
    void getCompID(QString);
    void on_cancel_clicked();

    void on_venueSearch_clicked();
    void getVenueID(QString id);
public slots:
    void search(QString teamID);
signals:
    void sendRefresh(QString);

private:
    Ui::EditTeamDiag *ui;
    QString id;
    DivisionSelector *divisionselector;
    CompSelector *compselector;
    VenueSelector *venueselector;
};

#endif // EDITTEAMDIAG_H
