#ifndef STRUCTURE_H
#define STRUCTURE_H
#include<stdio.h>
#include<stdlib.h> 

typedef struct{
	unsigned int athId; 
	unsigned int regId;
	//unsigned int divId; 
	char *lastName; 
	char *firstName;
	char gender; 
	unsigned int age; 
	char *weight; 
	char *height; 
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

typedef struct ElementTop50 ElementTop50;
struct ElementTop50 {
    Athlete ath;
    ElementTop50 *suivant;
};
typedef struct {
    ElementTop50 *premier;
} ListeTop50;

typedef struct ElementHash ElementHash;
struct ElementHash {
    Athlete *ath;
    ElementHash *suivant;
};
typedef struct {
    ElementHash *premier;
} ListeHash;
#endif
