#include "lingua.h"


Lingua::Lingua(const string& d, const string& c, const string& p, const string& s):
descrizione(d), comprensione(c), parlato(p), scritto(s){}

string Lingua::visualizza_descrizione()const{return descrizione;}
string Lingua::visualizza_comprensione()const{return comprensione;}
string Lingua::visualizza_parlato()const{return parlato;}
string Lingua::visualizza_scritto()const{return scritto;}

void Lingua::modifica_descrizione(const string& s){descrizione=s;}
void Lingua::modifica_comprensione(const string& s){comprensione=s;}
void Lingua::modifica_parlato(const string& s){parlato=s;}
void Lingua::modifica_scritto(const string& s){scritto=s;}


