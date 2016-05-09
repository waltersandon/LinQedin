#include "clientwindow.h"

ClientWindow::ClientWindow(LinqedInClient* client, QWidget *parent) : QDialog(parent), cl(client){


    groupBoxInfo = new QGroupBox(this);
    labelTipo = new QLabel(groupBoxInfo);
    labelUsername = new QLabel(groupBoxInfo);
    labelNome = new QLabel(groupBoxInfo);
    labelCognome = new QLabel(groupBoxInfo);
    labelNascita = new QLabel(groupBoxInfo);
    labelDescrizione = new QLabel(groupBoxInfo);
    labelType = new QLabel(groupBoxInfo);
    labelUser = new QLabel(groupBoxInfo);
    lineEditNome = new QLineEdit(groupBoxInfo);
    lineEditCognome = new QLineEdit(groupBoxInfo);
    dateEditNascita = new QDateEdit(groupBoxInfo);
    textEditDescrizione = new QTextEdit(groupBoxInfo);
    pushButtonSalvaEsci = new QPushButton(groupBoxInfo);
    pushButtonVisualizzaTariffa = new QPushButton(groupBoxInfo);
    labelTariffa = new QLabel(groupBoxInfo);
    labelCosto = new QLabel(groupBoxInfo);

    groupBoxCompetenze = new QGroupBox(groupBoxInfo);
    groupBoxEsperienze = new QGroupBox(groupBoxInfo);
    groupBoxTitoliS = new QGroupBox(groupBoxInfo);
    groupBoxLingue = new QGroupBox(groupBoxInfo);

    groupBoxContatti = new QGroupBox(groupBoxInfo);
    listWidgetContatti = new QListWidget(groupBoxContatti);
    pushButtonEliminaContatto = new QPushButton(groupBoxContatti);
    treeWidgetInfoContatto = new QTreeWidget(groupBoxContatti);

    pushButtonAggiungiIstruzione = new QPushButton(groupBoxTitoliS);
    pushButtonEliminaIstruzione = new QPushButton(groupBoxTitoliS);
    tableWidgetIstruzione = new QTableWidget(groupBoxTitoliS);
    if (tableWidgetIstruzione->columnCount() < 3)
        tableWidgetIstruzione->setColumnCount(3);
    QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
    tableWidgetIstruzione->setHorizontalHeaderItem(0, __qtablewidgetitem);
    QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
    tableWidgetIstruzione->setHorizontalHeaderItem(1, __qtablewidgetitem1);
    QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
    tableWidgetIstruzione->setHorizontalHeaderItem(2, __qtablewidgetitem2);

    pushButtonAggiungiLavoro = new QPushButton(groupBoxEsperienze);
    pushButtonEliminaLavoro = new QPushButton(groupBoxEsperienze);
    tableWidgetLavoro = new QTableWidget(groupBoxEsperienze);
    if (tableWidgetLavoro->columnCount() < 3)
        tableWidgetLavoro->setColumnCount(3);
    QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
    tableWidgetLavoro->setHorizontalHeaderItem(0, __qtablewidgetitem3);
    QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
    tableWidgetLavoro->setHorizontalHeaderItem(1, __qtablewidgetitem4);
    QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
    tableWidgetLavoro->setHorizontalHeaderItem(2, __qtablewidgetitem5);

    pushButtonAggiungiCompetenza = new QPushButton(groupBoxCompetenze);
    pushButtonEliminaCompetenza = new QPushButton(groupBoxCompetenze);
    tableWidgetCompetenze = new QTableWidget(groupBoxCompetenze);
    if (tableWidgetCompetenze->columnCount() < 2)
        tableWidgetCompetenze->setColumnCount(2);
    QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
    tableWidgetCompetenze->setHorizontalHeaderItem(0, __qtablewidgetitem6);
    QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
    tableWidgetCompetenze->setHorizontalHeaderItem(1, __qtablewidgetitem7);

    tableWidgetLingue = new QTableWidget(groupBoxLingue);
    if (tableWidgetLingue->columnCount() < 4)
        tableWidgetLingue->setColumnCount(4);
    QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
    tableWidgetLingue->setHorizontalHeaderItem(0, __qtablewidgetitem8);
    QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
    tableWidgetLingue->setHorizontalHeaderItem(1, __qtablewidgetitem9);
    QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
    tableWidgetLingue->setHorizontalHeaderItem(2, __qtablewidgetitem10);
    QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
    tableWidgetLingue->setHorizontalHeaderItem(3, __qtablewidgetitem11);
    pushButtonAggiungiLingua = new QPushButton(groupBoxLingue);
    pushButtonEliminaLingua = new QPushButton(groupBoxLingue);

    groupBoxRicerca = new QGroupBox(this);
    listWidgetRicerca = new QListWidget(groupBoxRicerca);
    labelRicercaUsername = new QLabel(groupBoxRicerca);
    labelRicercaUser = new QLabel(groupBoxRicerca);
    lineEditRicercaUsername = new QLineEdit(groupBoxRicerca);
    pushButtonRicerca = new QPushButton(groupBoxRicerca);
    pushButtonAggiungiContatto = new QPushButton(groupBoxRicerca);

    connect(pushButtonVisualizzaTariffa,SIGNAL(clicked()),this,SLOT(on_pushButton_tatiffa()));
    connect(pushButtonSalvaEsci,SIGNAL(clicked()),this,SLOT(on_pushButton_salva_esci()));
    connect(pushButtonRicerca,SIGNAL(clicked()),this,SLOT(on_pushButtonRicercaContatti()));
    connect(listWidgetContatti,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_listWidgetContatti(QListWidgetItem*)));
    connect(pushButtonEliminaContatto,SIGNAL(clicked()),this,SLOT(on_pushButtonEliminaContatto()));
    connect(pushButtonAggiungiIstruzione,SIGNAL(clicked()),this,SLOT(on_pushButtonAggiungiIstruzione()));
    connect(pushButtonEliminaIstruzione,SIGNAL(clicked()),this,SLOT(on_pushButtonEliminaIstruzione()));
    connect(pushButtonAggiungiLavoro,SIGNAL(clicked()),this,SLOT(on_pushButtonAggiungiEsperienze()));
    connect(pushButtonEliminaLavoro,SIGNAL(clicked()),this,SLOT(on_pushButtonEliminaEsperienze()));
    connect(pushButtonAggiungiCompetenza,SIGNAL(clicked()),this,SLOT(on_pushButtonAggiungiCompetenze()));
    connect(pushButtonEliminaCompetenza,SIGNAL(clicked()),this,SLOT(on_pushButtonEliminaCompetenze()));
    connect(pushButtonAggiungiLingua,SIGNAL(clicked()),this,SLOT(on_pushButtonAggiungiLingue()));
    connect(pushButtonEliminaLingua,SIGNAL(clicked()),this,SLOT(on_pushButtonEliminaLingue()));
    connect(pushButtonAggiungiContatto,SIGNAL(clicked()),this,SLOT(on_pushButtonAggiungiContatto()));

    setView();
    carica_info_utente();
    carica_profilo_utente();
}

