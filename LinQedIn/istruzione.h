#ifndef ISTRUZIONE_H
#define ISTRUZIONE_H
#include<string>
using std::string;

class Istruzione{
private:
    string titolo_di_studio;
    int anno_inizio;
    int anno_diploma;

public:
    Istruzione(string, int, int);

    string visualizza_titolo_di_studio()const;
    void modifica_titilo_di_studio(const string&);

    int visualizza_anno_inizio()const;
    void modifica_anno_inizio(int);

    int visualizza_anno_diploma()const;
    void modifica_anno_diploma(int);
};

#endif // ISTRUZIONE_H
