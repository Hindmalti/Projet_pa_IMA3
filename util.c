#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

void printAthlete(Athlete *ptr){
    if(ptr != NULL){
        printf("%d %s %s %c %s m %s kg %deme\n"/*%d %d %d %d %d %d"*/, ptr->athId, ptr->lastName, ptr->firstName, ptr->gender, ptr->height, ptr->weight, ptr->overallRank/*, ptr->score18_1, ptr->score18_2, ptr->score18_2a, ptr->score18_3, ptr->score18_4, ptr->score18_5*/); 
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

/*Athlete* rechercheAthleteID(ListeAthlete liste, int athId){
    while(liste != NULL){
        if(liste->athId == athId){
            return liste;
        }
        liste = liste->suivant;
    }
    return NULL;
} 

void rechercheAthleteNom(ListeAthlete liste, char *nom){
    while(liste != NULL){
        if(!strcmp(liste->lastName, nom)){
            printAthlete(liste);
        }
        liste = liste->suivant;
    }
}

void afficherAthlete(HashListeAthlete ht, int athId){
    int indice = hash_int(athId);
    printAthlete(rechercheAthleteID(ht[indice], athId));
}

void afficherNom(HashListeAthlete ht, char *nom){
    int indice = hash_word(nom);
    rechercheAthleteNom(ht[indice], nom);
}*/

void ajoutAthleteTeteTrieeScore(Liste_TOP_50 *liste, Athlete athlete, Element_TOP_50 *element){
    // cas particulier du debut de liste
    if(liste->premier == NULL || athlete.overallRank < liste->premier->ath.overallRank){
        // cree l'element
        Element_TOP_50 *ajout = malloc(sizeof *ajout);
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
        Element_TOP_50 *ajout = malloc(sizeof *ajout);
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

void ajoutTeteListHash(ListeHash *liste, Athlete *ath){
	// creation de l'element
	ElementHash *ajout = malloc(sizeof *ajout);
	ajout->ath = ath;
	
	// ajout en tete
	ajout->suivant = liste->premier;
	liste->premier = ajout;
}

void ajoutAthleteHashID(ListeHashAthlete *liste, int listeSize, Athlete *ath){
	// generation du hash
	int hash = hash_int(ath->athId, listeSize);
	// ajout dans la liste chainee a l'index du hash dans la table de hachage
	ajoutTeteListHash(liste[hash], ath);
}

void ajoutAthleteHashNom(ListeHashAthlete *liste, int listeSize, Athlete *ath){
	// generation du hash
	char *str = "";
	strcpy(str, ath->lastName); // copie de lastName dans str
	strcat(str, ath->firstName); // concatenation de str et de firstName (resultat dans str)
	int hash = hash_word(str, listeSize);
	// ajout dans la liste chainee a l'index du hash dans la table de hachage
	ajoutTeteListHash(liste[hash], ath);
}

void printListeAthlete(Liste_TOP_50 liste){
    Element_TOP_50 *element = liste.premier;
    while(element != NULL){
        printAthlete(&(element->ath));
        element = element->suivant;
    }
}

void tiret(int n){
    int i = 0;
    for(i = 0 ; i<n ; i++){
        printf("-");
    }
    printf("\n");
}

void ajoutAthlete(Liste_TOP_50 *liste50, ListeHashAthlete *listeHashID, int listeHashIDSize, ListeHashAthlete *listeHashNom, int listeHashNomSize, Athlete ath){
    // ajout dans la table des TOP50
	ajoutAthleteTeteTrieeScore(liste50, ath, liste50->premier);
    
    // ajout dans la table de hachage des noms
	ajoutAthleteHashID(listeHashNom, listeHashNomSize, &ath);
	
    // ajout dans la table de hachage des IDs
	ajoutAthleteHashID(listeHashID, listeHashIDSize, &ath);
}
