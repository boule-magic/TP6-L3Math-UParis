#include <stdio.h>

int prime_or_not(int n) {
    for(int i = 2 ; i*i <= n ; i++) {
	if(n%i == 0) {
	    return 0; //nombre composé
	}
    }
    return 1; //nombre premier
}

int prime(int n) {
    int compteur = 0;
    for(int i = 2 ; i < n ; i++) {
	if(prime_or_not(i) == 1) {
	    compteur++;
	}
    }
    return compteur;
}

int main() {
    int n = 1000000;
    printf("Naïf (n**2) : nombre de nombres premier dans [2,%d] = %d\n",n,prime(n));
}
