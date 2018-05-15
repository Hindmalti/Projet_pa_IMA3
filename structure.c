#include <stdio.h>
#include <stdlib.h>

// structure athlète 

typedef struct{
	unsigned int athId; 
	unsigned int regId;
	//unsigned int divId; 
	char *lastName; 
	char *firstName;
	char gender; 
	unsigned int age; 
	unsigned int weight; 
	unsigned int height; 
	unsigned int affiliateId; 
	char *affiliateName; 
	unsigned int overallScore; 
 	unsigned int overallRank; 
	unsigned int score18_1;
	//char *scoreDisplay18_1;
	unsigned int rank18_1;
	unsigned int score18_2;
	//char *scoreDisplay18_2;
	unsigned int rank18_2;
	unsigned int score18_2a;
	//char *scoreDisplay18_2a;
	unsigned int rank18_2a;
	unsigned int score18_3;
	//char *scoreDisplay18_3;
	unsigned int rank18_3;
	unsigned int score18_4;
	//char *scoreDisplay18_4;
	unsigned int rank18_4;
	unsigned int score18_5;
	//char *scoreDisplay18_5;
	unsigned int rank18_5;
}Athlete;

typedef struct Element_TOP_50 Element_TOP_50;
struct Element_TOP_50 {
    Athlete ath;
    Element_TOP_50 *suivant;
};
typedef struct {
    Element_TOP_50 *premier;
} Liste_TOP_50;


/*
// structure liste chaînée triée 
typedef struct Element{
	Athlete *pAth; 
	Element *suivant; 
	
} Element;
typedef struct {
	Element *premier;
} Liste;
// on remplit notre 
void ajoutRecursif(Liste *liste, Athlete *pAthlete, Element *element){
    if(liste->premier == NULL){
        Element *ajout = malloc(sizeof *ajout);
        ajout->pAth = pAthlete;
        ajout->suivant = NULL;
        liste->premier = ajout;
        return;
    }
    if(pAthele < liste->premier->pAth){
        Element *ajout = malloc(sizeof *ajout);
        ajout->pAth = pAthlete;
        ajout->suivant = liste->premier;
        liste->premier = ajout;
        return;
    }
    if(element->suivant == NULL || val < element->suivant->valeur){
        Element *ajout = malloc(sizeof *ajout);
        ajout->pAth = pAthlete;
        ajout->suivant = element->suivant;
        element->suivant = ajout;
        return;
    }
    addRecursif(liste, pAthele, element->suivant);
    return;
}

void printListe(Liste liste){
    Element *element = liste.premier;
    while(element != NULL){
        printf("%d\n", element->pAth->athId);
        element = element->suivant;
    }
}
*/

