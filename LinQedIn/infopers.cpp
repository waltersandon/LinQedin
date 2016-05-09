#include "infopers.h"

InfoPers::InfoPers(string n,string c, Data d, string des):
nome(n),cognome(c),nascita(d), descrizione(des){}

string InfoPers::visualizza_nome()const{return nome;}

void InfoPers::modifica_nome(const string& s){nome=s;}

string InfoPers::visualizza_cognome()const{return cognome;}

void InfoPers::modifica_cognome(const string& s){cognome=s;}

Data InfoPers::visualizza_nascita()const{return nascita;}

void InfoPers::modifica_nascita(const Data & d){
    nascita.modifica_data(d);
}
void InfoPers::modifica_anno_nascita(int a){nascita.modifica_anno(a);}
void InfoPers::modifica_mese_nascita(int m){
    nascita.modifica_mese(m);
    Data::consistenza(nascita);//non inserisco una data non corretta
}

void InfoPers::modifica_giorno_nascita(int g){
    nascita.modifica_giorno(g);
    Data::consistenza(nascita);
}

string InfoPers::visualizza_descrizione()const{return descrizione;}

void InfoPers::modifica_descrizione(const string& s){descrizione=s;}
