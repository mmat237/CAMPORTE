#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "camera.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PBajoutercam_clicked();

    void on_PBsupprimercam_clicked();

    void on_PBrecherche_clicked();

    void on_PBmodifiercam_clicked();

    void on_PBajouterporte_clicked();

    void on_PBmodifierporte_clicked();


    void on_PBsupprimerporte_clicked();

    void on_PBrechercheporte_clicked();

private:
    Ui::MainWindow *ui;

    Camera Ca;
};
#endif // MAINWINDOW_H
