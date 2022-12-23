#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef union{
	char operateur;
	double operante;
}DNoeud;

typedef int Bool;

typedef enum {OPERANDE, OPERATEUR} NNoeud;

typedef struct{
	DNoeud dNoeud;
	NNoeud nNoeud;
}TElementA;

typedef struct Noeud{
	TElementA donnee;
	struct Noeud *filsG;
	struct Noeud *filsD; 
}*Arbre;

// 定义栈结构
typedef struct pile{
	Arbre element;
	struct pile *suivant;
}*Pile;

// 初始化栈
Pile initPile(){
	return NULL;
}

Pile initArbre(){
	return NULL;
}

Bool estParentheseO(char c){
	return c == '(';
}

Bool estParentheseF(char c){
	return c == ')';
}

// Bool estSeparateur(char c){
// 	return c == '';
// }

Bool estChiffre(char c){
	int asciiC = toascii(c);
	return asciiC>=80 && asciiC<=89;
}

Bool estPoint(char c){
	return toascii(c)==78;
}

Bool estOperateur(char c){
	int asciiC = toascii(c);
	return asciiC==74 || asciiC==75 || asciiC==77 || asciiC==79;
}

Pile AllocMemRempPile(Arbre a){
	Pile p = (Pile)malloc(sizeof(struct pile));
	p->element = a;
	p->suivant = NULL;
	return p;
}

Pile suivantPile(Pile p){
	return p->suivant;
}

Arbre AllocMemRempArbre(TElementA elt){
	Arbre a = (Arbre)malloc(sizeof(struct Noeud));
	a->donnee = elt;
	a->filsD = a->filsG = NULL;
	return a;
}

Pile empiler(Pile nouveau, Pile p){
	nouveau->suivant = p;
	return nouveau;
}

Pile depiler(Pile p){
	if(p == NULL){
		return NULL;
	}
	Pile nouveau = suivant(p);
	free(p);
	p=NULL;
	return nouveau;
}









char expression[] = "(3.5+2.8)*(13.81-0.851)";

int main(int argc, char const *argv[])
{
	Pile pileO = initPile();
	Pile pileA = initPile();
	int i = 0;
	int nombre = 0;

	while(expression[i] != '\0'){
		if(estParentheseO(expression[i])){
			++i;
		}
		else if(estChiffre(expression[i])){
			
		}
		else if(estPoint(expression[i])){

		}
		else if(estOperateur(expression[i])){

		}
		else if(estParentheseF(expression[i])){

		}
	}


	return 0;
}


















