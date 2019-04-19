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
    void alphaSort();

    QSqlDatabase database;

public slots:
    void adminLogin();

    void customerLogin();

    void logout();

    void newCustomer();
};

#endif // MAINWINDOW_H
