#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::adminLogin(){
    ui->stackedWidget->setCurrentIndex(2);
    connect();

    if(!database.open())
    {
        ui->stackedWidget->setCurrentIndex(0);
        close();

    }else{

        alphaSort();

        ui->comboBox->addItem("Customer List");
        ui->comboBox->addItem("Day 1");
        ui->comboBox->addItem("Day 2");
        ui->comboBox->addItem("Day 3");
        ui->comboBox->addItem("Day 4");
        ui->comboBox->addItem("Day 5");
        ui->comboBox->addItem("Day 6");
        ui->comboBox->addItem("Day 7");

    }
}


void MainWindow::customerLogin(){
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::logout(){
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox->clear();

}

void MainWindow::newCustomer(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::alphaSort()
{
    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery * qry = new QSqlQuery(database);

    qry->prepare("select * from customers ");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug() << (modal->rowCount());
    ui->tableView->setColumnWidth(0,200);
    ui->tableView->setColumnWidth(1,150);
    ui->tableView->setColumnWidth(2,150);
    ui->tableView->setColumnWidth(3,150);

}







bool MainWindow::connect(){
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("datastuff.db");

    if(!database.open()){
        qDebug() << ("panic");
        return false;
    }

    qDebug() << ("Don't panic");
    return true;
}

void MainWindow::close(){
    database.close();
    database.removeDatabase(QSqlDatabase::defaultConnection);
    qDebug() << ("Closed");
}
