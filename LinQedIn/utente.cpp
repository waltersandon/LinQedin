#include "utente.h"

Utente::Utente(string u, string n, string c, Data d, string descr, Profilo* pr,vector<Rete*> r):
    username(u), info(new InfoPers(n,c,d,descr)), profile(pr), network(r){}

Utente::~Utente()
{
    //mi assicuro che venga distrutto anche l'oggetto Infopers e non solo il puntatore
    if(info)
        delete info;
    //stessa cosa per l'oggetto Profilo
    if(profile)
        delete profile;
    vector<Rete*>::iterator it=network.begin();
    //scorro network e in ogni elemento prendo l'utente della rete
    //ad ogni utente invoco rimuovi_utente che elimina me nella
    //lista di utente e poi elimino l'utente dalla rete
    for(;it!=network.end();++it) delete *it;
}

string Utente::visualizza_username()const{return username;}

void Utente::modifica_username(const string& s){username=s;}

InfoPers* Utente::visualizza_info()const{return info;}

Profilo* Utente::visualizza_profilo()const{return profile;}

bool Utente::ho_contatti()const{return network.size()==0;}

int Utente::n_contatti()const{return network.size();}

void Utente::aggiungi_contatto(const Rete & net){
    Rete* aux=const_cast<Rete*>(&net);
    network.push_back(aux);
}

void Utente::rimuovi_contatto(const string& user){
    for(int i=0; i<n_contatti();++i){
        if(vai_a_contatto(i)->visualizza_contatto()==user){
            delete vai_a_contatto(i);
            network.erase(network.begin()+i);
        }
    }
}

Rete* Utente::vai_a_contatto(int i)const{
    vector<Rete*>::const_iterator it=network.begin()+i;
        return *it;
}

vector<Rete*> Utente::visualizza_network()const{
    return network;
}
