#include<stdio.h>
#include<stdlib.h>

typedef int TElement;
typedef struct cellule
{
	TElement donnee;
	struct cellule *suivant;
}*Cel;

Cel initPile(){
	return NULL;
}

Cel initFile(){
	return NULL;
}

Cel suivant(Cel c){
	return c->suivant;
}

Cel allocMemRempElt(TElement elt){
	Cel c = (Cel)malloc(sizeof(struct cellule));
	c->donnee = elt;
	c->suivant = NULL;
	return c;
}

TElement donnee(Cel c){
	return c->donnee;
}

int estVide(Cel c){
	return c==NULL;
}

int estPlein(Cel c){
	return 0;
}

Cel sommetPile(Cel c){
	return suivant(c);
}

Cel empilerV(TElement elt){
	Cel c = allocMemRempElt(elt);
	c->suivant = c;
	return c;
}

void empiler(TElement elt, Cel c){
	Cel n = allocMemRempElt(elt);
	Cel s = sommetPile(c);
	c->suivant = n;
	n->suivant = s;
}

Cel emfilerV(TElement elt){
	Cel n = allocMemRempElt(elt);
	n->suivant = n;
	return n;
}

void emfiler(TElement elt, Cel c){
	Cel n = allocMemRempElt(elt);
	Cel t = suivant(c);
	n->suivant = t;
	c->suivant = n;
}

void afficherPile(Cel c){
	Cel p = suivant(c);
	Cel pp = p;
	printf("\n afficher la Pile:\n");
	do{
		printf("%d -> ",donnee(pp));
		pp = suivant(pp);
	}while(pp != p);
}

void afficherFile(Cel c){

	Cel t = suivant(c);
	Cel tt = t;
	printf("\n afficher le File:\n");
	do{
		printf("%d -> ",donnee(tt));
		tt = suivant(tt);
	}while(tt != t);

}

int main(int argc, char const *argv[])
{
	TElement donnees[5] = {55,66,77,88,99};

	Cel p = initPile();
	Cel f = initFile();

	p = empilerV(donnees[0]);
	f = emfilerV(donnees[0]);

	for(int i = 1; i < 5; i++){
		empiler(donnees[i],p);
		emfiler(donnees[i],f);
	}

	afficherPile(p);
	afficherFile(f);

	return 0;
}






































