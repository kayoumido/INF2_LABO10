/*
 * File:   gestionPort.h
 * Author: Aloïs Christen, Doran Kayoumi
 *
 * Created on 28. mai 2019, 16:47
 */

#include <stdio.h>

#include "gestionPort.h"

#define VIDER_BUFFER while(getchar() != '\n')

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

Details saisirDetailsMoteur(void) {
    Details result;

    printf("saisirDetailsMoteur");

    return result;
}

Details saisirDetailsVoile(void) {
    Details result;

    printf("saisirDetailsVoile");

    return result;
}

Details saisirDetailsRame(void) {
    Details result;

    printf("saisirDetailsRame");

    return result;
}
