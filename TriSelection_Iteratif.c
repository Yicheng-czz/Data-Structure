#include<stdio.h>

int indMin(int tete, int taille, int* tab){
	int min = tete;
	for(int i = tete+1; i < taille; i++){
		if(tab[i] < tab[min])  min = i;
	}
	return min;
}

void tri_Selection(int taille, int* tab){

	int iMin = 0, temp = 0;

	for(int i = 0; i < taille-1; i++){

		iMin = indMin(i, taille, tab);

		if(iMin != i){
			temp = tab[iMin];
			tab[iMin] = tab[i];
			tab[i] = temp;
		}

	}

}

void afficherTab(int taille, int* tab){
	for(int i =0; i < taille; i++){
		printf("%d -> ", tab[i]);
	}
}


int main(int argc, char const *argv[])
{
	
	int tableau[10] = {88,10,45,76,33,65,16,9,87,0};
	tri_Selection(10,tableau);
	afficherTab(10,tableau);

	return 0;
}