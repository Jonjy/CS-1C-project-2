#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
#include <ctime>
#include <QList>

/*NOTES*
 *make selecting membership a dropdown box
 *for deleting users make that a dropdown box
 *for deleting items make that a dropdown box
 *make updating/viewing the tables a function of MainWindow with model as a member variable
 *           and call that function whenever the admin page is opened and delete the member variable
 *           when back is pressed.
 *the should convert requirement - calc rebate and see if they save and then suggest an upgrade if they will save
 */


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox_3->addItem("Regular");
    ui->comboBox_3->addItem("Executive");

    ui->comboBox_5->addItem("Regular");
    ui->comboBox_5->addItem("Executive");

    int i;
    for(i = 0; i < 12; i++){
        if(i<9){
            ui->comboBox_6->addItem("0" +QString::number(i + 1));//month
        }
        else{
            ui->comboBox_6->addItem(QString::number(i + 1));//month
        }
    }
    for (i = 0; i < 31; i++){
       if(i<9){
           ui->comboBox_7->addItem("0" +QString::number(i + 1));//month
       }
       else{
        ui->comboBox_7->addItem(QString::number(i + 1));//day
       }
    }

    time_t current = time(nullptr);
    tm timestruct;
    localtime_s(&timestruct, &current);
    for(i = timestruct.tm_year + 1900; i<timestruct.tm_year+1906; i++){
        ui->comboBox_8->addItem(QString::number(i));//year
    }
    ui->stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshcustomerdb(){
    MainWindow db;
    QSqlQueryModel * model = new QSqlQueryModel();

    db.opendb();
    QSqlQuery * qry = new QSqlQuery(db.mydb);

    qry->prepare("select * from customers"); //* selects all

    qry->exec();
    model->setQuery(*qry);

    if(ui->stackedWidget->currentIndex()==2){
        ui->tableView->setModel(model);
        ui->comboBox_2->setModel(model);
    }
    if(ui->stackedWidget->currentIndex()==3){
        ui->tableView_2->setModel(model);
        ui->comboBox_4->setModel(model);
    }
    db.closedb();
}

