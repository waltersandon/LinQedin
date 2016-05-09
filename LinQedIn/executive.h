#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include"utente.h"
#include"database.h"

class DataBase;
class Executive : public Utente{
private:
    static double tariffa_executive;
public:
    Executive(string, string, string, Data, string="", Profilo* = new Profilo(),vector<Rete*> = vector<Rete*>());

    ~Executive();

    void trova_tipo_utente(const DataBase&, const string& u, QList<QString>&) ;

    static double visualizza_tariffa();
    double costo_annuale()const;
};

#endif // EXECUTIVE_H
