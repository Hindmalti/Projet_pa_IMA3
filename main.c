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
	/* ----- INITIALISATION ----- */
	
	//garde-fou
	if (2 != argc){
		printf("Aide : %s nom_fichier_csv\n", argv[0]);
        return 1;
    }
    
	// definition des listes
	printf("Creation des listes...\n");
	
    int temp = combienAthlete(argv[1]);
	if(temp == -1)
		return 2; // arret du programme code 2
    int listeHashSize = temp/3; // /3 -> en moyenne 3 athletes qui ont le meme hash
    
    ListeTop50 listeTop50;
    ListeHash listeHashID[listeHashSize];
    ListeHash listeHashNom[listeHashSize];
	ListeTop50Ep listeTop50Ep[5];
	
	initialisation(&listeTop50, listeHashID, listeHashSize, listeHashNom, listeHashSize, listeTop50Ep);
	
	// Lecture du csv
	printf("Lecture du fichier...\n");
	
	read_csv_file(argv[1], &listeTop50, listeHashID, listeHashSize, listeHashNom, listeHashSize, listeTop50Ep);
    
	// Test de requetes sur les listes de hachage
	/*printf("Test sur les listes de hachage...\n");
	
	printf("Recherche de l'id 17 :\n");
    printAthlete(rechercheAthleteID(listeHashID, listeHashSize, 17));
	printf("Recherche de du nom \"azdfgdfggd\" + \"dgdfgdf\"\n");
    printAthlete(rechercheAthleteNom(listeHashNom, listeHashSize, "azdfgdfggd", "dgdfgdf"));
    tiret(30);*/
	
	/* ----- EXECUTION INSTRUCTIONS -----*/
	
	char buffer[2048];
	int quit = 0;
	while(quit != 1){
		printf("\n\n");
		tiret(30);
		
		printf("Veuillez entrer une commande (entre 1 et 9)\n");
		// demande de commande
		fgets(buffer, 2048, stdin);
		printf("\n");
		
		int numCommande = buffer[0] - '0';
		if(numCommande < 1 || numCommande > 9){
			printf("Usage des commandes : [0-9] [argument]\n");
			continue;
		}
		
		switch(numCommande){
			case 1:{
				printf(" *** Affichage du TOP 50 :\n\n");
				printf("%2.2s %15.15s %15.15s %10.10s\n\n", "##", "NOM DE FAMILLE", "PRENOM", "SCORE");
				printTop50(listeTop50);
				break;
			}
			case 2:{
				if(buffer[1] != ' ' || (buffer[2] != 'M' && buffer[2] != 'F')){
					printf("Usage de la commande 2 : 2 [M ou F]\n");
					break;
				}
				printf(" *** Affichage du TOP 50 %s :\n\n", buffer[2] == 'M' ? "masculin" : "feminin");
				printf("%2.2s %15.15s %15.15s %10.10s\n\n", "##", "NOM DE FAMILLE", "PRENOM", "SCORE");
				printTop50Genre(listeTop50, buffer[2]);
				break;
			}
			case 3:{
				char temp1[2046];
				strncpy(temp1, buffer+2, 2046);
				int id = atoi(temp1);
				if(buffer[1] != ' ' || id <= 0){
					printf("Usage de la commande 3 : 3 [id region]\n");
					break;
				}
				printf(" *** Affichage du TOP 50 de la region ayant pour id %d :\n\n", id);
				printf("%2.2s %15.15s %15.15s %10.10s\n\n", "##", "NOM DE FAMILLE", "PRENOM", "SCORE");
				printTop50Region(listeTop50, id);
				break;
			}
			case 4:{
				char temp2[2046];
				strncpy(temp2, buffer+2, 2046);
				int ep = atoi(temp2);
				if(buffer[1] != ' ' || ep <= 0 || ep > 5){
					printf("Usage de la commande 4 : 4 [ep = 1 a 5]\n");
					break;
				}
				printf(" *** Affichage du TOP 50 de l'etape ayant pour id %d :\n\n", ep);
				printf("%2.2s %15.15s %15.15s %10.10s\n\n", "##", "NOM DE FAMILLE", "PRENOM", "SCORE");
				printTop50Epreuve(listeTop50Ep[ep - 1], ep);
				break;
			}
			case 5:{
				char temp3[2046];
				strncpy(temp3, buffer+2, 2046);
				int id = atoi(temp3);
				if(buffer[1] != ' ' || id <= 0){
					printf("Usage de la commande 5 : 5 [id athlete]");
					break;
				}
				printf(" *** Recherche de l'athlete ayant pour id %d :\n\n", id);
				printf("%7.7s %15.15s %15.15s %4.4s %3.3s %8.8s %8.8s %11.11s %11.11s %11.11s %11.11s %11.11s %11.11s\n",
						"ID", "NOM DE FAMILLE", "PRENOM", "SEXE", "AGE", "TAILLE m", "POIDS kg", "SCORE 18.1", "SCORE 18.2", "SCORE 18.2a", "SCORE 18.3", "SCORE 18.4", "SCORE 18.5"); 
				printAthleteDefaut(rechercheAthleteID(listeHashID, listeHashSize, id));
				break;
			}
			case 6:{
				char temp4[2046];
				strncpy(temp4, buffer+2, 2046);
				if(buffer[1] != ' ' || buffer[0] != '\0'){
					printf("Usage de la commande 6 : 6 [nom famille athlete]\n");
					break;
				}
				printf(" *** Recherche de l'athlete ayant pour nom de famille %s :\n\n", temp4);
				printf("%7.7s %15.15s %15.15s %4.4s %3.3s %8.8s %8.8s %11.11s %11.11s %11.11s %11.11s %11.11s %11.11s\n",
						"ID", "NOM DE FAMILLE", "PRENOM", "SEXE", "AGE", "TAILLE m", "POIDS kg", "SCORE 18.1", "SCORE 18.2", "SCORE 18.2a", "SCORE 18.3", "SCORE 18.4", "SCORE 18.5"); 
				printAthleteDefaut(rechercheAthleteNom(listeHashID, listeHashSize, temp4));
				break;
			}
			case 7:{
				char temp5[2046];
				strncpy(temp5, buffer+2, 2046);
				int id = atoi(temp5);
				if(buffer[1] != ' ' || id <= 0){
					printf("Usage de la commande 7 : 7 [id salle]\n");
					break;
				}
				printf(" *** Affichage du classement de la salle ayant pour id %d :\n\n", id);
				printf("%3.3s %15.15s %15.15s %10.10s\n\n", "###", "NOM DE FAMILLE", "PRENOM", "SCORE");
				printTopSalle(listeTop50, id);
				break;
			}
			case 8:{
				printf(" *** Affichage du classement des salles de Lille :\n\n");
				printf("%3.3s %15.15s %15.15s %10.10s\n\n", "###", "NOM DE FAMILLE", "PRENOM", "SCORE");
				printTopSalleLille(listeTop50);
				break;
			}
			case 9:{
				printf("Le programme va maintenant s'arreter...\n");
				quit = 1;
				break;
			}
		}
	}
	
	
	// destruction de toutes les listes
	printf("Destruction des listes...\n");
	
	detruireTout(&listeTop50, listeHashID, listeHashSize, listeHashNom, listeHashSize);
	
	printf("Fin du programme.\n");
    
    return 0;
}
