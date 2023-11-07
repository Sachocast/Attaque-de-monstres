#include <stdio.h>
#include <stdlib.h>
#include "entetes.h"

///Lutin = 1 , Monstre = 2 , Porte = 3 , vide = 0


int getLigne(monstre tabMonstre [],int j){
    return tabMonstre[j].ligne;
}

void sendLigne(monstre tabMonstre [],int j,int var){
    tabMonstre[j].ligne = var;
}


int getCol(monstre tabMonstre [],int j){
    return tabMonstre[j].col;
}

void sendCol(monstre tabMonstre [],int j,int var){
    tabMonstre[j].col = var;
}


int getDepl(monstre tabMonstre [],int j){
    return tabMonstre[j].depl;
}

void sendDepl(monstre tabMonstre [],int j,int var){
    tabMonstre[j].depl = var;
}


int depMonstre(int grille[10][10],int largeurGrille,int j,monstre tabMonstres []){

        int dx,dy;  ///direction x et direction y

        int d;
        d = getDepl(tabMonstres,j); /// direction du monstre
        if (d==1){
            dx =0;dy =-1; ///vers la gauche
        }
        else if(d==2){
            dx =-1;dy =0; ///vers le haut
        }
        else if(d==3){
            dx =0;dy =1; ///vers la droite
        }
        else if(d==4){
            dx =1;dy =0; ///vers le bas
        }

        int tempx,tempy; /// coordonnees temporaires du monstre

        tempx = getLigne(tabMonstres,j) + dx; ///x temporaire : x + dx
        tempy = getCol(tabMonstres,j) + dy;   ///y temporaire : y + dy


        /// si a la position suivante
        ///(Monstre ne sort pas de la grille en bas et à droite) et
        ///(Monstre ne sort pas de la grille en haut et à gauche) et
        ///(Monstre ne touche pas un monstre) et
        ///(Monstre ne touche pas le Lutin) et
        ///(Monstre ne touche pas la porte)
        if ((tempx < largeurGrille && tempy < largeurGrille) && (tempx >= 0 && tempy >= 0) && (grille[tempx][tempy]!=2) && (grille[tempx][tempy]!=1) && (grille[tempx][tempy]!=3)){
            grille [getLigne(tabMonstres,j)][getCol(tabMonstres,j)] = 0; /// On vide la position actuelle du monstre
            sendLigne(tabMonstres,j,tempx);                              /// On change la postition du monstre par la position temporaire
            sendCol(tabMonstres,j,tempy);
            grille[getLigne(tabMonstres,j)][getCol(tabMonstres,j)] = 2;  /// On place le monstre sur la grille à la nouvelle position
            return 1; /// On renvoie 1: Le montre c'est déplacer
        }
        /// sinon si le Lutin se trouve à la prochaine position du monstre
        else if(grille[tempx][tempy]==1)
            return 2; /// On renvoie 2: Le joueur est mort: la partie est finie
        else
            return 0; /// On renvoie 0: Le Monstre change de sens
}

void sensMonstre(int grille[10][10],int largeurGrille,int j,monstre tabMonstres []){

            if (getDepl(tabMonstres,j) == 1)      /// si le monstre se deplace vers la gauche

                sendDepl(tabMonstres,j,3);  ///le montre change de sens et va vers la droite

            else if (getDepl(tabMonstres,j) == 2) /// si le monstre se deplace vers le haut

                sendDepl(tabMonstres,j,4);  ///le montre change de sens et va vers le bas

            else if (getDepl(tabMonstres,j) == 3) /// si le monstre se deplace vers la droite

                sendDepl(tabMonstres,j,1);  ///le montre change de sens et va vers la gauche

            else if (getDepl(tabMonstres,j) == 4) /// si le monstre se deplace vers le bas

                sendDepl(tabMonstres,j,2);  ///le montre change de sens et va vers le haut
}

void depMonstreMain(int grille[10][10],int largeurGrille,int j,monstre tabMonstres [],int *fin){

        int Ok,Ok2; /// Ok: l'état du monstre à la sortie du déplacement

        Ok = depMonstre(grille,largeurGrille,j,tabMonstres);


        if (Ok == 1){ /// le monstre s'est déplacer
        }
        else if (Ok == 2){ /// le monstre tue le joueur

            *fin = 2;/// la partie est perdue
        }
        else{ /// le monstre rencontre un obstacle

            sensMonstre(grille,largeurGrille,j,tabMonstres); /// le montre se retourne
            Ok2 = depMonstre(grille,largeurGrille,j,tabMonstres); ///le monstre se deplace s'il le peut
            if (Ok2 == 1){ /// le monstre s'est déplacer
            }
            else if (Ok2 == 2){ /// le monstre tue le joueur
                *fin = 2;/// la partie est perdue
            }
            else{ /// le monstre rencontre un obstacle
            sensMonstre(grille,largeurGrille,j,tabMonstres);
        }
}
}





