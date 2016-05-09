#include"mainwindow.h"
#include<QApplication>
#include"database.h"
using namespace std;

int main(int argc, char *argv[]){

    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    return app.exec();


}

