#include "camera.h"

Camera::Camera(int id,int anglevision,QString modealimentation,QString modeenregistrement,QString microphone)
{
this->id=id;
this->anglevision=anglevision;
this->modealimentation=modealimentation;
this->modeenregistrement=modeenregistrement;
this->microphone=microphone;
}

bool Camera::ajouter()
{
QSqlQuery query;
QString res= QString::number(id)

query.prepare("insert into camera(id,anglevision,modealimentation,modeenregistrement,microphone)""values(:id, :anglevision, :modealimentation, :modeenregistrement, :microphone)");
query.bindvalue(":id",res);
query.bindvalue(":anglevision",anglevision);
query.bindvalue(":modealimentation",modealimentation);
query.bindvalue(":modeenregistrement",modeenregistrement);
query.bindvalue(":microphone",microphone);

return query.exec();

}

QSqlQueryModel * Camera::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select * from camera");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Anglevision"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Modealimentation"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Modeenregistrement"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Microphone"));

return model;
        }

bool Camera::supprimer(int id)
{
QSqlQuery query;
QString res=Qstring::number(id);

query.prepare("Delete from camera where ID=:id");
query.bindValue(":id",res);

return query.exec();
}


bool Camera::rechercher(int id)
 {
     QSqlQuery *query = new QSqlQuery;
    query->prepare("select * from camera where ID=:id");
    if (query->exec())
    {
        return(1);
    }
    return(0);
 }

