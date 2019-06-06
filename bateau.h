/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   navire.h
 * Author: Alois
 *
 * Created on 28. mai 2019, 16:47
 */

#ifndef NAVIRE_H
#define NAVIRE_H

typedef enum {MOTEUR, VOILE, RAME} Type;
typedef const char* Noplaque;

typedef struct  {
    unsigned int nb_moteurs;
    double puissance;
} Bateau_moteur;

typedef struct  {
    unsigned int nb_rames;
} Bateau_rame;

typedef struct  {
    double surface; // mètre carrés
} Bateau_voile;

typedef union   {
  Bateau_moteur moteur;  
  Bateau_rame rame;  
  Bateau_voile voile;  
} Details;

typedef struct  {
  Type type;
  Noplaque No;
  double longeur; // mètres
  Details details;
} Bateau;

Bateau saisirBateau();
void afficherDetailsBateau(Bateau* b);

#endif /* NAVIRE_H */

