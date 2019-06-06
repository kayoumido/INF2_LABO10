#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "gestionPort.h"
#include "bateau.h"
#include "tools.h"

int main() {
//    Bateau b1 = saisirBateau();
//    Bateau b2 = saisirBateau();
//    Bateau b3 = saisirBateau();

    Bateau b1 = (Bateau) {
        .no   = "VD123",
        .type = MOTEUR,
        .longeur = 5,
        .details.moteur = (BateauMoteur) {
            .nbMoteurs = 2,
            .puissance = 3
        }
    };

    Bateau b2 = (Bateau) {
        .no   = "VD456",
        .type = VOILE,
        .longeur = 5,
        .details.voile = (BateauVoile) {
            .surface = 10
        }
    };

    Bateau b3 = (Bateau) {
        .no   = "VD789",
        .type = RAME,
        .longeur = 5,
        .details.rame = (BateauRame) {
            .nbRames = 2
        }
    };

//    afficherDetailsBateau(&b1);
//    afficherDetailsBateau(&b2);
//    afficherDetailsBateau(&b3);

    Port port;

    // For some reason when the port is init, it's filled with random data
    //  so to avoid issues later on, everything is set to NULL
    for (size_t i = 0; i < CAPACITE_PORT; ++i) {
        port[i] = NULL;
    }

    placerBateau(&b1, port);
    placerBateau(&b2, port);
    placerBateau(&b3, port);
    afficherPort(port);
    NEW_LINE;

    libererPlace("VD123", port);
    afficherPort(port);
    NEW_LINE;


    afficherPlace(0, port);
    afficherPlace(1, port);
    afficherPlace(2, port);
    NEW_LINE;

    afficherDetails("VD789", port);


    return EXIT_SUCCESS;
}
