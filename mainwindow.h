#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsWidget>
#include <QMainWindow>
#include <QGraphicsView>

#include <windows.h>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void gestion_score();


private slots:
    void on_Play_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_ScoreBoard_clicked();



    void on_Space_Shooter_clicked();

    void on_flappy_plane_clicked();

private:

    int cx = GetSystemMetrics(SM_CXSCREEN); //hop je connais la taille de l'ecrant
    int cy = GetSystemMetrics(SM_CYSCREEN); //
    Ui::MainWindow *ui;
    std::vector<std::vector<std::string>> myvar; //gestion du score/pseudo
};

#endif // MAINWINDOW_H
