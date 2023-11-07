#ifndef MON_H
#define MON_H

#include <stdio.h>




typedef struct
{
    int ligne ;
    int col ;
    int depl ;      /// 1=gauche, 2=haut, 3=droite, 4=bas
} monstre ;




void recuperationGrille (FILE *f, int grille [10][10], int *largeurGrille, int *nbMonstres, monstre tabMonstres [], int *lLutin, int *cLutin, int *lPorte, int *cPorte) ;
void afficherMonstres (monstre tabMonstres [], int nbMonstres) ;
void afficherLigneVide (int largeur) ;
void afficherLigneNumeros (int grille [10][10], int largeur, int l) ;
void afficherLignePleine (int largeur) ;
void afficherGrille (int grille [10][10], int largeur) ;


int deplacementsMonstresLutins (int reponse, int *nbTours, int grille [10][10], int largeurGrille, int nbMonstres,
                                monstre tabMonstres [], int *lLutin, int *cLutin, int lPorte, int cPorte) ;

void depLutin(int dx,int dy,int grille [10][10],int largeurGrille,int *lLutin, int *cLutin,int *fin);





void depMonstreMain(int grille[10][10],int largeurGrille,int j,monstre tabMonstre [],int *fin);

int getLigne(monstre tabMonstre [],int j);
void sendLigne(monstre tabMonstre [],int j,int var);
int getCol(monstre tabMonstre [],int j);
void sendCol(monstre tabMonstre [],int j,int var);
int getDepl(monstre tabMonstre [],int j);
void sendDepl(monstre tabMonstre [],int j,int var);



int depMonstre(int grille[10][10],int largeurGrille,int j,monstre tabMonstre []);
void sensMonstre(int grille[10][10],int largeurGrille,int j,monstre tabMonstre []);



#endif
