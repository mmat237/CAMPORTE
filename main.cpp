#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;

    bool test=c.createconnection();

    MainWindow w;

    if(test) //Si la connexion est etablie
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
        QObject::tr("connection succesful.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else //Si la connexion a échoué

        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
        QObject::tr("connection failed.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
