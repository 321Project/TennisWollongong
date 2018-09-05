#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "refine.h"
#include "player.h"
#include "addplayerdiag.h"
#include "editplayerdiag.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dbOpen();
    dbRefresh();
}
MainWindow::~MainWindow()
{
    dbClose();
    delete ui;
}

void MainWindow::on_Refine_clicked()
{
    refine = new Refine(this);
    refine->show();
}

void MainWindow::on_playeAdButton_clicked()
{
    addplayerdiag = new AddPlayerDiag(this);
    addplayerdiag->show();

    QObject::connect(addplayerdiag,SIGNAL(sendRefresh()),this,SLOT(getRefresh()) );

}

void MainWindow::on_PlayerEditButton_clicked()
{
    editplayerdiag = new EditPlayerDiag(this);
    editplayerdiag->show();

    QObject::connect(editplayerdiag,SIGNAL(sendRefresh()),this,SLOT(getRefresh()) );
}
void MainWindow::dbRefresh()
{
    ui->playerTable->setModel(dbLoad());
}
void MainWindow::getRefresh()
{
    dbRefresh();
}
