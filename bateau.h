/*
 * File:   bateau.h
 * Author: Aloïs Christen, Doran Kayoumi
 *
 * Created on 28. mai 2019, 16:47
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

Bateau saisirBateau();
void afficherBateau(Bateau* b);
void afficherDetailsBateau(Bateau* b);

#endif /* BATEAU_H */

