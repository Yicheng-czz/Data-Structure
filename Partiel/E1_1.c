// Partiel 2021
#include<stdio.h>
#include<stdlib.h>

//1)
#define MAX 50
typedef struct monome{
	int degree;
	double coefficient;
}Monome;
typedef struct polynome{
	int nbElts; 
	Monome tab[MAX];
}Polynome;
//2)
typedef struct monome{
	int degree;
	double coefficient;
}Monome;
typedef struct polynome{
	int nbEltsMax;
	int nbElts;
	Monome* tab;
}Polynome;
//3)


