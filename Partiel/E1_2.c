// Partiel 2021
#include<stdio.h>
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
	int nombreElt;
	int MaxElt;
	Monome tab[MAX];

}Polynome;

//2)
typedef struct monome{
	int degree;
	double coefficient;
}Monome;
typedef struct polynome{
	Monome tab*;
	int nombreElt;
	int MaxElt;
}Polynome;
//3)
//4)
