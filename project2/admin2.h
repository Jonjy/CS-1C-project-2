#ifndef ADMIN2_H
#define ADMIN2_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
namespace Ui {
class admin2;
}

class admin2 : public QWidget
{
    Q_OBJECT

public:
    QSqlDatabase items;
    void connClose(){
        QString connection;
        connection = items.connectionName();
        items.close();
        items = QSqlDatabase();
        items.removeDatabase(connection);
        qDebug()<<"Connection Closed";
    }

    bool connOpen(){
        items = QSqlDatabase::addDatabase("QSQLITE");
        items.setDatabaseName("sales.db.db");

        if(items.open()){
            qDebug()<<"YEET";
            return true;
        }
        else{
            qDebug()<<"NAW";
            return false;
        }
    }
    explicit admin2(QWidget *parent = nullptr);
    ~admin2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::admin2 *ui;
};

#endif // ADMIN2_H
