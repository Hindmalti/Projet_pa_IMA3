#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

int asciis(char *word){
    int i = 0, h = 0;
    while(word[i] != '\0'){
        h += word[i];
        i++;
    }
    return h;
}

int hash_int(int athID, int tableSize){
    return athID % tableSize;
}

int hash_word(char *word, int tableSize){
    return (asciis(word) % tableSize);
}

void initialisation(ListeTop50 liste50[], ListeTop50Ep listeTop50Ep[][5],
		int listeTop50Size, ListeHash listeHashID[], int listeHashIDSize,
		ListeHash listeHashNom[], int listeHashNomSize){
	// s'assure que les listes sont bien initialisees et que le pointeur du premier element est bien NULL
	for(int i = 0; i < listeTop50Size; i++)
		liste50[i].premier = NULL;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < listeTop50Size; j++)
			listeTop50Ep[j][i].premier = NULL;
	for(int i = 0; i < listeHashIDSize; i++)
		listeHashID[i].premier = NULL;
	for(int i = 0; i < listeHashNomSize; i++)
		listeHashNom[i].premier = NULL;
}

void detruitTeteHash(ListeHash *liste){
	ElementHash *element = liste->premier;
	if(element != NULL){
		liste->premier = element->suivant;
		free(element);
	}
}

void detruitTeteTop50(ListeTop50 *liste){
	ElementTop50 *element = liste->premier;
	if(element != NULL){
		liste->premier = element->suivant;
		free(element);
	}
}

void ajoutAthleteTeteTrieeScore(ListeTop50 *liste, Athlete athlete){
    // cas particulier du debut de liste
    if(liste->premier == NULL || athlete.overallScore >= liste->premier->ath.overallScore){
		
		// cree l'element
        ElementTop50 *ajout = malloc(sizeof *ajout);
        ajout->ath = athlete;
        
        // pointe vers les elements suivants
        ajout->suivant = liste->premier;
        
        // l'ajoute dans la liste
        liste->premier = ajout;
        return;
    }
	ElementTop50 *element = liste->premier;
	
	while(1){
		// ajoute l'element si on est arrive a la fin de la liste ou si le suivant a un plus gros rank
		if(element->suivant == NULL || athlete.overallScore > element->suivant->ath.overallScore
				|| (athlete.overallScore == 0 && element->suivant->ath.overallScore == 0)){
			// cree l'element
			ElementTop50 *ajout = malloc(sizeof *ajout);
			ajout->ath = athlete;
			
			// pointe vers les elements suivants
			ajout->suivant = element->suivant;
			
			// l'ajoute dans la liste
			element->suivant = ajout;
			return;
		}
		element = element->suivant;
	}
    return;
}

void ajoutAthleteTeteTrieeScoreEp(ListeTop50Ep *liste, Athlete *athlete, int epreuveId){
	int scoreEpAthlete = 0;
	int scoreEpPremierAth = 0;
	switch(epreuveId){
		case 0:
			scoreEpAthlete = athlete->score18_1;
			scoreEpPremierAth = liste->premier == NULL ? 0 : liste->premier->ath->score18_1;
			break;
		case 1:
			scoreEpAthlete = athlete->score18_2;
			scoreEpPremierAth = liste->premier == NULL ? 0 : liste->premier->ath->score18_2;
			break;
		case 2:
			scoreEpAthlete = athlete->score18_3;
			scoreEpPremierAth = liste->premier == NULL ? 0 : liste->premier->ath->score18_3;
			break;
		case 3:
			scoreEpAthlete = athlete->score18_4;
			scoreEpPremierAth = liste->premier == NULL ? 0 : liste->premier->ath->score18_4;
			break;
		case 4:
			scoreEpAthlete = athlete->score18_5;
			scoreEpPremierAth = liste->premier == NULL ? 0 : liste->premier->ath->score18_5;
			break;
	}
	
    // cas particulier du debut de liste
    if(liste->premier == NULL || scoreEpAthlete >= scoreEpPremierAth){
        // cree l'element
        ElementTop50Ep *ajout = malloc(sizeof *ajout);
        ajout->ath = athlete;
        
        // pointe vers les elements suivants
        ajout->suivant = liste->premier;
        
        // l'ajoute dans la liste
        liste->premier = ajout;
        return;
    }
	ElementTop50Ep *element = liste->premier;
    
	while(1){
		int scoreEpElementAth = 0;
		switch(epreuveId){
			case 0:
				scoreEpElementAth = (element == NULL || element->suivant == NULL) ?
						0 : element->suivant->ath->score18_1;
				break;
			case 1:
				scoreEpElementAth = (element == NULL || element->suivant == NULL) ?
						0 : element->suivant->ath->score18_2;
				break;
			case 2:
				scoreEpElementAth = (element == NULL || element->suivant == NULL) ?
						0 : element->suivant->ath->score18_3;
				break;
			case 3:
				scoreEpElementAth = (element == NULL || element->suivant == NULL) ?
						0 : element->suivant->ath->score18_4;
				break;
			case 4:
				scoreEpElementAth = (element == NULL || element->suivant == NULL) ?
						0 : element->suivant->ath->score18_5;
				break;
		}
		
		// ajoute l'element si on est arrive a la fin de la liste ou si le suivant a un plus gros rank
		if(element->suivant == NULL || scoreEpAthlete >= scoreEpElementAth){
			
			if((scoreEpAthlete == 0 && scoreEpPremierAth == 0)){
				printf("aaaaa\n");
			}
			// cree l'element
			ElementTop50Ep *ajout = malloc(sizeof *ajout);
			ajout->ath = athlete;
			
			// pointe vers les elements suivants
			ajout->suivant = element->suivant;
			
			// l'ajoute dans la liste
			element->suivant = ajout;
			return;
		}
		element = element->suivant;
	}
    return;
}

