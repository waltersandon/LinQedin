#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H
#include"QDialog"
#include"QGroupBox"
#include"QLabel"
#include"QDateEdit"
#include"QLineEdit"
#include"QPushButton"
#include"QListWidget"
#include"QTreeWidget"
#include"QTreeWidgetItem"
#include"QComboBox"
#include"QHBoxLayout"
#include"linqedinadmin.h"
#include"QHeaderView"
#include"QStringList"

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(LinqedInAdmin*, QWidget *parent = 0);
    ~AdminWindow();

    static int mese_to_int(const QString&);

    void setupView();
    void reset_campi_aggiungi_utente();
    void carica_lista_utenti();
    void carica_info_utente(Utente*);
    void setComboBox_cambia_tipo(Utente*);
    QTreeWidgetItem* add_root(const QString&);
    void addChild(QTreeWidgetItem*, const QString&);

signals:

private slots:

    void on_pushButtonESCI();
    void on_pushButton_cerca();
    void on_pushButton_aggiungi();
    void on_comboBox_cambio_tipo();
    void on_pushButton_elimina();
    void on_listViewUtenti_item(QListWidgetItem*);
    void on_pushButton_cambia();

private:
    QGroupBox *groupBoxAggiungi;
    QLabel *labelUserAggiungi;
    QLabel *labelNomeAggiungi;
    QLabel *labelCognomeAggiungi;
    QLabel *labelDescrAggiungi;
    QDateEdit *dataEditAggiungi;
    QLineEdit *lineEditCognomeAggiungi;
    QLineEdit *lineEditNomeAggiungi;
    QLineEdit *lineEditUserAggiungi;
    QPushButton *pushButtonAggiungi;
    QGroupBox *groupBoxIscritti;
    QLineEdit *lineEditUser;
    QPushButton *pushButtonCerca;
    QListWidget *listViewUtenti;
    QPushButton *pushButtonElimina;
    QTreeWidget *treeWidgetUtente;
    QComboBox *comboBox;
    QPushButton *pushButtonESCI;
    QLabel *labelListaUtenti;
    QComboBox *comboBoxCambiaTipo;
    QLabel *labelTree;
    QLabel *labelTreeUsername;

    QGroupBox *groupBoxPwd;
    QLabel *vecchiaPwd;
    QLineEdit *inserisciVecchia;
    QLabel *nuovaPwd;
    QLineEdit *inserisciNuova;
    QPushButton *pushButtonCambia;


    LinqedInAdmin* a;
};

#endif // ADMINWINDOW_H
