/*
 * File:   gestionPort.h
 * Author: Aloïs Christen, Doran Kayoumi
 *
 * Created on 28. mai 2019, 16:47
 */

#include <stdio.h>
#include <stdlib.h>

#include "tools.h"
#include "gestionPort.h"


/**
 * @brief Parcours un port afin de trouver la première place disponible
 * @param port a parcourirs
 * @return la première place de libre
 * @note s'il n'y a pas de place de libre, l'index retourné sera plus grande que la capacité du tabeau
 */
size_t premierEmplacementLibre(const Port port) {
    size_t i = 0;

    while (i < CAPACITE_PORT && port[i] != NULL) i++;

    return i;
}

/**
 * @brief Parcours un port afin de trouver la position d'un bateau
 * @param plaque du bateau cherché
 * @param port
 *
 * @return la position du bateau s'il a été trouvé, sinon -1
 */
int trouverBateau(NoPlaque plaque, Port port) {
    for (int i = 0; i < CAPACITE_PORT; ++i) {
        if (port[i] && port[i]->no == plaque) {
            return i;
        }
    }
    return -1;
}

bool placerBateau(const Bateau *bateau, Port port) {
    // Parcours du port pour vérifier si le bateau n'est pas déjà présent
    // s'il est déjà présent, on ne fais rien
    size_t place = trouverBateau(bateau->no, port);
    if (place == -1)
        return false;

    // On vérifie s'il y a une place de livre de port
    size_t i = premierEmplacementLibre(port);
    if (i >= CAPACITE_PORT) {
        return false;
    }

    // Tout est ok, alors le bateau peut être ajouter dans le port
    port[i] = (Bateau *) bateau;
    return true;
}


void libererPlace(NoPlaque plaque, Port port) {

    // recherche du bateau
    size_t place = trouverBateau(plaque, port);

    if (place < CAPACITE_PORT) {
        port[place] = NULL;
    }
}

void afficherDetails(NoPlaque plaque, Port port) {
    size_t empl = trouverBateau(plaque, port);
    if (empl < CAPACITE_PORT) {

        printf("Details du bateau %s : \n", plaque);
        afficherDetailsBateau(port[empl]);
    }
}

void afficherPlace(size_t place, Port port) {
    printf("Bateau à la place %d : \n", place);

    if (port[place]) {
        afficherBateau(port[place]);
    } else {
        printf("-\n");
    }
    NEW_LINE;
}

void parcours(Port port, void(*action)(Bateau *bateau)) {
    for (size_t i = 0; i < CAPACITE_PORT; i++) {
        if (port[i])
            action(port[i]);
    }
}

void afficherPort(Port port) {
    printf("Affichage du port : \n");
    printf("-------------------\n");

    parcours(port, afficherDetailsBateau);
}

