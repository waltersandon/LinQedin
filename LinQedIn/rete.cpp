#include "rete.h"

Rete::Rete(const string& s):contatto(s){}

string Rete::visualizza_contatto()const{
    return contatto;
}

Rete::~Rete(){}
