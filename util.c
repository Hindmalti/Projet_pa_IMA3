#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

void printAthleteTop50(Athlete *ptr){
    if(ptr != NULL){
        printf("%20.20s %20.20s %10d\n", ptr->lastName, ptr->firstName, ptr->overallScore); 
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
        printf("%20.20s %20.20s %16d\n", ptr->lastName, ptr->firstName, score); 
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

void printTop50Epreuve(ListeTop50Ep liste[][5], int listeSize, int epreuveId){
	ElementTop50Ep *elements[listeSize];
	for(int i = 0; i < listeSize; i++){
		elements[i] = liste[i][epreuveId - 1].premier;
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
			// au debut (save = 0), elements[save] peut être NULL
			// on repousse le probleme jusqu'a elements[save] != NULL
			if(elements[save] == NULL){
				save = i;
				continue;
			}
			if(elements[i] != NULL){
				int saveSc = 0;
				int iSc = 0;
				switch(epreuveId){
					case 0:
						saveSc = elements[save]->ath->score18_1;
						iSc = elements[i]->ath->score18_1;
						break;
					case 1:
						saveSc = elements[save]->ath->score18_2;
						iSc = elements[i]->ath->score18_2;
						break;
					case 2:
						saveSc = elements[save]->ath->score18_3;
						iSc = elements[i]->ath->score18_3;
						break;
					case 3:
						saveSc = elements[save]->ath->score18_4;
						iSc = elements[i]->ath->score18_4;
						break;
					case 4:
						saveSc = elements[save]->ath->score18_5;
						iSc = elements[i]->ath->score18_5;
						break;
				}
				if(saveSc < iSc){
					save = i;
				}
			}
		}
		
		printf("%2.2d ", count+1);
		printAthleteTop50Ep(elements[save]->ath, epreuveId);
        elements[save] = elements[save]->suivant;
		count++;
    }while(allElementsNULL != 1 && count < 50);
}

void printHashId(ListeHash liste[], int listeSize, unsigned int athID){
	Athlete *ath = rechercheAthleteID(liste, listeSize, athID);
	printf("%10.10s %15.15s %15.15s  %4.4s  %3.3s  %8.8s  %8.8s\n",
			"ID", "NOM DE FAMILLE", "PRENOM", "SEXE", "AGE", "TAILLE m", "POIDS kg");
	printf("%10d %15.15s %15.15s     %c %4d %7.2f m %6d kg\n\n",
			ath->athId, ath->lastName, ath->firstName, ath->gender, ath->age,
			ath->height, ath->weight);
	printf("%11.11s %11.11s %12.12s %11.11s %11.11s %11.11s\n",
			"SCORE 18.1", "SCORE 18.2", "SCORE 18.2a", "SCORE 18.3", "SCORE 18.4",
			"SCORE 18.5");
	printf("%11d %11d %12d %11d %11d %11d\n",
			ath->score18_1, ath->score18_2, ath->score18_2a, ath->score18_3,
			ath->score18_4, ath->score18_5);
}


void printHashNom(ListeHash liste[], int listeSize, char *lastName){
	Athlete *ath = rechercheAthleteNom(liste, listeSize, lastName);
	printf("%10.10s %15.15s %15.15s  %4.4s  %3.3s  %8.8s  %8.8s\n",
			"ID", "NOM DE FAMILLE", "PRENOM", "SEXE", "AGE", "TAILLE m", "POIDS kg");
	printf("%10d %15.15s %15.15s     %c %4d %7.2f m %6d kg\n\n",
			ath->athId, ath->lastName, ath->firstName, ath->gender, ath->age,
			ath->height, ath->weight);
	printf("%11.11s %11.11s %12.12s %11.11s %11.11s %11.11s\n",
			"SCORE 18.1", "SCORE 18.2", "SCORE 18.2a", "SCORE 18.3", "SCORE 18.4",
			"SCORE 18.5");
	printf("%11d %11d %12d %11d %11d %11d\n",
			ath->score18_1, ath->score18_2, ath->score18_2a, ath->score18_3,
			ath->score18_4, ath->score18_5);
}

void printTopSalle(ListeTop50 liste[], int listeSize, unsigned int salleId){
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
				if(elements[i] != NULL && elements[i]->ath.affiliateId != salleId){
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
		printf("%3.3d ", count+1);
        printAthleteTop50(&(elements[save]->ath));
        elements[save] = elements[save]->suivant;
		count++;
    }while(allElementsNULL != 1);
}

void printTopSalleLille(ListeTop50 liste[], int listeSize){
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
				if(elements[i] != NULL
						&& elements[i]->ath.affiliateId != 19413
						&& elements[i]->ath.affiliateId != 14534
						&& elements[i]->ath.affiliateId != 7775
						&& elements[i]->ath.affiliateId != 11610
						&& elements[i]->ath.affiliateId != 12105
						&& elements[i]->ath.affiliateId != 19352
						&& elements[i]->ath.affiliateId != 21303){
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
		printf("%3.3d ", count+1);
        printAthleteTop50(&(elements[save]->ath));
        elements[save] = elements[save]->suivant;
		count++;
    }while(allElementsNULL != 1);
}

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

