#include "linqedinclient.h"

LinqedInClient::LinqedInClient(DataBase* d, Utente* u): client(u), db(d){}

LinqedInClient::~LinqedInClient()
{
    if(client)
        delete client;
    if(db)
        delete db;
}

Utente* LinqedInClient::visualizza_client() const{
    return client;
}

DataBase* LinqedInClient::visualizza_db()const{
    return db;
}

void LinqedInClient::aggiungi_contatto(const string& s){
    Rete* aux = new Rete(s);
    client->aggiungi_contatto(*aux);
}

void LinqedInClient::rimuovi_contatto(const string& s){
    client->rimuovi_contatto(s);
}
