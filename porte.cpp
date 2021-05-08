#include "porte.h"

Porte::Porte(int numero,QString qualiteserrure,QString esthetisme)
{
this->numero=numero;
this->qualiteserrure=qualiteserrure;
this->esthetisme=esthetisme;
}

bool Porte::ajouter()
{
QSqlQuery query;
QString res= QString::number(numero);

query.prepare("insert into porte(numero,qualiteserrure,esthetisme)""values(:numero, :qualiteserrure, :esthetisme)");
query.bindvalue(":numero",res);
query.bindvalue(":qualiteserrure",qualiteserrure);
query.bindvalue(":esthetisme",esthetisme);

return query.exec();

}

QSqlQueryModel * Porte::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select * from camera");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numero"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Qualiteserrure"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Esthetisme"));

return model;
        }

bool Porte::supprimer(int numero)
{
QSqlQuery query;
QString res=Qstring::number(numero);

query.prepare("Delete from camera where Numero=:numero");
query.bindValue(":numero",res);

return query.exec();
}


bool Porte::rechercher(int numero)
 {
     QSqlQuery *query = new QSqlQuery;
    query->prepare("select * from camera where Numero=:numero");
    if (query->exec())
    {
        return(1);
    }
    return(0);
 }




