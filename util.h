#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

void printAthleteDebug(Athlete *ptr);

void printAthleteTop50(Athlete *ptr);

void printAthleteTop50Ep(Athlete *ptr, int epreuveId);

void printAthleteDefaut(Athlete *ptr);

void printTop50(ListeTop50 liste);

void printTop50Genre(ListeTop50 liste, char genre);

void printTop50Region(ListeTop50 liste, int regionId);

void printTop50Epreuve(ListeTop50Ep liste, int epreuveId);

void printTopSalle(ListeTop50 liste, unsigned int salleId);

void printTopSalleLille(ListeTop50 liste);

void printListeHashTableau(ListeHash liste[], int listeSize);

void tiret(int n);

#endif
