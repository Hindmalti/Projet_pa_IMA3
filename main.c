#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "structure.h"


int main(void){
	// definition d'athletes de test
	
    Athlete ath1 = {15, 5640, "dfgdfggd", "dgdfgdf", 'M', 21, "541", "10", 54564, "bfdgdfgd",
        54054, 1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    Athlete ath2 = {16, 5641, "azdfgdfggd", "dgdfgdf", 'M', 21, "541", "10", 54564, "bfdgdfgd",
        54054, 3, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    Athlete ath3 = {17, 5642, "cvfgdffgd", "dgdfgdf", 'M', 21, "541", "10", 54564, "bfdgdfgd",
        54054, 6, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    Athlete ath4 = {18, 5643, "jkjhkjhgd", "dgdfgdf", 'M', 21, "541", "10", 54564, "bfdgdfgd",
        54054, 2, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    Athlete ath5 = {19, 5644, "rezhkjhgd", "dgdfgdf", 'M', 21, "541", "10", 54564, "bfdgdfgd",
        54054, 2, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    
	// definition des listes
	
    int tempListeSize = 2;
    
    ListeTop50 listeTop50;
    listeTop50.premier = NULL;
	
    ListeHash listeHashID[tempListeSize];
	for(int i = 0; i < tempListeSize; i++)
		listeHashID[i].premier = NULL;
	
    ListeHash listeHashNom[tempListeSize];
	for(int i = 0; i < tempListeSize; i++)
		listeHashNom[i].premier = NULL;
	
	// ajout d'athletes de test
    
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath1);
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath2);
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath3);
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath4);
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath5);
	
	// verification des listes
    
    printListeAthlete(listeTop50);
    tiret(30);
    printListeHashTableau(listeHashID, tempListeSize);
    tiret(30);
    printListeHashTableau(listeHashNom, tempListeSize);
    tiret(30);
    
    printAthlete(rechercheAthleteID(listeHashID, tempListeSize, 17));
    printAthlete(rechercheAthleteNom(listeHashNom, tempListeSize, "azdfgdfggd", "dgdfgdf"));
    
    return 0;
}