void ajoutTeteListeHash(ListeHash *liste, Athlete *ath){
	// creation de l'element
	ElementHash *ajout = malloc(sizeof *ajout);
	ajout->ath = ath;
	
	// ajout en tete
	ajout->suivant = liste->premier;
	liste->premier = ajout;
}

void ajoutAthleteHashID(ListeHash liste[], int listeSize, Athlete *ath){
	// generation du hash
	int hash = hash_int(ath->athId, listeSize);
	// ajout dans la liste chainee a l'index du hash dans la table de hachage
	ajoutTeteListeHash(&liste[hash], ath);
}

void ajoutAthleteHashNom(ListeHash liste[], int listeSize, Athlete *ath){
	// generation du hash
	int hash = hash_word(ath->lastName, listeSize);
	// ajout dans la liste chainee a l'index du hash dans la table de hachage
	ajoutTeteListeHash(&liste[hash], ath);
}

Athlete* rechercheAthleteID(ListeHash liste[], int listeSize, unsigned int athID){
	// generation du hash
	int hash = hash_int(athID, listeSize);
    // recherche dans la liste des hashs similaires
    ElementHash *element = liste[hash].premier;
    while(element != NULL){
        if(element->ath->athId == athID)
            return element->ath;
        element = element->suivant;
    }
    return NULL;
}

Athlete* rechercheAthleteNom(ListeHash liste[], int listeSize, char *lastName){
	// generation du hash
	int hash = hash_word(lastName, listeSize);
    // recherche dans la liste des hashs similaires
    ElementHash *element = liste[hash].premier;
    while(element != NULL){
        if(strcmp(element->ath->lastName, lastName) == 0)
            return element->ath;
        element = element->suivant;
    }
    return NULL;
}

void ajoutAthlete(ListeTop50 liste50[], ListeTop50Ep listeTop50Ep[][5], int whichTop50,
		ListeHash listeHashID[], int listeHashIDSize, ListeHash listeHashNom[],
		int listeHashNomSize, Athlete *ath){
	// ajout dans la table des TOP50
	ajoutAthleteTeteTrieeScore(&liste50[whichTop50], *ath);
	
	// ajout dans les tables des TOP50 des epreuves
	for(int i = 0; i < 5; i++)
		ajoutAthleteTeteTrieeScoreEp(&listeTop50Ep[whichTop50][i], ath, i);
	
    // ajout dans la table de hachage des noms
	ajoutAthleteHashNom(listeHashNom, listeHashNomSize, ath);
    // ajout dans la table de hachage des IDs
	ajoutAthleteHashID(listeHashID, listeHashIDSize, ath);
}

void detruireTout(ListeTop50 liste50[], int listeTop50Size, ListeHash listeHashID[],
		int listeHashIDSize, ListeHash listeHashNom[], int listeHashNomSize){
	// destruction de ListeHashID
	for(int i = 0; i < listeHashIDSize; i++){
		ElementHash *element = listeHashID[i].premier;
		while(element != NULL){
			detruitTeteHash(&listeHashID[i]);
			element = listeHashID[i].premier;
		}
	}
	// destruction de ListeHashNom
	for(int i = 0; i < listeHashNomSize; i++){
		ElementHash *element = listeHashNom[i].premier;
		while(element != NULL){
			detruitTeteHash(&listeHashNom[i]);
			element = listeHashNom[i].premier;
		}
	}
	// destruction de ListeTop50
	for(int i = 0; i < listeTop50Size; i++){
		ElementTop50 *element = liste50->premier;
		while(element != NULL){
			detruitTeteTop50(liste50);
			element = liste50->premier;
		}
	}
}

