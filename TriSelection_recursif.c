#include<stdio.h>

int indMin(int tete, int taille, int* tab){
	int min = tete;
	for(int i = tete+1; i < taille; i++){
		if(tab[i] < tab[min]) min = i;
	}
	return min;
}


void TriSelection(int tete, int taille, int* tab){
	if(taille-tete < 2) return;
	int min = 0,temp = 0;

	min = indMin(tete,taille,tab);
	if(min != tete){
		temp = tab[tete];
		tab[tete] = tab[min];
		tab[min] = temp;
	}

	TriSelection(tete+1, taille, tab);

}

void afficherTab(int taille, int* tab){
	for(int i =0; i < taille; i++){
		printf("%d -> ", tab[i]);
	}
}



int main(int argc, char const *argv[])
{
	/* code */
	int tableau[10] = {88,10,45,76,33,65,16,9,87,0};
	TriSelection(0,10,tableau);
	afficherTab(10,tableau);
	return 0;
}