void MainWindow::refreshitemdb(){
    MainWindow db;
    QSqlQueryModel * model = new QSqlQueryModel();

    db.opendb();
    QSqlQuery * qry = new QSqlQuery(db.mydb);

    qry->prepare("select * from stock"); //* selects all

    qry->exec();
    model->setQuery(*qry);

    if(ui->stackedWidget->currentIndex()==2){
        ui->tableView->setModel(model);
        ui->comboBox->setModel(model);
    }
    if(ui->stackedWidget->currentIndex()==3){
        ui->tableView_2->setModel(model);
        //ui->comboBox_5->setModel(model);
    }

    db.closedb();
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
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_6_clicked() //delete user from database
{
    MainWindow db;
    QString name = ui->comboBox_2->currentText();

    if(!db.opendb()){
        qDebug()<<"Failed to open database";
        db.closedb();
        return;
    }
    db.closedb();

    db.opendb();
    QSqlQuery qry;

    qry.prepare("SELECT * FROM customers WHERE name = '"+name+"'");
    qry.exec();
    if(qry.isNull(qry.first())){
        QMessageBox::critical(this, tr("Delete"),tr("Name not found"));
        db.closedb();
        return;
    }

    qry.prepare("DELETE FROM customers WHERE name = '"+name+"' ");

    if(qry.exec()){
        QMessageBox::critical(this, tr("Delete"),tr("Deleted"));
        db.closedb();
    }
    else{
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
    }
    refreshcustomerdb();
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_8_clicked()//add member
{
    QString name = ui->lineEdit_3->text();
    QString id = ui->lineEdit_4->text();
    QString membership = ui->comboBox_3->currentText();

    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();

    time_t current = time(nullptr);
    tm timestruct;
    localtime_s(&timestruct, &current);
    QString date = QString::number(timestruct.tm_mon + 1) + "/" + QString::number(timestruct.tm_mday) + "/" + QString::number(timestruct.tm_year + 1901);

    MainWindow db;

    if(!db.opendb()){
        qDebug()<<"Failed to open database";
        db.closedb();
        return;
    }
    db.closedb();

    db.opendb();
    QSqlQuery qry;
    qry.prepare("INSERT INTO customers (name,ID,status,expiration) values ('"+name+"','"+id+"', '"+membership+"', '"+date+"') ");

    if(qry.exec()){
        QMessageBox::critical(this, tr("Add"),tr("Entry added"));
        db.closedb();
    }
    else{
        QMessageBox::critical(this, tr("Error"),qry.lastError().text());
    }
    refreshcustomerdb();
}

void MainWindow::on_pushButton_9_clicked()//table view of customer database
{
    MainWindow db;
    QSqlQueryModel * model = new QSqlQueryModel();

    db.opendb();
    QSqlQuery * qry = new QSqlQuery(db.mydb);

    qry->prepare("select * from customers"); //* selects all

    qry->exec();
    model->setQuery(*qry);

    ui->tableView->setModel(model);
    ui->comboBox_2->setModel(model);

    db.closedb();
}

void MainWindow::on_pushButton_11_clicked()//table view of item database
{
    MainWindow db;
    QSqlQueryModel * model = new QSqlQueryModel();

    db.opendb();
    QSqlQuery * qry = new QSqlQuery(db.mydb);

    qry->prepare("select * from stock"); //* selects all

    qry->exec();
    model->setQuery(*qry);

    ui->tableView->setModel(model);
    ui->comboBox->setModel(model);

    db.closedb();
}

void MainWindow::on_pushButton_12_clicked() //adding item
{
    MainWindow db;
    QString item, amount, price;
    item = ui->lineEdit_6->text();
    amount = ui->lineEdit_7->text();
    price = ui->lineEdit_8->text();

    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();

    if(db.opendb()){qDebug()<< "database opened"; }
    else {qDebug()<<"database failed to open";}
    db.closedb();

    db.opendb();
    QSqlQuery query;

    query.prepare("insert into stock (Item, count, price) values ('"+item+"', '"+amount+"', '"+price+"')");

    if(query.exec()){
        qDebug()<<"Changes Made";
        db.closedb();
    }
    else{qDebug()<<"Changes failed";
    query.lastError();
    }
    refreshitemdb();
}

void MainWindow::on_pushButton_14_clicked() //delete item
{
    MainWindow db;
    QString item = ui->comboBox->currentText();

    if(!db.opendb()){
        qDebug()<<"Failed to open database";
        db.closedb();
        return;
    }
    db.closedb();

    db.opendb();
    QSqlQuery qry;

    qry.prepare("DELETE FROM stock WHERE Item = '"+item+"' ");

    if(qry.exec()){
        QMessageBox::critical(this, tr("Delete"),tr("Deleted"));
        db.closedb();
    }
    else{
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
    }
    refreshitemdb();
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_17_clicked()
{
    refreshitemdb();
}

void MainWindow::on_pushButton_18_clicked()
{
    refreshcustomerdb();
}

void MainWindow::on_pushButton_19_clicked()//edit name
{
    QString oldname = ui->comboBox_4->currentText();
    QString newname = ui->lineEdit_2->text();
    MainWindow db;

    if(!db.opendb()){
        qDebug()<<"Failed to open database";
        db.closedb();
        return;
    }
    db.closedb();

    db.opendb();
    QSqlQuery qry;

    qry.prepare("UPDATE customers SET name = '"+newname+"' WHERE name = '"+oldname+"' ");

    if(qry.exec()){
        db.closedb();
    }
    else{
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
    }
    refreshcustomerdb();
    ui->lineEdit_2->clear();
}

void MainWindow::on_pushButton_20_clicked()//edit id
{
    QString name = ui->comboBox_4->currentText();
    QString id = ui->lineEdit_5->text();
    MainWindow db;

    if(!db.opendb()){
        qDebug()<<"Failed to open database";
        db.closedb();
        return;
    }
    db.closedb();

    db.opendb();
    QSqlQuery qry;

    qry.prepare("UPDATE customers SET ID = '"+id+"' WHERE name = '"+name+"' ");

    if(qry.exec()){
        db.closedb();
    }
    else{
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
    }
    refreshcustomerdb();
    ui->lineEdit_5->clear();
}

void MainWindow::on_pushButton_21_clicked()//edit status
{
    QString name = ui->comboBox_5->currentText();
    QString status = ui->lineEdit_5->text();
    MainWindow db;

    if(!db.opendb()){
        qDebug()<<"Failed to open database";
        db.closedb();
        return;
    }
    db.closedb();

    db.opendb();
    QSqlQuery qry;

    qry.prepare("UPDATE customers SET status = '"+status+"' WHERE name = '"+name+"' ");

    if(qry.exec()){
        db.closedb();
    }
    else{
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
    }
    refreshcustomerdb();
}

void MainWindow::on_pushButton_22_clicked()
{
    QString name = ui->comboBox_5->currentText();

    QString month = ui->comboBox_6->currentText();
    QString day = ui->comboBox_7->currentText();
    QString year = ui->comboBox_8->currentText();
    QString exp = month + "/" + day + "/" + year;

    MainWindow db;
    db.opendb();
    QSqlQuery qry;

    qry.prepare("UPDATE customers SET expiration = '"+exp+"' WHERE name = '"+name+"' ");

    if(qry.exec()){
        db.closedb();
    }
    else{
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
    }
    refreshcustomerdb();
    ui->comboBox_6->setCurrentIndex(0);
    ui->comboBox_7->setCurrentIndex(0);
    ui->comboBox_8->setCurrentIndex(0);
}

void MainWindow::on_pushButton_23_clicked()
{
   ui->stackedWidget->setCurrentIndex(4);

   MainWindow db, db2;

   QSqlQueryModel * model = new QSqlQueryModel();
   QSqlQueryModel * model2 = new QSqlQueryModel();

   db.opendb();
   db2.opendb();

   QSqlQuery * qry = new QSqlQuery(db.mydb);
   QSqlQuery * qry2 = new QSqlQuery(db2.mydb);

   qry->prepare("select * from customers where (status = 'Executive') AND (rebate<55) ");
   qry2->prepare("select * from customers where (status = 'Regular') AND (runningTotal > 2750) ");

   qry->exec();
   qry2->exec();

   model->setQuery(*qry);
   model2->setQuery(*qry2);

   ui->tableView_3->setModel(model);//exec to regular
   ui->tableView_4->setModel(model2);//regular to exec

   db.closedb();
   db2.closedb();
}
void MainWindow::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::managerLogin(){
    if(ui->lineEdit->text() != "manager"){
        ui->label_4->setText("Password is incorrect");
        //QMessageBox::information(this, "Login", "Password is incorrect");
        return;
    }
    ui->lineEdit->clear();
    ui->stackedWidget->setCurrentIndex(5);
    opendb();

    dayCombo();
    idCombo();
    itemCombo();
    statusCombo();
    nameCombo();
    monthCombo();

    QSqlQuery * qry = new QSqlQuery(mydb);
    QString item = ui->ItemBox->currentText();


    qry->prepare("select * from sales ORDER BY Day ASC");

    qry->exec();

    tableMake(qry);
}

void MainWindow::tableMake(QSqlQuery * qry){
    QSqlQueryModel * modal = new QSqlQueryModel();
    float items=0, revenue=0;
    int exec=0, reg=0;
    modal->setQuery(*qry);
    ui->managerView->setModel(modal);

    qDebug() << (modal->rowCount());
    ui->managerView->setColumnWidth(0,100);
    ui->managerView->setColumnWidth(1,74);
    ui->managerView->setColumnWidth(2,200);
    ui->managerView->setColumnWidth(3,80);
    ui->managerView->setColumnWidth(4,73);
    ui->managerView->setColumnWidth(5,73);
    qry->first();

    if(qry->first()){
        if(qry->value(6).toString() == "Executive"){
            exec++;
        }else{
            reg++;
        }
        items += qry->value(4).toFloat();
        revenue +=qry->value(3).toFloat()*qry->value(4).toFloat();

    }
    while(qry->next()){
        if(qry->value(6).toString() == "Executive"){
            exec++;
        }else{
            reg++;
        }
        items += qry->value(4).toFloat();
        revenue +=qry->value(3).toFloat()*qry->value(4).toFloat();//*1.0775

    }
    qDebug()<<(items);
    qDebug()<<(revenue);
    ui->SoldEdit->setText(QString::number(items));
    ui->salesEdit->setText(QString::number(revenue,'f',2));
    ui->execEdit->setText(QString::number(exec));
    ui->regEdit->setText(QString::number(reg));
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


void MainWindow::nameCombo(){
    QSqlQuery * qry = new QSqlQuery(mydb);

    qry->prepare("select Name from customers ORDER BY Name ASC");
    qry->exec();

    QList<QString> list;

    list.append("All customers");

    if(qry->first()){
        list.append(qry->value(0).toString());
    }
    while(qry->next()){
        list.append(qry->value(0).toString());
    }

    ui->NameBox->addItems(list);
}

void MainWindow::idCombo(){
    QSqlQuery * qry = new QSqlQuery(mydb);


    qry->prepare("select ID from customers ORDER BY ID ASC");
    qry->exec();

    QList<QString> list;

    list.append("All customers");

    if(qry->first()){
        list.append(qry->value(0).toString());
    }
    while(qry->next()){
        list.append(qry->value(0).toString());
    }

    ui->IDBox->addItems(list);
}

void MainWindow::itemCombo(){
    QSqlQuery * qry = new QSqlQuery(mydb);

    qry->prepare("select Item from stock");
    qry->exec();

    QList<QString> list;

    list.append("All Items");

    if(qry->first()){
        list.append(qry->value(0).toString());
    }

    while(qry->next()){
        list.append(qry->value(0).toString());
    }

    ui->ItemBox->addItems(list);
}

void MainWindow::statusCombo(){
    ui->statusBox->addItem("All Customers");
    ui->statusBox->addItem("Executive");
    ui->statusBox->addItem("Regular");
}

void MainWindow::monthCombo(){
    ui->monthBox->addItem("January");
    ui->monthBox->addItem("Febuary");
    ui->monthBox->addItem("March");
    ui->monthBox->addItem("April");
    ui->monthBox->addItem("May");
    ui->monthBox->addItem("June");
    ui->monthBox->addItem("July");
    ui->monthBox->addItem("August");
    ui->monthBox->addItem("September");
    ui->monthBox->addItem("October");
    ui->monthBox->addItem("November");
    ui->monthBox->addItem("December");
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

void MainWindow::nameSelect(){

    QSqlQuery * qry = new QSqlQuery(mydb);
    QString name = ui->NameBox->currentText();

    if (name == "All customers"){
        ui->IDBox->setCurrentText("All customers");
        return;
    }

    QString quer ="select ID from customers WHERE Name = '"+name+"'";
    qDebug()<<(quer);
    qry->prepare(quer);
    qry->exec();
    qDebug()<<qry->first();
    QString id= qry->value(0).toString();

    ui->IDBox->setCurrentText(id);
}

void MainWindow::idSelect(){

    QSqlQuery * qry = new QSqlQuery(mydb);
    QString id = ui->IDBox->currentText();

    if(id == "All customers"){
        ui->NameBox->setCurrentText("All customers");
        return;
    }

    QString quer ="select Name from customers WHERE Id ='"+id+"'";
    qDebug()<<(quer);
    qry->prepare(quer);
    qry->exec();
    qDebug()<<qry->first();
    QString name= qry->value(0).toString();
    ui->NameBox->setCurrentText(name);
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
    QString item = ui->statusBox->currentText();

    if(item == "Executive" || item == "Regualar"){
        qry->prepare("select * from sales WHERE status = '"+item+"'");
    }else{
        qry->prepare("select * from sales");
    }

    qry->exec();

    tableMake(qry);
}

void MainWindow::Search(){
    QSqlQuery * qry = new QSqlQuery(mydb);
    QString line = "select * from sales";
    bool added = false;
    QString where = " where ";

    if(ui->DayBox->currentText() != "Select Day"){
        added = true;
        line += where;
        line += "Day = '";
        line += ui->DayBox->currentText().at(4);
        line += "'";
    }
    if(ui->IDBox->currentText() != "All customers"){
        if(added){
            line += " AND ";
        }else{
            added = true;
            line += where;
        }
        line += "ID = '";
        line += ui->IDBox->currentText();
        line += "'";
    }
    if(ui->ItemBox->currentText() != "All Items"){
        if(added){
            line += " AND ";
        }else{
            added = true;
            line += where;
        }
        line += "Product = '";
        line += ui->ItemBox->currentText();
        line += "'";
    }
    if(ui->statusBox->currentText() != "All Customers"){
        if(added){
            line += " AND ";
        }else{
            added = true;
            line += where;
        }
        line += "[Member Status] = '";
        line += ui->statusBox->currentText();
        line += "' ORDER BY Day ASC";
    }


    qDebug()<<(line);
    qry->exec(line);
    tableMake(qry);

}

void MainWindow::reset(){
    ui->NameBox->setCurrentIndex(0);
    ui->IDBox->setCurrentIndex(0);
    ui->statusBox->setCurrentIndex(0);
    ui->ItemBox->setCurrentIndex(0);
    ui->DayBox->setCurrentIndex(0);
}

void MainWindow::idSort(){
    qDebug()<<("here i am");
    QSqlQuery * qry = new QSqlQuery(mydb);
    QString line = "select * from sales";
    bool added = false;
    QString where = " where ";

    if(ui->DayBox->currentText() != "Select Day"){
        added = true;
        line += where;
        line += "Day = '";
        line += ui->DayBox->currentText().at(4);
        line += "'";
    }
    if(ui->IDBox->currentText() != "All customers"){
        if(added){
            line += " AND ";
        }else{
            added = true;
            line += where;
        }
        line += "ID = '";
        line += ui->IDBox->currentText();
        line += "'";
    }
    if(ui->ItemBox->currentText() != "All Items"){
        if(added){
            line += " AND ";
        }else{
            added = true;
            line += where;
        }
        line += "Product = '";
        line += ui->ItemBox->currentText();
        line += "'";
    }
    if(ui->statusBox->currentText() != "All Customers"){
        if(added){
            line += " AND ";
        }else{
            added = true;
            line += where;
        }
        line += "[Member Status] = '";
        line += ui->statusBox->currentText();
        line += "'";
    }

    line += " ORDER by ID ASC";

    qDebug()<<(line);
    qry->exec(line);
    tableMake(qry);

}

void MainWindow::itemSort(){
    qDebug()<<("here i am");
    QSqlQuery * qry = new QSqlQuery(mydb);
    QString line = "select * from sales";
    bool added = false;
    QString where = " where ";

    if(ui->DayBox->currentText() != "Select Day"){
        added = true;
        line += where;
        line += "Day = '";
        line += ui->DayBox->currentText().at(4);
        line += "'";
    }
    if(ui->IDBox->currentText() != "All customers"){
        if(added){
            line += " AND ";
        }else{
            added = true;
            line += where;
        }
        line += "ID = '";
        line += ui->IDBox->currentText();
        line += "'";
    }
    if(ui->ItemBox->currentText() != "All Items"){
        if(added){
            line += " AND ";
        }else{
            added = true;
            line += where;
        }
        line += "Product = '";
        line += ui->ItemBox->currentText();
        line += "'";
    }
    if(ui->statusBox->currentText() != "All Customers"){
        if(added){
            line += " AND ";
        }else{
            added = true;
            line += where;
        }
        line += "[Member Status] = '";
        line += ui->statusBox->currentText();
        line += "'";
    }

    line += " ORDER by Product ASC";
    qDebug()<<(line);
    qry->exec(line);
    tableMake(qry);

}

void MainWindow::displayStock(){
    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery * qry = new QSqlQuery(mydb);

    qry->prepare("SELECT * from stock");

    qry->exec();
    modal->setQuery(*qry);
    ui->managerView->setModel(modal);
}

void MainWindow::displayCustomers(){
    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery * qry = new QSqlQuery(mydb);

    qry->prepare("SELECT * from customers");

    qry->exec();
    modal->setQuery(*qry);
    ui->managerView->setModel(modal);
    ui->managerView->setColumnWidth(0,202);
    ui->managerView->setColumnWidth(1,102);
    ui->managerView->setColumnWidth(2,102);
    ui->managerView->setColumnWidth(3,102);
    ui->managerView->setColumnWidth(4,102);
    ui->managerView->setColumnWidth(5,102);
}

void MainWindow::expiriningCustomers(){
    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery * qry = new QSqlQuery(mydb);

    QString fuckthisfuckingshit = ui->monthBox->currentText();

    if(fuckthisfuckingshit == "January"){
        fuckthisfuckingshit= "01";
    }
    if(fuckthisfuckingshit == "Febuary"){
        fuckthisfuckingshit= "02";
    }
    if(fuckthisfuckingshit == "March"){
        fuckthisfuckingshit= "03";
    }
    if(fuckthisfuckingshit == "April"){
        fuckthisfuckingshit= "04";
    }
    if(fuckthisfuckingshit == "May"){
        fuckthisfuckingshit= "05";
    }
    if(fuckthisfuckingshit == "June"){
        fuckthisfuckingshit= "06";
    }
    if(fuckthisfuckingshit == "July"){
        fuckthisfuckingshit= "07";
    }
    if(fuckthisfuckingshit == "August"){
        fuckthisfuckingshit= "08";
    }
    if(fuckthisfuckingshit == "September"){
        fuckthisfuckingshit= "09";
    }
    if(fuckthisfuckingshit == "October"){
        fuckthisfuckingshit= "10";
    }
    if(fuckthisfuckingshit == "November"){
        fuckthisfuckingshit= "11";
    }
    if(fuckthisfuckingshit == "December"){
        fuckthisfuckingshit= "12";
    }


    qry->prepare("SELECT * from customers WHERE expiration LIKE '"+fuckthisfuckingshit+"%'");

    qry->exec();
    modal->setQuery(*qry);
    ui->managerView->setModel(modal);
    ui->managerView->setColumnWidth(0,202);
    ui->managerView->setColumnWidth(1,102);
    ui->managerView->setColumnWidth(2,102);
    ui->managerView->setColumnWidth(3,102);
    ui->managerView->setColumnWidth(4,102);
    ui->managerView->setColumnWidth(5,102);
}

void MainWindow::logout(){
    ui->stackedWidget->setCurrentIndex(0);
    closedb();
    ui->DayBox->clear();
    ui->NameBox->clear();
    ui->IDBox->clear();
    ui->ItemBox->clear();
    ui->statusBox->clear();
}

void MainWindow::dodo(){
    QSqlQuery * qry = new QSqlQuery(mydb);


    qry->prepare("select ID from customers ORDER BY ID ASC");
    qry->exec();

    QList<QString> list;

    if(qry->first()){
        list.append(qry->value(0).toString());
    }
    while(qry->next()){
        list.append(qry->value(0).toString());
    }

    for(QList<QString>::iterator it = list.begin();it != list.end();it++){
    QString id= *it;
    qry->exec("select * from sales WHERE ID = "+ id);


    float revenue=0;
    qry->first();

    if(qry->first()){
        if(qry->value(6).toString() == "Executive"){
        revenue +=qry->value(3).toFloat()*qry->value(4).toFloat();
        }
    }
    while(qry->next()){
        revenue +=qry->value(3).toFloat()*qry->value(4).toFloat();
    }

    QString bleh ="UPDATE customers SET [purchase total] = '"+ QString::number(revenue,'f',2) +"' WHERE ID = "+id;
    qDebug()<<(bleh);
    qry->prepare(bleh);
    qry->exec();


    bleh="UPDATE customers SET [rebate amount] = '"+ QString::number(revenue*0.2,'f',2) +"' WHERE ID = "+id;
    qDebug()<<(bleh);
    qry->prepare(bleh);
    qry->exec();
    }
}
