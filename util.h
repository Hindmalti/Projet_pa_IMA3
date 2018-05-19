#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

void printAthlete(Athlete *ptr);

int asciis(char *word);

int hash_int(int athID);

int hash_word(char *word);

void initialisation(ListeTop50 *liste50, ListeHash listeHashID[], int listeHashIDSize, ListeHash listeHashNom[], int listeHashNomSize);

void detruitTeteHash(ListeHash *liste);

void detruitTeteTop50(ListeTop50 *liste);
	
void ajoutAthleteTeteTrieeScore(ListeTop50 *liste, Athlete athlete, ElementTop50 *element);

void ajoutTeteListeHash(ListeHash *liste, Athlete *ath);

void ajoutAthleteHashID(ListeHash liste[], int listeSize, Athlete *ath);

void ajoutAthleteHashNom(ListeHash liste[], int listeSize, Athlete *ath);

Athlete* rechercheAthleteID(ListeHash liste[], int listeSize, int athID);

Athlete* rechercheAthleteNom(ListeHash liste[], int listeSize, char *lastName, char *firstName);

void printListeAthlete(ListeTop50 liste);

void printListeHashTableau(ListeHash liste[], int listeSize);

void detruireTout(ListeTop50 *liste50, ListeHash listeHashID[], int listeHashIDSize, ListeHash listeHashNom[], int listeHashNomSize);

void tiret(int n);

void ajoutAthlete(ListeTop50 *liste50, ListeHash listeHashID[], int listeHashIDSize, ListeHash listeHashNom[], int listeHashNomSize, Athlete *ath);

#endif
