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
	printf("Creation des listes...\n");
	
    int tempListeSize = 6;
    
    ListeTop50 listeTop50;
    ListeHash listeHashID[tempListeSize];
    ListeHash listeHashNom[tempListeSize];
	initialisation(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize);
	
	// ajout d'athletes de test
	printf("Remplissage des listes...\n");
    
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath1);
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath2);
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath3);
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath4);
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath5);
	
	// verification des listes
	printf("Affichage des listes...\n");
    
	printf("   TOP50 :\n");
    printListeAthlete(listeTop50);
    tiret(30);
	printf("   HASH ID :\n");
    printListeHashTableau(listeHashID, tempListeSize);
    tiret(30);
	printf("   HASH NOM :\n");
    printListeHashTableau(listeHashNom, tempListeSize);
    tiret(30);
    
	// Test de requetes sur les listes de hachage
	printf("Test sur les listes de hachage...\n");
	
	printf("Recherche de l'id 17 :\n");
    printAthlete(rechercheAthleteID(listeHashID, tempListeSize, 17));
	printf("Recherche de du nom \"azdfgdfggd\" + \"dgdfgdf\"\n");
    printAthlete(rechercheAthleteNom(listeHashNom, tempListeSize, "azdfgdfggd", "dgdfgdf"));
    tiret(30);
	
	// destruction de toutes les listes
	printf("Destruction des listes...\n");
	
	detruireTout(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize);
	
	// verification
	printf("Verification de la destruction...\n");
    
	printf("   TOP50 :\n");
    printListeAthlete(listeTop50);
    tiret(30);
	printf("   HASH ID :\n");
    printListeHashTableau(listeHashID, tempListeSize);
    tiret(30);
	printf("   HASH NOM :\n");
    printListeHashTableau(listeHashNom, tempListeSize);
    tiret(30);
    
    return 0;
}
