#ifndef LINQEDINCLIENT_H
#define LINQEDINCLIENT_H
#include"database.h"

class LinqedInClient{
private:
    Utente* client;
    DataBase* db;
public:
    LinqedInClient(DataBase*, Utente*);
    ~LinqedInClient();

    Utente* visualizza_client()const;

    DataBase* visualizza_db()const;

    void aggiungi_contatto(const string&);
    void rimuovi_contatto(const string&);
};

#endif // LINQEDINCLIENT_H