ClientWindow::~ClientWindow(){}

void ClientWindow::setView(){
    resize(1160, 602);

    setWindowTitle("Cliente");

    QFont fontGroup;
    fontGroup.setItalic(true);
    fontGroup.setPixelSize(12);

    groupBoxInfo->setGeometry(QRect(0, 10, 905, 581));
    groupBoxInfo->setFont(fontGroup);
    labelTipo->setGeometry(QRect(10,30,101,16));
    labelUsername->setGeometry(QRect(10, 60, 101, 16));
    labelNome->setGeometry(QRect(10, 90, 101, 16));
    labelCognome->setGeometry(QRect(10, 120, 101, 16));
    labelNascita->setGeometry(QRect(10, 150, 101, 16));
    labelDescrizione->setGeometry(QRect(10, 180, 101, 16));
    labelType->setGeometry(QRect(128,30,131,20));
    labelUser->setGeometry(QRect(128, 60, 131, 20));
    lineEditNome->setGeometry(QRect(130, 90, 131, 21));
    lineEditCognome->setGeometry(QRect(130, 120, 131, 21));
    dateEditNascita->setGeometry(QRect(130, 150, 110, 24));
    textEditDescrizione->setGeometry(QRect(130, 180, 131, 80));

    groupBoxCompetenze->setGeometry(QRect(300, 20 ,250, 160));
    groupBoxEsperienze->setGeometry(QRect(590, 20, 300, 160));
    groupBoxTitoliS->setGeometry(QRect(300, 190, 250, 160));
    groupBoxLingue->setGeometry(QRect(590, 190, 300, 160));
    groupBoxContatti->setGeometry(QRect(300, 360, 520, 200));

    listWidgetContatti->setGeometry(QRect(0, 19, 150, 140));
    treeWidgetInfoContatto->setGeometry(QRect(209, 19, 310, 140));
    pushButtonEliminaContatto->setGeometry(QRect(220, 170, 80, 20));

    pushButtonAggiungiIstruzione->setGeometry(QRect(30, 130, 80, 30));
    pushButtonEliminaIstruzione->setGeometry(QRect(150, 130, 80, 30));
    tableWidgetIstruzione->setGeometry(QRect(0, 18, 250, 115));
    tableWidgetIstruzione->horizontalHeader()->setDefaultSectionSize(83);

    pushButtonAggiungiLavoro->setGeometry(QRect(50, 130, 80, 30));
    pushButtonEliminaLavoro->setGeometry(QRect(180, 130, 80, 30));
    tableWidgetLavoro->setGeometry(QRect(0, 18, 300, 115));
    tableWidgetLavoro->horizontalHeader()->setDefaultSectionSize(95);

    pushButtonAggiungiCompetenza->setGeometry(QRect(30, 130, 80, 30));
    pushButtonEliminaCompetenza->setGeometry(QRect(150, 130, 80, 30));
    tableWidgetCompetenze->setGeometry(QRect(0, 18, 250, 115));
    tableWidgetCompetenze->horizontalHeader()->setDefaultSectionSize(125);

    pushButtonAggiungiLingua->setGeometry(QRect(50, 130, 80, 30));
    pushButtonEliminaLingua->setGeometry(QRect(180, 130, 80, 30));
    tableWidgetLingue->setGeometry(QRect(0, 18, 300, 115));
    tableWidgetLingue->horizontalHeader()->setDefaultSectionSize(75);

    QFont tasti;
    tasti.setPixelSize(16);

    pushButtonSalvaEsci->setGeometry(QRect(30,520,230,45));
    pushButtonSalvaEsci->setFont(tasti);
    pushButtonVisualizzaTariffa->setGeometry(QRect(30, 300,230,45));
    pushButtonVisualizzaTariffa->setFont(tasti);
    labelTariffa->setGeometry(QRect(50, 350, 150, 16));
    labelCosto->setGeometry(QRect(185, 350, 101, 16));

    groupBoxRicerca->setGeometry(QRect(910, 10, 581, 581));
    groupBoxRicerca->setFont(fontGroup);
    listWidgetRicerca->setGeometry(QRect(10, 200, 231, 321));
    labelRicercaUsername->setGeometry(QRect(40, 170, 91, 20));
    labelRicercaUser->setGeometry(QRect(115, 170, 121, 21));
    lineEditRicercaUsername->setGeometry(QRect(50, 50, 131, 21));
    lineEditRicercaUsername->setClearButtonEnabled(true);
    pushButtonRicerca->setGeometry(QRect(60, 80, 115, 32));
    pushButtonAggiungiContatto->setGeometry(QRect(40, 540, 181, 32));


    groupBoxInfo->setTitle( "Informazioni Personali");
    labelTipo->setText("Tipo");
    labelUsername->setText( "Username");
    labelNome->setText( "Nome");
    labelCognome->setText( "Cognome");
    labelNascita->setText( "Data di Nascita");
    labelDescrizione->setText( "Descrizione");
    labelType->setText("text");
    labelUser->setText( "text");
    lineEditNome->setText(QString());
    dateEditNascita->setDisplayFormat( "dd/MM/yyyy");
    labelTariffa->setText("Il Costo Mensile è di: ");
    labelCosto->setText("");

    dateEditNascita->setDisplayFormat("dd.MM.yyyy");
    pushButtonSalvaEsci->setText("Salva E Esci");

    pushButtonVisualizzaTariffa->setText("Tariffa");

    groupBoxContatti->setTitle("Contatti");
    pushButtonEliminaContatto->setText("Rimuovi");
    treeWidgetInfoContatto->header()->setStretchLastSection(false);
    treeWidgetInfoContatto->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    QTreeWidgetItem *qtreewidgetitem = treeWidgetInfoContatto->headerItem();
    qtreewidgetitem->setText(0,  "Contatto LinQedIn");

    pushButtonAggiungiIstruzione->setText( "Aggiungi");
    pushButtonEliminaIstruzione->setText( "Rimuovi");
    QTableWidgetItem *qtablewidgetitem = tableWidgetIstruzione->horizontalHeaderItem(0);
    qtablewidgetitem->setText( "Percorso");
    QTableWidgetItem *qtablewidgetitem1 = tableWidgetIstruzione->horizontalHeaderItem(1);
    qtablewidgetitem1->setText( "Inizio");
    QTableWidgetItem *qtablewidgetitem2 = tableWidgetIstruzione->horizontalHeaderItem(2);
    qtablewidgetitem2->setText( "Fine");



    pushButtonAggiungiLavoro->setText( "Aggiungi");
    pushButtonEliminaLavoro->setText( "Rimuovi");
    QTableWidgetItem *qtablewidgetitem3 = tableWidgetLavoro->horizontalHeaderItem(0);
    qtablewidgetitem3->setText( "Esperienza");
    QTableWidgetItem *qtablewidgetitem4 = tableWidgetLavoro->horizontalHeaderItem(1);
    qtablewidgetitem4->setText( "Inizio");
    QTableWidgetItem *qtablewidgetitem5 = tableWidgetLavoro->horizontalHeaderItem(2);
    qtablewidgetitem5->setText( "Fine");

    pushButtonAggiungiCompetenza->setText( "Aggiungi");
    pushButtonEliminaCompetenza->setText( "Rimuovi");
    QTableWidgetItem *qtablewidgetitem6 = tableWidgetCompetenze->horizontalHeaderItem(0);
    qtablewidgetitem6->setText( "Argomento");
    QTableWidgetItem *qtablewidgetitem7 = tableWidgetCompetenze->horizontalHeaderItem(1);
    qtablewidgetitem7->setText( "Livello");

    pushButtonAggiungiLingua->setText( "Aggiungi");
    pushButtonEliminaLingua->setText( "Rimuovi");
    QTableWidgetItem *qtablewidgetitem8 = tableWidgetLingue->horizontalHeaderItem(0);
    qtablewidgetitem8->setText( "Lingua");
    QTableWidgetItem *qtablewidgetitem9 = tableWidgetLingue->horizontalHeaderItem(1);
    qtablewidgetitem9->setText( "Compr");
    QTableWidgetItem *qtablewidgetitem10 = tableWidgetLingue->horizontalHeaderItem(2);
    qtablewidgetitem10->setText( "Parlato");
    QTableWidgetItem *qtablewidgetitem11 = tableWidgetLingue->horizontalHeaderItem(3);
    qtablewidgetitem11->setText( "Scritto");

    groupBoxCompetenze->setTitle("Competenze");
    groupBoxEsperienze->setTitle("Esperienze Lavorative");
    groupBoxTitoliS->setTitle("Titoli Di Studio");
    groupBoxLingue->setTitle("Lingue");

    groupBoxRicerca->setTitle( "Ricerca Contatti");
    labelRicercaUsername->setText( "Username : ");
    labelRicercaUser->setText(QString());
    lineEditRicercaUsername->setPlaceholderText("      Username");
    pushButtonRicerca->setText( "Cerca");
    pushButtonAggiungiContatto->setText( "Aggiungi Contatto");

}


