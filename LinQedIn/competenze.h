#ifndef COMPETENZE_H
#define COMPETENZE_H
#include<string>
using std::string;

class Competenze{
private:
    string competenza;
    int valutazione;
public:
    Competenze(string , int);
    ~Competenze();

    string visualizza_competenza()const;
    void modifica_competenza(const string&);

    int visualizza_valutazione();
    void modifica_valutazione(int);

};

#endif // COMPETENZE_H
