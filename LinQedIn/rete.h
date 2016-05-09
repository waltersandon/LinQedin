#ifndef RETE_H
#define RETE_H

#include<string>
using std::string;

class Utente;

class Rete{
private:
    string contatto;
public:
    Rete(const string&);
    ~Rete();
    string visualizza_contatto()const;
};

#endif // RETE_H
