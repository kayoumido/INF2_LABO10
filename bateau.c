/*
 * File:   bateau.c
 * Author: Aloïs Christen, Doran Kayoumi
 *
 * Created on 28. mai 2019, 16:47
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bateau.h"
#include "tools.h"

#define LONGUEUR_PLAQUE_MAX 5
#define NB_TYPE 3

const char* TYPE_BATEAU[] = {
    "Moteur",
    "Voile",
    "Rame"
};

NoPlaque saisirNoPlaque(void);
Longueur saisirLongueur(void);
Type     saisirType(void);


Details saisirDetailsMoteur(void);
Details saisirDetailsVoile(void);
Details saisirDetailsRame(void);

Details (*saisirDetails[])(void) = {
    saisirDetailsMoteur,
    saisirDetailsRame,
    saisirDetailsVoile
};


Bateau saisirBateau(){
    Bateau bateau;

    bateau.no = saisirNoPlaque();
    bateau.longeur = saisirLongueur();
    bateau.type = saisirType();
    bateau.details = saisirDetails[bateau.type]();

    return bateau;
}

NoPlaque saisirNoPlaque(void) {
    unsigned ok;
    char no[LONGUEUR_PLAQUE_MAX+1];
    do {
        printf("Veuillez saisir le no de plaque du bateau : ");

        char format[5];
        sprintf(format, "%%%ds", LONGUEUR_PLAQUE_MAX);

        ok = scanf(format, &no);
        VIDER_BUFFER;
    } while (!ok && printf("Le no de plaque saisie est invalide!\n"));
    NEW_LINE;

    return no;
}

Longueur saisirLongueur(void) {
    Longueur longueur;
    unsigned ok;
    do {
        printf("Veuillez saisir la longueur du bateau : ");

        ok = scanf("%lf", &longueur);
        VIDER_BUFFER;
    } while (!ok && printf("La longueur saisie est invalide!\n"));
    NEW_LINE;

    return longueur;
}

Type saisirType(void) {
    unsigned ok;
    Type type;
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
    } while ((!ok || type > NB_TYPE - 1) && printf("Le type saisie est inconnu!\n"));
    NEW_LINE;

    return type;
}

Details saisirDetailsMoteur(void) {
    Details result;
    NBMoteurs nbMoteurs;
    Puissance puissance;
    unsigned ok;

    do {
        printf("Veuillez saisir le nombre de moteurs : ");
        ok = scanf("%hu", &nbMoteurs);
        VIDER_BUFFER;
    } while (!ok && printf("NNMoteurs : Erreur de saisie!"));
    NEW_LINE;

    do {
        printf("Veuillez saisir la puissance : ");
        ok = scanf("%hu", &puissance);
        VIDER_BUFFER;
    } while (!ok && printf("Puissance : Erreur de saisie!"));
    NEW_LINE;

    result.moteur = (BateauMoteur){
        .nbMoteurs = nbMoteurs,
        .puissance = puissance
    };

    return result;
}

Details saisirDetailsVoile(void) {
    Details result;

    Surface surface;
    unsigned ok = 0;

    do {
        printf("");
        ok = scanf("%lf", &surface);
        VIDER_BUFFER;
    } while (!ok && printf("Surface : Erreur de saisie!"));
    NEW_LINE;

    result.voile = (BateauVoile) {
        .surface = surface
    };

    return result;
}

Details saisirDetailsRame(void) {
    Details result;

    NBRames nbRames;
    unsigned ok;

    do {
        printf("Veuillez saisir le nombre de rames : ");
        ok = scanf("%hu", &nbRames);
        VIDER_BUFFER;
    } while (!ok && printf("Surface : Erreur de saisie!"));
    NEW_LINE;

    result.rame = (BateauRame) {
        .nbRames = nbRames
    };

    return result;
}




