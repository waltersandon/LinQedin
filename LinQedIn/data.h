#ifndef DATA_H
#define DATA_H

#include <string>
#include <sstream>
#include <iostream>
#include <istream>
using std::string;

class Data{
private:
    int giorno;
    int mese;
    int anno;
    static bool consistenza(const int&, const int&, const int&);
public:
    static bool consistenza(const Data&);

    Data(int =1, int =1, int =2000);
    Data(const Data&);
    int visualizza_giorno() const;
    int visualizza_mese() const;
    int visualizza_anno() const;

    Data& operator =(const Data&);
    bool modifica_data(const Data&);//simile ad operator= ma con tipo di ritorno diverso
    void modifica_anno(int);
    void modifica_mese(int);
    void modifica_giorno(int);

    bool operator==(const Data&) const;
    bool operator!=(const Data&) const;
    bool operator<(const Data&) const;
    bool operator<=(const Data&) const;
    bool operator>(const Data&) const;
    bool operator>=(const Data&) const;

    string toString() const;
};
#endif // DATA_H
