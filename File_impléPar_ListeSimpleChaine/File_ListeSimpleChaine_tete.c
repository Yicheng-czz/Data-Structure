#include<stdio.h>
#include<stdlib.h>

typedef int TElement;
typedef struct Cellule
{
	TElement donnee;
	struct Cellule *suivant;
}*Liste;


// initialise une file
Liste initFile(){
	return NULL;
}

// obtention l'adresse de suivant de la cellule
Liste suivant(Liste l){
	return l->suivant;
}

// obtention donnne de la cellule
TElement donnee(Liste l){
	return l->donnee;
}

// revoie vrai si la file est vide, faux sinon
int estVideF(Liste l){
	return l==NULL;
}

// retourner l'élément au sommet de la file si la file est non vide
// sans modifier l'etat de la file
Liste sommetFile(Liste l){
	if(!estVideF(l)){
		return l;
	}
	else{
		return NULL;
	}
}

// alloc memoire et remplir de 'elt'
Liste allocMemRempElt(TElement elt){
	Liste l = (Liste)malloc(sizeof(struct Cellule));
	l->donnee = elt;
	l->suivant = NULL;
	return l;
}

// Trouver l'adresse de la queue
Liste queue(Liste l){
	Liste ll = l;
	while(suivant(ll) != NULL){
		ll = suivant(ll);
	}
	return ll;
}

Liste emfilerV(TElement elt){
	Liste l = allocMemRempElt(elt);
	return l;
}


// ajout un élément en queue de la file si la n'est pas pleine
void emfiler(TElement elt, Liste l){
	Liste ll = allocMemRempElt(elt);
	
	Liste q = queue(l);
	q->suivant = ll;
	
}

// trouver la cellule qui est devant la queue
Liste celDevantQueue(Liste l){
	while(suivant(suivant(l)) != NULL){
		l = suivant(l);
	}
	return l;
}

// supprime de la file le premier élément si la file est non vide
void defiler(Liste l){
	Liste cel = celDevantQueue(l);
	Liste queue = suivant(cel);
	cel->suivant = NULL;
	free(queue);
	queue = NULL;
}

// afficher les donnees de la file
void afficher(Liste l){
	Liste ll = l;
	while(ll != NULL){
		printf("%d -> ",donnee(ll));
		ll = suivant(ll);
	}
}

int taille(Liste l){
	int somme = 0;
	Liste ll = l;
	while(ll != NULL){
		somme += 1;
		ll = suivant(ll);
	}
	return somme;
}


int main(int argc, char const *argv[])
{
	int donnees[3] = {22,33,55};
	Liste l = initFile();
	l = emfilerV(22);
	// printf("%d", donnee(l));
	for(int i = 1; i < 3; i++){
		emfiler(donnees[i],l);
	}
	
	afficher(l);
	printf("\nla taille de la file: %d\n",taille(l));

	Liste sommet = sommetFile(l);
	printf("\ndonnee de sommet : %d\n", donnee(sommet));

	defiler(l);
	afficher(l);
	printf("\nla taille de la file apres deplier : %d\n",taille(l));
	return 0;
}