void ClientWindow::carica_info_utente(){
    labelUser->setText(QString::fromStdString(cl->visualizza_client()->visualizza_username()));
    if(dynamic_cast<Basic*>(cl->visualizza_client()))
        labelType->setText("Basic");
    else if(dynamic_cast<Business*>(cl->visualizza_client()))
        labelType->setText("Business");
    else labelType->setText("Executive");
    lineEditNome->setText(QString::fromStdString(cl->visualizza_client()->visualizza_info()->visualizza_nome()));
    lineEditCognome->setText(QString::fromStdString(cl->visualizza_client()->visualizza_info()->visualizza_cognome()));
    Data data=cl->visualizza_client()->visualizza_info()->visualizza_nascita();
    int giorno=data.visualizza_giorno();
    int mese=data.visualizza_mese();
    int anno=data.visualizza_anno();
    dateEditNascita->setDate(QDate(anno,mese,giorno));
    textEditDescrizione->setText(QString::fromStdString(cl->visualizza_client()->visualizza_info()->visualizza_descrizione()));
}

void ClientWindow::carica_profilo_utente(){
    carica_contatti_utente();
    carica_istruzione_utente();
    carica_lavoro_utente();
    carica_competenze_utente();
    carica_lingue_utente();
}

void ClientWindow::on_pushButtonRicercaContatti(){
    labelRicercaUser->setText("");
    listWidgetRicerca->clear();
    QList<QString> lista;
    QString u=lineEditRicercaUsername->text();
    Utente *ricerca=cl->visualizza_db()->trova_utente(u.toStdString());
    if(ricerca){
        cl->visualizza_client()->trova_tipo_utente(*(cl->visualizza_db()),u.toStdString(), lista);
        labelRicercaUser->setText(u);
        for(int i=0; i<lista.size();++i){
            QListWidgetItem* item= new QListWidgetItem(lista.at(i));
            listWidgetRicerca->insertItem(i,item);
        }
    }
    else{
        QMessageBox err;
        err.setText("Non presente nel database");
        err.exec();
    }
}


