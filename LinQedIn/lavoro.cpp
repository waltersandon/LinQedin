#include "lavoro.h"

Lavoro::Lavoro(string e, Data i, Data f):esperienza_lav(e),
    inizio_esp(i),fine_esp(f){if(f<=i)fine_esp=i;}

string Lavoro::visualizza_esp()const{return esperienza_lav;}

void Lavoro::modifica_esp(const string& s){esperienza_lav=s;}

Data Lavoro::visualizza_inizio_esp()const{return inizio_esp;}

void Lavoro::modifica_inizio_esp(const Data & d){inizio_esp=d;}

Data Lavoro::visualizza_fine_esp()const{return fine_esp;}

void Lavoro::modifica_fine_esp(const Data & d){fine_esp=d;}
