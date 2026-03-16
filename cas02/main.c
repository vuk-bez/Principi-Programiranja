#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stampa_matrice(int n, int m, int** mat) { 
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void unos_matrice(int n, int m, int** mat) { 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void rnd_matrice(int n, int m, int** mat) { 
    srand(time(0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mat[i][j] = rand() % 10;
        }
    }
}

int** PomnoziMn(int** a, int** b, int n, int m, int q) {
    
    int** c = malloc(sizeof(a));
    for(int i = 0; i < sizeof(a); i++) {
        c[i] = malloc(sizeof(a[0]));
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < q; j++) {
            int s = 0;
            for(int k = 0; k < m; k++) {
                s += a[i][k] * b[k][j];
            }
            c[i][j] = s;
        }
    }

    return c;
}

void sortirajVrste(int n, int m, int** a) {

    for(int i = 0; i < n; i++) {  
        for(int j = 0; j < m-1; j++) {
            int min_indx = j;
            for(int k = j+1; k < m; k++){
                if(a[i][k] < a[i][min_indx]) {
                    min_indx = k;
                }
            }
            int temp = a[i][j];
            a[i][j] = a[i][min_indx];
            a[i][min_indx] = temp;
        }
    }
}

int** rotacija90(int n, int** a) {

    int** c = malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++) {
        c[i] = malloc(n*sizeof(int));
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            c[j][n-i-1] = a[i][j];      
        }
    }

    return c;
}
/*
 za vjezbu:
 
 suma/min/max kolona i vrsta
 sortiranje vrsta ili kolona
 transponovanje, flip, rotacije matrice
*/
int main() {
    
    int n, m;
    
    printf("Unesite redom dimenzije matrica (n, m): \n");
    scanf("%d%d", &n, &m);

    int** a = malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++) {
        a[i] = malloc(m*sizeof(int));
    }

    /* int** b = malloc(p*sizeof(int*));
    for(int i = 0; i < p; i++) {
        b[i] = malloc(q*sizeof(int));
    }*/

    rnd_matrice(n, m, a);
   // rnd_matrice(p, q, b);

    stampa_matrice(n, m, a);
    printf("\n");
    //sortirajVrste(n, m, a);
    
    stampa_matrice(n, m, rotacija90(n, a));
   // printf("\n");
   //stampa_matrice(n, q, PomnoziMn(a, b, n, m, q));
  
    return 0;
}