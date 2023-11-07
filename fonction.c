#include <stdio.h>
#include <stdlib.h>
#include "entetes.h"

void depLutin(int dx, int dy,int grille [10][10],int largeurGrille,int *lLutin, int *cLutin,int *fin){

        int tempx,tempy;        ///coordonnees temporaires du Lutin
        tempx = *lLutin +dx;    ///x temporaire : x + dx
        tempy = *cLutin +dy;    ///y temporaire : y + dy


        ///si à sa prochaine position
        ///(Lutin ne sort pas de la grille en bas et à droite) et
        ///(Lutin ne sort pas de la grille en haut et à gauche)
        if ((tempx < largeurGrille && tempy < largeurGrille) && (tempx >= 0 && tempy >= 0)){

            grille [*lLutin][*cLutin] = 0; /// On vide la position actuelle du lutin

            *lLutin = tempx; /// on change la position x du lutin
            *cLutin = tempy; /// on change la position y du lutin

            if (grille[*lLutin][*cLutin] == 3) /// si lutin touche une porte
                *fin = 1; /// Partie gagnée
            else if (grille[*lLutin][*cLutin] == 2) /// si lutin touche un montre
                *fin = 2; /// Partie perdue

            grille [*lLutin][*cLutin] = 1; /// On place le lutin sur la grille à sa nouvelle position
        }

}


int deplacementsMonstresLutins (int reponse, int *nbTours, int grille [10][10], int largeurGrille, int nbMonstres,
                                monstre tabMonstres [], int *lLutin, int *cLutin, int lPorte, int cPorte) {

    *nbTours+=1; /// on ajoute un tour au compteur
    int *fin,a; /// Etat de la fin
    a = 0;
    fin = &a;


    switch(reponse) { ///switch direction du lutin
    case 1 : /// le lutin va à gauche
        depLutin(0,-1,grille,largeurGrille,lLutin, cLutin, fin);
        break;
    case 2 : /// le lutin va en haut
        depLutin(-1,0,grille,largeurGrille,lLutin, cLutin, fin);
        break;
    case 3 : /// le lutin va à droite
        depLutin(0,1,grille,largeurGrille,lLutin, cLutin, fin);
        break;
    case 4 : /// le lutin va en bas
        depLutin(1,0,grille,largeurGrille,lLutin, cLutin, fin);
        break;
    }

    if (*fin == 2){ /// si la partie est perdue
        return *fin; /// partie perdue en n tours
    }

    int j = 0;

    while ((j<nbMonstres)&&(*fin!=2)){
         depMonstreMain(grille,largeurGrille,j,tabMonstres,fin); ///On deplace les monstres
         j++;
    }


    return *fin; /// fin de la partie en n tours / partie gagnee en n tours

}
