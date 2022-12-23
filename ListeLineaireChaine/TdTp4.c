#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<math.h>

// FactPremier et Liste sont les structures des données pour liste chainée
typedef struct{
	int fact;
	int nbOcc;
}FactPremier;

typedef struct cellule{
	FactPremier donnee;
	struct cellule *suivant;
}*Liste;


// Exercice 1 (1)
// Initialisation de TabList
typedef struct{
	int nb;
	Liste listePremier;
}TElement;
// tab dynamique
typedef struct{
	int nbEltMax;
	int nbElt;
	TElement *tab;
}Tableau;



Tableau* initTabList(nbMax){
	Tableau *t = (Tableau*)malloc(sizeof(Tableau));
	if(t == NULL){
		perror("Initiliation du \'Tableau\' avec echec");
		exit(EXIT_FAILURE);
	}
	t->nbEltMax = nbMax;
	t->nbElt = 0;
	t->tab = (TElement*)malloc(sizeof(TElement) * nbMax);

	// un test
	// for(int i = 0; i< 3; i++){
	// 	t->tab[i].nb = (i+1)*10;
	// 	t->tab[i].listePremier = NULL;
	// 	t->nbElt += 1;
	// }
	return t;
}

// Exercice 1 (2)
int nombreDiviser(nombre, facteur){
	if( nombre % facteur == 0){
		return 1 + nombreDiviser(nombre/facteur, facteur);
	}
	else{
		return 0;
	}
}


// Ajout un cellule dans une liste donnée
// liste: la liste donnée
// cellule: l'élement qu'on veut ajouter
Liste ajoutElt(liste,cellule){
	if(cellule == NULL){
		return 
	}
}


// LNP est une liste de facteur
// n: le nombre qu'on va decomposer
// LNP: un tableau qui contient des facteur
// tailleLNP: la taille du LNP
Liste decomposition(n,LNP,tailleLNP){
	Liste l = (Liste)malloc(sizeof(cellule));
	Liste p = l;
	int facteur = tailleLNP[0];
	int Rn = sqrt(n);
	while(facteur <= Rn){
		int occ = nombreDiviser(n,facteur);
		if( occ != 0){
			p->donnee.facteur = facteur;
			p->donnee.nbOcc = occ;
		}
	}
}


int main(int argc, char const *argv[])
{
	Tableau *t = initTabList(10);
	if( t->nbElt != 0){
		for(int i = 0; i < 3; i++){
			if(t->tab[i].listePremier == NULL){
				printf("%d(NULL) -> ", t->tab[i].nb);
			}
			else{
				printf("%d -> ", t->tab[i].nb);
			}
			
		}
	}
	else{
		printf("t est vide\n");
	}
	return 0;
}
































