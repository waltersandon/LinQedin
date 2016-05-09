#include "business.h"

double Business::tariffa_business=17.99;

Business::Business(string u, string n, string c, Data d, string descr, Profilo* pr, vector<Rete*> r):
Utente(u,n,c,d,descr,pr,r){}

Business::~Business(){}

void Business::trova_tipo_utente(const DataBase& db, const string& user, QList<QString>& list){
    Utente* ut = db.trova_utente(user);
    Utente::Functor f(2);
    f(ut, list);
}

double Business::visualizza_tariffa(){
    return tariffa_business;
}

double Business::costo_annuale()const{
    return visualizza_tariffa();
}
