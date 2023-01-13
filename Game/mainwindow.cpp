#include "mainwindow.h"
#include "notagame.h"
#include "ui_mainwindow.h"
#include "mygame.h"

#include <stdlib.h>
#include <fstream>
#include <QtWidgets>
#include <QTimer>
#include <vector>
#include <QLine>
#include <QWidget>

extern notagame * secondgame;
extern MyGame * game;
extern QString pseudo;

//constructor
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->ScoreBoard_2->hide();
    ui->Game_select->hide();    //on cache ce qui ne doit pas etre vu
    ui->pseudo->hide();
    move(cx/2 - width()/2 , cy/2 - height()/2); //attention sous W11 la mise a l'echelle casse tout et c'est un peut compliqué d'aller chercher ce paramettre

}

//destructor
MainWindow::~MainWindow(){
}




void MainWindow::on_Play_clicked()
{
    ui->Loadingscreen->hide();
    ui->Game_select->show();
    ui->Space_Shooter->setIcon(QIcon(":/image/buton_image.png")); //on met une image dans un bouton
    ui->Space_Shooter->setIconSize(QSize(200, 250)); // redef de la taille de l'image
    ui->flappy_plane->setIcon(QIcon(":/image/buton_jeu2.png")); //on met une image dans un bouton
    ui->flappy_plane->setIconSize(QSize(200, 250)); // redef de la taille de l'image
}



void MainWindow::on_Space_Shooter_clicked()
{
    ui->Game_select->hide();
    resize(ui->mybox->width(),ui->mybox->height());
    move(cx/2 - ui->mybox->width()/2  , cy/2 - ui->mybox->height());
    ui->pseudo->show();
}


void MainWindow::on_buttonBox_accepted()
{

    pseudo= ui->lineEdit->text(); //on garde le speudo en memoire
    if(pseudo == ""){
        pseudo="unknown";
    }
    ui->pseudo->hide();
    ui->Loadingscreen->show();
    resize(900,600);
    move(cx/2 - width()/2 , cy/2 - height()/2);
    hide();

    game = new MyGame();    //on lance le premier jeu
    game->move(cx/2 - game->scene->width()/2  , cy/2 - game->scene->height()/2);
    game->show();
}






void MainWindow::on_buttonBox_rejected()
{

    ui->pseudo->hide();
    ui->Loadingscreen->show();
    resize(900,600);
    move(cx/2 - width()/2 , cy/2 - height()/2);
}






void MainWindow::gestion_score(){

    std::fstream stream;
    stream.open("score.txt", std::ios::in); //ouverture du flux en lecture


    std::vector<std::string> name;
    std::vector<std::string> score;
    if(stream.is_open()){

        std::string line;
        int comptage=1;
        while(getline(stream,line)){ //getline(fstream,std::string) prend la premiere ligne du fstream et la met dans la std::string
            if(comptage==1){
                name.push_back(line);
                comptage++;
            }
            else if(comptage==2){
                score.push_back(line);
                comptage--;
            }
        }

    }

    //petit algorithme de tri (tri par maximum)
    std::string memoire_number;
    std::string memoire_name;
    for(int p=0;p<score.size()-1;p++){
        if(std::atoi(score[p+1].c_str())>std::atoi(score[p].c_str()) && p==0){ //std::atoi() convertion de char vers int permet de comparer les nombres si on essaye de comparer des std::string 100<20
            memoire_number=score[p];
            memoire_name=name[p];
            score[p]=score[p+1];
            name[p]=name[p+1];
            score[p+1]=memoire_number;
            name[p+1]=memoire_name;
            p=p-1;
        }
        else if (std::atoi(score[p+1].c_str())>std::atoi(score[p].c_str())){
            memoire_number=score[p];
            memoire_name=name[p];
            score[p]=score[p+1];
            name[p]=name[p+1];
            score[p+1]=memoire_number;
            name[p+1]=memoire_name;
            p=p-2;
        }
    }
    myvar.push_back(name);
    myvar.push_back(score);


}






void MainWindow::on_ScoreBoard_clicked()
{
    gestion_score();
    ui->ScoreBoard_2->show();
    ui->Loadingscreen->hide();
    std::vector<std::vector<QLabel *>> myvectoflab  //mes QLabel myvectoflab[0] les noms myvectoflab[1] le score
    {
        {ui->label_2 , ui->label_4 , ui->label_6, ui->label_8 , ui->label_10},
        {ui->label_3, ui->label_5 , ui->label_7 , ui->label_9 , ui->label_11}
    };
    //on affiche le texte dans les QLabel
    for(int i=0;i<myvar[0].size();i++){
        if(i==5){
            break;
        }
        myvectoflab[0][i]->setText(myvar[0][i].c_str());
        myvectoflab[1][i]->setText(myvar[1][i].c_str());
    }
    myvar.clear();
}





void MainWindow::on_flappy_plane_clicked()
{
    hide();
    secondgame = new notagame();    //on lance le deuxieme "jeu"
    secondgame->show();
}

