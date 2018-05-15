#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

void printAthlete(Athlete *ptr);

int hash_int(int athID);

int hash_word(char *word);

int asciis(char *word);

void ajoutAthleteTeteTrieeScore(Liste_TOP_50 *liste, Athlete athlete, Element_TOP_50 *element);

void printListeAthlete(Liste_TOP_50 liste);

void tiret(int n);
 
void ajoutAthlete(Athlete* ath);

#endif
