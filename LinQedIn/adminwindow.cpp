#include "adminwindow.h"

AdminWindow::AdminWindow(LinqedInAdmin* ad,QWidget *parent) : QDialog(parent), a(ad)
{

    groupBoxIscritti = new QGroupBox(this);
    lineEditUser = new QLineEdit(groupBoxIscritti);
    pushButtonCerca = new QPushButton(groupBoxIscritti);
    labelListaUtenti = new QLabel(groupBoxIscritti);
    listViewUtenti = new QListWidget(groupBoxIscritti);
    pushButtonElimina = new QPushButton(groupBoxIscritti);
    labelTree = new QLabel(groupBoxIscritti);
    labelTreeUsername = new QLabel(groupBoxIscritti);
    treeWidgetUtente = new QTreeWidget(groupBoxIscritti);
    comboBoxCambiaTipo = new QComboBox(groupBoxIscritti);
    comboBoxCambiaTipo->insertItem(0,"Utente Basic");
    comboBoxCambiaTipo->insertItem(1,"Utente Executive");
    comboBoxCambiaTipo->insertItem(2,"Utente Business");

    groupBoxAggiungi = new QGroupBox(this);
    labelUserAggiungi = new QLabel(groupBoxAggiungi);
    lineEditUserAggiungi = new QLineEdit(groupBoxAggiungi);
    labelNomeAggiungi = new QLabel(groupBoxAggiungi);
    lineEditNomeAggiungi = new QLineEdit(groupBoxAggiungi);
    labelCognomeAggiungi = new QLabel(groupBoxAggiungi);
    lineEditCognomeAggiungi = new QLineEdit(groupBoxAggiungi);
    labelDescrAggiungi = new QLabel(groupBoxAggiungi);
    dataEditAggiungi = new QDateEdit(groupBoxAggiungi);
    comboBox = new QComboBox(groupBoxAggiungi);
    comboBox->insertItem(0,"Utente Basic");
    comboBox->insertItem(0,"Utente Executive");
    comboBox->insertItem(0,"Utente Business");
    pushButtonAggiungi = new QPushButton(groupBoxAggiungi);


    groupBoxPwd = new QGroupBox(this);
    vecchiaPwd = new QLabel(groupBoxPwd);
    inserisciVecchia = new QLineEdit(groupBoxPwd);
    nuovaPwd = new QLabel(groupBoxPwd);
    inserisciNuova = new QLineEdit(groupBoxPwd);
    pushButtonCambia = new QPushButton(groupBoxPwd);
    pushButtonESCI = new QPushButton(groupBoxPwd);

    setupView();
    carica_lista_utenti();

    connect(listViewUtenti,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_listViewUtenti_item(QListWidgetItem*)));
    connect(pushButtonCerca,SIGNAL(clicked()),this,SLOT(on_pushButton_cerca()));
    connect(pushButtonAggiungi,SIGNAL(clicked()),this,SLOT(on_pushButton_aggiungi()));
    connect(pushButtonElimina,SIGNAL(clicked()),this,SLOT(on_pushButton_elimina()));
    connect(pushButtonESCI,SIGNAL(clicked()),this,SLOT(on_pushButtonESCI()));
    connect(comboBoxCambiaTipo,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_cambio_tipo()));
    connect(pushButtonCambia,SIGNAL(clicked()),this,SLOT(on_pushButton_cambia()));

}

AdminWindow::~AdminWindow()
{}

