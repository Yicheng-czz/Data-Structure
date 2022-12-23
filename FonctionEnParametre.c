#include<stdio.h>


typedef int TElement;
#define DIM 5

int OperatBinaire(int x, int y, int (*f)(int, int) ){

	/*appel de f sur les arguments x et y*/
	return ((*f)(x,y) ) ;

}

int somme(int a, int b){

	return(a+b);

}

int diff(int a, int b){

	return(a-b);

}

int produit(int a, int b){

	return (a*b);

}

// b !=0
int division(int a, int b){

	return (a/b);

}

int modulo(int a, int b){

	return (a%b);
}

// Pointeur d'une fonction
int recherche(int n,TElement* tab,TElement elt, int(*comp)( TElement, TElement) ) {

	int i;
	tab[n]=elt;
	i=0; 
	while(!((*comp)(elt,tab[i]))){
		i++;
	}
	return i<n;
}


int main(int argc, char const *argv[])
{
	
	// printf(" %d \n", OperatBinaire(3,4,somme));
	// printf(" %d \n", OperatBinaire(3,4,produit));
	// printf(" %d \n", OperatBinaire(3,4,diff));
	// printf(" %d \n", OperatBinaire(3,4,division));


	// un tableau dont le type d'element est pointeur de fonction
	int (*tabOperat[DIM])() = {somme, produit, diff, division, modulo};
	int choix,i,j;

	printf("Entrez le premier entier : ");

	scanf(" %d",&i);

	printf("\nEntrez le deuxième entier : "); scanf(" %d",&j);

	printf("\nEntrez la fonction 1 somme 2 diff 3 prod 4 quotient 5 modulo : ");

	scanf(" %d",&choix);

	if ((choix > 0) && (choix <= 5)) 
		printf("\n Résultat : %d.\n",(*(tabOperat[choix-1]))(i,j));
	else 
		printf("\n Mauvais numéro de fonction.\n");

	return 0;
}























