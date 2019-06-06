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

/**
 * @brief Ajoute un bateau (pointeur) dans un port
 *
 * @param bateau Pointeur vers le bateau a ajouter au port
 * @param port dans lequel on veut ajouter le bateau
 * @return Vrai si le bateau a été ajouté, sinon faux
 */
bool placerBateau(const Bateau* bateau, Port port);

/**
 * @brief Libère une place dans le port
 * @param plaque Le no de plaque du bateau
 * @param port dans lequel on veut liberer une place
 */
void libererPlace(NoPlaque plaque, Port port);

/**
 * @brief Affiche le détail complet d'un bateau
 *
 * @param plaque du bateau afficher
 * @param port
 */
void afficherDetails(NoPlaque plaque, Port port);

/**
 * @brief Affiche l'infos de base du bateau se trouvant à une place
 *
 * @param place que l'on veut afficher
 * @param port
 */
void afficherPlace(size_t place, Port port);

/**
 * @brief Permet un traitement à chacune des places du port.
 *
 * @param port a parcourir
 * @param action le traitement a effectuer
 */
void parcours(Port port, void(*action)(Bateau* bateau));

/**
 * @brief Affiche un port
 * @param port à afficher
 */
void afficherPort(Port port);

#endif //LABO10_GESTIONPORT_H
