#include<stdio.h>
#include<stdlib.h>


void InsertionElt(int elt, int* tab, int i, int n){
	if(n==0 || i>n){
		tab[n] = elt;
	}
	else{
		int j;
		for(j=n;j>=i;j--){
			tab[j] = tab[j-1];
		}
		tab[j] = elt;
	}
}

void TriInsertion(int* tab, int i,int n){
	
	if(i<n){
		while(i>0){
			
			
			
		}
		
		InsertionElt(tab[i],tab,i);
		TriInsertion(tab, i+1,n);
	}
	
}

int main(int argc, char const *argv[])
{
	printf("hello! world\n");
	// Polynome p;
	// for(int i = 0; i < 10; i++){
	// 	p.tab[i].degree = i;
	// 	p.tab[i].coefficient = i+1;
	// }
	// for(int i = 0; i < 10; i++){
	// 	printf("%fx^%d+",p.tab[i].coefficient,p.tab[i].degree);
	// }

	int tab[11] = {44,77,33,9,11,67,89,51,95,1,0};
	int elt = 2;
	InsertionElt(elt,tab,11,10);
	for(int i = 0; i < 11; i++){
	 	printf("%d -> ", tab[i]);
	}
	// printf("\n\n\n");

//	 TriInsertion(tab,1,11);
//	 for(int i = 0; i < 11; i++){
//	 	printf("%d -> ", tab[i]);
//	 }


	// LC lc = initLC();
	// InsertLCV(lc,tab[0]);
	// for(int i = 1; i < 11; i++){
	// 	Insert(lc,tab[i]);
	// }
	// Cel c = tete(lc);
	// do{
	// 	printf("%d -> ", donnee(c));
	// 	c = suivant(c);
	// }while(c != tete(lc));
	

	// TriSelection Test
	// TriSelection(11,tab);
	// for(int i = 0; i < 11; i++){
	// 	printf("%d -> ", tab[i]);
	// }



	// Tri Fusion Test
	// TriFusion(0,10,tab);
	// for(int i = 0; i < 11; i++){
	// 	printf("%d -> ", tab[i]);
	// }



	// Tri Rapide Test
//	TriRapide(0,10,tab);
//	for(int i = 0; i < 11; i++){
//		printf("%d -> ", tab[i]);
//	}



	return 0;
}

