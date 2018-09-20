#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSettings>
#include <QMessageBox>

namespace Ui {
class Database;
}
class Database : public QObject
{
    Q_OBJECT
public:
public slots:
    static void dbOpen();
    static void dbClose();
    static QSqlQueryModel* search(QString table, QString where);
    static int getIndex(QString column, QAbstractItemModel *model);
    static bool test(QString host, QString name, QString user, QString password);
};

#endif // DATABASE_H