/*
 * File:   bateau.h
 * Author: Aloïs Christen, Doran Kayoumi
 *
 * Déclaration de la structure d'un bateau et des divers fonctions
 * de gestion de bateaux
 */

#ifndef BATEAU_H
#define BATEAU_H

#include <stdbool.h>

typedef enum {MOTEUR, VOILE, RAME} Type;
typedef const char* NoPlaque;
typedef double Longueur;
typedef double Puissance;
typedef double Surface;
typedef unsigned int NBMoteurs;
typedef unsigned int NBRames;

typedef struct  {
    NBMoteurs nbMoteurs;
    Puissance puissance;
} BateauMoteur;

typedef struct  {
    NBRames nbRames;
} BateauRame;

typedef struct  {
    Surface surface; // mètre carrés
} BateauVoile;

typedef union   {
  BateauMoteur moteur;
  BateauRame rame;
  BateauVoile voile;
} Details;

typedef struct  {
  Type type;
  NoPlaque no;
  Longueur longeur; // mètres
  Details details;
} Bateau;

/**
 * @brief Effectue la saisie utilisateur pour créer un bateau
 *
 * @return Bateau créé à partir des données saisies par l'utilisateur
 */
Bateau saisirBateau();

/**
 * @brief Affiche les infos commune a tous les types de bateau
 *
 * @param b le bateau a afficher
 */
void afficherBateau(Bateau* b);

/**
 * @brief Affiche TOUTES les données d'une bateau
 *
 * @param b le bateau a afficher
 */
void afficherDetailsBateau(Bateau* b);

#endif /* BATEAU_H */

