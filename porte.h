#ifndef PORTE_H
#define PORTE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Porte
{
    QString qualiteserrure, esthetisme;
    int numero;
public:

    //Constructeurs
    Porte(){}
    Porte(int,QString,QString);

    //Getters
    QString getQualiteserrure(){return qualiteserrure;}
    QString getEsthetisme(){return esthetisme;}
    int getNumero(){return numero;}


    //Setters
    void setQualieserrure(QString a){qualiteserrure=a;}
    void setEsthetisme(QString e){esthetisme=e;}
    void setNumero(int numero){this->numero=numero;}

    //Fonctionnalités relatives a l'entité Porte
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool rechercher(int);
};

#endif // PORTE_H
