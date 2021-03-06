#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSql>
#include <QMainWindow>
#include <QDebug>
#include <QFileInfo>
#include "admin2.h"
#include "customerpurchase.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    bool opendb(){
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("sales.db.db");
        //mydb.setDatabaseName("C:/Users/Cam/Downloads/sales.db");


        if(!mydb.open()){
            qDebug()<<"error opening database\n";
            return false;
        }
        else{
            qDebug()<<"database opened\n";
            return true;
        }
    }

    void closedb(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    void refreshcustomerdb();
    void refreshitemdb();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

public slots:

    void Search();

    void logout();

    void displayStock();

    void displayCustomers();

    void dodo();

    void managerLogin();

   void daySelect();

   void idSelect();

   void itemSelect();

   void statusSelect();

   void nameSelect();

   void reset();

   void idSort();

   void itemSort();

   void expiriningCustomers();

   void topu();

   void topu2();

private:

    Ui::MainWindow *ui;

    void dayCombo();

    void idCombo();

    void itemCombo();

    void statusCombo();

    void nameCombo();

    void monthCombo();

    void tableMake(QSqlQuery * qry);

    admin2 * page;

    CustomerPurchase * purch;


};

#endif // MAINWINDOW_H
