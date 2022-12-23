#include<stdio.h>

int tata(int n, int x, int* coef){
	if(n == 0){
		return 0;
	}
	else{
		int p = 1;
		for(int i = n; i >= 1; i--){
			p = p * x;
		}
		printf("p = %d\n", p);
		return p*coef[n-1] + tata(n-1, x, coef);
	}
}

int main(int argc, char const *argv[])
{
	int coef[10] = {1,2,3,4,5,6,7,8,9,10};

	int res = tata(10, 1, coef);
	printf("%d", res);
	return 0;
}