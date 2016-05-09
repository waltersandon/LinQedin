#include "basic.h"

Basic::Basic(string u, string n, string c, Data d, string descr, Profilo* pr, vector<Rete*> r):
    Utente(u,n,c,d,descr,pr,r){}

void Basic::trova_tipo_utente(const DataBase& db, const string& user, QList<QString>& list){
    Utente* ut = db.trova_utente(user);
    Utente::Functor f(1);
    f(ut, list);
}

Basic::~Basic(){}

double Basic::costo_annuale()const{return 0;}
