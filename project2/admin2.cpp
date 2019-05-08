#include "admin2.h"
#include "ui_admin2.h"

admin2::admin2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin2)
{
    ui->setupUi(this);
}

admin2::~admin2()
{
    delete ui;
}

void admin2::on_pushButton_clicked()
{
    admin2 db;
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
void admin2::on_pushButton_2_clicked()
{
    admin2 db;
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
void admin2::on_pushButton_3_clicked()
{
    QString name, quantity, price;
    name = ui->lineEdit_4->text();
    quantity = ui->lineEdit_5->text();
    price = ui->lineEdit_6->text();

    admin2 db;
    db.connOpen();
    QSqlQuery qry;
    qry.prepare("update inventory set stock='"+quantity+"', Price = '"+price+"' where itemname = '"+name+"'");
    qry.exec();
    db.connClose();
}
