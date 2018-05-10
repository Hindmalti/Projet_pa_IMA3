#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

void printAthlete(Athlete *ptr){
    if(ptr != NULL){
        printf("%d %s %s %c %s m %s kg %d %d %d %d %d %d", ptr->athId, ptr->lastName, ptr->firstName, ptr->gender, ptr->height, ptr->weight, ptr->score18_1, ptr->score18_2, ptr->score18_2a, ptr->score18_3, ptr->score18_4, ptr->score18_5); 
    }
}

int hash_int(int athID){
    return athID % TABLE_SIZE;
}

int hash_word(char *word){
    return (asciis(word) % TABLE_SIZE);
}

int asciis(char *word){
    int i = 0, h = 0;
    while(word[i] != '\0'){
        h += word[i];
        i++;
    }
    return h;
}

Athlete* rechercheAthleteID(ListeAthlete liste, int athId){
    while(liste != NULL){
        if(liste->athId == athId){
            return liste;
        }
        liste = liste->suivant;
    }
   return NULL;
} 

void rechercheAthleteNom(ListeAthlete liste, char *nom){
    while(liste != NULL){
        if(!strcmp(liste->lastName, nom)){
            printAthlete(liste);
        }
        liste = liste->suivant;
    }
}

void afficherAthlete(HashListeAthlete ht, int athId){
    int indice = hash_int(athId);
    printAthlete(rechercheAthleteID(ht[indice], athId));
}

void afficherNom(HashListeAthlete ht, char *nom){
    int indice = hash_word(nom);
    rechercheAthleteNom(ht[indice], nom);
}

void ajoutAthleteTete(ListeAthlete *liste, Athlete* ptr){
    Athlete *new = malloc(sizeof(Athlete));
    memcpy(new,ptr,sizeof(Athlete));
    *liste->suivant = *liste;
    *liste = new;
}

void printListeAthlete(ListeAthlete liste){
    while(liste != NULL){
        printAthlete(liste);
        tiret(10);
        liste = liste->suivant;
    }
}

void tiret(int n){
    int i = 0;
    for(i = 0 ; i<n ; i++){
        printf("-");
    }
    printf("\n");
}


