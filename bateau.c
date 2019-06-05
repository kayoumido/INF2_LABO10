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
    "Voile",
    "Rame"
};


Details saisirDetailsMoteur(void);
Details saisirDetailsVoile(void);
Details saisirDetailsRame(void);

Details (*saisirDetails[])(void) = {
    saisirDetailsMoteur,
    saisirDetailsRame,
    saisirDetailsVoile
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
    result.no = no;

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

void afficherDetailsBateau(Bateau* b){
    
}

