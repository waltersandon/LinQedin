#ifndef BUSINESS_H
#define BUSINESS_H
#include"utente.h"
#include"database.h"

class DataBase;
class Business : public Utente
{
private:

    static double tariffa_business;

public:

    Business(string, string, string, Data, string="", Profilo* = new Profilo(),vector<Rete*> = vector<Rete*>());

    ~Business();

    void trova_tipo_utente(const DataBase &, const string& u, QList<QString>&);

    static double visualizza_tariffa();
    double costo_annuale()const;

};


#endif // BUSINESS_H
