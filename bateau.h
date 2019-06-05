/*
 * File:   bateau.h
 * Author: Aloïs Christen, Doran Kayoumi
 *
 * Created on 28. mai 2019, 16:47
 */

#ifndef BATEAU_H
#define BATEAU_H

typedef enum {MOTEUR, VOILE, RAME} Type;
typedef const char* NoPlaque;

typedef struct  {
    unsigned short nbMoteurs;
    double puissance;
} BateauMoteur;

typedef struct  {
    unsigned short nbRames;
} BateauRame;

typedef struct  {
    double surface; // mètre carrés
} BateauVoile;

typedef union   {
  BateauMoteur moteur;
  BateauRame rame;
  BateauVoile voile;
} Details;

typedef struct  {
  Type type;
  NoPlaque no;
  double longeur; // mètres
  Details details;
} Bateau;

Bateau saisirBateau();
void afficherDetailsBateau(Bateau* b);

#endif /* BATEAU_H */

