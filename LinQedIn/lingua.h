#ifndef LINGUA_H
#define LINGUA_H

#include<string>
using std::string;

class Lingua{
private:

    string descrizione;
    string comprensione;
    string parlato;
    string scritto;


public:


    Lingua(const string&, const string&, const string&, const string&);


    string visualizza_descrizione() const;
    string visualizza_comprensione() const;
    string visualizza_parlato() const;
    string visualizza_scritto() const;

    void modifica_descrizione(const string&);
    void modifica_comprensione(const string&);
    void modifica_parlato(const string&);
    void modifica_scritto(const string&);

};

#endif // LINGUA_H
