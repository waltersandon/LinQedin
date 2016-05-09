#include "database.h"

string DataBase::password="Admin";

DataBase::DataBase(){carica();}

DataBase::~DataBase(){
    for(vector<Utente*>::iterator it= all.begin(); it!=all.end();++it)
        delete *it;
}

string DataBase::visualizza_pwd(){return password;}

void DataBase::modifica_pwd(const string& pwd){password=pwd;}

bool DataBase::db_vuoto()const{
    return all.size();
}

int DataBase::numero_utenti()const{
    return all.size();
}

vector<Utente*> DataBase::visualizza_bd()const{
    return all;
}

//ritorna true se utente è già presente false se lo inserisce
bool DataBase::aggiungi_utente(Utente *ute){
    bool trovato=false;
       vector<Utente*>::iterator it= all.begin();
       for(; it!=all.end() && !trovato ;++it){
           if((*it)->visualizza_username()==ute->visualizza_username())
               trovato=true;
       }
       if(!trovato)
           all.push_back(ute);
       return trovato;
}

void DataBase::rimuovi_utente(const string& us){
    for(int i=0; i<numero_utenti();++i){
         if(vai_ad_utente(i)->visualizza_username()==us){
             delete vai_ad_utente(i);
             all.erase(all.begin()+i);
         }
     }
}

Utente* DataBase::vai_ad_utente(int i){
    vector<Utente*>::iterator it=all.begin()+i;
        return *it;
}

Utente* DataBase::last_utente(){
    return vai_ad_utente(all.size()-1);
}

void DataBase::cambio_tipo(const string& us, const string& tipo){
    Utente *aux=trova_utente(us);
    string u=aux->visualizza_username();
    string n=aux->visualizza_info()->visualizza_nome();
    string c=aux->visualizza_info()->visualizza_cognome();
    Data data=aux->visualizza_info()->visualizza_nascita();
    string d=aux->visualizza_info()->visualizza_descrizione();
    Profilo * newProfilo= new Profilo();
    vector<Rete*> contatti=vector<Rete*>();
    for(int i=0; i<aux->visualizza_profilo()->n_competenze();++i){
        string competenza=aux->visualizza_profilo()->vai_a_competenza(i)->visualizza_competenza();
        int voto=aux->visualizza_profilo()->vai_a_competenza(i)->visualizza_valutazione();
        Competenze* newCompetenza=new Competenze(competenza,voto);
        newProfilo->aggiungi_competenza(*newCompetenza);
    }
    for(int i=0; i<aux->visualizza_profilo()->n_lavori();++i){
        string esperienza=aux->visualizza_profilo()->vai_a_lavoro(i)->visualizza_esp();
        Data inizio=aux->visualizza_profilo()->vai_a_lavoro(i)->visualizza_inizio_esp();
        Data fine=aux->visualizza_profilo()->vai_a_lavoro(i)->visualizza_fine_esp();
        Lavoro* newEsperienza= new Lavoro(esperienza,inizio,fine);
        newProfilo->aggiungi_lavoro(*newEsperienza);
    }
    for(int i=0; i<aux->visualizza_profilo()->n_istruzioni();++i){
        string titolo=aux->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_titolo_di_studio();
        int inizio=aux->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_inizio();
        int fine=aux->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_diploma();
        Istruzione* newTitolo=new Istruzione(titolo,inizio,fine);
        newProfilo->aggiungi_titolo_studio(*newTitolo);
    }
    for(int i=0; i<aux->visualizza_profilo()->n_lingue();++i){
        string lingua=aux->visualizza_profilo()->vai_a_lingua(i)->visualizza_descrizione();
        string comprensione=aux->visualizza_profilo()->vai_a_lingua(i)->visualizza_comprensione();
        string parlato=aux->visualizza_profilo()->vai_a_lingua(i)->visualizza_parlato();
        string scritto=aux->visualizza_profilo()->vai_a_lingua(i)->visualizza_scritto();
        Lingua* newLingua=new Lingua(lingua, comprensione, parlato, scritto);
        newProfilo->aggiungi_lingua(*newLingua);
    }
    for(int i=0; i<aux->n_contatti();++i){
        string contatto=aux->vai_a_contatto(i)->visualizza_contatto();
        Rete* newRete= new Rete(contatto);
        contatti.push_back(newRete);
    }
    rimuovi_utente(us);
    Utente *newUtente=0;
    if(tipo=="Utente Basic"){
        newUtente=new Basic(u,n,c,data,d,newProfilo,contatti);
        aggiungi_utente(newUtente);
    }
    else if(tipo=="Utente Business"){
        newUtente=new Business(u,n,c,data,d,newProfilo,contatti);
        aggiungi_utente(newUtente);
    }
    else{
        newUtente=new Executive(u,n,c,data,d,newProfilo,contatti);
        aggiungi_utente(newUtente);
    }
    salva();
}


