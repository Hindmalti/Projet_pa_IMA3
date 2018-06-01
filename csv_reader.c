#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "util.h"
#include "structure.h"

// Conditionals
const bool          IS_DEBUG            = false;

// Constants
const unsigned int  BUFFER_SIZE         = 2048;
const unsigned int  FIELD_SIZE          = 20;
const char          CSV_DELIMITERS[]    = ",";

// Globals
char**              CSV_HEADER_FIELDS;
unsigned int        CSV_NB_FIELDS;

void display_header()
{
    for(unsigned int i = 0; i < CSV_NB_FIELDS; i++)
    {
        printf("%d - %s\n", i, CSV_HEADER_FIELDS[i]);
    }
}

char *strtok_new(char * string, char const * delimiter)
{
	static char *source = NULL;
	char *p, *ret = 0;
	if(string != NULL) source = string;
	if(source == NULL) return NULL;

	if( (p = strpbrk (source, delimiter)) != NULL)
	{
		*p = 0;
		ret = source;
		source = ++p;
	}
	return ret;
}

// return -1 en cas de probleme
int combienAthlete(char *filename){
	FILE* fp = fopen(filename, "r");
    if (fp == NULL){
        fprintf(stderr, "Impossible d'ouvrir le fichier : %s\n", filename);
        return -1;
    }
	
    char buffer[BUFFER_SIZE]; // pour contenir la ligne
	int i = -1; // -1 pour le header
    while ( NULL != fgets(buffer, BUFFER_SIZE, fp) )
		i++;
	
	return i;
}

void read_csv_file(const char * filename, int maxLine, ListeTop50 liste50[],
		ListeTop50Ep listeTop50Ep[][5], int listeTop50Size,
		ListeHash listeHashID[], int listeHashIDSize, ListeHash listeHashNom[],
		int listeHashNomSize)
{
	
    FILE*   fp = fopen(filename, "r");
    char    buffer[BUFFER_SIZE];

    // Check if the file is really opened
    if (NULL == fp)
    {
        fprintf(stderr, "Impossible d'ouvrir le fichier : %s\n", filename);
        return;
    }

    // 1st row is a header with field descriptions
	
    fgets(buffer, BUFFER_SIZE, fp);
	
    // Remaining rows are the entries
	
	int currentLigne = 0;
	int afficheLigne = maxLine/5;
	chargementTexte(-1);
    while ( NULL != fgets(buffer, BUFFER_SIZE, fp) )
    {
		currentLigne++;
		if(currentLigne % afficheLigne == 0)
			chargementTexte((currentLigne * 100) / maxLine);
		
        char* token = strtok_new(buffer, CSV_DELIMITERS);
		
		int index = 0;
		Athlete *ath = malloc(sizeof *ath);
        while (NULL != token)
        {
			switch(index){
				case 0:
					ath->athId = atoi(token);
					break;
				case 1:
					ath->regId = atoi(token);
					break;
				//case 2 n'est pas necessaire
				case 3:
					ath->lastName = malloc(strlen(token) + 1);
					strcpy(ath->lastName, token);
					break;
				case 4:
					ath->firstName = malloc(strlen(token) + 1);
					strcpy(ath->firstName, token);
					break;
				case 5:
					ath->gender = token[0];
					break;
				case 6:
					ath->age = atoi(token);
					break;
				case 7:
					ath->weight = ((float) atoi(token)) * 0.4536f; // conversion lb -> kg
					break;
				case 8:
					ath->height = ((float) atoi(token)) * 0.0254f; // conversion in -> m
					break;
				case 9:
					ath->affiliateId = atoi(token);
					break;
				//case 10 n'est pas necessaire
				case 11:
					ath->overallScore = atoi(token);
					break;
				//case 12 n'est pas necessaire
				case 13:
					ath->score18_1 = atoi(token);
					break;
				//case 14 n'est pas necessaire
				//case 15 n'est pas necessaire
				case 16:
					ath->score18_2 = atoi(token);
					break;
				//case 17 n'est pas necessaire
				//case 18 n'est pas necessaire
				case 19:
					ath->score18_2a = atoi(token);
					break;
				//case 20 n'est pas necessaire
				//case 21 n'est pas necessaire
				case 22:
					ath->score18_3 = atoi(token);
					break;
				//case 23 n'est pas necessaire
				//case 24 n'est pas necessaire
				case 25:
					ath->score18_4 = atoi(token);
					break;
				//case 26 n'est pas necessaire
				//case 27 n'est pas necessaire
				case 28:
					ath->score18_5 = atoi(token);
					break;
				//case 29 n'est pas necessaire
				//case 30 n'est pas necessaire
			}
			index++;
            token = strtok_new(NULL, CSV_DELIMITERS);
        }
		int whichListeTop50 = (currentLigne * (listeTop50Size - 1)) / maxLine;
		ajoutAthlete(liste50, listeTop50Ep, whichListeTop50, listeHashID, listeHashIDSize, listeHashNom,
				listeHashNomSize, ath);
	}
	
	chargementTexte(100);
    fclose(fp);
}
