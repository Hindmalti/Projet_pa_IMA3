#ifndef STRUCTURE_H
#define STRUCTURE_H
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct{
	unsigned int athId; 
	unsigned int regId;
	//unsigned int divId; 
	char *lastName; 
	char *firstName;
	char gender; 
	unsigned int age; 
	unsigned int weight;
	float height; 
	unsigned int affiliateId; 
	//char *affiliateName; 
	unsigned int overallScore; 
 	//unsigned int overallRank; 
	unsigned int score18_1;
	//char *scoreDisplay18_1;
	//unsigned int rank18_1;
	unsigned int score18_2;
	//char *scoreDisplay18_2;
	//unsigned int rank18_2;
	unsigned int score18_2a;
	//char *scoreDisplay18_2a;
	//unsigned int rank18_2a;
	unsigned int score18_3;
	//char *scoreDisplay18_3;
	//unsigned int rank18_3;
	unsigned int score18_4;
	//char *scoreDisplay18_4;
	//unsigned int rank18_4;
	unsigned int score18_5;
	//char *scoreDisplay18_5;
	//unsigned int rank18_5;
}Athlete;

typedef struct ElementTop50 ElementTop50;
struct ElementTop50 {
    Athlete ath;
    ElementTop50 *suivant;
};
typedef struct {
    ElementTop50 *premier;
} ListeTop50;

typedef struct ElementTop50Ep ElementTop50Ep;
struct ElementTop50Ep {
    Athlete *ath;
    ElementTop50Ep *suivant;
};
typedef struct {
    ElementTop50Ep *premier;
} ListeTop50Ep;

typedef struct ElementHash ElementHash;
struct ElementHash {
    Athlete *ath;
    ElementHash *suivant;
};
typedef struct {
    ElementHash *premier;
} ListeHash;

int asciis(char *word);

int hash_int(int athID, int tableSize);

int hash_word(char *word, int tableSize);

void initialisation(ListeTop50 liste50[], int listeTop50Size, ListeHash listeHashID[],
		int listeHashIDSize, ListeHash listeHashNom[], int listeHashNomSize,
		ListeTop50Ep listeTop50Ep[5]);

void detruitTeteHash(ListeHash *liste);

void detruitTeteTop50(ListeTop50 *liste);

void ajoutAthleteTeteTrieeScore(ListeTop50 *liste, Athlete athlete);

void ajoutAthleteTeteTrieeScoreEp(ListeTop50Ep *liste, Athlete *athlete, int epreuveId);

void ajoutTeteListeHash(ListeHash *liste, Athlete *ath);

void ajoutAthleteHashID(ListeHash liste[], int listeSize, Athlete *ath);

void ajoutAthleteHashNom(ListeHash liste[], int listeSize, Athlete *ath);

Athlete* rechercheAthleteID(ListeHash liste[], int listeSize, unsigned int athID);

Athlete* rechercheAthleteNom(ListeHash liste[], int listeSize, char *lastName);

void ajoutAthlete(ListeTop50 liste50[], int whichTop50, ListeHash listeHashID[],
		int listeHashIDSize, ListeHash listeHashNom[], int listeHashNomSize,
		ListeTop50Ep listeTop50Ep[5], Athlete *ath);

void detruireTout(ListeTop50 liste50[], int listeTop50Size, ListeHash listeHashID[],
		int listeHashIDSize, ListeHash listeHashNom[], int listeHashNomSize);

#endif
