#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    if(!mydb.open())
        qDebug()<<"error opening database\n";
    else
        qDebug()<<"database opened\n";
     */

    //using style sheet instead of QPixmap. Add (background:rgba(255,255,255,.2)) to stylesheet of groupbox to avoid issues
/*
    QPixmap bkgnd("C:/Users/Cam/Documents/project2/photos/bulkclub");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
   this->close();
}

void MainWindow::on_pushButton_clicked()
{
    QString pass = ui->lineEdit->text();

    if(pass == "password"){
        ui->stackedWidget->setCurrentIndex(1);
        ui->lineEdit->clear();
        ui->label_4->clear();
    }
    else{
        ui->label_4->setText("Password is incorrect");
        //QMessageBox::information(this, "Login", "Password is incorrect");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_5_clicked()
{
    //connect();

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_6_clicked() //delete user from database
{
    MainWindow db;
    QString name = ui->lineEdit_2->text();
    ui->lineEdit_2->clear();

    if(!db.opendb()){
        qDebug()<<"Failed to open database";
        db.closedb();
        return;
    }
    db.closedb();

    db.opendb();
    QSqlQuery qry;
    qry.prepare("DELETE FROM customers WHERE name = '"+name+"' ");
    //select * from customers where Name = "Fred Frugal"

    if(qry.exec()){
        QMessageBox::critical(this, tr("Delete"),tr("Deleted"));
        db.closedb();
    }
    else{
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
    }

    /*
    //Connecting to databse
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Cam/Downloads/datastuff.db");
    if(!db.open())
        qDebug()<<"failed to open database";
    //

    QString id = ui->lineEdit_2->text();
    //close database -> db.close()  and   db.removeDatabase(QSqlDatabase::defaultConnection)

    QSqlQuery qry;
    qry.prepare("Delete from customers ID Number = '"+id+"' ");

    //db.close();
    //db.removeDatabase(QSqlDatabase::defaultConnection);
    */
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_8_clicked()//add member
{
    QString name = ui->lineEdit_3->text();
    QString id = ui->lineEdit_4->text();
    QString membership = ui->lineEdit_5->text();
    //QString date = ui->label_6->text();

    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();

    time_t current = time(nullptr);
    tm timestruct;
    localtime_s(&timestruct, &current);
    QString date = QString::number(timestruct.tm_mon + 1) + "/" + QString::number(timestruct.tm_mday) + "/" + QString::number(timestruct.tm_year + 1900);

    MainWindow db;

    if(!db.opendb()){
        qDebug()<<"Failed to open database";
        db.closedb();
        return;
    }
    db.closedb();

    db.opendb();
    QSqlQuery qry;
    qry.prepare("INSERT INTO customers (name,id,status,join_date) values ('"+name+"','"+id+"', '"+membership+"', '"+date+"') ");

    if(qry.exec()){
        QMessageBox::critical(this, tr("Add"),tr("Entry added"));
        db.closedb();
    }
    else{
        QMessageBox::critical(this, tr("Error"),qry.lastError().text());
    }

}

void MainWindow::on_pushButton_9_clicked()
{
    MainWindow db;
    QSqlQueryModel * model = new QSqlQueryModel();

    db.opendb();
    QSqlQuery * qry = new QSqlQuery(db.mydb);

    qry->prepare("select * from customers"); //* selects all

    qry->exec();
    model->setQuery(*qry);

    ui->tableView->setModel(model);

    db.closedb();
}
