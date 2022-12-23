#include<stdio.h>
#include<stdlib.h>

typedef int TElement;
typedef struct cellule
{
	TElement donnee;
	struct cellule *suivant;
}*Liste;
typedef struct{
	Liste tete;
	Liste queue;
	int taille;
}ListeCTQ;

// obtention de la tete de LCTQ
Liste tete(ListeCTQ l){
	return l.tete;
}

// obtention de la suivant de Liste(l) donnée
Liste suivant(Liste l){
	return l->suivant;
}

// obtention de la queue de LCTQ
Liste queue(ListeCTQ l){
	return l.queue;
}

// obtention de la taille de LCTQ
int tailleLCTQ(ListeCTQ l){
	return l.taille;
}

// est vide ou non
int estVide(ListeCTQ l){
	return l.taille==0;
}

// obtention de donnee de cellule
TElement donnee(Liste l){
	return l->donnee;
}

// faire une initialisation de LCTQ
ListeCTQ initLCTQ(){
	ListeCTQ lctq;
	lctq.tete = NULL,
	lctq.queue = NULL;
	lctq.taille = 0;
	return lctq;
}

// allocation memoire pour un TElement
Liste allocMemRempTelt(TElement elt){
	Liste cel;
	cel = (Liste)malloc(sizeof(struct cellule));
	cel->donnee = elt;
	cel->suivant = cel;
	return cel;
}

// Insertion un cellule quand LCTQ est vide
void InserLCTQ_V(ListeCTQ *lctq, TElement num){
	Liste cel = allocMemRempTelt(num);
	lctq->tete = cel;
	lctq->queue = cel;
	lctq->taille += 1;
}

// Insertion un cellule quand LCTQ n'est pas vide
void InserLCTQ_queue(ListeCTQ *lctq, TElement num){
	Liste q = queue(*lctq);
	Liste t = tete(*lctq);
	Liste cel = allocMemRempTelt(num);
	q->suivant = cel;
	cel->suivant = t;
	lctq->queue = cel;
	lctq->taille += 1;
}

void afficher(ListeCTQ lctq){
	Liste l = tete(lctq);
	Liste tmp = l;
	do{
		printf("%d -> ",donnee(tmp));
		tmp = suivant(tmp);
	}while(tmp != l);
	printf("\n FIN \n");
}


int main(){

	ListeCTQ lctq = initLCTQ();
	TElement tab[5] = {1,3,5,7,9};
	InserLCTQ_V(&lctq,1);
	for(int i = 1; i < 5; i++){
		InserLCTQ_queue(&lctq, tab[i]);
	}
	afficher(lctq);

	return 0;
}

