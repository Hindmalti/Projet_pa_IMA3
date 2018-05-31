#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

void printAthleteTop50(Athlete *ptr);

void printAthleteTop50Ep(Athlete *ptr, int epreuveId);

void printAthleteDefaut(Athlete *ptr);

void printTop50(ListeTop50 liste[], int listeSize);

void printTop50Genre(ListeTop50 liste[], int listeSize, char genre);

void printTop50Region(ListeTop50 liste[], int listeSize, int regionId);

void printTop50Epreuve(ListeTop50Ep liste[][5], int listeSize, int epreuveId);

void printTopSalle(ListeTop50 liste[], unsigned int salleId);

void printTopSalleLille(ListeTop50 liste[]);

void tiret(int n);

void chargementTexte(int pourcent);

#endif
