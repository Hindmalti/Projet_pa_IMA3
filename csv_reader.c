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

void read_csv_header(char * header_line)
{
    int     nb_fields   = 0;
    char*   string_ptr  = header_line;

    // Count the occurrences of delimiters
    while (NULL != string_ptr)
    {
        nb_fields++;
        string_ptr = strpbrk(string_ptr, CSV_DELIMITERS);
        if (NULL != string_ptr)
        {
            string_ptr++;
        }
    }

    // Globals allocation
    CSV_NB_FIELDS       = nb_fields;
    CSV_HEADER_FIELDS   = malloc( nb_fields * sizeof(char*) );

    char* token         = strtok_new(header_line, CSV_DELIMITERS);              // strtok_new init.

	printf("aaa\n");
    // Re-read the line to get the header of the columns
    for (int i = 0; i < nb_fields; i++)
    {
        CSV_HEADER_FIELDS[i] = malloc( FIELD_SIZE * sizeof(char) );             // alloc
        memset(CSV_HEADER_FIELDS[i], 0, FIELD_SIZE);                            // 0 init.
        strcpy(CSV_HEADER_FIELDS[i], token);                                    // copy field in the structure
        token = strtok_new(NULL, CSV_DELIMITERS);                               // loop to get a new field label
    }

    if (IS_DEBUG) display_header();
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
	
    //read_csv_header(buffer);
    // Remaining rows are the entries
	
	int currentLigne = 0;
	chargementTexte(-1);
    while ( NULL != fgets(buffer, BUFFER_SIZE, fp) )
    {
		currentLigne++;
		if(currentLigne % 100 == 0)
			chargementTexte((currentLigne * 100) / maxLine);
		
        if (IS_DEBUG) printf("Ligne is %s\n", buffer);
		
        char*           token;
        unsigned int    i = 0;

        // strtok init.
        token = strtok_new(buffer, CSV_DELIMITERS);
		
		int index = 0;
		Athlete *ath = malloc(sizeof *ath);
        while (NULL != token)
        {
			if (IS_DEBUG) printf("Field in %d is %s\n", i, token);
			
            // ...
            // you can strcpy the `token` string in your data structures
            // ...
			
			char* temp = token;
			int inttemp = -1;
			if(index != 3 || index != 4 || index != 5 || index != 10)
				inttemp = atoi(temp);
			
			switch(index){
				case 0:
					ath->athId = inttemp;
					break;
				case 1:
					ath->regId = inttemp;
					break;
				//case 2 n'est pas necessaire
				case 3:
					ath->lastName = malloc(strlen(temp) + 1);
					strcpy(ath->lastName, temp);
					break;
				case 4:
					ath->firstName = malloc(strlen(temp) + 1);
					strcpy(ath->firstName, temp);
					break;
				case 5:
					ath->gender = temp[0];
					break;
				case 6:
					ath->age = inttemp;
					break;
				case 7:
					ath->weight = ((float) inttemp) * 0.4536f; // conversion lb -> kg
					break;
				case 8:
					ath->height = ((float) inttemp) * 0.0254f; // conversion in -> m
					break;
				case 9:
					ath->affiliateId = inttemp;
					break;
				//case 10 n'est pas necessaire
				case 11:
					ath->overallScore = inttemp;
					break;
				//case 12 n'est pas necessaire
				case 13:
					ath->score18_1 = inttemp;
					break;
				//case 14 n'est pas necessaire
				//case 15 n'est pas necessaire
				case 16:
					ath->score18_2 = inttemp;
					break;
				//case 17 n'est pas necessaire
				//case 18 n'est pas necessaire
				case 19:
					ath->score18_2a = inttemp;
					break;
				//case 20 n'est pas necessaire
				//case 21 n'est pas necessaire
				case 22:
					ath->score18_3 = inttemp;
					break;
				//case 23 n'est pas necessaire
				//case 24 n'est pas necessaire
				case 25:
					ath->score18_4 = inttemp;
					break;
				//case 26 n'est pas necessaire
				//case 27 n'est pas necessaire
				case 28:
					ath->score18_5 = inttemp;
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
	
    for(unsigned int i = 0; i < CSV_NB_FIELDS; i++)
    {
        free(CSV_HEADER_FIELDS[i]);
    }
    free(CSV_HEADER_FIELDS);
}
