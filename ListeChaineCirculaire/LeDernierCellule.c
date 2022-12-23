#include<stdio.h>
#include<stdlib.h>
#define DIM 10

typedef int TElement;

typedef struct cellule{
	TElement donnee;
	struct cellule *suivant;
}*Liste;

//
Liste suivant(Liste l){
	return l->suivant;
}

TElement donnee(Liste l){
	return l->donnee;
}

Liste initLC(){
	return NULL;
}

int estVide(Liste l){
	return l==NULL;
}

Liste allocMemRempCel(TElement elt){
	Liste cel ; 
 	cel=(Liste)malloc(sizeof(struct cellule)) ; 
 	// tester l’allocation 
 	if (estVide(cel)) {
      	printf("\npb d’alloc mémoire") ; 
      	exit(1);
 	}
 	cel->donnee=elt ; 
 	return cel ; 
} 

Liste inserListeCV(TElement elt){ 
	Liste cel; 
 
	// Création de la cellule et remplissage du membre donne 
 	cel = allocMemRempCel(elt) ; 
 
 	//réalisation du chaînage 
 	cel->suivant = cel; 
 	return cel ; 
}

// ajouter un element
void ajoutElt(TElement elt, Liste l){
	
	Liste ai, cel;
	
	ai = suivant(l);
	cel = allocMemRempCel(elt) ;
	cel->suivant = ai;
	l->suivant = cel;
}


// remplir un LC par un tab
Liste rempliLC(TElement* tab, int tailleTab){
	int i;
	Liste l;
	l = inserListeCV(tab[0]);
	for(i = 1; i < tailleTab; i++){
		ajoutElt(tab[i], l);
	}
	return l;
}

// afficher un LC
void afficherLC(Liste l){
	Liste tmp = l;
	
	do{
		printf("%d -> ", donnee(tmp));
		tmp = suivant(tmp);
	}while(tmp != l);
}

int main(int argc, char const *argv[])
{
	Liste l;

	l = initLC();

	//printf("Initiliation est bonne");
	int tab[DIM] = {55,66,77,88,99}, n=5, i;
	printf("tab creer est bon");

	if (n>0)
		l = rempliLC(tab,n);

	afficherLC(l);
	printf("\n FIN \n");
	return 0;
}





















