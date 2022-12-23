#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	double coef;
	int degree;
}Monome;

typedef struct cellule{
	Monome monome;
	struct cellule *suivant;
	struct cellule *precedent;
}*Polynome;

Polynome initP(){
	return NULL;
}

int estVideP(Polynome poly){
	return poly==NULL;
}

Monome monome(Polynome poly){
	return poly->monome;
}

double coef(Monome m){
	return m.coef;
}

int degree(Monome m){
	return m.degree;
}

Polynome suivant(Polynome poly){
	return poly->suivant;
}

Polynome precedent(Polynome poly){
	return poly->precedent;
}

// trouver un poly qui contient 'm'
Polynome rechMonPoly(Monome m, Polynome poly){
	while(!estVideP(poly) && monome(poly) != m){
		poly = suivant(poly);
	}
	return poly;
}

Monome consMonome(double coef, int degree){
	Monome m = {coef, degree};
	return m;
}

Polynome allocMemRemp(Monome m){
	Polynome poly = (Polynome)malloc(sizeof(struct cellule));
	poly->monome = m;
	return poly;
}

// suppression de 'm' dans 'poly'
Polynome supplMonPoly(Polynome poly, Monome m){
	Polynome as = rechMonPoly(m,poly);
	as->precedent->suivant = suivant(as);
	as->suivant->precedent = precedent(as);
	return poly;
}

Polynome delPolynome(Polynome poly){
	Polynome s = poly;
	Polynome ai = suivant(s);
	while(ai != NULL){
		free(s);
		s = ai;
		ai = suivant(ai);
	}
	free(s);
	return NULL;
}

// Trouver l'adresse de Insertion
// 'ai' est le Polynome avant le Polynome voulu supprime
Polynome adrInsertion(Monome m, Polynome p){
	Polynome ai = p;
	Polynome sai = suivant(ai);
	while(!estVideP(sai) && degree(m)>degree(monome(sai))){
		ai = sai;
		sai = suivant(ai);
	}
	return ai;
}



double maxCoef(Polynome poly){
	double max = coef(monome(poly));
	Polynome ai = suivant(poly);
	while(ai != NULL){
		if(coef(monome(ai)) > max){
			max = coef(monome(ai));
			ai = suivant(ai);
		}
	}
	return max;
}

double sommeCoef(Polynome poly){
	double somme = 0;
	while(poly != NULL){
		somme += coef(monome(poly));
		poly = suivant(poly);
	}
	return somme;
}

// void afficher(Polynome poly){
// 	Polynome pp = poly;
// 	char cc[50] = "";
// 	while(pp != NULL){
// 		cc = cc + str(degree(monome(pp)));
// 		if(coef(monome(pp)) != 0){
// 			cc = cc + "x" +str(coef(pp));
// 		}
// 		pp = suivant(pp);
// 	}
// 	printf("\n%s\n",cc);
// }

Polynome inserTetePV(Monome m){
	Polynome poly = allocMemRemp(m);
	poly->suivant = initP();
	poly->precedent = initP();
	return poly;
}

Polynome inserTeteP(Monome m, Polynome poly){
	Polynome cel = allocMemRemp(m);
	cel->suivant = poly;
	poly->precedent = cel;
	cel->precedent = initP();
	poly = cel;
	return poly;
}

Polynome der(Polynome poly){
	Polynome derCel = poly;
	while(suivant(derCel) != NULL){
		derCel = suivant(derCel);
	}
	return derCel;
}

Polynome inserQueue(Polynome poly, Polynome der, Monome m){
	Polynome cel = allocMemRemp(m);
	cel->suivant = initP();
	cel->precedent = der;
	der->suivant = cel;
	return poly;
}


int main(int argc, char const *argv[])
{
	double monomes[5][2] = {{13,1},{-2.5,2},{1,5},{2,8},{-7,13}};
	Monome m = {13,1};
	Polynome poly = initP();
	poly = inserTetePV(m);
	for(int i = 1; i < 5; i++){
		Monome m = monomes[i];
		poly = inserTeteP(m,poly);
	}
	//afficher(poly);

	return 0;
}


























































