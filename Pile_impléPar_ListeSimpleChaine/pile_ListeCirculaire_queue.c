#include<stdio.h>
#include<stdlib.h>

typedef int TElement;
typedef struct cellule{

	TElement donnee;
	struct cellule *suivant;

}*Cel;


Cel initPile(){
	return NULL;
}

int estVide(Cel c){
	return c==NULL;
}

int estPlein(Cel c){
	return 0;
}

Cel suivant(Cel c){
	return c->suivant;
}

TElement donnee(Cel c){
	return c->donnee;
}

Cel sommetPile(Cel c){
	return suivant(c);
}

Cel allocMemRempElt(TElement elt){
	Cel c = (Cel)malloc(sizeof(struct cellule));
	c->donnee = elt;
	c->suivant = NULL;
	return c;
}

Cel empilerV(TElement elt){
	Cel c = allocMemRempElt(elt);
	c->suivant = c;
	return c;
}

void empiler(TElement elt, Cel c){
	Cel n = allocMemRempElt(elt);
	Cel sc = sommetPile(c);
	c->suivant = n;
	n->suivant = sc;
}

void depiler(Cel c){
	Cel s = sommetPile(c);
	Cel ss = suivant(s);
	if(s==ss){
		free(s);
		c = NULL;
	}
	else{
		c->suivant = ss;
		free(s);
		s = NULL;
	}
}


void afficher(Cel c){
	Cel p = suivant(c);
	Cel pp = suivant(c);
	do{
		printf("%d -> ",donnee(p));
		p = suivant(p);
	}while(p != pp);
}


int main(int argc, char const *argv[])
{
	
	Cel c = initPile();

	TElement donnees[5] = {55,66,77,88,99};

	c = empilerV(donnees[0]);

	for(int i = 1; i < 5; i++){
		empiler(donnees[i],c);
	}

	afficher(c);

	return 0;
}


























