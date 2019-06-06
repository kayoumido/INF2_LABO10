#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gestionPort.h"

int main() {
    Bateau b = saisirBateau();
    afficherDetailsBateau(&b, true);
    return EXIT_SUCCESS;
}
