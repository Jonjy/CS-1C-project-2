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
#include <QtWidgets/QGroupBox>
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
    QWidget *page;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_4;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *page_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *manager;
    QTableView *tableView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_13;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_21;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_51;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_12;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_11;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_31;
    QSpacerItem *horizontalSpacer_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QComboBox *DayBox;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_9;
    QComboBox *IDBox;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_11;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QLabel *label_21;
    QLineEdit *NameEdit;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_3;
    QLineEdit *IDEdit;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_7;
    QLineEdit *statusEdit;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_3;
    QLabel *label_31;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_71;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLabel *label_71;
    QLabel *label_8;
    QPushButton *pushButton_8;
    QTableView *tableView1;
    QPushButton *pushButton_9;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1009, 602);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, -20, 1011, 561));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setStyleSheet(QString::fromUtf8("background-image: url(:/photos/photos/bulkclub.jpeg);"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(740, 330, 241, 171));
        groupBox->setStyleSheet(QString::fromUtf8("background:rgba(255,255,255,.2);\n"
"background-color: rgb(255, 255, 255);"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 70, 71, 21));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 70, 113, 20));
        lineEdit->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 161, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Mongolian Baiti"));
        font1.setPointSize(26);
        font1.setBold(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        label_2->setFont(font1);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 100, 171, 16));
        QFont font2;
        font2.setPointSize(10);
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 120, 241, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_10 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        horizontalLayout_2->addWidget(pushButton_10);

        pushButton = new QPushButton(horizontalLayoutWidget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(810, 520, 91, 31));
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(910, 520, 91, 31));
        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(340, 250, 201, 91));
        QFont font3;
        font3.setPointSize(14);
        pushButton_5->setFont(font3);
        stackedWidget->addWidget(page_2);
        manager = new QWidget();
        manager->setObjectName(QString::fromUtf8("manager"));
        tableView = new QTableView(manager);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 30, 751, 491));
        horizontalLayoutWidget = new QWidget(manager);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 519, 981, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        pushButton_13 = new QPushButton(horizontalLayoutWidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        horizontalLayout->addWidget(pushButton_13);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        pushButton_21 = new QPushButton(horizontalLayoutWidget);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));

        horizontalLayout->addWidget(pushButton_21);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        pushButton_7 = new QPushButton(horizontalLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout->addWidget(pushButton_7);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        pushButton_51 = new QPushButton(horizontalLayoutWidget);
        pushButton_51->setObjectName(QString::fromUtf8("pushButton_51"));

        horizontalLayout->addWidget(pushButton_51);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        pushButton_12 = new QPushButton(horizontalLayoutWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        horizontalLayout->addWidget(pushButton_12);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_11 = new QPushButton(horizontalLayoutWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        horizontalLayout->addWidget(pushButton_11);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        pushButton_31 = new QPushButton(horizontalLayoutWidget);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));

        horizontalLayout->addWidget(pushButton_31);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayoutWidget = new QWidget(manager);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(790, 29, 221, 491));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        DayBox = new QComboBox(verticalLayoutWidget);
        DayBox->setObjectName(QString::fromUtf8("DayBox"));

        verticalLayout->addWidget(DayBox);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        IDBox = new QComboBox(verticalLayoutWidget);
        IDBox->setObjectName(QString::fromUtf8("IDBox"));

        verticalLayout->addWidget(IDBox);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_21 = new QLabel(verticalLayoutWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout->addWidget(label_21);

        NameEdit = new QLineEdit(verticalLayoutWidget);
        NameEdit->setObjectName(QString::fromUtf8("NameEdit"));

        verticalLayout->addWidget(NameEdit);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        IDEdit = new QLineEdit(verticalLayoutWidget);
        IDEdit->setObjectName(QString::fromUtf8("IDEdit"));

        verticalLayout->addWidget(IDEdit);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        statusEdit = new QLineEdit(verticalLayoutWidget);
        statusEdit->setObjectName(QString::fromUtf8("statusEdit"));

        verticalLayout->addWidget(statusEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        stackedWidget->addWidget(manager);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_31 = new QLabel(page_3);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(80, 120, 111, 21));
        lineEdit_2 = new QLineEdit(page_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(180, 120, 113, 20));
        pushButton_6 = new QPushButton(page_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(190, 150, 75, 23));
        pushButton_71 = new QPushButton(page_3);
        pushButton_71->setObjectName(QString::fromUtf8("pushButton_71"));
        pushButton_71->setGeometry(QRect(920, 530, 75, 23));
        groupBox_2 = new QGroupBox(page_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(60, 280, 291, 201));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 151, 16));
        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(120, 40, 113, 20));
        lineEdit_4 = new QLineEdit(groupBox_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(120, 70, 113, 20));
        lineEdit_5 = new QLineEdit(groupBox_2);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(120, 100, 113, 20));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(16, 40, 81, 20));
        label_71 = new QLabel(groupBox_2);
        label_71->setObjectName(QString::fromUtf8("label_71"));
        label_71->setGeometry(QRect(20, 70, 81, 20));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 100, 91, 20));
        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(120, 170, 75, 23));
        tableView1 = new QTableView(page_3);
        tableView1->setObjectName(QString::fromUtf8("tableView1"));
        tableView1->setGeometry(QRect(440, 100, 551, 291));
        pushButton_9 = new QPushButton(page_3);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(580, 420, 111, 41));
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1009, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Bulk Club", nullptr));
        label_4->setText(QString());
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Manger", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Admin Stuff", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Stock Screen", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "Customer Screen", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Customer info", nullptr));
        pushButton_51->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Regular Sales", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Executive sales", nullptr));
        pushButton_31->setText(QCoreApplication::translate("MainWindow", "logout", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Select Day:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Select Customer ID:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Select Item:", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "ID number", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "enter name 2 delete", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        pushButton_71->setText(QCoreApplication::translate("MainWindow", "back", nullptr));
        groupBox_2->setTitle(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Enter info 2 add user", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "first/last name", nullptr));
        label_71->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "status (reg/exec)", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Load/Update Table", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
