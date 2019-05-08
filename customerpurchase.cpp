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

//complete purchase button 
//updates the customer's rebate 
//updates the stock of the item
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
    QString prepareStatment = "select price from stock where Item = '"+item+"'";
    qDebug()<<prepareStatment;
    query.prepare(prepareStatment);
    if(query.exec()) qDebug()<<"Query succesful";
    else {
        qDebug()<<"Query unsuccesful";
    }


    query.first();
    price = query.value(0).toDouble();
    total = price * amount;
    rebate = total * (0.02);

    qDebug()<<price<<" "<<total<<" "<< rebate;
    db.connClose();

    db.connOpen();
    QSqlQuery qry;
    qry.prepare("select rebate from customers where ID = '"+customer+"'");
    if(qry.exec()) qDebug()<<"Qry succesful";
    else{
        qDebug()<<"Qry unsuccesful";
    }
    qry.first();
    double runningRebate = qry.value(0).toDouble();
    double newRebate = runningRebate + rebate;
    qDebug()<<runningRebate<<" "<<newRebate;
    db.connClose();

    db.connOpen();
    QSqlQuery query2;
    QString whatthefuck = "update customers set rebate = '"+QString::number(newRebate,'f',2)+"' where ID = '"+customer+"'";
    query2.prepare(whatthefuck);
    qDebug()<< whatthefuck;
    if(query2.exec()) qDebug()<<"success!";
    else qDebug()<<"Not succesful!";
    db.connClose();


    db.connOpen();
    QSqlQuery Qry2;
    Qry2.prepare("select count from stock where Item = '"+item+"'");
    if(Qry2.exec()) qDebug()<<"Qry2 success!";
    else qDebug()<<"Qry2 unsuccesful!";
    Qry2.first();

    int amnt = ui->spinBox->value();
    int runningCount = Qry2.value(0).toInt();
    int newCount = runningCount - amnt;
    qDebug()<<runningCount;
    db.connClose();

   db.connOpen();
   QSqlQuery query3;
   query3.prepare("update stock set count = '"+QString::number(newCount,'f',0)+"' where Item = '"+item+"'");
   if(query3.exec()) qDebug()<<"query3 success!";
   else qDebug()<<"querry3 unsuccesful!";
    db.connClose();
}

//load database to table-view
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

