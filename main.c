#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gestionPort.h"
#include "bateau.h"

int main() {
    Bateau b = saisirBateau();
    afficherDetailsBateau(&b);
    return EXIT_SUCCESS;
}
