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

//Add Item To the list Button
void adminPage::on_pushButton_clicked()
{
    adminPage db;
    QString item, amount, price;
    item = ui->lineEdit->text();
    amount = ui->lineEdit_2->text();
    price = ui->lineEdit_3->text();

    if(db.connOpen()){qDebug()<< "STILL GOOD"; }
    else {qDebug()<<"NOPE NOT GOOD";}
    db.connClose();

    db.connOpen();
    QSqlQuery query;

    query.prepare("insert into inventory (itemname, stock, price) values ('"+item+"', '"+amount+"', '"+price+"')");

    if(query.exec()){
        qDebug()<<"Changes Made";
        db.connClose();
    }
    else{qDebug()<<"Changes failed";
    query.lastError();}
    db.connClose();
}


//Refresh List Button
void adminPage::on_pushButton_2_clicked()
{
    adminPage db;
    QSqlQueryModel * model = new QSqlQueryModel();

    db.connOpen();
    QSqlQuery * qry = new QSqlQuery();

    qry->prepare("select * from inventory"); //* selects all

    qry->exec();
    model->setQuery(*qry);

    ui->tableView->setModel(model);
    db.connClose();
}

//updateList button
void adminPage::on_pushButton_3_clicked()
{
    QString name, quantity, price;
    name = ui->lineEdit_4->text();
    quantity = ui->lineEdit_5->text();
    price = ui->lineEdit_6->text();

    adminPage db;
    db.connOpen();
    QSqlQuery qry;
    qry.prepare("update inventory set stock='"+quantity+"', Price = '"+price+"' where itemname = '"+name+"'");
    qry.exec();
    db.connClose();
}
