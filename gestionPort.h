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

typedef Bateau* Port[CAPACITE_PORT];



bool placerBateau(const Bateau* bateau, Port port);

void libererPlace(NoPlaque plaque, Port port);

void afficherDetails(NoPlaque plaque, Port port);

void afficherPlace(size_t empl, Port port);

void parcours(Port port, void(*f)(NoPlaque no, Port port));

void afficherPort(Port port);

#endif //LABO10_GESTIONPORT_H