void ClientWindow::carica_contatti_utente(){
    listWidgetContatti->clear();
    for(int i=0; i<cl->visualizza_client()->n_contatti();++i){
        string username=cl->visualizza_client()->vai_a_contatto(i)->visualizza_contatto();
        if(cl->visualizza_db()->trova_utente(username)){
            QListWidgetItem * item= new QListWidgetItem(QString::fromStdString(username));
            listWidgetContatti->insertItem(0,item);
        }
        else
            cl->visualizza_client()->rimuovi_contatto(username);
    }
}

void ClientWindow::on_pushButtonAggiungiContatto(){
    QString user= labelRicercaUser->text();
    bool presente=false;
    if(user!="" && user!=QString::fromStdString(cl->visualizza_client()->visualizza_username())){
        for(int i=0; i<cl->visualizza_client()->n_contatti() && !presente;++i){
            if(cl->visualizza_client()->vai_a_contatto(i)->visualizza_contatto()==user.toStdString()){
                presente=true;
            }
        }
        if(presente){
            QMessageBox presente;
            presente.setText("Contatto già presente nella tua lista");
            presente.exec();
        }
        else{
            Rete* r=new Rete(user.toStdString());
            cl->visualizza_client()->aggiungi_contatto(*r);
            //caricarlo in maniera bidirezionale
            cl->visualizza_db()->trova_utente(user.toStdString())->aggiungi_contatto(*(new Rete(cl->visualizza_client()->visualizza_username())));
            carica_contatti_utente();
            QMessageBox ok;
            ok.setText("Contatto Aggiunto");
            ok.exec();
        }
    }
    else{
        QMessageBox err;
        err.setText("Nessun contatto da aggiungere");
        err.exec();
    }
}

