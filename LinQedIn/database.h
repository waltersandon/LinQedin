#ifndef DATABASE_H
#define DATABASE_H

#include"utente.h"
#include"basic.h"
#include"business.h"
#include"executive.h"
#include"QFile"
#include"QXmlStreamReader"
#include"QXmlStreamWriter"
#include"QStringList"
#include"QFileDialog"
#include"QMessageBox"

class DataBase{
private:

    string static password;
    vector<Utente*> all;

public:

    DataBase();

    ~DataBase();

    static string visualizza_pwd();
    static void modifica_pwd(const string&);

    bool db_vuoto()const;

    int numero_utenti()const;

    vector<Utente*> visualizza_bd()const;

    bool aggiungi_utente(Utente*);

    void rimuovi_utente(const string&);

    Utente* vai_ad_utente(int);

    Utente* trova_utente(const string&)const;

    Utente* last_utente();

     void cambio_tipo(const string&, const string&);

    void write_competenza(QXmlStreamWriter*, const Utente&)const;

    void write_esp_lav(QXmlStreamWriter*, const Utente&)const;

    void write_studio(QXmlStreamWriter*, const Utente&)const;

    void write_lingua(QXmlStreamWriter*, const Utente&)const;

    void carica();
    void carica_pwd();

    void salva()const;
    void salva_pwd()const;

};

#endif // DATABASE_H
