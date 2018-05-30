#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

/*void printAthleteDebug(Athlete *ptr){
    if(ptr != NULL){
        printf("%6.6d %10.10s %10.10s %c %4.4f m %4.4d kg %6.6deme %d %d %d %d %d %d\n", ptr->athId, ptr->lastName, ptr->firstName, ptr->gender, ptr->height, ptr->weight, ptr->overallScore, ptr->score18_1, ptr->score18_2, ptr->score18_2a, ptr->score18_3, ptr->score18_4, ptr->score18_5); 
    }
}*/

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
        printf("%15.15s %15.15s %10.10d\n", ptr->lastName, ptr->firstName, score); 
    }
}

void printAthleteDefaut(Athlete *ptr){
    if(ptr != NULL){
        printf("%7d %15.15s %15.15s    %c %3d %6.4f m %5d kg %11d %11d %11d %11d %11d %11d\n", ptr->athId, ptr->lastName, ptr->firstName, ptr->gender, ptr->age, ptr->height, ptr->weight, ptr->score18_1, ptr->score18_2, ptr->score18_2a, ptr->score18_3, ptr->score18_4, ptr->score18_5); 
    }
}

void printTop50(ListeTop50 liste){
    ElementTop50 *element = liste.premier;
	int i = 0;
    while(element != NULL && i < 50){
		printf("%2.2d ", i+1);
        printAthleteTop50(&(element->ath));
        element = element->suivant;
		i++;
    }
}

void printTop50Genre(ListeTop50 liste, char genre){
    ElementTop50 *element = liste.premier;
	int i = 0;
    while(element != NULL && i < 50){
		if(element->ath.gender == genre){
			printf("%2.2d ", i+1);
			printAthleteTop50(&(element->ath));
			i++;
		}
        element = element->suivant;
    }
}

void printTop50Region(ListeTop50 liste, unsigned int regionId){
    ElementTop50 *element = liste.premier;
	int i = 0;
    while(element != NULL && i < 50){
		if(element->ath.regId == regionId){
			printf("%2.2d ", i+1);
			printAthleteTop50(&(element->ath));
			i++;
		}
        element = element->suivant;
    }
}

void printTop50Epreuve(ListeTop50Ep liste, int epreuveId){
    ElementTop50Ep *element = liste.premier;
	int i = 0;
    while(element != NULL && i < 50){
		printf("%2.2d ", i+1);
		printAthleteTop50Ep(element->ath, epreuveId);
        element = element->suivant;
		i++;
    }
}

void printTopSalle(ListeTop50 liste, unsigned int salleId){
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

void printTopSalleLille(ListeTop50 liste){
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
}

void printListeHashTableau(ListeHash liste[], int listeSize){
    // pour chaque hash
    for(int i = 0; i < listeSize; i++){
        // affiche tous les Athletes dans la liste des hashs similaires
        printf("{ hash : %d\n", i);
        ElementHash *element = liste[i].premier;
        while(element != NULL){
            printf("    ");
            printAthleteDefaut(element->ath);
            element = element->suivant;
        }
        printf("}\n");
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
