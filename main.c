#include <stdio.h>
#include <stdlib.h>
#include "entetes.h"


int main()
{
    FILE    *fConfig ;                  /// lien vers le fichier conteant les valeurs initiales de la grille
    FILE    *fDeplLutin ;               /// lien vers le fichier contenant la liste des d�placements du lutin
    int     largeurGrille ;             /// variables qui permettent
    int     grille [10][10] ;           /// de repr�senter la grille
    int     nbMonstres ;                /// nombre de monstres pr�sents sur la grille (maximum 10)
    monstre tabMonstres [10] ;          /// tableau qui stocke les coordonn�es et les d�placements des monstres
    int     lLutin, cLutin ;            /// ligne et colonne du lutin
    int     lPorte, cPorte ;            /// ligne et colonne de la porte de sortie
    int     finDePartie = 0 ;           /// variable qui d�termine que la partie est finie
                                        /// 0=partie en cours, 1 = partie gagn�e, 2 = partie perdue
    int     nbTours = 0 ;               /// indique en combien de ours la partie se termine

    int     deplLutin ;                 /// indique le sens de d�placement du lutin


    /// ////////////////////////////////////////////////////// ///
    /// r�cup�ration de la grille stock� dans un fichier texte ///
    /// ////////////////////////////////////////////////////// ///
    fConfig = fopen ("grille1.txt","r") ;
    recuperationGrille (fConfig, grille, &largeurGrille, &nbMonstres, tabMonstres, &lLutin, &cLutin, &lPorte, &cPorte) ;

    /// affichage de la grille r�cup�r�e
    afficherGrille (grille, largeurGrille) ;
    ///afficherMonstres (tabMonstres, nbMonstres) ;


    fDeplLutin = fopen ("deplacementsLutin_grille1.txt", "r") ;
    while (finDePartie == 0 && !feof(fDeplLutin))
    {
        fscanf (fDeplLutin, "%d", &deplLutin) ;
        printf ("Le lutin se deplace ") ;
        if (deplLutin==1)
            printf ("a gauche\n") ;
        else if (deplLutin==2)
            printf ("en haut\n") ;
        else if (deplLutin==3)
            printf ("a droite\n") ;
        else if (deplLutin==4)
            printf ("en bas\n") ;

        finDePartie = deplacementsMonstresLutins (deplLutin, &nbTours, grille, largeurGrille, nbMonstres, tabMonstres, &lLutin, &cLutin, lPorte, cPorte) ;
        printf ("Appuyez sur entree pour jouer le tour suivant\n") ;
        getchar () ;
        system("CLS") ;                 /// permet d'effacer la console
        afficherGrille (grille, largeurGrille) ;
    }
    if (finDePartie==1)
        printf ("la partie a ete gagnee en %d tours\n", nbTours) ;
    else if (finDePartie==2)
        printf ("la partie a ete perdue en %d tours\n", nbTours) ;
    else
        printf ("partie nulle apres %d tours\n", nbTours) ;

    getchar () ;

    fclose (fConfig) ;
    fclose (fDeplLutin) ;

    return 0;
}
