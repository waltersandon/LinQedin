#ifndef INFOPERS_H
#define INFOPERS_H

#include"data.h"
#include<string>
using std::string;

class InfoPers{
private:
    string nome;
    string cognome;
    Data nascita;
    string descrizione;
public:
    InfoPers(string,string,Data,string="");

    string visualizza_nome()const;
    void modifica_nome(const string&);

    string visualizza_cognome()const;
    void modifica_cognome(const string&);

    Data visualizza_nascita()const;
    void modifica_nascita(const Data&);
    void modifica_anno_nascita(int);
    void modifica_mese_nascita(int);
    void modifica_giorno_nascita(int);


    string visualizza_descrizione()const;
    void modifica_descrizione(const string&);

};

#endif // INFOPERS_H


