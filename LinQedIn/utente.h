#ifndef UTENTE_H
#define UTENTE_H

#include"profilo.h"
#include"rete.h"
#include"infopers.h"
#include<vector>
#include"QList"
#include"QString"
using std::vector;

class DataBase;

class Utente{
    //friend class Functor;
private:
    string username;
    InfoPers* info;
    Profilo* profile;
    vector<Rete*> network;
public:
    Utente(string, string, string, Data, string="", Profilo* = new Profilo(), vector<Rete*> = vector<Rete*>());
    virtual ~Utente();

    string visualizza_username()const;
    void modifica_username(const string&);

    InfoPers* visualizza_info()const;
    Profilo* visualizza_profilo()const;

    bool ho_contatti()const;
    int n_contatti()const;
    void aggiungi_contatto(const Rete&);//alla rete
    void rimuovi_contatto(const string&);//dalla rete
    Rete* vai_a_contatto(int)const;
    vector<Rete*> visualizza_network()const;

    virtual void trova_tipo_utente(const DataBase &, const string &, QList<QString> &) =0;
    virtual double costo_annuale()const =0;

    class Functor{
    public:
        int Tipo;
        Functor(int x=0) : Tipo(x) {}
        void operator() (const Utente* u, QList<QString>& list) const
        {
            switch(Tipo)
            {
                case 1:
                    list.push_back("Nome : "+QString::fromStdString(u->visualizza_info()->visualizza_nome()));
                    list.push_back("Cognome : "+QString::fromStdString(u->visualizza_info()->visualizza_cognome()));
                    list.push_back("Anno di Nascita : "+QString::fromStdString(u->visualizza_info()->visualizza_nascita().toString()));
                    list.push_back("Competenze : NON DISPONIBILI");
                    list.push_back("Esperienze Lavorative : NON DISPONIBILI");
                    list.push_back("Titoli di studio : NON DISPONIBILI");
                    list.push_back("Lingue : NON DISPONIBILI");
                    list.push_back("Contatti : NON DISPONIBILI");
                    break;
                case 2:
                list.push_back("Nome : "+QString::fromStdString(u->visualizza_info()->visualizza_nome()));
                list.push_back("Cognome : "+QString::fromStdString(u->visualizza_info()->visualizza_cognome()));
                list.push_back("Anno di Nascita : "+QString::fromStdString(u->visualizza_info()->visualizza_nascita().toString()));
                for(int i=0 ; i< u->visualizza_profilo()->n_competenze();++i){
                    QString competenza=QString::fromStdString(u->visualizza_profilo()->vai_a_competenza(i)->visualizza_competenza()).append(" con voto ").append(
                                QString::number(u->visualizza_profilo()->vai_a_competenza(i)->visualizza_valutazione()));
                    list.push_back("Competenza : "+competenza);
                }
                for(int i=0 ; i< u->visualizza_profilo()->n_lavori();++i){
                                    QString esperienza=QString::fromStdString(u->visualizza_profilo()->vai_a_lavoro(i)->visualizza_esp()).append(" dal ").append(
                                                QString::fromStdString(u->visualizza_profilo()->vai_a_lavoro(i)->visualizza_inizio_esp().toString()))
                                            .append(" al ").append(QString::fromStdString(u->visualizza_profilo()->vai_a_lavoro(i)->visualizza_inizio_esp().toString()));
                                    list.push_back("Esperienza : "+esperienza);
                                }

                for(int i=0 ; i< u->visualizza_profilo()->n_istruzioni();++i){
                    QString istruzione=QString::fromStdString(u->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_titolo_di_studio()).append(" Iniziato nel: ").append(
                                QString::number(u->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_inizio())).append(" diplomato nel:")
                            .append(QString::number(u->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_diploma()));
                    list.push_back("Istruzione : "+istruzione);
                }
                for(int i=0 ; i< u->visualizza_profilo()->n_lingue();++i){
                    QString lingua=QString::fromStdString(u->visualizza_profilo()->vai_a_lingua(i)->visualizza_descrizione()).append(" Livello Comprensione: ").append(
                                QString::fromStdString(u->visualizza_profilo()->vai_a_lingua(i)->visualizza_comprensione())).append(" Livello Parlato: ").append(
                                QString::fromStdString(u->visualizza_profilo()->vai_a_lingua(i)->visualizza_parlato())).append(" Livello Scritto: ").append(
                                QString::fromStdString(u->visualizza_profilo()->vai_a_lingua(i)->visualizza_scritto()));
                    list.push_back("Lingua : "+lingua);
                }
                list.push_back("Contatti : NON DISPONIBILI");
                    break;

                case 3:
                list.push_back("Nome : "+QString::fromStdString(u->visualizza_info()->visualizza_nome()));
                list.push_back("Cognome : "+QString::fromStdString(u->visualizza_info()->visualizza_cognome()));
                list.push_back("Anno di Nascita : "+QString::fromStdString(u->visualizza_info()->visualizza_nascita().toString()));
                for(int i=0 ; i< u->visualizza_profilo()->n_competenze();++i){
                    QString competenza=QString::fromStdString(u->visualizza_profilo()->vai_a_competenza(i)->visualizza_competenza()).append(" con voto ").append(
                                QString::number(u->visualizza_profilo()->vai_a_competenza(i)->visualizza_valutazione()));
                    list.push_back("Competenza : "+competenza);
                }
                for(int i=0 ; i< u->visualizza_profilo()->n_lavori();++i){
                                    QString esperienza=QString::fromStdString(u->visualizza_profilo()->vai_a_lavoro(i)->visualizza_esp()).append(" dal ").append(
                                                QString::fromStdString(u->visualizza_profilo()->vai_a_lavoro(i)->visualizza_inizio_esp().toString()))
                                            .append(" al ").append(QString::fromStdString(u->visualizza_profilo()->vai_a_lavoro(i)->visualizza_inizio_esp().toString()));
                                    list.push_back("Esperienza : "+esperienza);
                                }

                for(int i=0 ; i< u->visualizza_profilo()->n_istruzioni();++i){
                    QString istruzione=QString::fromStdString(u->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_titolo_di_studio()).append(" Iniziato nel: ").append(
                                QString::number(u->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_inizio())).append(" diplomato nel: ")
                            .append(QString::number(u->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_diploma()));
                    list.push_back("Istruzione : "+istruzione);
                }
                for(int i=0 ; i< u->visualizza_profilo()->n_lingue();++i){
                    QString lingua=QString::fromStdString(u->visualizza_profilo()->vai_a_lingua(i)->visualizza_descrizione()).append(" Livello Comprensione: ").append(
                                QString::fromStdString(u->visualizza_profilo()->vai_a_lingua(i)->visualizza_comprensione())).append(" Livello Parlato: ").append(
                                QString::fromStdString(u->visualizza_profilo()->vai_a_lingua(i)->visualizza_parlato())).append(" Livello Scritto: ").append(
                                QString::fromStdString(u->visualizza_profilo()->vai_a_lingua(i)->visualizza_scritto()));
                    list.push_back("Lingua : "+lingua);
                }
                for(int i=0; i< u->n_contatti();++i){
                   list.push_back("Contatto : "+QString::fromStdString(u->vai_a_contatto(i)->visualizza_contatto()));
                }
                break;
            }
        }
    };
};

#endif // UTENTE_H
