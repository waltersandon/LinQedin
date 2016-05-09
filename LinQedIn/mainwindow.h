#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<QVBoxLayout>
#include<QGroupBox>
#include<QPushButton>
#include<QLineEdit>
#include<QMenuBar>
#include<QToolBar>
#include<QStatusBar>
#include"adminwindow.h"
#include"clientwindow.h"
#include"linqedinclient.h"
#include"linqedinadmin.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupView();
    DataBase* visualizza_db()const;
signals:

private slots:
    void on_admin();
    void on_client();

private:

    DataBase *db;

    QLabel *title;
    QGroupBox *adminBox;
    QPushButton *admin;
    QLineEdit *lineEditAdmin;
    QGroupBox *clientBox;
    QPushButton *client;
    QLineEdit *lineEdit;
};

#endif // MAINWINDOW_H
