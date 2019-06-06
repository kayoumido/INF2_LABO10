/*
 * File:   gestionPort.h
 * Author: Aloïs Christen, Doran Kayoumi
 *
 * Created on 28. mai 2019, 16:47
 */

#include <stdio.h>
#include <stdlib.h>

#include "gestionPort.h"
#define CAPACITE_PORT 40

#define VIDER_BUFFER while(getchar() != '\n')
size_t premierEmplacementLibre(const Port* port){
    size_t i = 0;
    while(i < CAPACITE_PORT && port[i] != NULL){
        i++;
    }
    return i;
}

bool placerBateau(const Bateau* bateau, Port port){
    size_t i = premierEmplacementLibre(port);
    if( i >= CAPACITE_PORT){
        return false; // Pas d'emplacements libres
    }
    port[i] = bateau;
    return true;
}

size_t trouverEmplBateau(NoPlaque plaque, Port port){
    size_t i = 0;
    for(; i < CAPACITE_PORT; ++i){
       if(port[i] && port[i]->No == plaque){
           return i;
       } 
    }
    return i;
}

void libererPlace(NoPlaque plaque, Port port){
    size_t empl = trouverEmplBateau(plaque, port);
    if(empl < CAPACITE_PORT){
        free(port[empl]);
        port[empl] = NULL;
    }
}

void afficherDetails(NoPlaque plaque, Port port){
    size_t empl = trouverEmplBateau(plaque, port);
    if(empl < CAPACITE_PORT){
        afficherDetailsBateau(port[empl], false);
    } else {
        printf("-\n");
    }
}

void parcours();

void afficherPort();

