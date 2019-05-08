#ifndef CUSTOMERPURCHASE_H
#define CUSTOMERPURCHASE_H

#include <QDialog>
#include<QtSql>
#include<QDebug>
#include<cstdlib>
#include<iostream>
namespace Ui {
class CustomerPurchase;
}

class CustomerPurchase : public QDialog
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
        //items.removeDatabase(QSqlDatabase::defaultConnection);
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
    explicit CustomerPurchase(QWidget *parent = nullptr);
    ~CustomerPurchase();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::CustomerPurchase *ui;
};

#endif // CUSTOMERPURCHASE_H
