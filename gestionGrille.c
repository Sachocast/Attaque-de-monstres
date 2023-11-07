
#include <stdio.h>
#include <stdlib.h>
#include "entetes.h"


void recuperationGrille (FILE *f, int grille [10][10], int *largeurGrille, int *nbMonstres, monstre tabMonstres [], int *lLutin, int *cLutin, int *lPorte, int *cPorte)
{
    int i, j, l, c, dep ;
    fscanf (f, "%d", largeurGrille) ;
    fscanf (f, "%d", nbMonstres) ;

    for(int i=0; i<*largeurGrille; i++)
    {
        for (j=0; j<*largeurGrille; j++)
            grille[i][j] = 0 ;
    }
    for(i=0; i<*nbMonstres; i++)
    {
        fscanf (f, "%d %d %d", &l, &c, &dep) ;
        tabMonstres [i].ligne = l ;
        tabMonstres [i].col = c ;
        tabMonstres [i].depl = dep ;
        grille [l][c] = 2 ;
    }
    fscanf (f, "%d %d",&l, &c) ;
    grille [l][c] = 1 ;
    *lLutin = l ;
    *cLutin = c ;

    fscanf (f, "%d %d",&l, &c) ;
    grille [l][c] = 3 ;
    *lPorte = l ;
    *cPorte = c ;
}

void afficherMonstres (monstre tabMonstres [], int nbMonstres)
{
    printf ("Deplacement des monstres :  ") ;
    for (int i=0; i<nbMonstres; i++)
    {
        printf ("[%d, %d] = %d    ", tabMonstres [i].ligne, tabMonstres [i].col, tabMonstres [i].depl) ;
    }
    printf ("\n") ;
}


/// ///////////////////////////////////////// ///
/// //////D�but affichage de la grille/////// ///
/// ///////////////////////////////////////// ///

void afficherLigneVide (int largeur)
{
    for (int j=0; j<largeur; j++)
    {
        printf ("\t|") ;
    }
    printf ("\n") ;
}

void afficherLigneNumeros (int grille [10][10], int largeur, int l)
{
    printf("|") ;
    for (int j=0; j<largeur; j++)
        if(grille [l][j]==1)
            printf ("   L\t|") ;
        else if(grille [l][j]==2)
            printf ("   M\t|") ;
        else if(grille [l][j]==3)
            printf ("   S\t|") ;
        else
            printf ("\t|") ;
    printf ("\n|") ;
}

void afficherLignePleine (int largeur)
{
    for (int i=0; i<largeur; i++)
    {
        printf ("+-------") ;
    }
    printf ("+\n") ;
}

void afficherGrille (int grille [10][10], int largeur)
{
    int i ;

    printf ("\n\n\n") ;

    ///Ligne du haut de la grille
    afficherLignePleine (largeur) ;

    for (i=0; i<largeur; i++)
    {
        printf ("|") ;
        afficherLigneVide (largeur) ;
        afficherLigneNumeros (grille, largeur, i) ;
        afficherLigneVide (largeur) ;
        afficherLignePleine (largeur) ;
    }
}

/// ///////////////////////////////////////// ///
/// ///////Fin affichage de la grille//////// ///
/// ///////////////////////////////////////// ///


