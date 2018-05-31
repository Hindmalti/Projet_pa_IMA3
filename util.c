#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

void printAthleteTop50(Athlete *ptr){
    if(ptr != NULL){
        printf("%15.15s %15.15s %10d\n", ptr->lastName, ptr->firstName, ptr->overallScore); 
    }
}

void printAthleteTop50Ep(Athlete *ptr, int epreuveId){
    if(ptr != NULL){
		int score = 0;
		switch(epreuveId){
			case 0:
				score = ptr->score18_1;
				break;
			case 1:
				score = ptr->score18_2;
				break;
			case 2:
				score = ptr->score18_3;
				break;
			case 3:
				score = ptr->score18_4;
				break;
			case 4:
				score = ptr->score18_5;
				break;
		}
        printf("%15.15s %15.15s %10d\n", ptr->lastName, ptr->firstName, score); 
    }
}

void printAthleteDefaut(Athlete *ptr){
    if(ptr != NULL){
        printf("%10d %15.15s %15.15s    %c %3d %6.4f m %5d kg %11d %11d %11d %11d %11d %11d\n", ptr->athId, ptr->lastName, ptr->firstName, ptr->gender, ptr->age, ptr->height, ptr->weight, ptr->score18_1, ptr->score18_2, ptr->score18_2a, ptr->score18_3, ptr->score18_4, ptr->score18_5); 
    }
}

void printTop50(ListeTop50 liste[], int listeSize){
	ElementTop50 *elements[listeSize];
	for(int i = 0; i < listeSize; i++){
		elements[i] = liste[i].premier;
	}
	
	int count = 0;
	int allElementsNULL;
    do{
		// check si tous les elements sont null
		allElementsNULL = 1;
		for(int i = 0; i < listeSize; i++){
			if(elements[i] != NULL){
				allElementsNULL = 0;
				break;
			}
		}
		if(allElementsNULL == 1)
			break;
		
		// trouve le plus grand score entre les elements
		int save = 0;
		for(int i = 1; i < listeSize; i++){
			if(elements[i] != NULL && elements[save]->ath.overallScore < elements[i]->ath.overallScore)
				save = i;
		}
		
		// affiche le prochain
		printf("%2.2d ", count+1);
        printAthleteTop50(&(elements[save]->ath));
        elements[save] = elements[save]->suivant;
		count++;
    }while(allElementsNULL != 1 && count < 50);
}

void printTop50Genre(ListeTop50 liste[], int listeSize, char genre){
	ElementTop50 *elements[listeSize];
	for(int i = 0; i < listeSize; i++){
		elements[i] = liste[i].premier;
	}
	
	int count = 0;
	int allElementsNULL;
    do{
		//selectionne dans les elements uniquement la categorie recherchee
		int ok = 0;
		while(ok == 0){
			ok = 1;
			for(int i = 0; i < listeSize; i++){
				if(elements[i] != NULL && elements[i]->ath.gender != genre){
					elements[i] = elements[i]->suivant;
					ok = 0;
				}
			}
		}
		// check si tous les elements sont null
		allElementsNULL = 1;
		for(int i = 0; i < listeSize; i++){
			if(elements[i] != NULL){
				allElementsNULL = 0;
				break;
			}
		}
		if(allElementsNULL == 1)
			break;
		
		// trouve le plus grand score entre les elements
		int save = 0;
		for(int i = 1; i < listeSize; i++){
			if(elements[i] != NULL && elements[save]->ath.overallScore < elements[i]->ath.overallScore)
				save = i;
		}
		
		// affiche le prochain
		printf("%2.2d ", count+1);
        printAthleteTop50(&(elements[save]->ath));
        elements[save] = elements[save]->suivant;
		count++;
    }while(allElementsNULL != 1 && count < 50);
}

void printTop50Region(ListeTop50 liste[], int listeSize, unsigned int regionId){
	ElementTop50 *elements[listeSize];
	for(int i = 0; i < listeSize; i++){
		elements[i] = liste[i].premier;
	}
	
	int count = 0;
	int allElementsNULL;
    do{
		//selectionne dans les elements uniquement la categorie recherchee
		int ok = 0;
		while(ok == 0){
			ok = 1;
			for(int i = 0; i < listeSize; i++){
				if(elements[i] != NULL && elements[i]->ath.regId != regionId){
					elements[i] = elements[i]->suivant;
					ok = 0;
				}
			}
		}
		// check si tous les elements sont null
		allElementsNULL = 1;
		for(int i = 0; i < listeSize; i++){
			if(elements[i] != NULL){
				allElementsNULL = 0;
				break;
			}
		}
		if(allElementsNULL == 1)
			break;
		
		// trouve le plus grand score entre les elements
		int save = 0;
		for(int i = 1; i < listeSize; i++){
			// au debut (save = 0), elements[save] peut être NULL
			// on repousse le probleme jusqu'a elements[save] != NULL
			if(elements[save] == NULL){
				save = i;
				continue;
			}
			if(elements[i] != NULL && elements[save]->ath.overallScore < elements[i]->ath.overallScore)
				save = i;
		}
		
		// affiche le prochain
		printf("%2.2d ", count+1);
        printAthleteTop50(&(elements[save]->ath));
        elements[save] = elements[save]->suivant;
		count++;
    }while(allElementsNULL != 1 && count < 50);
}

/*void printTop50Epreuve(ListeTop50Ep liste[], int epreuveId){
    ElementTop50Ep *element = liste.premier;
	int i = 0;
    while(element != NULL && i < 50){
		printf("%2.2d ", i+1);
		printAthleteTop50Ep(element->ath, epreuveId);
        element = element->suivant;
		i++;
    }
}

void printTopSalle(ListeTop50 liste[], unsigned int salleId){
    ElementTop50 *element = liste.premier;
	int i = 0;
    while(element != NULL){
		if(element->ath.affiliateId == salleId){
			printf("%3.3d ", i+1);
			printAthleteTop50(&(element->ath));
			i++;
		}
        element = element->suivant;
    }
}

void printTopSalleLille(ListeTop50 liste[]){
    ElementTop50 *element = liste.premier;
	int i = 0;
    while(element != NULL){
		if(element->ath.affiliateId == 19413
				|| element->ath.affiliateId == 14534
				|| element->ath.affiliateId == 7775
				|| element->ath.affiliateId == 11610
				|| element->ath.affiliateId == 12105
				|| element->ath.affiliateId == 19352
				|| element->ath.affiliateId == 21303){
			printf("%2.2d ", i+1);
			printAthleteTop50(&(element->ath));
			i++;
		}
        element = element->suivant;
    }
}*/
void tiret(int n){
    // affiche n tirets
    int i = 0;
    for(i = 0 ; i<n ; i++){
        printf("-");
    }
    printf("\n");
}

void chargementTexte(int pourcent){
	if(pourcent == -1){
		printf("[                             ]   0%%");
		return;
	}
	
	for(int i = 0; i < 35; i++){ //29 + 1 + 1 + 3 + 1
		printf("\b");
	}
	for(int i = 0; i < 29; i++){
		if(i <= (int) ((float) pourcent * 0.3))
			printf("=");
		else
			printf(" ");
	}
	printf("] %3d%%", pourcent);
}

