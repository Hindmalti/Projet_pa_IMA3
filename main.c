#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "structure.h"
#include "csv_reader.h"

/**
 * Codes d'erreurs / return :
 *   - 0 : aucune erreur
 *   - 1 : nombre d'argument != 2 (appel de l'executable + 1 argument)
 *   - 2 : Impossible de lire le fichier
 */
int main(int argc, char * argv[]){
	//garde-fou
	
	if (2 != argc){
		printf("Aide : %s nom_fichier_csv\n", argv[0]);
        return 1;
    }
	
	// definition d'athletes de test
	
    /*Athlete ath1 = {15, 5640, "dfgdfggd", "dgdfgdf", 'M', 21, 541, 10, 54564, "bfdgdfgd",
        54054, 1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    Athlete ath2 = {16, 5641, "azdfgdfggd", "dgdfgdf", 'M', 21, 541, 10, 54564, "bfdgdfgd",
        54054, 3, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    Athlete ath3 = {17, 5642, "cvfgdffgd", "dgdfgdf", 'M', 21, 541, 10, 54564, "bfdgdfgd",
        54054, 6, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    Athlete ath4 = {18, 5643, "jkjhkjhgd", "dgdfgdf", 'M', 21, 541, 10, 54564, "bfdgdfgd",
        54054, 2, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    Athlete ath5 = {19, 5644, "rezhkjhgd", "dgdfgdf", 'M', 21, 541, 10, 54564, "bfdgdfgd",
        54054, 2, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};*/
    
	// definition des listes
	printf("Creation des listes...\n");
	
    int temp = combienAthlete(argv[1]);
	if(temp == -1)
		return 2;
    int listeHashSize = temp/3; // /3 -> en moyenne 3 athletes qui ont le meme hash
    
    ListeTop50 listeTop50;
    ListeHash listeHashID[listeHashSize];
    ListeHash listeHashNom[listeHashSize];
	initialisation(&listeTop50, listeHashID, listeHashSize, listeHashNom, listeHashSize);
	
	// ajout d'athletes de test
	printf("Remplissage des listes...\n");
	
	read_csv_file(argv[1], &listeTop50, listeHashID, listeHashSize, listeHashNom, listeHashSize);
	
	// verification des listes
	printf("Affichage des listes...\n");
    
	printf("   TOP50 :\n");
    printListeAthlete(listeTop50);
    tiret(30);
	printf("   HASH ID :\n");
    printListeHashTableau(listeHashID, listeHashSize);
    tiret(30);
	printf("   HASH NOM :\n");
    printListeHashTableau(listeHashNom, listeHashSize);
    tiret(30);
    
	// Test de requetes sur les listes de hachage
	/*printf("Test sur les listes de hachage...\n");
	
	printf("Recherche de l'id 17 :\n");
    printAthlete(rechercheAthleteID(listeHashID, listeHashSize, 17));
	printf("Recherche de du nom \"azdfgdfggd\" + \"dgdfgdf\"\n");
    printAthlete(rechercheAthleteNom(listeHashNom, listeHashSize, "azdfgdfggd", "dgdfgdf"));
    tiret(30);*/
	
	// destruction de toutes les listes
	printf("Destruction des listes...\n");
	
	detruireTout(&listeTop50, listeHashID, listeHashSize, listeHashNom, listeHashSize);
	
	// verification
	printf("Verification de la destruction...\n");
    
	printf("   TOP50 :\n");
    printListeAthlete(listeTop50);
    tiret(30);
	printf("   HASH ID :\n");
    printListeHashTableau(listeHashID, listeHashSize);
    tiret(30);
	printf("   HASH NOM :\n");
    printListeHashTableau(listeHashNom, listeHashSize);
    tiret(30);
    
    return 0;
}
