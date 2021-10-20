#include <stdio.h>

void print_array(int* a, int n);
void read_array(int* a, int n);
int max(int* a, int n);
int max_pos(int* a, int n);
int search(int v, int* a, int n);
int prime_or_not(int n);
int prime(int n);
int eratosthene(int* tab, int n);


int main () {

    //Exercice 1
    
    int n = 3;
    int tab[n];
    print_array(tab, n);
    read_array(tab, n);
    print_array(tab, n);
	

    //Exercice 2
    
    printf("max = tab[%d] = %d\n",max_pos(tab,n),max(tab,n));
    printf("search(3) => tab[%d]\n", search(3,tab,n));

    //Exercice 3

    printf("Naïf vs Eratosthène : n = ");
    scanf("%d", &n);
    int tab2[n+1];
    printf("Naïf (n**2) : nombre de nombres premier dans [2,%d] = %d\n",n,prime(n));
    printf("Eratosthène (n) : nombre de nombres premier dans [2,%d] = %d\n",n,eratosthene(tab2, n+1));

}

void print_array(int* a, int n) {
    for(int i = 0 ; i < n ; i++)
	printf("%d ", a[i]);
    printf("\n");
}

void read_array(int* a, int n) {
    printf("Remplissez ce tableau primaire de %d éléments :\n", n);
    for(int i = 0 ; i < n ; i++) {
	printf("%d>",i);
	scanf("%d", &a[i]);
    }
}

int max(int* a, int n) {
    int maximum = 0;
    for(int i = 0 ; i < n ; i++) {
	if(maximum < a[i])
	    maximum = a[i];
    }
    return maximum;
}

int max_pos(int* a, int n) {
    int i_max = 0;
    for(int i = 0 ; i < n ; i++) {
	if(a[i_max] < a[i])
	    i_max = i;
    }
    return i_max;
}

int search(int v, int* a, int n) {
    for(int i = 0 ; i < n ; i++) {
	if(a[i] == v)
	    return i;
    }
    return -1;
}

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
	    //printf("%d\n", i);
	}
    }
    //printf("\n");
    return compteur;
}

int eratosthene(int* tab, int n) {
    int compteur = 0;
    for(int i = 2 ; i < n ; i++) {
	tab[i] = 1;
    }
    for(int i = 2 ; i < n ; i++) {
	if(tab[i] == 1) {
	    compteur++;
	    //printf("%d\n", i);
	    for(int j = i+i ; j < n ; j += i) {
		tab[j] = 0;
	    }
	}
    }
    //printf("\n");
    return compteur;
}


