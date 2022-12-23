#include<stdio.h>
#include<stdlib.h>

typedef int TElement;
#define MAXELT 30
typedef struct pile
{
	
	TElement tab[MAXELT];
	int maxSize;
	int eltSize;

}Pile;

Pile initPile(){
	Pile p;
	p.maxSize = MAXELT;
	p.eltSize = 0;
	return p;
}

int estVideP(Pile p){
	return p.eltSize == 0;
}

int estPleinP(Pile p){
	return p.eltSize==p.maxSize;
}

TElement sommetPile(Pile p){
	return p.tab[0];
}

int sizeCourante(Pile p){
	return p.eltSize;
}

void empilerV(TElement elt,Pile *p){
	p->tab[0] = elt;
	p->eltSize = 1;
}

void empiler(TElement elt, Pile *p){
	if(!estPleinP(*p)){
		for(int i = sizeCourante(*p); i > 0; i--){
			p->tab[i] = p->tab[i-1];
		}
		p->tab[0] = elt;
		p->eltSize++;
	}
}

void depiler(Pile *p){
	if(!estVideP(*p)){
		for(int i = 1; i < sizeCourante(*p); i++){
			p->tab[i-1] = p->tab[i];
		}
		p->tab[sizeCourante(*p)-1] = 0;
		p->eltSize--;
	}
}

void afficher(Pile p){
	printf("\nla taille de la pile: %d\n", sizeCourante(p));
	for(int i = 0; i < sizeCourante(p); i++){
		printf("%d -> ", p.tab[i]);
	}
}

int main(int argc, char const *argv[])
{
	Pile p = initPile();

	TElement donnees[5] = {55,66,77,88,99};

	empilerV(donnees[0],&p);
	for(int i = 1; i < 5; i++){
		empiler(donnees[i],&p);
	}

	afficher(p);

	for(int i = 0; i < 3; i++){
		depiler(&p);
	}

	afficher(p);


	return 0;
}


























