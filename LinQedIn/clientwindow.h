#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H
#include"QDialog"
#include"QLabel"
#include"QGroupBox"
#include"mainwindow.h"
#include"QTextEdit"
#include"QToolBox"
#include"QTableWidget"
#include"linqedinclient.h"
#include"QHeaderView"
#include"QStandardItemModel"
#include"QStandardItem"
#include"QStringList"
#include"QComboBox"

class ClientWindow : public QDialog
{
    Q_OBJECT

private:

    QGroupBox *groupBoxInfo;
    QLabel* labelTipo;
    QLabel *labelUsername;
    QLabel *labelNome;
    QLabel *labelCognome;
    QLabel *labelNascita;
    QLabel *labelDescrizione;
    QLabel* labelType;
    QLabel *labelUser;
    QLineEdit *lineEditNome;
    QLineEdit *lineEditCognome;
    QDateEdit *dateEditNascita;
    QTextEdit *textEditDescrizione;
    QPushButton* pushButtonSalvaEsci;
    QGroupBox* groupBoxContatti;
    QListWidget* listWidgetContatti;
    QPushButton *pushButtonEliminaContatto;
    QTreeWidget *treeWidgetInfoContatto;

    QPushButton *pushButtonAggiungiIstruzione;
    QPushButton *pushButtonEliminaIstruzione;
    QTableWidget *tableWidgetIstruzione;

    QTableWidget *tableWidgetLavoro;
    QPushButton *pushButtonAggiungiLavoro;
    QPushButton *pushButtonEliminaLavoro;

    QTableWidget *tableWidgetCompetenze;
    QPushButton *pushButtonAggiungiCompetenza;
    QPushButton *pushButtonEliminaCompetenza;

    QTableWidget *tableWidgetLingue;
    QPushButton *pushButtonAggiungiLingua;
    QPushButton *pushButtonEliminaLingua;

    QGroupBox* groupBoxCompetenze;
    QGroupBox* groupBoxEsperienze;
    QGroupBox* groupBoxTitoliS;
    QGroupBox* groupBoxLingue;

    QGroupBox *groupBoxRicerca;
    QListWidget *listWidgetRicerca;
    QLabel *labelRicercaUsername;
    QLabel *labelRicercaUser;
    QLineEdit *lineEditRicercaUsername;
    QPushButton *pushButtonRicerca;
    QPushButton *pushButtonAggiungiContatto;

    QPushButton *pushButtonVisualizzaTariffa;
    QLabel* labelTariffa;
    QLabel* labelCosto;

    LinqedInClient* cl;
public:
    explicit ClientWindow(LinqedInClient*,QWidget *parent = 0);
   ~ClientWindow();

    static int mese_to_int(const QString&);

    void setView();

    void carica_info_utente();
    void carica_profilo_utente();
    void carica_contatti_utente();
    void carica_istruzione_utente();
    void carica_lavoro_utente();
    void carica_competenze_utente();
    void carica_lingue_utente();

    void salva_modifiche_info()const;
    void salva_modifiche_competenze()const;
    void salva_modifiche_istruzione()const;
    void salva_modifiche_esp_lav()const;
    void salva_modifiche_lingue()const;   

    QTreeWidgetItem* add_root(const QString&);
    void addChild(QTreeWidgetItem*, const QString&);
    void carica_info_contatto(Utente*);

private slots:

    void on_pushButton_tatiffa();
    void on_pushButton_salva_esci();
    void on_pushButtonRicercaContatti();

    void on_listWidgetContatti(QListWidgetItem*);
    void on_pushButtonEliminaContatto();
    void on_pushButtonAggiungiEsperienze();
    void on_pushButtonEliminaEsperienze();
    void on_pushButtonAggiungiCompetenze();
    void on_pushButtonEliminaCompetenze();
    void on_pushButtonAggiungiIstruzione();
    void on_pushButtonEliminaIstruzione();
    void on_pushButtonAggiungiLingue();
    void on_pushButtonEliminaLingue();
    void on_pushButtonAggiungiContatto();
};

#endif // CLIENTWINDOW_H
