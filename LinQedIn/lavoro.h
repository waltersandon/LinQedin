#ifndef LAVORO_H
#define LAVORO_H

#include<string>
using std::string;
#include"data.h"

class Lavoro{
private:
    string esperienza_lav;
    Data inizio_esp;
    Data fine_esp;
public:
    Lavoro(string, Data, Data);

    string visualizza_esp()const;
    void modifica_esp(const string&);

    Data visualizza_inizio_esp()const;
    void modifica_inizio_esp(const Data&);

    Data visualizza_fine_esp()const;
    void modifica_fine_esp(const Data&);
};

#endif // LAVORO_H
