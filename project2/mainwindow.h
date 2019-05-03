#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSql>
#include <QMainWindow>
#include <QDebug>
#include <QFileInfo>

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

    void managerLogin();

    void daySelect();

    void idSelect();

    void itemSelect();

    void statusSelect();

private:
    Ui::MainWindow *ui;

    void manTablefill();

    void dayCombo();

    void idCombo();

    void itemCombo();

    void statusCombo();

    void tableMake(QSqlQuery * qry);

};

#endif // MAINWINDOW_H
