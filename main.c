#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "structure.h"


int main(void){
    Athlete ath1 = {15, 5640, "dfgdfggd", "dgdfgdf", 'M', 21, "541", "10", 54564, "bfdgdfgd", 54054, 1};
    Athlete ath2 = {15, 5640, "azdfgdfggd", "dgdfgdf", 'M', 21, "541", "10", 54564, "bfdgdfgd", 54054, 3};
    Athlete ath3 = {15, 5640, "cvfgdffgd", "dgdfgdf", 'M', 21, "541", "10", 54564, "bfdgdfgd", 54054, 6};
    Athlete ath4 = {15, 5640, "jkjhkjhgd", "dgdfgdf", 'M', 21, "541", "10", 54564, "bfdgdfgd", 54054, 2};
    Athlete ath5 = {15, 5640, "rezhkjhgd", "dgdfgdf", 'M', 21, "541", "10", 54564, "bfdgdfgd", 54054, 2};
    
    Liste_TOP_50 liste;
    liste.premier = NULL;
    ajoutAthleteTeteTrieeScore(&liste, ath1, liste.premier);
    ajoutAthleteTeteTrieeScore(&liste, ath2, liste.premier);
    ajoutAthleteTeteTrieeScore(&liste, ath3, liste.premier);
    ajoutAthleteTeteTrieeScore(&liste, ath4, liste.premier);
    ajoutAthleteTeteTrieeScore(&liste, ath5, liste.premier);
    
    printListeAthlete(liste);
    
    return 0;
}
