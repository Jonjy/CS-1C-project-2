/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *Login;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *name;
    QLineEdit *lineEdit_4;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QWidget *admin;
    QPushButton *pushButton;
    QLabel *label;
    QWidget *manager;
    QTableView *tableView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_3;
    QLineEdit *lineEdit_5;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_8;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;
    QWidget *newCustomer;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1318, 820);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1311, 811));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        Login = new QWidget();
        Login->setObjectName(QString::fromUtf8("Login"));
        gridLayoutWidget_2 = new QWidget(Login);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(510, 270, 261, 80));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        name = new QLineEdit(gridLayoutWidget_2);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout_2->addWidget(name, 0, 1, 1, 1);

        lineEdit_4 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout_2->addWidget(lineEdit_4, 1, 1, 1, 1);

        horizontalLayoutWidget_2 = new QWidget(Login);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(430, 480, 451, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_2->addWidget(pushButton_6);

        horizontalLayoutWidget_3 = new QWidget(Login);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 50, 1301, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 16pt \"Comic Sans MS\";"));

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(Login);
        admin = new QWidget();
        admin->setObjectName(QString::fromUtf8("admin"));
        pushButton = new QPushButton(admin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(610, 630, 75, 23));
        label = new QLabel(admin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(576, 62, 111, 41));
        stackedWidget->addWidget(admin);
        manager = new QWidget();
        manager->setObjectName(QString::fromUtf8("manager"));
        tableView = new QTableView(manager);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(40, 30, 981, 631));
        horizontalLayoutWidget = new QWidget(manager);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(40, 670, 1251, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(horizontalLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout->addWidget(pushButton_7);

        pushButton_11 = new QPushButton(horizontalLayoutWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        horizontalLayout->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(horizontalLayoutWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        horizontalLayout->addWidget(pushButton_12);

        pushButton_9 = new QPushButton(horizontalLayoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        horizontalLayout->addWidget(pushButton_9);

        pushButton_5 = new QPushButton(horizontalLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        verticalLayoutWidget = new QWidget(manager);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(1030, 29, 261, 631));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        lineEdit_5 = new QLineEdit(verticalLayoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout->addWidget(lineEdit_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        lineEdit_6 = new QLineEdit(verticalLayoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        verticalLayout->addWidget(lineEdit_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        stackedWidget->addWidget(manager);
        newCustomer = new QWidget();
        newCustomer->setObjectName(QString::fromUtf8("newCustomer"));
        pushButton_2 = new QPushButton(newCustomer);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(620, 640, 75, 23));
        stackedWidget->addWidget(newCustomer);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1318, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_4, SIGNAL(released()), MainWindow, SLOT(customerLogin()));
        QObject::connect(pushButton_6, SIGNAL(released()), MainWindow, SLOT(adminLogin()));
        QObject::connect(pushButton, SIGNAL(released()), MainWindow, SLOT(logout()));
        QObject::connect(pushButton_2, SIGNAL(released()), MainWindow, SLOT(logout()));
        QObject::connect(pushButton_3, SIGNAL(released()), MainWindow, SLOT(logout()));

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "User Name", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Manager", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Buy N Large Login", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "logout", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Admin screen", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Change Status", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "logout", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "ID number", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Date Joined", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
