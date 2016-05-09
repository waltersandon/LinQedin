#ifndef BASIC_H
#define BASIC_H

#include"utente.h"
#include"database.h"

class DataBase;

class Basic:public Utente{
public:
    Basic(string, string, string, Data, string="", Profilo* = new Profilo(),vector<Rete*> = vector<Rete*>());

    ~Basic();

    void trova_tipo_utente(const DataBase&, const string& u, QList<QString>&) ;

    double costo_annuale()const;

};

#endif // BASIC_H
#include"utente.h"

