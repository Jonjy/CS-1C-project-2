#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include<QtSql>
#include<QDebug>
#include <QMainWindow>
#include<QFileInfo>


namespace Ui {
class adminPage;
}

class adminPage : public QMainWindow
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
        items.setDatabaseName("C:\\Users\\mrpou\\Documents\\inventory.db3");

        if(items.open()){
            qDebug()<<"YEET";
            return true;
        }
        else{
            qDebug()<<"NAW";
            return false;
        }
    }
    explicit adminPage(QWidget *parent = nullptr);
    ~adminPage();

private slots:
    void on_pushButton_clicked();



private:
    Ui::adminPage *ui;

};

#endif // ADMINPAGE_H
