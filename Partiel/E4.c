#include<stdio.h>
#include<stdlib.h>
//1)

typedef int TElement;

typedef struct cellule{
	TElement e;
	struct cellule *suivant;
}*Cel;

typedef struct liste{
	Cel tete;
	Cel queue; 
}*Liste;

