#include "customerpurchase.h"
#include "ui_customerpurchase.h"

CustomerPurchase::CustomerPurchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerPurchase)
{
    ui->setupUi(this);
}

CustomerPurchase::~CustomerPurchase()
{
    delete ui;
}

void CustomerPurchase::on_pushButton_clicked()
{
    CustomerPurchase db;
    QString customer, item;
    double amount, price, total, rebate;
    customer = ui->lineEdit_3->text();
    item = ui->lineEdit->text();
    amount = ui->spinBox->value();

    db.connOpen();
    QSqlQuery query;
    query.prepare("select price from stock where Item = '"+item+"'");
    query.exec();
   // query.bindValue(0,"price");

    price = query.value(0).toDouble();
    total = price * amount;
    rebate = total * .02;

    std::cout<< price << " " << total<< " "<< rebate;
    db.connClose();


}

void CustomerPurchase::on_pushButton_3_clicked()
{
    CustomerPurchase db;
    QSqlQueryModel * model = new QSqlQueryModel();

    db.connOpen();
    QSqlQuery * qry = new QSqlQuery();

    qry->prepare("select * from stock"); //* selects all

    qry->exec();
    model->setQuery(*qry);

    ui->tableView->setModel(model);
    db.connClose();
}
