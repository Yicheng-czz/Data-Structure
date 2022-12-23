#include<stdio.h>

void partionner(int indinf, int indsup, int* tab){
    int indpivot = indinf, pivot = tab[indpivot], k = indsup, i = indinf+1;
    while(i < k){
        if(tab[i]<= pivot) ++i;
        if(tab[k]> pivot) --k;
    }
    
}

void triRapide(int indinf, int indsup, int* tab){

}




int main(){



    return 0;
}