void ClientWindow::on_pushButtonEliminaContatto(){
    QListWidgetItem *item=listWidgetContatti->currentItem();
    if(item){
        cl->rimuovi_contatto(item->text().toStdString());
        cl->visualizza_db()->trova_utente(item->text().toStdString())->rimuovi_contatto(cl->visualizza_client()->visualizza_username());
        for(int r=0; r<listWidgetContatti->count();++r)
            if(item->text()==listWidgetContatti->item(r)->text()){
                listWidgetContatti->removeItemWidget(listWidgetContatti->takeItem(r));
                listWidgetContatti->removeItemWidget(item);
                treeWidgetInfoContatto->clear();
            }
    }
    else{
        QMessageBox err;
        err.setText("Nessun contatto selezionato");
        err.exec();
    }
}

void ClientWindow::carica_istruzione_utente(){

    tableWidgetIstruzione->clearContents();
    int num_rows=cl->visualizza_client()->visualizza_profilo()->n_istruzioni();
    tableWidgetIstruzione->setRowCount(num_rows);
    tableWidgetIstruzione->setColumnCount(3);
    for(int i=0; i<num_rows;++i){
        tableWidgetIstruzione->setItem(i,0,new QTableWidgetItem(QString::fromStdString(cl->visualizza_client()->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_titolo_di_studio())));
        tableWidgetIstruzione->setItem(i,1,new QTableWidgetItem(QString::number(cl->visualizza_client()->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_inizio())));
        tableWidgetIstruzione->setItem(i,2,new QTableWidgetItem(QString::number(cl->visualizza_client()->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_diploma())));
    }
}

void ClientWindow::on_pushButtonAggiungiIstruzione(){
    QString newTitolo=QString::number(cl->visualizza_client()->visualizza_profilo()->n_istruzioni()+1);
    Istruzione* aux=new Istruzione(newTitolo.toStdString(),0,0);
    cl->visualizza_client()->visualizza_profilo()->aggiungi_titolo_studio(*aux);
    salva_modifiche_istruzione();
    carica_istruzione_utente();
}

void ClientWindow::on_pushButtonEliminaIstruzione(){
    QTableWidgetItem * item= tableWidgetIstruzione->currentItem();
    if(item){
        string titolos=tableWidgetIstruzione->item(tableWidgetIstruzione->currentRow(),0)->text().toStdString();
        for(int i=0;i<cl->visualizza_client()->visualizza_profilo()->n_istruzioni();++i){
            if(titolos==cl->visualizza_client()->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_titolo_di_studio())
                cl->visualizza_client()->visualizza_profilo()->rimuovi_titolo_studio(i);
        }
        carica_istruzione_utente();
    }
    else{
        QMessageBox err;
        err.setText("Titolo di studio non selezionato");
        err.exec();
    }
}

void ClientWindow::carica_lavoro_utente(){
    tableWidgetLavoro->clearContents();
    int num_rows=cl->visualizza_client()->visualizza_profilo()->n_lavori();
    tableWidgetLavoro->setRowCount(num_rows);
    tableWidgetLavoro->setColumnCount(3);
    for(int i=0; i<num_rows;++i){
        QDateEdit* inizio=new QDateEdit(tableWidgetLavoro);
        inizio->setDisplayFormat("dd.MM.yyyy");
        QDateEdit* fine=new QDateEdit(tableWidgetLavoro);
        fine->setDisplayFormat("dd.MM.yyyy");
        int giorno, mese, anno;
        Data dataI=cl->visualizza_client()->visualizza_profilo()->vai_a_lavoro(i)->visualizza_inizio_esp();
        giorno=dataI.visualizza_giorno();
        mese=dataI.visualizza_mese();
        anno=dataI.visualizza_anno();
        inizio->setDate(QDate(anno,mese,giorno));
        Data dataF=cl->visualizza_client()->visualizza_profilo()->vai_a_lavoro(i)->visualizza_fine_esp();
        giorno=dataF.visualizza_giorno();
        mese=dataF.visualizza_mese();
        anno=dataF.visualizza_anno();
        fine->setDate(QDate(anno,mese,giorno));
        tableWidgetLavoro->setItem(i,0,new QTableWidgetItem(QString::fromStdString(cl->visualizza_client()->visualizza_profilo()->vai_a_lavoro(i)->visualizza_esp())));
        tableWidgetLavoro->setCellWidget(i,1,inizio);
        tableWidgetLavoro->setCellWidget(i,2,fine);
    }
}

void ClientWindow::on_pushButtonAggiungiEsperienze(){
    QString newLavoro=QString::number(cl->visualizza_client()->visualizza_profilo()->n_lavori()+1);
    Data* inizio=new Data();
    Data* fine=new Data();
    Lavoro* aux=new Lavoro(newLavoro.toStdString(), *inizio, *fine );
    cl->visualizza_client()->visualizza_profilo()->aggiungi_lavoro(*aux);
    salva_modifiche_esp_lav();
    carica_lavoro_utente();
}

