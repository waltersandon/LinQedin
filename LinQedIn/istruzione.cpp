#include "istruzione.h"

Istruzione::Istruzione(string s, int i, int f):
    titolo_di_studio(s), anno_inizio(i), anno_diploma(f){
  if(f<i)anno_diploma=anno_inizio;
}

string Istruzione::visualizza_titolo_di_studio()const{return titolo_di_studio;}

void Istruzione::modifica_titilo_di_studio(const string& s){titolo_di_studio=s;}

int Istruzione::visualizza_anno_inizio()const{return anno_inizio;}

void Istruzione::modifica_anno_inizio(int i){anno_inizio=i;}

int Istruzione::visualizza_anno_diploma()const{return anno_diploma;}

void Istruzione::modifica_anno_diploma(int f){anno_diploma=f;}
