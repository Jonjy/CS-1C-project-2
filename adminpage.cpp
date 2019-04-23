#include "adminpage.h"
#include "ui_adminpage.h"

adminPage::adminPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminPage)
{
    ui->setupUi(this);

}

adminPage::~adminPage()
{
    delete ui;
}

void adminPage::on_pushButton_clicked()
{
    adminPage db;
    QString item, amount;
    item = ui->lineEdit->text();
    amount = ui->lineEdit_2->text();

    if(db.connOpen()){qDebug()<< "STILL GOOD"; }
    else {qDebug()<<"NOPE NOT GOOD";}
    db.connClose();

    db.connOpen();
    QSqlQuery query;

    query.prepare("insert into inventory (itemname, stock) values ('"+item+"', '"+amount+"')");

    if(query.exec()){
        qDebug()<<"Changes Made";
        db.connClose();
    }
    else{qDebug()<<"Changes failed";
    query.lastError();}
}

