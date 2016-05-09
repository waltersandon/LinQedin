#ifndef LINQEDINADMIN_H
#define LINQEDINADMIN_H
#include"database.h"

class LinqedInAdmin{

private:

    DataBase* db;

public:

    LinqedInAdmin(DataBase*);
    ~LinqedInAdmin();

    bool aggiungi_utente(Utente*);//aggiunge un utente nel database
    void rimuovi_utente(const string&);//rimuove un utente dal database
    Utente* trova_utente(const string&)const;//ritorna il puntatore a quell'utente
    DataBase* visualizza_bd()const;

};

#endif // LINQEDINADMIN_H
