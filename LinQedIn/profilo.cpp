#include "profilo.h"

Profilo::Profilo(){}

Profilo::~Profilo(){
    vector<Competenze*>::iterator it1=c.begin();
    vector<Lavoro*>::iterator it2=l.begin();
    vector<Istruzione*>::iterator it3=i.begin();
    vector<Lingua*>::iterator it4=li.begin();

    for(;it1!=c.end();++it1)
            delete *it1;
    for(;it2!=l.end();++it2)
            delete *it2;
    for(;it3!=i.end();++it3)
            delete *it3;
    for(;it4!=li.end();++it4)
            delete *it4;
}

bool Profilo::c_vuoto()const{
    return c.size()==0;
}

bool Profilo::l_vuoto()const{
    return l.size()==0;
}

bool Profilo::i_vuoto()const{
    return i.size()==0;
}

bool Profilo::li_vuoto()const{
    return li.size()==0;
}

int Profilo::n_competenze()const{
    return c.size();
}

int Profilo::n_lavori() const{
    return l.size();
}

int Profilo::n_istruzioni() const{
    return i.size();
}

int Profilo::n_lingue()const{
    return li.size();
}

void Profilo::aggiungi_competenza(const Competenze & com){
    Competenze* aux=const_cast<Competenze*>(&com);
    c.push_back(aux);
}

void Profilo::aggiungi_lavoro(const Lavoro & lav){
    Lavoro* aux=const_cast<Lavoro*>(&lav);
    l.push_back(aux);
}

void Profilo::aggiungi_titolo_studio(const Istruzione & is){
    Istruzione* aux=const_cast<Istruzione*>(&is);
    i.push_back(aux);
}

void Profilo::aggiungi_lingua(const Lingua & l){
    Lingua* aux=const_cast<Lingua*>(&l);
    li.push_back(aux);
}

void Profilo::rimuovi_competenza(int pos){
    vector<Competenze*>::iterator it=c.begin()+pos;
        if(*it)
            delete *it;
        c.erase(it);
}

void Profilo::rimuovi_lavoro(int pos){
    vector<Lavoro*>::iterator it=l.begin()+pos;
        if(*it)
            delete *it;
        l.erase(it);
}

void Profilo::rimuovi_titolo_studio(int pos){
    vector<Istruzione*>::iterator it=i.begin()+pos;
        if(*it)
            delete *it;
        i.erase(it);
}

void Profilo::rimuovi_lingua(int pos){
    vector<Lingua*>::iterator it=li.begin()+pos;
        if(*it)
            delete *it;
        li.erase(it);
}


Competenze* Profilo::vai_a_competenza(int pos){
    vector<Competenze*>::iterator it=c.begin()+pos;
    return *it;
}


Lavoro* Profilo::vai_a_lavoro(int pos){
    vector<Lavoro*>::iterator it=l.begin()+pos;
    return *it;
}

Istruzione* Profilo::vai_a_titolo_studio(int pos){
    vector<Istruzione*>::iterator it=i.begin()+pos;
    return *it;
}

Lingua* Profilo::vai_a_lingua(int pos){
    vector<Lingua*>::iterator it=li.begin()+pos;
    return *it;
}
