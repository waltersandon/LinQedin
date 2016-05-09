#include "linqedinadmin.h"


LinqedInAdmin::LinqedInAdmin(DataBase* d):db(d)
{}

LinqedInAdmin::~LinqedInAdmin(){
    if(db)
        delete db;
}

bool LinqedInAdmin::aggiungi_utente(Utente * u){
    return db->aggiungi_utente(u);
}

void LinqedInAdmin::rimuovi_utente(const string& u){
    db->rimuovi_utente(u);
}

Utente* LinqedInAdmin::trova_utente(const string& u) const{
    return db->trova_utente(u);
}

DataBase* LinqedInAdmin::visualizza_bd()const{
    return db;
}


