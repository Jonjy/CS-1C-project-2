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

    ui->stackedWidget->setCurrentIndex(0);

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
        ui->stackedWidget->setCurrentIndex(3);
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

    ui->stackedWidget->setCurrentIndex(3);
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

void MainWindow::managerLogin(){
    if(ui->lineEdit->text() != "pass"){
        QMessageBox::information(this, "Error",
                            "Incorrect user name or password",
                            QMessageBox::Ok);
        return;
    }


    ui->stackedWidget->setCurrentIndex(2);
    opendb();

    dayCombo();

    idCombo();

    itemCombo();

    QSqlQuery * qry = new QSqlQuery(mydb);
    QString item = ui->ItemBox->currentText();


    qry->prepare("select * from sales");

    qry->exec();

    tableMake(qry);
}

void MainWindow::tableMake(QSqlQuery * qry){
    QSqlQueryModel * modal = new QSqlQueryModel();

    modal->setQuery(*qry);
    ui->managerView->setModel(modal);

    qDebug() << (modal->rowCount());
    ui->managerView->setColumnWidth(0,100);
    ui->managerView->setColumnWidth(1,75);
    ui->managerView->setColumnWidth(2,200);
    ui->managerView->setColumnWidth(3,75);
}

void MainWindow::dayCombo(){
    ui->DayBox->addItem("Select Day");
    ui->DayBox->addItem("Day 1");
    ui->DayBox->addItem("Day 2");
    ui->DayBox->addItem("Day 3");
    ui->DayBox->addItem("Day 4");
    ui->DayBox->addItem("Day 5");
    ui->DayBox->addItem("Day 6");
    ui->DayBox->addItem("Day 7");
    return;
}


void MainWindow::idCombo(){
    QSqlQuery * qry = new QSqlQuery(mydb);

    QSqlQueryModel * combo = new QSqlQueryModel();

    qry->prepare("select ID from customers ORDER BY ID ASC");
    qry->exec();

    combo->setQuery(*qry);

    ui->IDBox->setModel(combo);
}

void MainWindow::itemCombo(){
    QSqlQuery * qry = new QSqlQuery(mydb);

    QSqlQueryModel * combo = new QSqlQueryModel();

    qry->prepare("select Item from stock");
    qry->exec();

    combo->setQuery(*qry);

    ui->ItemBox->setModel(combo);

}

void MainWindow::statusCombo(){
    ui->DayBox->addItem("All Customers");
    ui->DayBox->addItem("Executive");
    ui->DayBox->addItem("Regular");
}

void MainWindow::daySelect(){

    QSqlQuery * qry = new QSqlQuery(mydb);
    QString day = ui->DayBox->currentText();

    if(day == "Select Day"){
        qry->prepare("select * from sales");
    }else{
        day=day.at(4);
        qry->prepare("select * from sales WHERE day = '"+day+"'");
    }
    qry->exec();

    tableMake(qry);
}

void MainWindow::idSelect(){

    QSqlQuery * qry = new QSqlQuery(mydb);
    QString id = ui->IDBox->currentText();


    qry->prepare("select * from sales WHERE ID = '"+id+"'");

    qry->exec();

    tableMake(qry);
}

void MainWindow::itemSelect(){
    QSqlQuery * qry = new QSqlQuery(mydb);
    QString item = ui->ItemBox->currentText();


    qry->prepare("select * from sales WHERE Product = '"+item+"'");

    qry->exec();

    tableMake(qry);
}

void MainWindow::statusSelect(){
    QSqlQuery * qry = new QSqlQuery(mydb);
    QString item = ui->ItemBox->currentText();


    qry->prepare("select * from sales WHERE Product = '"+item+"'");

    qry->exec();

    tableMake(qry);
}