void AdminWindow::setupView(){
    resize(940, 620);

    QFont fontGroup;
    fontGroup.setItalic(true);
    fontGroup.setPixelSize(14);

    groupBoxIscritti->setGeometry(QRect(10, 0, 911, 370));
    groupBoxIscritti->setFont(fontGroup);
    lineEditUser->setGeometry(QRect(390, 30, 121, 21));
    lineEditUser->setClearButtonEnabled(true);
    pushButtonCerca->setGeometry(QRect(390, 50, 115, 32));
    listViewUtenti->setGeometry(QRect(60, 100, 291, 230));
    pushButtonElimina->setGeometry(QRect(650, 340, 115, 32));
    treeWidgetUtente->setGeometry(QRect(560, 100, 291, 230));
    labelListaUtenti->setGeometry(QRect(160, 70, 91, 21));
    comboBoxCambiaTipo->setGeometry(QRect(620, 70, 159, 26));
    labelTree->setGeometry(QRect(620, 40, 71, 16));
    labelTreeUsername->setGeometry(QRect(700, 40, 141, 16));

    groupBoxAggiungi->setGeometry(QRect(10, 370, 320, 231));
    groupBoxAggiungi->setFont(fontGroup);
    labelUserAggiungi->setGeometry(QRect(50, 30, 71, 16));
    labelNomeAggiungi->setGeometry(QRect(50, 60, 59, 16));
    labelCognomeAggiungi->setGeometry(QRect(50, 90, 71, 16));
    labelDescrAggiungi->setGeometry(QRect(50, 120, 101, 16));
    dataEditAggiungi->setGeometry(QRect(160, 120, 121, 24));
    lineEditCognomeAggiungi->setGeometry(QRect(160, 90, 113, 21));
    lineEditNomeAggiungi->setGeometry(QRect(160, 60, 113, 21));
    lineEditUserAggiungi->setGeometry(QRect(160, 30, 113, 21));
    pushButtonAggiungi->setGeometry(QRect(110, 190, 115, 32));
    comboBox->setGeometry(QRect(90, 160, 151, 21));

    treeWidgetUtente->header()->setStretchLastSection(false);
    treeWidgetUtente->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    groupBoxPwd->setGeometry(QRect(340,370,585,231));
    groupBoxPwd->setFont(fontGroup);
    vecchiaPwd->setGeometry(QRect(50, 30, 200, 16));
    nuovaPwd->setGeometry(QRect(50, 97, 200, 16));
    inserisciVecchia->setGeometry(QRect(50, 50, 130, 30));
    inserisciNuova->setGeometry(QRect(50, 120, 130, 30));
    pushButtonCambia->setGeometry(QRect(35,170, 170, 50));
    pushButtonESCI->setGeometry(QRect(400, 170, 181, 51));

    dataEditAggiungi->setDisplayFormat("dd.MM.yyyy");
    setWindowTitle("Amministrazione");
    groupBoxAggiungi->setTitle("Nuovo Utente");
    labelUserAggiungi->setText("Username");
    labelNomeAggiungi->setText("Nome");
    labelCognomeAggiungi->setText("Cognome");
    labelDescrAggiungi->setText("Data di Nascita");
    pushButtonAggiungi->setText("Aggiungi");
    groupBoxIscritti->setTitle("Utenti Iscritti");
    lineEditUser->setPlaceholderText("    Username");
    pushButtonCerca->setText("Cerca");
    pushButtonElimina->setText("Elimina");
    labelListaUtenti->setText("Lista Utenti");
    pushButtonESCI->setText("ESCI");
    labelTree->setText("Username : ");
    labelTreeUsername->setText("");
    treeWidgetUtente->setHeaderLabel("Utente LinQedIn");
    lineEditUserAggiungi->setPlaceholderText("mrossi");
    lineEditNomeAggiungi->setPlaceholderText("Mario");
    lineEditCognomeAggiungi->setPlaceholderText("Rossi");

    const bool __sortingEnabled = treeWidgetUtente->isSortingEnabled();
    treeWidgetUtente->setSortingEnabled(false);
    treeWidgetUtente->setSortingEnabled(__sortingEnabled);

    groupBoxPwd->setTitle("Cambio Password");
    vecchiaPwd->setText("Inserisci Password Attuale");
    inserisciVecchia->setPlaceholderText("Vecchia Password");
    inserisciVecchia->setEchoMode(QLineEdit::Password);
    nuovaPwd->setText("Inserisci Nuova Password");
    inserisciNuova->setPlaceholderText("Nuova Password");
    inserisciNuova->setEchoMode(QLineEdit::Password);
    pushButtonCambia->setText("Cambio Password");

}

int AdminWindow::mese_to_int(const QString & s){
    if(s=="gen")return 1;
    else if(s=="feb") return 2;
    else if(s=="mar")return 3;
    else if(s=="apr")return 4;
    else if(s=="mag")return 5;
    else if(s=="giu")return 6;
    else if(s=="lug")return 7;
    else if(s=="ago")return 8;
    else if(s=="set")return 9;
    else if(s=="ott")return 10;
    else if(s=="nov")return 11;
    else if(s=="dic")return 12;
    else return 0;
}

void AdminWindow::on_pushButtonESCI(){
    this->close();
}

void AdminWindow::reset_campi_aggiungi_utente(){
    lineEditUserAggiungi->setPlaceholderText("mrossi");
    lineEditNomeAggiungi->setPlaceholderText("Mario");
    lineEditCognomeAggiungi->setPlaceholderText("Rossi");
}

void AdminWindow::carica_lista_utenti(){
    listViewUtenti->clear();
    for(int i=0; i<a->visualizza_bd()->numero_utenti(); ++i){
        string user=a->visualizza_bd()->vai_ad_utente(i)->visualizza_username();
        QListWidgetItem *newItem= new QListWidgetItem(QString::fromStdString(user));
        listViewUtenti->addItem(newItem);
    }
}

