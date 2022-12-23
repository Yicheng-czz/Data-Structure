#include<stdio.h>
#include<stdlib.h>

typedef int TElement;
typedef struct cellule{

	TElement donnee;
	struct cellule *suivant;

}*Cel;


typedef struct pile{

	Cel tete;
	Cel queue;

}*Pile;


Pile initPile(){
	Pile p = (Pile)malloc(sizeof(struct pile));
	p->tete = NULL;
	p->queue = NULL;
	return p; 
}

Cel sommetPile(Pile p){
	return p->tete;
}

Cel queue(Pile p){
	return p->queue;
}

int estVide(Pile p){
	return sommetPile(p)==NULL;
}

Cel suivant(Cel c){
	return c->suivant;
}

TElement donnee(Cel c){
	return c->donnee;
}

int estPlein(Pile p){
	return 0;
}

Cel allocMemRempElt(TElement elt){
	Cel c = (Cel)malloc(sizeof(struct cellule));
	c->donnee = elt;
	c->suivant = NULL;
	return c;
}

void emplierV(TElement elt, Pile p){
	Cel c = allocMemRempElt(elt);
	p->tete = p->queue = c;
}

void emplier(TElement elt, Pile p){
	Cel c = allocMemRempElt(elt);
	c->suivant = sommetPile(p);
	p->tete = c;
}


void depiler(Pile p){
	if(!estVide(p)){
		Cel s = sommetPile(p);
		Cel c = suivant(s);
		p->tete = c;
		if(c==NULL) p->queue=NULL;
		free(s);
		s = NULL;
	}
}

void afficher(Pile p){
	Cel c = sommetPile(p);
	while(c != NULL){
		printf("%d -> ", donnee(c));
		c = suivant(c);
	}
}

int main(int argc, char const *argv[])
{
	
	Pile p = initPile();

	TElement donnees[5] = {55,66,77,88,99};

	emplierV(donnees[0],p);
	for(int i = 1; i < 5; i++){
		emplier(donnees[i],p);
	}

	afficher(p);

	printf("\n commencement de depiler \n");

	while(sommetPile(p) != NULL){
		depiler(p);

		afficher(p);
		printf("\n\n\n\n");
	}


	return 0;
}











































