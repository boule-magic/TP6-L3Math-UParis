#include <stdio.h>

int eratosthene(int* tab, int n) {
    int compteur = 0;
    for(int i = 2 ; i < n ; i++) {
	tab[i] = 1;
    }
    for(int i = 2 ; i < n ; i++) {
	if(tab[i] == 1) {
	    compteur++;
	    for(int j = i+i ; j < n ; j += i) {
		tab[j] = 0;
	    }
	}
    }
    return compteur;
}

int main() {
    int n = 1000000;
    int tab[n+1];
    printf("Eratosthène (n) : nombre de nombres premier dans [2,%d] = %d\n",n,eratosthene(tab, n+1));
}
