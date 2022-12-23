#include<stdio.h>
#include<stdlib.h>

typedef int TElement;
typedef struct pile
{
	TElement donnee;
	struct pile *suivant;
}*Pile;


Pile initPile(){
	return NULL;
}

int estVideP(Pile p){
	return p==NULL;
}

int estPleinP(Pile p){
	return 0;
}

TElement donnee(Pile p){
	return p->donnee;
}

Pile sommetPile(Pile p){
	return p;
}

Pile suivant(Pile p){
	return p->suivant;
}

Pile allocMemRempElt(TElement elt){
	Pile p = (Pile)malloc(sizeof(struct pile));
	p->donnee = elt;
	p->suivant = NULL;
	return p;
}

Pile empilerV(TElement elt){
	return allocMemRempElt(elt);
}

Pile empiler(TElement elt, Pile p){
	Pile nouv = allocMemRempElt(elt);
	nouv->suivant = sommetPile(p);
	return nouv;
}

Pile deplier(Pile p){
	Pile sommet = sommetPile(p);
	Pile nouv = suivant(sommet);
	free(sommet);
	sommet = NULL;
	return nouv;
}

void afficher(Pile p){
	Pile pp = p;
	while(pp != NULL){
		printf("%d -> ", donnee(pp));
		pp = suivant(pp);
	}
}

int main(int argc, char const *argv[])
{
	
	Pile p = initPile();

	TElement donnees[5] = {55,66,77,88,99};

	p = empilerV(donnees[0]);
	for(int i = 1; i < 5; i++){
		p = empiler(donnees[i], p);
	}

	afficher(p);

	return 0;
}

























