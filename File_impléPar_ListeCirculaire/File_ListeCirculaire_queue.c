#include<stdio.h>
#include<stdlib.h>

// la cellule courante est la queue
// le suivant de la cellule courante est la tete
typedef int TElement;
typedef struct Cellule{

	TElement donnee;
	struct Cellule *suivant;

}*Liste;


Liste initFile(){
	return NULL;
}

Liste suivant(Liste l){
	return l->suivant;
}

TElement donnee(Liste l){
	return l->donnee;
}

int estVideF(Liste l){
	return l==NULL;
}

int estPleinF(Liste l){
	return 0;
}

Liste sommetFile(Liste l){
	return suivant(l);
}

Liste allocMemRempElt(TElement elt){
	Liste n = (Liste)malloc(sizeof(struct Cellule));
	n->suivant = n;
	n->donnee = elt;
	return n;
}

Liste enfilerV(TElement elt){
	Liste l = allocMemRempElt(elt);
	return l;
}


Liste enfiler(TElement elt, Liste l){
	Liste n = allocMemRempElt(elt);
	Liste t = suivant(l);
	l->suivant = n;
	n->suivant = t;
	return n;
}

void defiler(Liste l){
	Liste t = suivant(l);
	Liste tt = suivant(t);
	l->suivant = tt;
	free(t);
	t = NULL;
}

void afficher(Liste l){
	Liste ll = l;
	do{
		printf("%d -> ",donnee(ll));
		ll = suivant(ll);
	}while(l != ll);
}


int main(int argc, char const *argv[])
{
	
	Liste l = initFile();

	int tab[5] = {55,66,77,88,99};

	l = enfilerV(tab[0]);
	for(int i = 1; i < 5; i++){
		l = enfiler(tab[i],l);
	}

	afficher(l);

	return 0;
}


