/**********************scrittura su file xml**************/

void DataBase::write_competenza(QXmlStreamWriter* xml, const Utente & u) const{
    for(int i=0;i<u.visualizza_profilo()->n_competenze();i++){
        xml->writeStartElement("Competenza");
        xml->writeTextElement("nomeC", QString::fromStdString(u.visualizza_profilo()->vai_a_competenza(i)->visualizza_competenza()));
        xml->writeTextElement("votoC", QString::number(u.visualizza_profilo()->vai_a_competenza(i)->visualizza_valutazione()));
        xml->writeEndElement();
    }

}

void DataBase::write_esp_lav(QXmlStreamWriter* xml, const Utente & u)const{
    for(int i=0;i<u.visualizza_profilo()->n_lavori();i++){
        xml->writeStartElement("Esperienza");
        xml->writeTextElement("nomeE", QString::fromStdString(u.visualizza_profilo()->vai_a_lavoro(i)->visualizza_esp()));
        xml->writeTextElement("inizio", QString::fromStdString(u.visualizza_profilo()->vai_a_lavoro(i)->visualizza_inizio_esp().toString()));
        xml->writeTextElement("fine", QString::fromStdString(u.visualizza_profilo()->vai_a_lavoro(i)->visualizza_fine_esp().toString()));
        xml->writeEndElement();
    }
}

void DataBase::write_studio(QXmlStreamWriter* xml, const Utente & u)const{
    for(int i=0;i<u.visualizza_profilo()->n_istruzioni();i++){
        xml->writeStartElement("TitoloS");
        xml->writeTextElement("nomeTS", QString::fromStdString(u.visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_titolo_di_studio()));
        xml->writeTextElement("inizioTS", QString::number(u.visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_inizio()));
        xml->writeTextElement("fineTS", QString::number(u.visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_diploma()));
        xml->writeEndElement();
    }
}

void DataBase::write_lingua(QXmlStreamWriter* xml, const Utente & u)const{
    for(int i=0;i<u.visualizza_profilo()->n_lingue();i++){
        xml->writeStartElement("Lingua");
        xml->writeTextElement("nomeL", QString::fromStdString(u.visualizza_profilo()->vai_a_lingua(i)->visualizza_descrizione()));
        xml->writeTextElement("comprensione", QString::fromStdString(u.visualizza_profilo()->vai_a_lingua(i)->visualizza_comprensione()));
        xml->writeTextElement("parlato", QString::fromStdString(u.visualizza_profilo()->vai_a_lingua(i)->visualizza_comprensione()));
        xml->writeTextElement("scritto", QString::fromStdString(u.visualizza_profilo()->vai_a_lingua(i)->visualizza_scritto()));
        xml->writeEndElement();
    }
}

void DataBase::salva_pwd()const{
    QFile* file = new QFile("/Users/waltersandon/Documents/p2/Walter_Sandon/LinQedIn/passwordLinQedIn.xml");
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox err;
        err.setText("Errore nell'apertura del file");
        err.exec();
     }
    else {
        QXmlStreamWriter* inp = new QXmlStreamWriter;
        inp->setAutoFormatting(true);
        inp->setDevice(file);
        inp->writeStartDocument();
        inp->writeStartElement("Utente");
        inp->writeAttribute("tipo","amministratore");
        inp->writeTextElement("codice", QString::fromStdString(visualizza_pwd()));
        inp->writeEndElement();
        inp->writeEndDocument();
        file->close();
        delete inp;
    }
    delete file;
}

