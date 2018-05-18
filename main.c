#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "structure.h"


int main(void){
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
    
    int tempListeSize = 3;
    
    ListeTop50 listeTop50;
    listeTop50.premier = NULL;
    ListeHash listeHashID[tempListeSize];
    ListeHash listeHashNom[tempListeSize];
    
    /*ajoutAthleteTeteTrieeScore(&listeTop50, ath1, listeTop50.premier);
    ajoutAthleteTeteTrieeScore(&listeTop50, ath2, listeTop50.premier);
    ajoutAthleteTeteTrieeScore(&listeTop50, ath3, listeTop50.premier);
    ajoutAthleteTeteTrieeScore(&listeTop50, ath4, listeTop50.premier);
    ajoutAthleteTeteTrieeScore(&listeTop50, ath5, listeTop50.premier);*/
    
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath1);
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath2);
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath3);
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath4);
    ajoutAthlete(&listeTop50, listeHashID, tempListeSize, listeHashNom, tempListeSize, &ath5);
    
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
