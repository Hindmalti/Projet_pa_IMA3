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


void initialisation(ListeTop50 *liste50, ListeHash listeHashID[], int listeHashIDSize, ListeHash listeHashNom[], int listeHashNomSize, ListeTop50Ep listeTop50Ep[5]){
	// s'assure que les listes sont bien initialisees et que le pointeur du premier element est bien NULL
	liste50->premier = NULL;
	for(int i = 0; i < listeHashIDSize; i++)
		listeHashID[i].premier = NULL;
	for(int i = 0; i < listeHashNomSize; i++)
		listeHashNom[i].premier = NULL;
	for(int i = 0; i < 5; i++){
		listeTop50Ep[i].premier = NULL;
	}
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

void ajoutAthleteTeteTrieeScore(ListeTop50 *liste, Athlete athlete, ElementTop50 *element){
    // cas particulier du debut de liste
    if(liste->premier == NULL || athlete.overallScore > liste->premier->ath.overallScore){
        // cree l'element
        ElementTop50 *ajout = malloc(sizeof *ajout);
        ajout->ath = athlete;
        
        // pointe vers les elements suivants
        ajout->suivant = liste->premier;
        
        // l'ajoute dans la liste
        liste->premier = ajout;
        return;
    }
    
    // ajoute l'element si on est arrive a la fin de la liste ou si le suivant a un plus gros rank
    if(element->suivant == NULL || athlete.overallScore > element->suivant->ath.overallScore){
        // cree l'element
        ElementTop50 *ajout = malloc(sizeof *ajout);
        ajout->ath = athlete;
        
        // pointe vers les elements suivants
        ajout->suivant = element->suivant;
        
        // l'ajoute dans la liste
        element->suivant = ajout;
        return;
    }
    
    // recursivite
    ajoutAthleteTeteTrieeScore(liste, athlete, element->suivant);
    return;
}

void ajoutAthleteTeteTrieeScoreEp(ListeTop50Ep *liste, Athlete *athlete, ElementTop50Ep *element, int epreuveId){
	int scoreEpAthlete = 0;
	int scoreEpPremierAth = 0;
	int scoreEpElementAth = 0;
	switch(epreuveId){
		case 0:
			scoreEpAthlete = athlete->score18_1;
			scoreEpPremierAth = liste->premier == NULL ? 0 : liste->premier->ath->score18_1;
			scoreEpElementAth = (element == NULL || element->suivant == NULL) ? 0 : element->suivant->ath->score18_1;
			break;
		case 1:
			scoreEpAthlete = athlete->score18_2;
			scoreEpPremierAth = liste->premier == NULL ? 0 : liste->premier->ath->score18_2;
			scoreEpElementAth = (element == NULL || element->suivant == NULL)? 0 : element->suivant->ath->score18_2;
			break;
		case 2:
			scoreEpAthlete = athlete->score18_3;
			scoreEpPremierAth = liste->premier == NULL ? 0 : liste->premier->ath->score18_3;
			scoreEpElementAth = (element == NULL || element->suivant == NULL) ? 0 : element->suivant->ath->score18_3;
			break;
		case 3:
			scoreEpAthlete = athlete->score18_4;
			scoreEpPremierAth = liste->premier == NULL ? 0 : liste->premier->ath->score18_4;
			scoreEpElementAth = (element == NULL || element->suivant == NULL) ? 0 : element->suivant->ath->score18_4;
			break;
		case 4:
			scoreEpAthlete = athlete->score18_5;
			scoreEpPremierAth = liste->premier == NULL ? 0 : liste->premier->ath->score18_5;
			scoreEpElementAth = (element == NULL || element->suivant == NULL) ? 0 : element->suivant->ath->score18_5;
			break;
	}
	
    // cas particulier du debut de liste
    if(liste->premier == NULL || scoreEpAthlete > scoreEpPremierAth){
        // cree l'element
        ElementTop50Ep *ajout = malloc(sizeof *ajout);
        ajout->ath = athlete;
        
        // pointe vers les elements suivants
        ajout->suivant = liste->premier;
        
        // l'ajoute dans la liste
        liste->premier = ajout;
        return;
    }
    
    // ajoute l'element si on est arrive a la fin de la liste ou si le suivant a un plus gros rank
    if(element->suivant == NULL || scoreEpAthlete > scoreEpElementAth){
        // cree l'element
        ElementTop50Ep *ajout = malloc(sizeof *ajout);
        ajout->ath = athlete;
        
        // pointe vers les elements suivants
        ajout->suivant = element->suivant;
        
        // l'ajoute dans la liste
        element->suivant = ajout;
        return;
    }
    
    // recursivite
    ajoutAthleteTeteTrieeScoreEp(liste, athlete, element->suivant, epreuveId);
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

void ajoutAthlete(ListeTop50 *liste50, ListeHash listeHashID[], int listeHashIDSize, ListeHash listeHashNom[], int listeHashNomSize, ListeTop50Ep listeTop50Ep[5], Athlete *ath){
    // ajout dans la table des TOP50
	ajoutAthleteTeteTrieeScore(liste50, *ath, liste50->premier);
	
	// ajout dans les tables des TOP50 des epreuves
	for(int i = 0; i < 5; i++)
		ajoutAthleteTeteTrieeScoreEp(&listeTop50Ep[i], ath, listeTop50Ep->premier, i);
	
    // ajout dans la table de hachage des noms
	ajoutAthleteHashNom(listeHashNom, listeHashNomSize, ath);
	
    // ajout dans la table de hachage des IDs
	ajoutAthleteHashID(listeHashID, listeHashIDSize, ath);
}

void detruireTout(ListeTop50 *liste50, ListeHash listeHashID[], int listeHashIDSize, ListeHash listeHashNom[], int listeHashNomSize){
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
	ElementTop50 *element = liste50->premier;
	while(element != NULL){
		detruitTeteTop50(liste50);
		element = liste50->premier;
	}
}