void AdminWindow::on_pushButton_cerca(){
    QString username = lineEditUser->text();
    if(username==""){
        QMessageBox err;
        err.setText("Inserisci Username");
        lineEditUser->setPlaceholderText("mrossi");
        err.exec();
    }
    else{
        Utente* aux=a->trova_utente(username.toStdString());
        if(aux==0){
            QMessageBox err;
            err.setText("Nessun Utente Trovato");
            err.exec();
            lineEditUser->setPlaceholderText("mrossi");
        }
        else{
            for(int r = 0; r < listViewUtenti->count(); r++)
            {
                QListWidgetItem *item = listViewUtenti->item(r);
                if(item->text()==username)
                    listViewUtenti->setCurrentItem(item);
            }
            labelTreeUsername->setText(QString::fromStdString(aux->visualizza_username()));
            carica_info_utente(aux);
        }
    }
}

void AdminWindow:: setComboBox_cambia_tipo(Utente *u){
    if(dynamic_cast<Basic*>(u))
        comboBoxCambiaTipo->setCurrentIndex(0);
    else if(dynamic_cast<Executive*>(u))
        comboBoxCambiaTipo->setCurrentIndex(1);
    else if(dynamic_cast<Business*>(u))
        comboBoxCambiaTipo->setCurrentIndex(2);
}

QTreeWidgetItem* AdminWindow::add_root(const QString &name){
    QTreeWidgetItem *itm= new QTreeWidgetItem(treeWidgetUtente);
    itm->setText(0, name);
    treeWidgetUtente->addTopLevelItem(itm);
    return itm;
}

void AdminWindow::addChild(QTreeWidgetItem *parent, const QString& name){
    QTreeWidgetItem *itm=new QTreeWidgetItem();
    itm->setText(0,name);
    parent->addChild(itm);
}


void AdminWindow::carica_info_utente(Utente* aux){
    treeWidgetUtente->clear();
    labelTreeUsername->setText("");
    if(aux){
        setComboBox_cambia_tipo(aux);
        labelTreeUsername->setText(QString::fromStdString(aux->visualizza_username()));
        QTreeWidgetItem* it1=add_root("Nome");
        it1->setExpanded(true);
        addChild(it1, QString::fromStdString(aux->visualizza_info()->visualizza_nome()));
        QTreeWidgetItem* it2=add_root("Cognome");
        it2->setExpanded(true);
        addChild(it2, QString::fromStdString(aux->visualizza_info()->visualizza_cognome()));
        QTreeWidgetItem* it3=add_root("Data di Nascita");
        it3->setExpanded(true);
        addChild(it3, QString::fromStdString(aux->visualizza_info()->visualizza_nascita().toString()));
        QTreeWidgetItem* it4=add_root("Descrizione");
        it4->setExpanded(true);
        addChild(it4, QString::fromStdString(aux->visualizza_info()->visualizza_descrizione()));
        QTreeWidgetItem* it5=add_root("Competenze");
        it5->setExpanded(true);
        for(int i=0; i<aux->visualizza_profilo()->n_competenze();++i){
            QString text= QString::fromStdString(aux->visualizza_profilo()->vai_a_competenza(i)->visualizza_competenza()) +
                    " con voto "+QString::number(aux->visualizza_profilo()->vai_a_competenza(i)->visualizza_valutazione());
            addChild(it5,text);
        }
        QTreeWidgetItem* it6=add_root("Esperienze");
        it6->setExpanded(true);
        for(int i=0; i<aux->visualizza_profilo()->n_lavori();++i)
        {
            QString text= QString::fromStdString(aux->visualizza_profilo()->vai_a_lavoro(i)->visualizza_esp() +
                    " Dal "+ aux->visualizza_profilo()->vai_a_lavoro(i)->visualizza_inizio_esp().toString()+" Al "+
                    aux->visualizza_profilo()->vai_a_lavoro(i)->visualizza_fine_esp().toString());
            addChild(it6,text);
        }
        QTreeWidgetItem* it7=add_root("Titolo di studio");
        it7->setExpanded(true);
        for(int i=0; i<aux->visualizza_profilo()->n_istruzioni();++i)
        {
            QString text= QString::fromStdString(aux->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_titolo_di_studio()) +
                    " Iniziato nel " + QString::number(aux->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_inizio())+
                    " Conseguito nel "+ QString::number(aux->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_diploma());
            addChild(it7,text);
        }
        QTreeWidgetItem* it8=add_root("Lingue");
        it8->setExpanded(true);
        for(int i=0; i<aux->visualizza_profilo()->n_lingue();++i)
        {
            QString text= QString::fromStdString(aux->visualizza_profilo()->vai_a_lingua(i)->visualizza_descrizione()) +
                    " Comprensione: "+ QString::fromStdString(aux->visualizza_profilo()->vai_a_lingua(i)->visualizza_comprensione()) +
                    " Parlato: " + QString::fromStdString(aux->visualizza_profilo()->vai_a_lingua(i)->visualizza_parlato())+
                    " Scritto: " + QString::fromStdString(aux->visualizza_profilo()->vai_a_lingua(i)->visualizza_scritto());
            addChild(it8,text);
        }
        QTreeWidgetItem* it9=add_root("Contatti");
        it9->setExpanded(true);
        for(int i=0; i<aux->n_contatti();++i)
        {
            addChild(it9,QString::fromStdString(aux->vai_a_contatto(i)->visualizza_contatto()));
        }
    }
}

