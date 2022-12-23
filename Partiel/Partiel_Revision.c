// Partiel 2021

#include<stdio.h>
#include<stdlib.h>

#define MAX 50


// IMPLÉMENTATION CONTIGUË VERSION 2
// (2)
typedef struct monome
{
	int degree;
	double coefficient;
}Monome;
typedef struct polynome
{
	Monome tab[MAX];
	int nombreElt;
	int MaxElt;
}Polynome;

// (3)Representation dynamique
// typedef struct monome
// {
// 	int degree;
// 	double coefficient;
// }Monome;
typedef struct MonomeTableau
{
	int nbEltsMax;
	int nbElts;
	Monome* tab;
}mTab;


// EXERCICE2
// 插入算法
// n : 当前数组中的数据个数
// elt : 需要插入的数据
// tab : 已经排好序的数组
void itInsertionElt(int elt, int* tab, int n){
	int i = n;

	while(i > 0 && elt<tab[i-1]){
		tab[i] = tab[i-1];
		--i;
	}
	tab[i] = elt;

}
void reInsertionElt(int elt, int *tab, int n){
	if(n==0){
		tab[0] = elt;
	}
	else{
		if(elt < tab[n-1]){
			tab[n] = tab[n-1];
			reInsertionElt(elt,tab,n-1);
		}
		else{
			tab[n] = elt;
		}
	}
}


// 插入排序（递归形式）
// n : 当前数组中的数据个数
// i : index=i的数据作为carte
void reTriInsertion(int* tab, int i,int n){
	if(i<n){
		itInsertionElt(tab[i],tab,i);
		reTriInsertion(tab, i+1,n);
	}
}

void itTriInsertion(int* tab, int n){
	int i = 1;
	while(i <=  n){
		reInsertionElt(tab[i],tab,i);
		i = i + 1;
	}
}

// Tri Fusion归并排序
void Fusionner(int indInf, int indMil, int indsup, int* tab);
void TriFusion(int indInf, int indsup, int* tab){
	if(indInf < indsup){
		int indMil = (indInf + indsup)/2;
		TriFusion(indInf, indMil, tab);
		TriFusion(indMil+1, indsup, tab);
		Fusionner(indInf,indMil,indsup,tab);
	}
}

void Fusionner(int indInf, int indMil, int indsup, int* tab){

	// construction de tab1
	int tab1[indMil-indInf+1+1];
	for(int i = indInf; i <= indMil; i++){
		tab1[i-indInf] = tab[i];
	}

	// consctruction de tab2
	int tab2[indsup-(indMil+1)+1+1];
	for(int i = indMil+1; i <= indsup; i++){
		tab2[i-(indMil+1)] = tab[i];
	}

	// mettre un sentinelle
	tab1[indMil-indInf+1] = 100000000;
	tab2[indsup-(indMil+1)+1] = 100000000;


	int t1 = 0;
	int t2 = 0;
	// fusionner
	for(int i = indInf; i <= indsup; i++){
		if(tab1[t1] <= tab2[t2]){
			tab[i] = tab1[t1];
			t1++;
		}
		else{
			tab[i] = tab2[t2];
			t2++;
		}
	}
}

// Fusion des deux tables triées
// indexT1, indexT2, indexTF 数组下标
int* reFusionSentinelle(int* tabF, int* tab1, int* tab2, int indexT1,int tailleT1, int indexT2, int tailleT2, int indexTF, int tailleTF){
	if(tailleT1 + tailleT2 == tailleTF){
		return tabF;
	}
	else if(tailleT1 == indexT1){
		tabF[indexTF] = tab2[indexT2];
		++tailleTF;
		++indexTF;
		++indexT2;
	}
	else if(tailleT2 == indexT2){
		tabF[indexTF] = tab1[indexT1];
		++tailleTF;
		++indexTF;
		++indexT1;
	}
	else{
		if(tab1[indexT1] < tab2[indexT2]){
			tabF[indexTF] = tab1[indexT1];
			++indexTF;
			++indexT1;
			++tailleTF;
		}
		else{
			tabF[indexTF] = tab2[indexT2];
			++indexTF;
			++indexT2;
			++tailleTF;
		}
	}
	return reFusionSentinelle(tabF,tab1,tab2,indexT1,tailleT1,indexT2,tailleT2,indexTF,tailleTF);
}


// Iteration: Fusion des deux tables triees
void itFusionSentinelle(int* tabF, int* tab1, int tailleT1, int* tab2, int tailleT2){
	int i = 0, j = 0, k = 0;
	while(k < tailleT1+tailleT1){
		if(i == tailleT1){
			tabF[k] = tab2[j];
			j++;
			k++;
		}
		else if(j == tailleT2){
			tabF[k] = tab1[i];
			i++;
			k++;
		}
		else{
			if(tab1[i] < tab2[j]){
				tabF[k] = tab1[i];
				k++;
				i++;
			}
			else{
				tabF[k] = tab2[j];
				k++;
				j++;
			}
		}
	}
}


