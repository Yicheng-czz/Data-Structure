// Partiel 2021
#include<stdio.h>
#include<stdlib.h>

//1)

//2)
#define MAX 50
typedef struct monome{
	int degree;
	double coefficient;
}Monome;
typedef struct polynome{
	Monome monome;
	struct polynome *suivant;
}*Polynome;
typedef struct liste{
	Polynome tete;
	Polynome queue;
}*Liste;
//3)
Polynome suppression(Monome m, Polynome p){
	
	return p
}
