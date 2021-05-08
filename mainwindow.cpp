#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Ca.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PBajoutercam_clicked()
{
    //recuperation des infos saisies dans les champs
    int id=ui->lineEdit_id->text().toInt();
     QString modealimentation=ui->lineEdit_modealimentation->text();
     QString modeenregistrement=ui->lineEdit_modeenregistrement->text();
      QString microphone=ui->lineEdit_microphone->text();
      int anglevision=ui->lineEdit_anglevision->text().toInt();

      Camera C(id,modealimentation,modeenregistrement,microphone,anglevision);

      bool test=C.ajouter();

      if(test) //Si la requete exexcutée
      {
          //Refresh (actualiser)

          ui->tableView->setModel(Ca.afficher());

          QMessageBox::information(nullptr, QObject::tr("OK"),
          QObject::tr("Ajout effectué.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else //Si la requete non exécutée

          QMessageBox::critical(nullptr, QObject::tr("Not OK"),
          QObject::tr("Ajout non éffectué.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_PBsupprimercam_clicked()
{
    //recuperation des infos saisies dans les champs
    int id=ui->lineEdit_idsup->text().toInt();


      bool test=Ca.supprimer(id);

      if(test) //Si la connexion est etablie
      {
          //Refresh (actualiser)

          ui->tableView->setModel(Ca.afficher());

          QMessageBox::information(nullptr, QObject::tr("OK"),
          QObject::tr("Suppression effectuée.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else //Si la connexion a échoué

          QMessageBox::critical(nullptr, QObject::tr("Not OK"),
          QObject::tr("Suppression non éffectuée.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_PBrecherche_clicked()
{
    //recuperation des infos saisies dans les champs
    int id=ui->lineEdit_idrech->text().toInt();


      bool test=Ca.rechercher(id);

      if(test) //Si la connexion est etablie
      {


          ui->tableView->setModel(Ca.rechercher());

          QMessageBox::information(nullptr, QObject::tr("OK"),
          QObject::tr("Recherche effectuée.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else //Si la connexion a échoué

          QMessageBox::critical(nullptr, QObject::tr("Not OK"),
          QObject::tr("Recherche non éffectuée.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_PBmodifiercam_clicked()
{

}

void MainWindow::on_PBajouterporte_clicked()
{
    //recuperation des infos saisies dans les champs
    int numero=ui->lineEdit_numero->text().toInt();
     QString qualiteserrure=ui->lineEdit_qualiteserrure->text();
     QString esthetisme=ui->lineEdit_esthetisme->text();

      Porte P(numero,qualiteserrure,esthetisme);

      bool test=P.ajouter();

      if(test) //Si la requete exexcutée
      {
          //Refresh (actualiser)

          ui->tableView->setModel(P.afficher());

          QMessageBox::information(nullptr, QObject::tr("OK"),
          QObject::tr("Ajout effectué.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else //Si la requete non exécutée

          QMessageBox::critical(nullptr, QObject::tr("Not OK"),
          QObject::tr("Ajout non éffectué.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_PBmodifierporte_clicked()
{

}



void MainWindow::on_PBsupprimerporte_clicked()
{
    //recuperation des infos saisies dans les champs
    int numero=ui->lineEdit_numerosup->text().toInt();


      bool test=P.supprimer(numero);

      if(test) //Si la connexion est etablie
      {
          //Refresh (actualiser)

          ui->tableView->setModel(P.afficher());

          QMessageBox::information(nullptr, QObject::tr("OK"),
          QObject::tr("Suppression effectuée.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else //Si la connexion a échoué

          QMessageBox::critical(nullptr, QObject::tr("Not OK"),
          QObject::tr("Suppression non éffectuée.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_PBrechercheporte_clicked()
{
    //recuperation des infos saisies dans les champs
    int numero=ui->lineEdit_numerorech->text().toInt();


      bool test=P.rechercher(numero);

      if(test) //Si la connexion est etablie
      {


          ui->tableView->setModel(P.rechercher());

          QMessageBox::information(nullptr, QObject::tr("OK"),
          QObject::tr("Recherche effectuée.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else //Si la connexion a échoué

          QMessageBox::critical(nullptr, QObject::tr("Not OK"),
          QObject::tr("Recherche non éffectuée.\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
}
