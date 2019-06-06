/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bateau.h"

#define VIDER_BUFFER while(getchar() != '\n')
#define LONGUEUR_PLAQUE_MAX 5
#define NB_TYPE 3

const char* TYPE_BATEAU[] = {
    "Moteur",
    "Rame",
    "Voile"
};


Details saisirDetailsMoteur(void);
Details saisirDetailsRame(void);
Details saisirDetailsVoile(void);

Details (*saisirDetails[])(void) = {
    saisirDetailsMoteur,
    saisirDetailsRame,
    saisirDetailsVoile
};

void afficherDetailsMoteur(Bateau* b);
void afficherDetailsRame(Bateau* b);
void afficherDetailsVoile(Bateau* b);

void (*afficherDetails[])(Bateau*) = {
    afficherDetailsMoteur,
    afficherDetailsRame,
    afficherDetailsVoile
};

Bateau saisirBateau(){
    Bateau result;

    // Noplaque
    unsigned ok;
    char no[LONGUEUR_PLAQUE_MAX+1];
    do {
        printf("Veuillez saisir le no de plaque du bateau : ");

        char format[5];
        sprintf(format, "%%%ds", LONGUEUR_PLAQUE_MAX);

        ok = scanf(format, &no);
        VIDER_BUFFER;
    } while (!ok && printf("Une erreur est survenu!\n"));
    result.No = no;

    printf("\n");

    // longueur
    double longueur;
    do {
        printf("Veuillez saisir la longueur du bateau : ");

        ok = scanf("%lf", &longueur);
        VIDER_BUFFER;
    } while (!ok && printf("Une erreur est survenu!\n"));
    result.longeur = longueur;

    printf("\n");

    Type type;
    // type
    do {
        printf("Veuilez saisir le type du bateu [");
        for (int i = 0; i < NB_TYPE; ++i) {
            if (i)
                printf(", ");

            printf("%d:%s", i, TYPE_BATEAU[i]);
        }
        printf("] : ");

        ok = scanf("%d", &type);
        VIDER_BUFFER;
    } while ((!ok || type > NB_TYPE - 1) && printf("Une erreur est survenu!\n"));
    result.type = type;

    printf("\n");

    // detail
    result.details = saisirDetails[result.type]();

    return result;
}




Details saisirDetailsMoteur(void) {
    Details result;

    unsigned ok; 
    do {
        printf("Veuilez saisir le nombre de moteurs du bateau :");
        ok = scanf("%c", &(result.moteur.nb_moteurs));
        VIDER_BUFFER;
    } while (!ok && printf("Une erreur est survenu!\n"));

    do {
        printf("Veuilez saisir la puissance totale des moteurs :");
        ok = scanf("%lf", &(result.moteur.puissance));
        VIDER_BUFFER;
    } while (!ok && printf("Une erreur est survenu!\n"));
    return result;
}


Details saisirDetailsRame(void) {
    Details result;

    unsigned ok; 
    do {
        printf("Veuilez saisir le nombre de rames du bateau :");
        ok = scanf("%c", &(result.rame.nb_rames));
        VIDER_BUFFER;
    } while (!ok && printf("Une erreur est survenu!\n"));

    return result;
}


Details saisirDetailsVoile(void) {
    Details result;

    unsigned ok; 
    do {
        printf("Veuilez saisir la surface totale des voiles du bateau :");
        ok = scanf("%lf", &(result.voile.surface));
        VIDER_BUFFER;
    } while (!ok && printf("Une erreur est survenu!\n"));

    return result;
}

void afficherDetailsBateau(Bateau* b, bool aussi_type){
   printf("No de plaque\t:\t%s\n", b->No);
   printf("Longeur\t\t:\t%lf\n", b->longeur);
   printf("Type de bateau\t:\t%s\n", TYPE_BATEAU[b->type]);
   if(aussi_type){
   // Appel de la fonction d'afficher des details 
        afficherDetails[b->type](b);
   }
}

void afficherDetailsMoteur(Bateau* b){
    printf("Nombre de moteurs\t:\t%u\n", b->details.moteur.nb_moteurs);
    printf("Puissance totale\t:\t%lf\n", b->details.moteur.puissance);
}
void afficherDetailsRame(Bateau* b){
    printf("Nombre de rames\t:\t%u\n", b->details.rame.nb_rames);
}
void afficherDetailsVoile(Bateau* b){
    printf("Surface des voiles\t:\t%lf\n", b->details.voile.surface);
}