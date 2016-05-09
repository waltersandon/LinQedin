#include "competenze.h"

Competenze::Competenze(string c, int v):
    competenza(c),valutazione(v){
    if(v<0) valutazione=1;
    else if(v>10) valutazione=10;
}

Competenze::~Competenze(){}

string Competenze::visualizza_competenza()const{
    return competenza;
}

void Competenze::modifica_competenza(const string &c){
    competenza=c;
}

int Competenze::visualizza_valutazione(){
    return valutazione;
}

void Competenze::modifica_valutazione(int v){
    if(v<0)
        valutazione=1;
    else if (v>10) valutazione=10;
    else valutazione=v;
}