void ClientWindow::on_pushButtonEliminaEsperienze(){
    QTableWidgetItem * item= tableWidgetLavoro->currentItem();
    if(item){
        string esperienza=tableWidgetLavoro->item(tableWidgetLavoro->currentRow(),0)->text().toStdString();
        for(int i=0;i<cl->visualizza_client()->visualizza_profilo()->n_lavori();++i){
            if(esperienza == cl->visualizza_client()->visualizza_profilo()->vai_a_lavoro(i)->visualizza_esp())
                cl->visualizza_client()->visualizza_profilo()->rimuovi_lavoro(i);
        }
        carica_lavoro_utente();
    }
    else{
        QMessageBox err;
        err.setText("Esperienza non selezionata");
        err.exec();
    }
}

void ClientWindow::carica_competenze_utente(){
    tableWidgetCompetenze->clearContents();
    int num_rows=cl->visualizza_client()->visualizza_profilo()->n_competenze();
    tableWidgetCompetenze->setRowCount(num_rows);
    tableWidgetCompetenze->setColumnCount(2);
    for(int i=0; i<num_rows;++i){
        QComboBox* comboCompetenze= new QComboBox(tableWidgetCompetenze);
        for(int c=0;c<10;++c)
            comboCompetenze->insertItem(c,QString::number(c+1));
        tableWidgetCompetenze->setItem(i,0,new QTableWidgetItem(QString::fromStdString(cl->visualizza_client()->visualizza_profilo()->vai_a_competenza(i)->visualizza_competenza())));
        int voto=cl->visualizza_client()->visualizza_profilo()->vai_a_competenza(i)->visualizza_valutazione();
        comboCompetenze->setCurrentIndex(voto-1);
        tableWidgetCompetenze->setCellWidget(i,1,comboCompetenze);
    }
}

void ClientWindow::on_pushButtonAggiungiCompetenze(){
    QString newCompetenza=QString::number(cl->visualizza_client()->visualizza_profilo()->n_competenze()+1);
    Competenze* aux=new Competenze(newCompetenza.toStdString(), 1);
    cl->visualizza_client()->visualizza_profilo()->aggiungi_competenza(*aux);
    salva_modifiche_competenze();
    carica_competenze_utente();
}

void ClientWindow::on_pushButtonEliminaCompetenze(){
    QTableWidgetItem * item= tableWidgetCompetenze->currentItem();
    if(item){
        string competenza=tableWidgetCompetenze->item(tableWidgetCompetenze->currentRow(),0)->text().toStdString();
        for(int i=0;i<cl->visualizza_client()->visualizza_profilo()->n_competenze();++i){
            if(competenza == cl->visualizza_client()->visualizza_profilo()->vai_a_competenza(i)->visualizza_competenza())
                cl->visualizza_client()->visualizza_profilo()->rimuovi_competenza(i);
        }
        carica_competenze_utente();
    }
    else{
        QMessageBox err;
        err.setText("Nessuna esperienza selezionata");
        err.exec();
    }
}

void ClientWindow::carica_lingue_utente(){
    tableWidgetLingue->clearContents();
    int num_rows=cl->visualizza_client()->visualizza_profilo()->n_lingue();
    tableWidgetLingue->setRowCount(num_rows);
    tableWidgetLingue->setColumnCount(4);
    for(int i=0; i<num_rows;++i){
        QComboBox* comboLingue= new QComboBox(tableWidgetLingue);
        comboLingue->insertItem(0,"A1");
        comboLingue->insertItem(1,"A2");
        comboLingue->insertItem(2,"B1");
        comboLingue->insertItem(3,"B2");
        comboLingue->insertItem(4,"C1");
        comboLingue->insertItem(5,"C2");
        QComboBox* comboLingue1= new QComboBox(tableWidgetLingue);
        comboLingue1->insertItem(0,"A1");
        comboLingue1->insertItem(1,"A2");
        comboLingue1->insertItem(2,"B1");
        comboLingue1->insertItem(3,"B2");
        comboLingue1->insertItem(4,"C1");
        comboLingue1->insertItem(5,"C2");
        QComboBox* comboLingue2= new QComboBox(tableWidgetLingue);
        comboLingue2->insertItem(0,"A1");
        comboLingue2->insertItem(1,"A2");
        comboLingue2->insertItem(2,"B1");
        comboLingue2->insertItem(3,"B2");
        comboLingue2->insertItem(4,"C1");
        comboLingue2->insertItem(5,"C2");

        tableWidgetLingue->setItem(i,0,new QTableWidgetItem(QString::fromStdString(cl->visualizza_client()->visualizza_profilo()->vai_a_lingua(i)->visualizza_descrizione())));
        QString comprensione=QString::fromStdString(cl->visualizza_client()->visualizza_profilo()->vai_a_lingua(i)->visualizza_comprensione());
        QString parlato=QString::fromStdString(cl->visualizza_client()->visualizza_profilo()->vai_a_lingua(i)->visualizza_parlato());
        QString scritto=QString::fromStdString(cl->visualizza_client()->visualizza_profilo()->vai_a_lingua(i)->visualizza_scritto());
        if(comprensione=="A1") comboLingue->setCurrentIndex(0);
        if(comprensione=="A2") comboLingue->setCurrentIndex(1);
        if(comprensione=="B1") comboLingue->setCurrentIndex(2);
        if(comprensione=="B2") comboLingue->setCurrentIndex(3);
        if(comprensione=="C1") comboLingue->setCurrentIndex(4);
        if(comprensione=="C2") comboLingue->setCurrentIndex(5);
        tableWidgetLingue->setCellWidget(i,1,comboLingue);
        if(parlato=="A1") comboLingue1->setCurrentIndex(0);
        if(parlato=="A2") comboLingue1->setCurrentIndex(1);
        if(parlato=="B1") comboLingue1->setCurrentIndex(2);
        if(parlato=="B2") comboLingue1->setCurrentIndex(3);
        if(parlato=="C1") comboLingue1->setCurrentIndex(4);
        if(parlato=="C2") comboLingue1->setCurrentIndex(5);
        tableWidgetLingue->setCellWidget(i,2,comboLingue1);
        if(scritto=="A1") comboLingue2->setCurrentIndex(0);
        if(scritto=="A2") comboLingue2->setCurrentIndex(1);
        if(scritto=="B1") comboLingue2->setCurrentIndex(2);
        if(scritto=="B2") comboLingue2->setCurrentIndex(3);
        if(scritto=="C1") comboLingue2->setCurrentIndex(4);
        if(scritto=="C2") comboLingue2->setCurrentIndex(5);
        tableWidgetLingue->setCellWidget(i,3,comboLingue2);
    }
}