void DataBase::salva()const{
    salva_pwd();
    QFile* file = new QFile("/Users/waltersandon/Documents/p2/Walter_Sandon/LinQedIn/utentiLinQedIn.xml");
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
       QMessageBox err;
       err.setText("Errore nell'apertura del file");
       err.exec();
    }
    else
    {
       QXmlStreamWriter* inp = new QXmlStreamWriter;
       inp->setAutoFormatting(true);
       inp->setDevice(file);
       inp->writeStartDocument();
       inp->writeStartElement("Utenti");
       for(vector<Utente*>::const_iterator it = all.begin(); it != all.end(); ++it)
       {
           Utente* utente= *it;
           inp->writeStartElement("Utente");
           if(dynamic_cast<Basic*>(*(it)))
           {
               inp->writeAttribute("tipo","Basic");
           }
           else if(dynamic_cast<Executive*>(*(it)))
           {
               inp->writeAttribute("tipo","Executive");
           }
           else if(dynamic_cast<Business*>(*(it)))
           {
               inp->writeAttribute("tipo","Business");
           }
           inp->writeTextElement("Username", QString::fromStdString(utente->visualizza_username()));
           inp->writeTextElement("Nome", QString::fromStdString(utente->visualizza_info()->visualizza_nome()));
           inp->writeTextElement("Cognome", QString::fromStdString(utente->visualizza_info()->visualizza_cognome()));
           inp->writeTextElement("DataNascita",QString::fromStdString(utente->visualizza_info()->visualizza_nascita().toString()));
           inp->writeTextElement("Descrizione", QString::fromStdString(utente->visualizza_info()->visualizza_descrizione()));

           if(utente->visualizza_profilo()->n_competenze()>0){
               //inp->writeStartElement("Competenze");
               write_competenza(inp,*utente);
               //inp->writeEndElement();
           }

           if(utente->visualizza_profilo()->n_lavori()>0){
               //inp->writeStartElement("EsperienzeLav");
               write_esp_lav(inp,*utente);
               //inp->writeEndElement();
           }
           if(utente->visualizza_profilo()->n_istruzioni()>0){
               //inp->writeStartElement("TitoliS");
               write_studio(inp,*utente);
               //inp->writeEndElement();
           }
           if(utente->visualizza_profilo()->n_lingue()>0){
               //inp->writeStartElement("Lingue");
               write_lingua(inp,*utente);
               //inp->writeEndElement();
           }
           for(int i=0; i<utente->n_contatti();++i){
               if(i==0) inp->writeStartElement("Rete");
               inp->writeTextElement("username", QString::fromStdString(utente->vai_a_contatto(i)->visualizza_contatto()));
               if(i==utente->n_contatti()-1) inp->writeEndElement();
           }
           inp->writeEndElement();
        }
        inp->writeEndElement();
        inp->writeEndDocument();
        file->close();
        delete inp;
    }
    delete file;
}


/*******************lettura su file xml****************/

void DataBase::carica_pwd(){
    QFile file("/Users/waltersandon/Documents/p2/Walter_Sandon/LinQedIn/passwordLinQedIn.xml");
    if(file.exists()){
        if(file.open(QFile::ReadOnly | QFile::Text)){
            QXmlStreamReader xml(&file);
            QString ad="amministratore";
            QString p;
            while (!xml.atEnd()) {
                if(xml.readNextStartElement()){
                    if(xml.attributes().value("tipo")==ad){
                        xml.readNextStartElement();
                        p=xml.readElementText();
                        modifica_pwd(p.toStdString());
                      xml.readNextStartElement();//user
                    }//tag password
                }//tag aperto
            }//while
        }//if open
        file.close();
    }//if exist
}

