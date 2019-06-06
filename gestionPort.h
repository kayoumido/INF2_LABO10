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


typedef Bateau* Port[CAPACITE_PORT];



bool placerBateau(const Bateau* bateau, Port port);

void libererPlace(NoPlaque plaque, Port port);

void afficherDetails(NoPlaque plaque, Port port);

void parcours();

void afficherPort();

#endif //LABO10_GESTIONPORT_H
