#include<stdio.h>
#include<stdlib.h>

int* Fusion(int tailleA, int tailleB, int* tabA, int* tabB){
    int* tabFusion = (int*)malloc(sizeof(int)*(tailleA+tailleB));
    int i = 0,j = 0,k = 0;
    while(i < tailleA && j < tailleB){
        if(tabA[i] < tabB[j]){
            tabFusion[k] = tabA[i];
            ++i;
        }
        else{
            tabFusion[k] = tabB[j];
            ++j;
        }
        ++k;
    }
    while(i < tailleA){
        tabFusion[k] = tabA[i];
        ++i;
        ++k;
    }
    while(j < tailleB){
        tabFusion[k] = tabB[j];
        ++j;
        ++k;
    }
    return tabFusion;

}

void afficherTab(int taille, int* tab){
    for(int i = 0; i < taille; i++){
        printf("%d -> ", tab[i]);
    }
}

int main(){

    int tableauA[5] = {34,55,67,90,101};
    int tableauB[5] = {0,50,56,81,90};
    int* tableauFusion = Fusion(5,5,tableauA,tableauB);
    afficherTab(10,tableauFusion);

    return 0;

}