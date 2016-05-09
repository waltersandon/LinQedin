#include "executive.h"

double Executive::tariffa_executive=59.99;

Executive::Executive(string u, string n, string c, Data d, string descr, Profilo* pr,vector<Rete*> r):
    Utente(u,n,c,d,descr,pr,r){}

Executive::~Executive(){}

void Executive::trova_tipo_utente(const DataBase& db, const string& user, QList<QString>& list){
    Utente* ut = db.trova_utente(user);
    Utente::Functor f(3);
    f(ut, list);
}

double Executive::visualizza_tariffa(){
    return tariffa_executive;
}

double Executive::costo_annuale()const{
    return visualizza_tariffa();
}