void DataBase::carica(){
    QFile file("/Users/waltersandon/Documents/p2/Walter_Sandon/LinQedIn/utentiLinQedIn.xml");
    if(file.exists()){
        if(file.open(QFile::ReadOnly | QFile::Text)){
            QXmlStreamReader xml(&file);
            QString u, n, c, d;
            QString type="";
            Data data;
            Competenze* comp;
            Lavoro* lav;
            Istruzione* istr;
            Lingua* ling;
            QString user;
            Utente* ut = 0;
            Rete* re;

            while (!xml.atEnd()) {
                if(xml.readNextStartElement()){
                    if(xml.name()=="Utente"){
                        type=(xml.attributes().value("tipo")).toString();
                        xml.readNextStartElement();//user
                        u=xml.readElementText();
                        xml.readNextStartElement();//nome
                        n=xml.readElementText();
                        xml.readNextStartElement();//cognome
                        c=xml.readElementText();
                        xml.readNextStartElement();//dataN
                        QString aux=xml.readElementText();
                        QStringList l=aux.split(".");
                        data=Data(l[0].toInt(),l[1].toInt(),l[2].toInt());
                        xml.readNextStartElement();//descrizione
                        QString d=xml.readElementText();

                        //inserisco l'utente nel database

                        if(type=="Basic"){
                            ut=new Basic(u.toStdString(), n.toStdString(), c.toStdString(), data, d.toStdString());
                        }
                        else if(type=="Executive"){
                            ut=new Executive(u.toStdString(), n.toStdString(), c.toStdString(), data, d.toStdString());
                        }
                        else if(type=="Business"){
                            ut=new Business(u.toStdString(), n.toStdString(), c.toStdString(), data, d.toStdString());
                        }
                        aggiungi_utente(ut);

                    }//end utente

                    else if(xml.name()=="TitoloS"){
                        xml.readNextStartElement();//nome titolo
                        QString nomeT=xml.readElementText();
                        xml.readNextStartElement();//inizio
                        int in=xml.readElementText().toInt();
                        xml.readNextStartElement();//fine
                        int fi=xml.readElementText().toInt();
                        xml.readNextStartElement();//end titoloS
                        istr=new Istruzione(nomeT.toStdString(), in, fi);
                        trova_utente(u.toStdString())->visualizza_profilo()->aggiungi_titolo_studio(*istr);
                    }//end titoli studio

                    else if(xml.name()=="Competenza"){
                        xml.readNextStartElement();//nome competenza
                        QString nomeC=xml.readElementText();
                        xml.readNextStartElement();//voto
                        int voto=xml.readElementText().toInt();
                        comp=new Competenze(nomeC.toStdString(), voto);
                        last_utente()->visualizza_profilo()->aggiungi_competenza(*comp);
                        xml.readNextStartElement();//end competenza
                    }//end competenza

                    else if (xml.name()=="Lingua") {
                        xml.readNextStartElement();//descrizione
                        QString nomeL=xml.readElementText();
                        xml.readNextStartElement();//comprensione
                        QString livelloC=xml.readElementText();
                        xml.readNextStartElement();//parlato
                        QString livelloP=xml.readElementText();
                        xml.readNextStartElement();//scritto
                        QString livelloS=xml.readElementText();
                        ling = new Lingua(nomeL.toStdString(), livelloC.toStdString(), livelloP.toStdString(), livelloS.toStdString());
                        trova_utente(u.toStdString())->visualizza_profilo()->aggiungi_lingua(*ling);
                        xml.readNextStartElement();//end lingua
                    }//end lingua

                    else if(xml.name()=="Esperienza") {
                        xml.readNextStartElement();//nome
                        QString nomeEsp=xml.readElementText();
                        xml.readNextStartElement();//inizio
                        QString inizio=xml.readElementText();
                        xml.readNextStartElement();//fine
                        QString fine=xml.readElementText();
                        QStringList i=inizio.split(".");
                        QStringList f=fine.split(".");
                        Data in(Data(i[0].toInt(),i[1].toInt(),i[2].toInt()));
                        Data fi(Data(f[0].toInt(),f[1].toInt(),f[2].toInt()));
                        lav=new Lavoro(nomeEsp.toStdString(), in, fi);
                        last_utente()->visualizza_profilo()->aggiungi_lavoro(*lav);
                        xml.readNextStartElement();//end esperienza
                    }//esperienza

                    else if(xml.name()=="Rete"){
                        xml.readNextStartElement();//salto al nodo username
                        while(xml.name()=="username"){
                            user=xml.readElementText();
                            re = new Rete(user.toStdString());
                            last_utente()->aggiungi_contatto(*re);
                            xml.readNextStartElement();
                        }//rete
                    }
                }//end controllo tag apertura
            }//end while
        }//if iniziale
        file.close();
    }
    carica_pwd();
}

Utente* DataBase::trova_utente(const string& s)const{
    vector<Utente*>::const_iterator it=all.begin();
      for( ; it != all.end() ; ++it){
          if((*it)->visualizza_username()==s)
              return *it;
      }
      return 0;
}
