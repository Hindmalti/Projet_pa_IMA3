#ifndef CSV_READER_H
#define CSV_READER_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "structure.h"

void display_header();

char *strtok_new(char * string, char const * delimiter);

int combienAthlete(char *filename);

void read_csv_header(char * header_line);

void read_csv_file(const char * filename, ListeTop50 *liste50, ListeHash listeHashID[], int listeHashIDSize, ListeHash listeHashNom[], int listeHashNomSize);

#endif