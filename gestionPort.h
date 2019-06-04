/*
 * File:   gestionPort.h
 * Author: Aloïs Christen, Doran Kayoumi
 *
 * Created on 28. mai 2019, 16:47
 */

#ifndef LABO10_GESTIONPORT_H
#define LABO10_GESTIONPORT_H

#include <stdbool.h>
#include "bateau.h"

#define CAPACITE_PORT 40


typedef const char *NoPlaque;

typedef struct {
    unsigned short nb_moteurs;
    double puissance;
} BateauMoteur;

typedef struct {
    unsigned short nb_rames;
} BateauRame;

typedef struct {
    double surface; // mètre carrés
} BateauVoile;



typedef Bateau* Port[CAPACITE_PORT];



bool placerBateau(Bateau bateau, Port port);

void libererPlace(NoPlaque plaque);

void afficherDetails(NoPlaque plaque);

void parcours();

void afficherPort();

#endif //LABO10_GESTIONPORT_H