void AdminWindow::on_pushButton_aggiungi(){
    bool add=true;
    QString username = lineEditUserAggiungi->text();
    QString nome = lineEditNomeAggiungi->text();
    QString cognome = lineEditCognomeAggiungi->text();
    QString data = dataEditAggiungi->date().toString();
    QStringList list=data.split(" ");
    Data dat(list[2].toInt(),mese_to_int(list[1]),list[3].toInt());
    if(username == "" || nome == "" || cognome == ""){
        QMessageBox err;
        err.setText("Compila tutti i campi");
        err.exec();
        reset_campi_aggiungi_utente();
    }
    else{
        if(comboBox->currentText()=="Utente Basic"){
            Utente* newUtente= new Basic(username.toStdString(), nome.toStdString(), cognome.toStdString(), dat);
            add=a->aggiungi_utente(newUtente);
            a->visualizza_bd()->salva();
            carica_lista_utenti();
        }
        else
            if(comboBox->currentText()=="Utente Executive"){
                Utente* newUtente= new Executive(username.toStdString(), nome.toStdString(), cognome.toStdString(), dat);
                add=a->aggiungi_utente(newUtente);
                a->visualizza_bd()->salva();
                carica_lista_utenti();
            }
        else
            if(comboBox->currentText()=="Utente Business"){
                Utente* newUtente= new Business(username.toStdString(), nome.toStdString(), cognome.toStdString(), dat);
                add=a->aggiungi_utente(newUtente);
                a->visualizza_bd()->salva();
                carica_lista_utenti();
            }
        QMessageBox ok;
        if(!add){
            ok.setText("Utente Aggiunto");
            ok.exec();
        }
        else{
            ok.setText("Username già presente");
            ok.exec();
        }
    }
    reset_campi_aggiungi_utente();
}

void AdminWindow::on_comboBox_cambio_tipo(){
    QString username = labelTreeUsername->text();
    if(username != ""){
        int reply = QMessageBox::question(this, "Cambio Tipo Utente", "Confermi di cambiare tipo?",
                                              QMessageBox::Yes, QMessageBox::Cancel);
              if(reply == QMessageBox::Yes){
                    a->visualizza_bd()->cambio_tipo(username.toStdString(), comboBoxCambiaTipo->currentText().toStdString());
                    a->visualizza_bd()->salva();
              }
    }
}

void AdminWindow::on_pushButton_elimina(){
    QString username = labelTreeUsername->text();
    QMessageBox err;
    Utente * u= a->trova_utente(username.toStdString());
    if(u){
        int reply = QMessageBox::question(this, "Cancellazione Utente", "Confermi la cancellazione dell'utente?",
                                              QMessageBox::Yes, QMessageBox::Cancel);
              if(reply == QMessageBox::Yes){
                  labelTreeUsername->setText("");
                    treeWidgetUtente->clear();
                    for(int r = 0; r < listViewUtenti->count(); r++)
                    {
                        QListWidgetItem *item = listViewUtenti->item(r);
                        if(item->text()==username){
                            listViewUtenti->removeItemWidget(listViewUtenti->takeItem(r));
                            listViewUtenti->removeItemWidget(item);
                            delete item;
                        }
                    }
                    a->rimuovi_utente(u->visualizza_username());
                    a->visualizza_bd()->salva();
              }
    }
    else{
        err.setText("Nessun utente selezionato");
        err.exec();
    }
}

void AdminWindow::on_listViewUtenti_item(QListWidgetItem *item){
    Utente *user=a->trova_utente(item->text().toStdString());
    carica_info_utente(user);
}

void AdminWindow::on_pushButton_cambia(){
    QMessageBox ok;
    QString pwdv=inserisciVecchia->text();
    QString pwdn=inserisciNuova->text();
    if(pwdv==QString::fromStdString(a->visualizza_bd()->visualizza_pwd())){
        a->visualizza_bd()->modifica_pwd(pwdn.toStdString());
        a->visualizza_bd()->salva_pwd();
        ok.setText("Cambio Password Effettuato");
        ok.exec();
    }
    else {
        ok.setText("Vecchia Password Errata");
        ok.exec();
    }
}
