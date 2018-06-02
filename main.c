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
	
    int nAth = combienAthlete(argv[1]);
	if(nAth == -1)
		return 2; // arret du programme code 2 = erreur de lecture
    int listeHashSize = nAth/3; // /3 -> en moyenne 3 athletes qui ont le meme hash
    int listeTop50Size = nAth > 100 ? (nAth/100) + 1 : 1; // 100 athletes max dans chaque segment des listes TOP 50
	
	// la liste chainee "ListeTop50" a ete fractionnee en "listeTop50Size" morceaux pour optimiser le programme
	// Ainsi, lors de l'ajout d'un nouvel athlete lors de la lecture du fichier csv, le programme n'a plus a parcourir
	// un nombre colossal l'elements dans la liste mais seullement 100 element au maximum.
    ListeTop50 listeTop50[listeTop50Size]; // questions 1, 2, 3, 7 et 8
    ListeHash listeHashID[listeHashSize]; // question 5
    ListeHash listeHashNom[listeHashSize]; // question 6
	// pareil que pour "ListeTop50" mais pour 5 epreuves
	ListeTop50Ep listeTop50Ep[listeTop50Size][5]; // question 4
	
	// initialise les listes correctement
	initialisation(listeTop50, listeTop50Ep, listeTop50Size, listeHashID,
			listeHashSize, listeHashNom, listeHashSize);
	
	// Lecture du csv
	printf("Lecture du fichier...\n");
	
	read_csv_file(argv[1], nAth, listeTop50, listeTop50Ep, listeTop50Size,
			listeHashID, listeHashSize, listeHashNom, listeHashSize);
	
	
	/* ----- EXECUTION INSTRUCTIONS -----*/
	
	char buffer[48]; // enregistre la demande
	int quit = 0; // enregistre le demande de quitter le programme = commande 9
	while(quit != 1){
		// separation
		printf("\n\n");
		tiret(70);
		
		printf("Veuillez entrer une commande (entre 1 et 9) : ");
		
		// demande de commande
		fgets(buffer, 48, stdin);
		printf("\n\n");
		
		// obtiens le numero de la commande
		int numCommande = buffer[0] - '0';
		if(numCommande < 1 || numCommande > 9){
			printf("Usage des commandes : [0-9] [argument]\n");
			continue;
		}
		
		// traitement de la commande
		switch(numCommande){
			case 1:{
				// TOP 50 global
				printf(" *** Affichage du TOP 50 :\n\n");
				printf("%2.2s %20.20s %20.20s %10.10s\n\n", "##", "NOM DE FAMILLE", "PRENOM", "SCORE");
				printTop50(listeTop50, listeTop50Size);
				break;
			}
			case 2:{
				// TOP 50 feminin / masculin
				if(buffer[1] != ' ' || (buffer[2] != 'M' && buffer[2] != 'F')){
					printf("Usage de la commande 2 : 2 [M ou F]\n");
					break;
				}
				printf(" *** Affichage du TOP 50 %s :\n\n", buffer[2] == 'M' ? "masculin" : "feminin");
				printf("%2.2s %20.20s %20.20s %10.10s\n\n", "##", "NOM DE FAMILLE", "PRENOM", "SCORE");
				printTop50Genre(listeTop50, listeTop50Size, buffer[2]);
				break;
			}
			case 3:{
				// TOP 50 par region
				char temp1[46];
				strncpy(temp1, buffer+2, 46);
				int id = atoi(temp1);
				if(buffer[1] != ' ' || id <= 0){
					printf("Usage de la commande 3 : 3 [id region]\n");
					break;
				}
				printf(" *** Affichage du TOP 50 de la region ayant pour id %d :\n\n", id);
				printf("%2.2s %20.20s %20.20s %10.10s\n\n", "##", "NOM DE FAMILLE", "PRENOM", "SCORE");
				printTop50Region(listeTop50, listeTop50Size, id);
				break;
			}
			case 4:{
				// TOP 50 par etapes
				char temp2[46];
				strncpy(temp2, buffer+2, 46);
				int ep = atoi(temp2);
				if(buffer[1] != ' ' || ep <= 0 || ep > 5){
					printf("Usage de la commande 4 : 4 [ep = 1 a 5]\n");
					break;
				}
				printf(" *** Affichage du TOP 50 de l'etape ayant pour id %d :\n\n", ep);
				printf("%2.2s %20.20s %20.20s %14.14s %d\n\n", "##", "NOM DE FAMILLE", "PRENOM", "SCORE EPREUVE", ep);
				printTop50Epreuve(listeTop50Ep, listeTop50Size, ep);
				break;
			}
			case 5:{
				// Recherce athlete par ID
				char temp3[46];
				strncpy(temp3, buffer+2, 46);
				int id = atoi(temp3);
				if(buffer[1] != ' ' || id <= 0){
					printf("Usage de la commande 5 : 5 [id athlete]");
					break;
				}
				printf(" *** Recherche de l'athlete ayant pour id %d :\n\n", id);
				printHashId(listeHashID, listeHashSize, id);
				break;
			}
			case 6:{
				// Recherche athlete par nom de famille
				char temp4[46];
				strncpy(temp4, buffer+2, 46);
				if(buffer[1] != ' ' || buffer[2] == '\n'){
					printf("Usage de la commande 6 : 6 [nom famille athlete]\n");
					break;
				}
				for(int i = 0; i < 46; i++){
					if(temp4[i] == '\n')
						temp4[i] = '\0';
				}
				printf(" *** Recherche de l'athlete ayant pour nom de famille %s :\n\n", temp4);
				printHashNom(listeHashNom, listeHashSize, temp4);
				break;
			}
			case 7:{
				// Classement par salle
				char temp5[46];
				strncpy(temp5, buffer+2, 46);
				int id = atoi(temp5);
				if(buffer[1] != ' ' || id <= 0){
					printf("Usage de la commande 7 : 7 [id salle]\n");
					break;
				}
				printf(" *** Affichage du classement de la salle ayant pour id %d :\n\n", id);
				printf("%3.3s %20.20s %20.20s %10.10s\n\n", "###", "NOM DE FAMILLE", "PRENOM", "SCORE");
				printTopSalle(listeTop50, listeTop50Size, id);
				break;
			}
			case 8:{
				// Classement des salles de Lille
				printf(" *** Affichage du classement des salles de Lille :\n\n");
				printf("%3.3s %20.20s %20.20s %10.10s\n\n", "###", "NOM DE FAMILLE", "PRENOM", "SCORE");
				printTopSalleLille(listeTop50, listeTop50Size);
				break;
			}
			case 9:{
				// Quitte le programme
				printf("Le programme va maintenant s'arreter...\n");
				quit = 1;
				break;
			}
		}
	}
	
	
	// destruction de toutes les listes
	printf("Destruction des listes...\n");
	detruireTout(listeTop50, listeTop50Size, listeHashID, listeHashSize, listeHashNom, listeHashSize);
	
	printf("Fin du programme.\n");
    
    return 0;
}
