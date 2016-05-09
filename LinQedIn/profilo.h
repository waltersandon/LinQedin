#ifndef PROFILO_H
#define PROFILO_H

#include"competenze.h"
#include"lavoro.h"
#include"istruzione.h"
#include"lingua.h"
#include<vector>
using std::vector;


class Profilo{
private:
    vector<Competenze*> c;
    vector<Lavoro*> l;
    vector<Istruzione*> i;
    vector<Lingua*> li;
public:
    Profilo();
    ~Profilo();

    bool c_vuoto()const;
    bool l_vuoto()const;
    bool i_vuoto()const;
    bool li_vuoto()const;

    int n_competenze()const;
    int n_lavori()const;
    int n_istruzioni()const;
    int n_lingue()const;

    void aggiungi_competenza(const Competenze&);
    void aggiungi_lavoro(const Lavoro&);
    void aggiungi_titolo_studio(const Istruzione&);
    void aggiungi_lingua(const Lingua&);

    void rimuovi_competenza(int);
    void rimuovi_lavoro(int);
    void rimuovi_titolo_studio(int);
    void rimuovi_lingua(int);

    Competenze* vai_a_competenza(int);
    Lavoro* vai_a_lavoro(int);
    Istruzione* vai_a_titolo_studio(int);
    Lingua* vai_a_lingua(int);
};

#endif // PROFILO_H