// Tri Rapide快速排序
int partitionner(int indInf, int indsup, int* tab);
void permutation(int L, int K, int* tab);
void TriRapide(int indInf, int indsup, int* tab){
	if(indInf < indsup){
		int IndPivote = partitionner(indInf,indsup,tab);
		TriRapide(indInf,IndPivote-1,tab);
		TriRapide(IndPivote+1,indsup,tab);
	}
}

int partitionner(int indInf, int indsup, int* tab){
	int indPivote = indInf;
	int pivote = tab[indInf];
	int L = indInf+1;
	int K = indsup;
	while(L <= K){
		while(L<=K && tab[L] <= pivote){
			L++;
		}
		while(L<=K && tab[K] > pivote){
			K--;
		}
		if(L<K){
			permutation(L,K,tab);
			L++;
			K--;
		}
	}
	if(indPivote != K){
		permutation(indPivote, K, tab);
	}
	return K;
}

void permutation(int L, int K, int* tab){
	int temp = tab[L];
	tab[L] = tab[K];
	tab[K] = temp;
}

// Tri Selection选择排序
void TriSelection(int n, int* tab){
	int iMin = 0, Min = 0;
	for(int i = 0; i < n-1; i++){
		iMin = i;
		Min = tab[iMin];
		for(int j = i+1; j < n; j++){
			if(tab[j] < Min){
				iMin = j;
				Min = tab[iMin];
			}
		}
		if(i != iMin){
			int temp = tab[iMin];
			tab[iMin] = tab[i];
			tab[i] = temp;
		}
	}
}


// EXERCICE4
// (1)
typedef int TElement;
typedef struct cellule
{
	TElement donnee;
	struct cellule* suivant;
}*Cel;
typedef struct listC{
	Cel tete;
	Cel queue;
}*LC;

LC initLC(){
	LC l = (LC)malloc(sizeof(struct listC));
	l->tete = l->queue = NULL;
	return l;
}

Cel tete(LC lc){
	return lc->tete;
}
Cel queue(LC lc){
	return lc->queue;
}
Cel suivant(Cel c){
	return c->suivant;
}
// (2)
Cel allocMemRemp(TElement elt){
	Cel c = (Cel)malloc(sizeof(struct cellule));
	c->donnee = elt;
	c->suivant = c;
	return c;
}

void InsertLCV(LC lc, TElement elt){
	Cel c = allocMemRemp(elt);
	lc->tete = lc->queue = c;
}

TElement donnee(Cel cel){
	return cel->donnee;
}

void Insert(LC lc, TElement elt){
	Cel t = tete(lc);
	Cel q = queue(lc);
	Cel p = allocMemRemp(elt);
	printf("处理%d中：",elt);
	if(elt > donnee(q)){
		q->suivant = p;
		lc->queue = p;
		p->suivant = t;
		printf("比尾大");
	}
	else if(elt < donnee(t)){
		p->suivant = t;
		lc->tete = p;
		q->suivant = p;
		printf("比头小");
	}
	else{
		// trouver l'adresse d'insertion
		while(elt > donnee(suivant(t))){
			t = suivant(t);
		}
		p->suivant = suivant(t);
		t->suivant = p;
		printf("在中间");
	}
	printf("\n");
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

	// int tab[11] = {0,0,0,0,0,0,0,0,0,0,0};
	// int elt = 1;
	// InsertionElt(elt,tab,0);
	// for(int i = 0; i < 11; i++){
	// 	printf("%d -> ", tab[i]);
	// }
	// printf("\n\n\n");

	// TriInsertion(tab,1,10);
	// for(int i = 0; i < 11; i++){
	// 	printf("%d -> ", tab[i]);
	// }


	int tab1[6] = {77,90,43,1,9,45};
	// itTriInsertion(tab1,5);
	// 	for(int i = 0; i < 6; i++){
	// 	printf("%d -> ", tab1[i]);
	// }
	// printf("\n\n\n");



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
	TriFusion(0,5,tab1);
	for(int i = 0; i < 6; i++){
		printf("%d -> ", tab1[i]);
	}



	// Tri Rapide Test
	// TriRapide(0,10,tab);
	// for(int i = 0; i < 11; i++){
	// 	printf("%d -> ", tab[i]);
	// }



	// Fusion des deux tables triees
	// int tab1[5] = {1,6,9,66,99};
	// int tab2[3] = {0,2,87};
	// int tab3[8] = {0,0,0,0,0,0,0,0};

	// // int* tabF = reFusionSentinelle(tab3,tab1,tab2,0,5,0,3,0,0);
	// itFusionSentinelle(tab3,tab1,5,tab2,3);

	// for(int i = 0; i < 8; i++){
	// 	printf("%d -> ", tab3[i]);
	// }

	return 0;
}




























