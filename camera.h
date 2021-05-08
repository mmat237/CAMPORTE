#ifndef CAMERA_H
#define CAMERA_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Camera
{
    QString modealimentation, modeenregistrement, microphone;
    int id,anglevision;
public:
    //Constructeurs
    Camera(){}
    Camera(int,int,QString,QString,QString);

    //Getters
    QString getModealimentation(){return modealimentation;}
    QString getModeenregistrement(){return modeenregistrement;}
    QString getMicrophone(){return microphone;}
    int getID(){return id;}
    int getAnglevision(){return anglevision;}

    //Setters
    void setModealimentation(QString a){modealimentation=a;}
    void setModeenregistrement(QString e){modeenregistrement=e;}
    void setMicrophone(QString m){microphone=m;}
    void setID(int id){this->id=id;}
    void setAnglevision(int anglevision){this->anglevision=anglevision;}


    //Fonctionnalités relatives a l'entité Camera
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool rechercher(int);
};

#endif // CAMERA_H
