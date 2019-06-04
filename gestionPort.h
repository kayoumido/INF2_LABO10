/*
 * File:   gestionPort.h
 * Author: Aloïs Christen, Doran Kayoumi
 *
 * Created on 28. mai 2019, 16:47
 */

#ifndef LABO10_GESTIONPORT_H
#define LABO10_GESTIONPORT_H

#include <stdbool.h>

#define CAPACITE_PORT 40
#define LONGUEUR_PLAQUE_MAX 5
#define NB_TYPE 3

const char* TYPE_BATEAU[] = {
    "Moteur",
    "Voile",
    "Rame"
};

typedef enum {
    MOTEUR, VOILE, RAME
} Type;

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

typedef union {
    BateauMoteur moteur;
    BateauVoile  voile;
    BateauRame   rame;
} Details;

typedef struct {
    Type type;
    NoPlaque no;
    double longeur; // mètres
    Details details;
} Bateau;

typedef Bateau* Port[CAPACITE_PORT];


Bateau saisirBateau();

bool placerBateau(Bateau bateau, Port port);

void libererPlace(NoPlaque plaque);

void afficherDetails(NoPlaque plaque);

void parcours();

void afficherPort();

#endif //LABO10_GESTIONPORT_H
