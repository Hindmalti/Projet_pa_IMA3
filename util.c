#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

void printAthlete(Athlete *ptr){
    if(ptr != NULL){
        printf("%d %s %s %c %d m %d kg %deme %d %d %d %d %d %d\n", ptr->athId, ptr->lastName, ptr->firstName, ptr->gender, ptr->height, ptr->weight, ptr->overallRank, ptr->score18_1, ptr->score18_2, ptr->score18_2a, ptr->score18_3, ptr->score18_4, ptr->score18_5); 
    }
}

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


void initialisation(ListeTop50 *liste50, ListeHash listeHashID[], int listeHashIDSize, ListeHash listeHashNom[], int listeHashNomSize){
	// s'assure que les listes sont bien initialisees et que le pointeur du premier element est bien NULL
	liste50->premier = NULL;
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

void ajoutAthleteTeteTrieeScore(ListeTop50 *liste, Athlete athlete, ElementTop50 *element){
    // cas particulier du debut de liste
    if(liste->premier == NULL || athlete.overallRank < liste->premier->ath.overallRank){
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
    if(element->suivant == NULL || athlete.overallRank < element->suivant->ath.overallRank){
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
	char str[50];
	strcpy(str, ath->lastName); // copie de lastName dans str
	strcat(str, ath->firstName); // concatenation de str et de firstName (resultat dans str)
	int hash = hash_word(str, listeSize);
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

Athlete* rechercheAthleteNom(ListeHash liste[], int listeSize, char *lastName, char *firstName){
	// generation du hash
	char str[50];
	strcpy(str, lastName); // copie de lastName dans str
	strcat(str, firstName); // concatenation de str et de firstName (resultat dans str)
	int hash = hash_word(str, listeSize);
    // recherche dans la liste des hashs similaires
    ElementHash *element = liste[hash].premier;
    while(element != NULL){
        if(strcmp(element->ath->lastName, lastName) == 0
            && strcmp(element->ath->firstName, firstName) == 0)
            return element->ath;
        element = element->suivant;
    }
    return NULL;
}

void printListeAthlete(ListeTop50 liste){
    ElementTop50 *element = liste.premier;
    while(element != NULL){
        printAthlete(&(element->ath));
        element = element->suivant;
    }
}

void printListeHashTableau(ListeHash liste[], int listeSize){
    // pour chaque hash
    for(int i = 0; i < listeSize; i++){
        // affiche tous les Athletes dans la liste des hashs similaires
        printf("{ hash : %d\n", i);
        ElementHash *element = liste[i].premier;
        while(element != NULL){
            printf("    ");
            printAthlete(element->ath);
            element = element->suivant;
        }
        printf("}\n");
    }
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

void tiret(int n){
    // affiche n tirets
    int i = 0;
    for(i = 0 ; i<n ; i++){
        printf("-");
    }
    printf("\n");
}

void ajoutAthlete(ListeTop50 *liste50, ListeHash listeHashID[], int listeHashIDSize, ListeHash listeHashNom[], int listeHashNomSize, Athlete *ath){
    // ajout dans la table des TOP50
	ajoutAthleteTeteTrieeScore(liste50, *ath, liste50->premier);
    
    // ajout dans la table de hachage des noms
	ajoutAthleteHashNom(listeHashNom, listeHashNomSize, ath);
	
    // ajout dans la table de hachage des IDs
	ajoutAthleteHashID(listeHashID, listeHashIDSize, ath);
}
