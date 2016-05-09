#include "mainwindow.h"
#include"QFileDialog"
#include"QMessageBox"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    db=new DataBase;

    title = new QLabel(this);
    adminBox = new QGroupBox(this);
    clientBox = new QGroupBox(this);
    lineEditAdmin = new QLineEdit(adminBox);
    lineEdit = new QLineEdit(clientBox);
    admin = new QPushButton(adminBox);
    client = new QPushButton(clientBox);

    setupView();

    connect(admin, SIGNAL(clicked()), this, SLOT(on_admin()));
    connect(client,SIGNAL(clicked()),this,SLOT(on_client()));
}

MainWindow::~MainWindow(){}

void MainWindow::setupView(){
    resize(750, 400);

    setWindowTitle("Login Area");

    QFont font, fontbox, fontbutton, fontTitle;
    fontbox.setPixelSize(15);
    fontbox.setItalic(true);
    fontbutton.setPixelSize(15);
    fontbutton.setItalic(true);
    font.setPixelSize(18);
    font.setItalic(true);
    fontTitle.setPixelSize(50);
    title->setStyleSheet("QLabel {color : #0080FF; }");

    title->setGeometry(QRect(200,30, 350, 80));
    adminBox->setGeometry(QRect(50, 150, 300, 150));
    clientBox->setGeometry(QRect(400, 150, 300, 150));
    adminBox->setFont(fontbox);
    clientBox->setFont(fontbox);

    admin->setGeometry(QRect(100,100,100,40));
    client->setGeometry(QRect(100,100,100,40));
    admin->setFont(fontbutton);
    client->setFont(fontbutton);


    lineEditAdmin->setGeometry(QRect(50,45,200,40));
    lineEditAdmin->setClearButtonEnabled(true);
    lineEditAdmin->setFont(font);
    lineEdit->setFont(font);
    lineEdit->setGeometry(QRect(50,45,200,40));
    lineEdit->setClearButtonEnabled(true);
    title->setFont(fontTitle);
    title->setText("LinQedIn");
    title->setAlignment(Qt::AlignCenter);
    adminBox->setTitle("Admin Area");
    clientBox->setTitle("Client Area");
    admin->setText("Login");
    client->setText("Login");
    lineEditAdmin->setPlaceholderText("   Inserisci Password");
    lineEdit->setPlaceholderText("  Inserisci Username");
    lineEditAdmin->setEchoMode(QLineEdit::Password);
}

DataBase* MainWindow::visualizza_db()const{
    return db;
}

void MainWindow::on_admin(){
    QString pwd= lineEditAdmin->text();
    if(pwd==QString::fromStdString(db->visualizza_pwd())){
        LinqedInAdmin* admin=new LinqedInAdmin(db);
        AdminWindow *admWindow=new AdminWindow(admin);
        admWindow->exec();
    }
    else {
        QMessageBox err;
        err.setText("  Inserisci una Password corretta");
        err.exec();
    }
}

void MainWindow::on_client(){
    QString username = lineEdit->text();
    Utente* ut= db->trova_utente(username.toStdString());
    if(ut){
        LinqedInClient* client=new LinqedInClient(db, ut);
        ClientWindow* clientWindow=new ClientWindow(client);
        clientWindow->exec();
    }
    else{
        QMessageBox err;
        err.setText("  Inserisci un Username valido");
        err.exec();
    }

}
