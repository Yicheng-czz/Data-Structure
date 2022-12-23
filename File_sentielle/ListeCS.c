#include<stdio.h>
#include<stdlib.h>

#define MAX 1000000;
typedef int TElement;
typedef struct cellule{

	TElement donnee;
	struct cellule *suivant;

}*ListeCS;

ListeCS allocMemRemp(elt){
	ListeCS lcs = (ListeCS)malloc(sizeof(struct cellule));
	lcs->donnee = elt;
	lcs->suivant = lcs;
	return lcs;
}

ListeCS initFile(){
	ListeCS lcs = allocMemRemp(-1);
	return lcs; 
}

ListeCS suivant(ListeCS lcs){
	return lcs->suivant;
}

TElement donnee(ListeCS lcs){
	return lcs->donnee;
}

int estVide(ListeCS lcs){
	return suivant(lcs)==lcs;
}

ListeCS sommetFile(ListeCS lcs){
	return suivant(lcs);
}

ListeCS dernier(ListeCS lcs){
	ListeCS ll = lcs;
	while(suivant(ll) != lcs){
		ll = suivant(ll);
	}
	return ll;
}

void emfiler(TElement elt, ListeCS lcs){
	ListeCS der = dernier(lcs);
	ListeCS l = allocMemRemp(elt);
	der->suivant = l;
	l->suivant = lcs;
}

void defiler(ListeCS lcs){
	ListeCS t = suivant(lcs);
	lcs->suivant = suivant(t);
	free(t);
	t = NULL;
}

void afficherLCS(ListeCS lcs){
	printf("\nAffichage de la LCS:\n");
	ListeCS ll = lcs;
	do{
		printf("%d -> ",donnee(ll));
		ll = suivant(ll);
	}while(ll != lcs);
}

void afficherTab(TElement *tab, int taille){
	printf("\nAffichage de la tableau:\n");
	for(int i = 0; i < taille; i++){
		printf("%d -> ",tab[i]);
	}
}

// lcs是头
ListeCS adrInserEltLT(TElement elt, ListeCS lcs){
	ListeCS ll = lcs;
	while(suivant(ll) != lcs && elt>donnee(suivant(ll))){
		ll = suivant(ll);
	}
	return ll;
}

void inserTriee(TElement elt,ListeCS lcs){
	ListeCS ai = adrInserEltLT(elt,lcs);
	ListeCS cel = allocMemRemp(elt);
	cel->suivant = suivant(ai);
	ai->suivant = cel;
}


int main(int argc, char const *argv[])
{
	
	ListeCS lcs = initFile();

	TElement donnees[5] = {99,33,66,77,11};

	for(int i = 0; i < 5; i++){

		inserTriee(donnees[i],lcs);
		
	}

	afficherLCS(lcs);

	for(int i = 0; i < 5; i++){
		TElement d = donnee(sommetFile(lcs));
		donnees[i] = d;
		defiler(lcs);
	}

	afficherTab(donnees,5);

	

	return 0;
}




