void ClientWindow::on_pushButtonAggiungiLingue(){
    QString newLingua=QString::number(cl->visualizza_client()->visualizza_profilo()->n_lingue()+1);
    Lingua* aux=new Lingua(newLingua.toStdString(), "C1", "C1", "C1");
    cl->visualizza_client()->visualizza_profilo()->aggiungi_lingua(*aux);
    salva_modifiche_lingue();
    carica_lingue_utente();
}

void ClientWindow::on_pushButtonEliminaLingue(){
    QTableWidgetItem * item= tableWidgetLingue->currentItem();
    if(item){
        string lingua=tableWidgetLingue->item(tableWidgetLingue->currentRow(),0)->text().toStdString();
        for(int i=0;i<cl->visualizza_client()->visualizza_profilo()->n_lingue();++i){
            if(lingua== cl->visualizza_client()->visualizza_profilo()->vai_a_lingua(i)->visualizza_descrizione())
                cl->visualizza_client()->visualizza_profilo()->rimuovi_lingua(i);
        }
        carica_lingue_utente();
    }
    else{
        QMessageBox err;
        err.setText("Lingua non selezionata");
        err.exec();
    }
}

void ClientWindow::salva_modifiche_info() const{
    QString n= lineEditNome->text();
    QString c= lineEditCognome->text();
    QString data= dateEditNascita->date().toString();
    QStringList list=data.split(" ");
    Data dat(list[2].toInt(),mese_to_int(list[1]),list[3].toInt());
    QString d= textEditDescrizione->toPlainText();
    cl->visualizza_client()->visualizza_info()->modifica_nome(n.toStdString());
    cl->visualizza_client()->visualizza_info()->modifica_cognome(c.toStdString());
    cl->visualizza_client()->visualizza_info()->modifica_nascita(dat);
    cl->visualizza_client()->visualizza_info()->modifica_descrizione(d.toStdString());
}

