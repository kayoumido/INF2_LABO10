/*
 * File:   bateau.c
 * Author: Aloïs Christen, Doran Kayoumi
 *
 * Implementation des fonctions de gestion de bateau
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "bateau.h"
#include "tools.h"

#define LONGUEUR_PLAQUE_MAX 5
#define NB_TYPE 3

const char* TYPE_BATEAU[] = {
    "Moteur",
    "Voile",
    "Rame"
};

/**
 * @brief Gestion de la saisie d'un no de plaque
 *
 * @return le no de plaque
 */
NoPlaque saisirNoPlaque(void);

/**
 * @brief Gestion de la saisie d'une longueur de bateau
 *
 * @return la longueur
 */
Longueur saisirLongueur(void);

/**
 * @brief Gestion de la saisie d'un type de bateau
 *
 * @return le type du bateau
 */
Type saisirType(void);

/**
 * @brief Gestion de la saisie des détails d'un bateau moteur
 *
 * @return Les details d'un bateau moteur
 */
Details saisirDetailsMoteur(void);

/**
 * @brief Gestion de la saisie des détails d'un bateau rame
 *
 * @return Les details d'un bateau rame
 */
Details saisirDetailsRame(void);

/**
 * @brief Gestion de la saisie des détails d'un bateau voile
 *
 * @return Les details d'un bateau voile
 */
Details saisirDetailsVoile(void);

/**
 * @brief Affiche le détails d'une bateau moteur
 *
 * @param b bateau à afficher
 */
void afficherDetailsMoteur(Bateau* b);

/**
 * @brief Affiche le détails d'une bateau rame
 *
 * @param b bateau à afficher
 */
void afficherDetailsRame(Bateau* b);

/**
 * @brief Affiche le détails d'une bateau voile
 *
 * @param b bateau à afficher
 */
void afficherDetailsVoile(Bateau* b);

Details (*saisirDetails[])(void) = {
    saisirDetailsMoteur,
    saisirDetailsVoile,
    saisirDetailsRame
};

void (*afficherDetailsFoncPtr[])(Bateau*) = {
    afficherDetailsMoteur,
    afficherDetailsVoile,
    afficherDetailsRame
};

Bateau saisirBateau() {
    Bateau bateau;

    bateau.no       = saisirNoPlaque();
    bateau.longeur  = saisirLongueur();
    bateau.type     = saisirType();
    bateau.details  = saisirDetails[bateau.type]();
    NEW_LINE;

    return bateau;
}

NoPlaque saisirNoPlaque(void) {
    unsigned ok;
    char* noPtr = (char*)calloc(LONGUEUR_PLAQUE_MAX+1, sizeof(char));
    do {
        printf("Veuillez saisir le no de plaque du bateau : ");

        char format[5];
        sprintf(format, "%%%ds", LONGUEUR_PLAQUE_MAX);
        ok = scanf(format, noPtr);
        VIDER_BUFFER;

    } while (!ok && printf("/!\\ Le no de plaque saisie est invalide!\n"));

    return noPtr;
}

Longueur saisirLongueur(void) {
    Longueur longueur;
    unsigned ok;
    do {
        printf("Veuillez saisir la longueur du bateau : ");

        ok = scanf("%lf", &longueur);
        VIDER_BUFFER;
    } while (!ok && printf("La longueur saisie est invalide!\n"));

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

    return type;
}

Details saisirDetailsMoteur(void) {
    Details result;
    NBMoteurs nbMoteurs;
    Puissance puissance;

    unsigned ok;
    do {
        printf("%s", "Veuillez saisir le nombre de moteurs : ");

        ok = scanf("%u", &nbMoteurs);
        VIDER_BUFFER;
    } while (!ok && printf("%s", "NNMoteurs : Erreur de saisie!"));

    do {
        printf("%s", "Veuillez saisir la puissance : ");

        ok = scanf("%lf", &puissance);
        VIDER_BUFFER;
    } while (!ok && printf("%s", "Puissance : Erreur de saisie!"));

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
        printf("Veuillez saisir la surface de la voile : ");
        ok = scanf("%lf", &surface);
        VIDER_BUFFER;
    } while (!ok && printf("Surface : Erreur de saisie!"));

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
    } while (!ok && printf("Rame : Erreur de saisie!"));

    result.rame = (BateauRame) {
        .nbRames = nbRames
    };

    return result;
}

void afficherBateau(Bateau* b){
   printf("No de plaque\t:\t%s\n", b->no);
   printf("Longeur\t\t:\t%lf\n", b->longeur);
   printf("Type de bateau\t:\t%s\n", TYPE_BATEAU[b->type]);
}

void afficherDetailsBateau(Bateau* b) {
    if (!b)
        return;

    afficherBateau(b);

   // Appel de la fonction d'afficher des details 
    afficherDetailsFoncPtr[b->type](b);
    NEW_LINE;
}

void afficherDetailsMoteur(Bateau* b) {
    printf("Nombre de moteurs \t:\t%u \n", b->details.moteur.nbMoteurs);
    printf("Puissance totale  \t:\t%lf\n", b->details.moteur.puissance);
}

void afficherDetailsRame(Bateau* b) {
    printf("Nombre de rames\t:\t%u\n", b->details.rame.nbRames);
}

void afficherDetailsVoile(Bateau* b) {
    printf("Surface des voiles\t:\t%lf\n", b->details.voile.surface);
}