/*
 * File:   gestionPort.h
 * Author: Aloïs Christen, Doran Kayoumi
 *
 * Created on 28. mai 2019, 16:47
 */

#include <stdio.h>

#include "gestionPort.h"

Details saisirDetailsMoteur(void);
Details saisirDetailsVoile(void);
Details saisirDetailsRame(void);

Details (*saisirDetails[])(void) = {
    saisirDetailsMoteur,
    saisirDetailsRame,
    saisirDetailsVoile
};


Bateau saisirBateau() {
    Bateau result;

    // Noplaque
    unsigned ok;
    char no[MAX_NO_LENGTH+1];
    do {
        printf("Veuillez saisir le no de plaque du bateau : ");

        char format[5];
        sprintf(format, "%%%ds", MAX_NO_LENGTH);

        ok = scanf(format, &no);

    } while (!ok && printf("Une erreur est survenu!\n"));
    result.no = no;

    printf("\n");

    // longueur
    double longueur;
    do {
        printf("Veuillez saisir la longueur du bateau : ");

        ok = scanf("%lf", &longueur);

    } while (!ok && printf("Une erreur est survenu!\n"));
    result.longeur = longueur;

    printf("\n");

    Type type;
    // type
    do {
        printf("Veuilez saisir le type du bateu [0:Moteur, 1:Voile, 2:Rame] : ");

        ok = scanf("%d", &type);

    } while ((!ok || type > MAX_NB_BATEAU_TYPE - 1) && printf("Une erreur est survenu!\n"));
    result.type = type;

    printf("\n");

    // detail
    result.details = saisirDetails[result.type]();

    return result;
}

Details saisirDetailsMoteur(void) {
    Details result;
    return result;
}

Details saisirDetailsVoile(void) {
    Details result;
    return result;
}

Details saisirDetailsRame(void) {
    Details result;
    return result;
}
