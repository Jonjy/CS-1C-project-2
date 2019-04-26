#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->DayBox->addItem("Select Day");
    ui->DayBox->addItem("Day 1");
    ui->DayBox->addItem("Day 2");
    ui->DayBox->addItem("Day 3");
    ui->DayBox->addItem("Day 4");
    ui->DayBox->addItem("Day 5");
    ui->DayBox->addItem("Day 6");
    ui->DayBox->addItem("Day 7");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::managerLogin(){
    if(ui->name->text()!="manager" || ui->password->text()!="pass"){
        QMessageBox::information(this, "Error",
                    "Incorrect user name or password",
                    QMessageBox::Ok);
        return;
    }
    ui->stackedWidget->setCurrentIndex(2);
    connect();

    if(!database.open())
    {
        ui->stackedWidget->setCurrentIndex(0);
        close();

    }else{

        viewDay(ui->DayBox->currentText());


        QSqlQuery * qry = new QSqlQuery(database);

        QSqlQueryModel * combo = new QSqlQueryModel();

        qry->prepare("select ID from customers ORDER BY ID ASC");
        qry->exec();

        combo->setQuery(*qry);

        ui->IDBox->setModel(combo);

    }
}


void MainWindow::adminLogin(){
    if(ui->name->text()!="admin" || ui->password->text()!="pass"){
        QMessageBox::information(this, "Error",
                    "Incorrect user name or password",
                    QMessageBox::Ok);
        return;
    }

    connect();
    if(!database.open())
    {
        ui->stackedWidget->setCurrentIndex(0);
        close();

    }else{

        IDSort();

    }
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::logout(){
    close();
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::newCustomer(){
    qDebug()<<("adding...");
    QString name, ID, status;
    name = ui->nameLine->text();
    ID = ui->IdLine->text();
    status = ui->statusLine->text();

    qDebug()<<(name)<<(ID)<<(status);

    QSqlQuery * qry = new QSqlQuery(database);

    name= "INSERT INTO customers (name, ID, status) "
          "VALUES ('"+name+"', '"+ID+"', '"+status+"')";

    qDebug()<<(name);
    qry->prepare(name);
    qry->exec();

    IDSort();

}

void MainWindow::customerScreen(){

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::deleteCustomer(){
    QSqlQuery * qry = new QSqlQuery(database);
    qry->exec("DELETE FROM customers WHERE ID ='"+ ui->deleteLine->text()+"'");
    IDSort();
}

void MainWindow::UpdateTable(){
    QString name, ID, status;
    name = ui->nameLine->text();
    ID = ui->IdLine->text();
    status = ui->statusLine->text();


    QSqlQuery * qry = new QSqlQuery(database);
    qry->prepare("");
    qry->exec();
}

void MainWindow::back(){
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::IDSort()
{
    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery * qry = new QSqlQuery(database);

    qry->prepare("select * from customers ORDER BY ID ASC");

    qry->exec();
    modal->setQuery(*qry);
    ui->adminView->setModel(modal);

    qDebug() << (modal->rowCount());
    ui->adminView->setColumnWidth(0,200);
    ui->adminView->setColumnWidth(1,200);
    ui->adminView->setColumnWidth(2,200);
    ui->adminView->setColumnWidth(3,200);

}

void MainWindow::viewDay(QString day){
    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery * qry = new QSqlQuery(database);


    if(day == "Select Day"){
        qry->prepare("select * from sales");
    }else{
        day=day.at(4);
        qry->prepare("select * from sales WHERE day = '"+day+"'");
    }
    qry->exec();
    modal->setQuery(*qry);
    //ui->table->setModel(modal);

    qDebug() << (modal->rowCount());
    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,75);
    ui->tableView->setColumnWidth(2,200);
    ui->tableView->setColumnWidth(3,100);
    ui->tableView->setColumnWidth(4,100);
}

void MainWindow::UpdateDay(){
    QString day = ui->DayBox->currentText();
    viewDay(day);
}

void MainWindow::search(){
    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery * qry = new QSqlQuery(database);

    QString ID = ui->IDBox->currentText();

    QString day = ui->DayBox->currentText().at(4);

    if(day == "Select Day"){
        qry->prepare("select * from sales WHERE ID = '"+ID+"'");
    }else{
        qry->prepare("select * from sales WHERE day = '"+ day+"' AND ID ='"+ID+"'");
    }
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug() << (modal->rowCount());
    ui->tableView->setColumnWidth(0,200);
    ui->tableView->setColumnWidth(1,200);
    ui->tableView->setColumnWidth(2,200);
    ui->tableView->setColumnWidth(3,200);
    ui->tableView->setColumnWidth(4,200);
}

void MainWindow::displayInfo(){
    QSqlQuery * qry = new QSqlQuery(database);

    QString ID = ui->IDBox->currentText();

    qDebug()<<(ID);

    QString query ="select * from customers where ID = "+ID+"";

    qDebug()<<(query);
    qry->prepare(query);
    qry->exec();

    ui->NameEdit->setText(qry->value(0).toString());
    ui->IDEdit->setText(qry->value(1).toString());
    ui->statusEdit->setText(qry->value(2).toString());

}





bool MainWindow::connect(){
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("sales.db.db");
    qDebug()<<("database attempt");

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