int ClientWindow::mese_to_int(const QString & s){
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

void ClientWindow::salva_modifiche_competenze()const{
    for(int r=0; r < tableWidgetCompetenze->rowCount();++r){
        QTableWidgetItem* item=tableWidgetCompetenze->item(r,0);
        QComboBox* voto=(QComboBox*)tableWidgetCompetenze->cellWidget(r,1);
        cl->visualizza_client()->visualizza_profilo()->vai_a_competenza(r)->modifica_competenza(item->text().toStdString());
        cl->visualizza_client()->visualizza_profilo()->vai_a_competenza(r)->modifica_valutazione(voto->currentText().toInt());
    }
}

void ClientWindow::salva_modifiche_istruzione()const{
    for(int r=0; r < tableWidgetIstruzione->rowCount();++r){
        QTableWidgetItem* item=tableWidgetIstruzione->item(r,0);
        QTableWidgetItem* annoi=tableWidgetIstruzione->item(r,1);
        QTableWidgetItem* annof=tableWidgetIstruzione->item(r,2);
        cl->visualizza_client()->visualizza_profilo()->vai_a_titolo_studio(r)->modifica_titilo_di_studio(item->text().toStdString());
        cl->visualizza_client()->visualizza_profilo()->vai_a_titolo_studio(r)->modifica_anno_inizio(annoi->text().toInt());
        cl->visualizza_client()->visualizza_profilo()->vai_a_titolo_studio(r)->modifica_anno_diploma(annof->text().toInt());
    }
}

void ClientWindow::salva_modifiche_esp_lav() const{
    for(int r=0; r<tableWidgetLavoro->rowCount();++r){
        QTableWidgetItem* item=tableWidgetLavoro->item(r,0);
        QDateEdit * i=(QDateEdit*)tableWidgetLavoro->cellWidget(r,1);
        QDateEdit * f=(QDateEdit*)tableWidgetLavoro->cellWidget(r,2);
        cl->visualizza_client()->visualizza_profilo()->vai_a_lavoro(r)->modifica_esp(item->text().toStdString());
        QString inizio=i->date().toString();
        QStringList listi=inizio.split(" ");
        QString fine=f->date().toString();
        QStringList listf=fine.split(" ");
        Data datai(listi[2].toInt(),mese_to_int(listi[1]),listi[3].toInt());
        Data dataf(listf[2].toInt(),mese_to_int(listf[1]),listf[3].toInt());
        cl->visualizza_client()->visualizza_profilo()->vai_a_lavoro(r)->modifica_inizio_esp(datai);
        cl->visualizza_client()->visualizza_profilo()->vai_a_lavoro(r)->modifica_fine_esp(dataf);
    }
}

void ClientWindow::salva_modifiche_lingue() const{
    for(int r=0; r< tableWidgetLingue->rowCount();++r){
           QTableWidgetItem* item=tableWidgetLingue->item(r,0);
           QComboBox* comprensione=(QComboBox*)tableWidgetLingue->cellWidget(r,1);
           QComboBox* parlato=(QComboBox*)tableWidgetLingue->cellWidget(r,2);
           QComboBox* scritto=(QComboBox*)tableWidgetLingue->cellWidget(r,3);
           cl->visualizza_client()->visualizza_profilo()->vai_a_lingua(r)->modifica_descrizione(item->text().toStdString());
           cl->visualizza_client()->visualizza_profilo()->vai_a_lingua(r)->modifica_comprensione(comprensione->currentText().toStdString());
           cl->visualizza_client()->visualizza_profilo()->vai_a_lingua(r)->modifica_parlato(parlato->currentText().toStdString());
           cl->visualizza_client()->visualizza_profilo()->vai_a_lingua(r)->modifica_scritto(scritto->currentText().toStdString());
       }

}


QTreeWidgetItem* ClientWindow::add_root(const QString &name){
    QTreeWidgetItem *itm= new QTreeWidgetItem(treeWidgetInfoContatto);
    itm->setText(0, name);
    treeWidgetInfoContatto->addTopLevelItem(itm);
    return itm;
}

void ClientWindow::addChild(QTreeWidgetItem *parent, const QString& name){
    QTreeWidgetItem *itm=new QTreeWidgetItem();
    itm->setText(0,name);
    parent->addChild(itm);
}

void ClientWindow::carica_info_contatto(Utente* aux){
    treeWidgetInfoContatto->clear();
    if(aux){
        QTreeWidgetItem* it=add_root("Username");
        it->setExpanded(true);
        addChild(it,QString::fromStdString(aux->visualizza_username()));
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
        for(int i=0; i<aux->visualizza_profilo()->n_competenze();++i)
        {
            QString text= QString::fromStdString(aux->visualizza_profilo()->vai_a_competenza(i)->visualizza_competenza()) +
                    " con voto "+QString::number(aux->visualizza_profilo()->vai_a_competenza(i)->visualizza_valutazione());
            addChild(it5,text);
        }
        QTreeWidgetItem* it6=add_root("Esperienze");
        it6->setExpanded(true);
        for(int i=0; i<aux->visualizza_profilo()->n_lavori();++i)
        {
            QString text= QString::fromStdString(aux->visualizza_profilo()->vai_a_lavoro(i)->visualizza_esp()) +
                    " Dal "+ QString::fromStdString(aux->visualizza_profilo()->vai_a_lavoro(i)->visualizza_inizio_esp().toString())
                    +" Al "+ QString::fromStdString(aux->visualizza_profilo()->vai_a_lavoro(i)->visualizza_fine_esp().toString());

            addChild(it6,text);
        }
        QTreeWidgetItem* it7=add_root("Titolo di studio");
        it7->setExpanded(true);
        for(int i=0; i<aux->visualizza_profilo()->n_istruzioni();++i)
        {
            QString text= QString::fromStdString(aux->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_titolo_di_studio())
                    + " Iniziato nel "+ QString::number(aux->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_inizio());
                    + " Terminato nel " + QString::number(aux->visualizza_profilo()->vai_a_titolo_studio(i)->visualizza_anno_diploma());
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

void ClientWindow::on_pushButton_salva_esci(){
    salva_modifiche_competenze();
    salva_modifiche_esp_lav();
    salva_modifiche_istruzione();
    salva_modifiche_lingue();
    salva_modifiche_info();
    cl->visualizza_db()->salva();
    this->close();
}

void ClientWindow::on_listWidgetContatti(QListWidgetItem *item){
    Utente *user=cl->visualizza_db()->trova_utente(item->text().toStdString());
    if(user)
        carica_info_contatto(user);
}

void ClientWindow::on_pushButton_tatiffa(){
    QString tar= QString::number(cl->visualizza_client()->costo_annuale())+ " €";
    labelCosto->setText(tar);
}
