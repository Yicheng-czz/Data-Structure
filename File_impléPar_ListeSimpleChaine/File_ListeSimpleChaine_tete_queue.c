#include<stdio.h>
#include<stdlib.h>

typedef int TElement;
typedef struct Cellule{
	TElement donnee;
	struct Cellule *suivant;
}*Cel;

struct Liste
{
	struct Cellule *tete;
	struct Cellule *queue;
};

int estVideF(struct Liste l){
	if(l.tete == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

int estPleinF(struct Liste l){
	return 0;
}

TElement donnee(Cel c){
	return c->donnee;
}

struct Liste initFile(){
	struct Liste l;
	l.tete = NULL;
	l.queue = NULL;
	return l;
}

Cel sommetFile(struct Liste l){
	return l.tete;
}

Cel queueFile(struct Liste l){
	return l.queue;
}

Cel suivant(Cel c){
	return c->suivant;
}

Cel allocMemRempElt(TElement elt){
	Cel cel;
	cel = (Cel)malloc(sizeof(struct Cellule));
	cel->donnee = elt;
	cel->suivant = NULL;
	return cel;
}

struct Liste enfilerV(TElement elt){
	struct Liste l;
	Cel c = allocMemRempElt(elt);
	l.tete = l.queue = c;
	return l;
}

void enfiler(TElement elt, struct  Liste *l){
	Cel c = allocMemRempElt(elt);
	l->queue->suivant = c;
	l->queue = c;
}

Cel celDevantQueue(struct Liste l){
	Cel t = sommetFile(l);
	Cel q = queueFile(l);
	while(suivant(t) != q){
		t = suivant(t);
	}
	return t;
}

void defiler(struct Liste *l){
	Cel c = celDevantQueue(*l);
	Cel q = suivant(c);
	c->suivant = NULL;
	l->queue = c;
	free(q);
	q = NULL;
}

void afficher(struct Liste l){
	Cel c = sommetFile(l);
	do{
		printf("%d -> ",donnee(c));
		c = suivant(c);
	}while(c != NULL);
}

int main(int argc, char const *argv[])
{
	struct Liste l = initFile();
	int tab[3] = {66,77,88};
	l = enfilerV(tab[0]);
	for(int i = 1; i < 3; i++){
		enfiler(tab[i], &l);
	}

	afficher(l);

	return 0;
}



































