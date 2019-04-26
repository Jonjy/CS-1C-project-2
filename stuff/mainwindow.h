#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTSql>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool connect();
    void close();
    void viewDay(QString day);
    void IDSort();

    QSqlDatabase database;

public slots:
    void adminLogin();

    void managerLogin();

    void logout();

    void newCustomer();

    void deleteCustomer();

    void UpdateTable();

    void UpdateDay();

    void search();

    void displayInfo();

    void back();

    void customerScreen();

};

#endif // MAINWINDOW_H
