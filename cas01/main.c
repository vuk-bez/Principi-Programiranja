#include <stdio.h>
#include <stdlib.h>


void stampa_matrice(int n, int m, int** mat) { // dinamicka alokacija kao argument **
    for(int i = 0; i < n; i++) { // stampanje matrice
        for(int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void unos_matrice(int n, int m, int** mat) { 
    for(int i = 0; i < n; i++) { // stampanje matrice
        for(int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

int main() {
    
    int a[3][3]; // staticka alokacija matrice
    a[0][1] = 10;

    printf("%d \n", a[0][1]);

    int x = 10;
    int* x_ptr = &x; // pokazivac, & - za preuzimanje adrese
    printf("%p\n", x_ptr); // p - za stampanje adrese na koju pokazuje pokazivac

    printf("%p\n", a);
    
    a[0][0] = 15;
    printf("%d \n", **a); // ** - vraca vrijednost na adresi matrice (sto je pocetni element)

   /* int b[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    }; */

    int b[3][3] = {0}; // svi elementi se postaljaju na nulu
    
   

    int n = 5;
    int m = 2;
    int mat[n][m];
    unos_matrice(n,m,mat);
    stampa_matrice(n, m, mat);

    int** d = malloc(n * sizeof(int*)); // memory allocation  za dinamicko zadavanje matrica
    for(int i = 0; i < n; i++) {
       d[i] = malloc(m * sizeof(int)); // nastavak implementacije pointera
    }

    unos_matrice(d, m, n);
    stampa_matrice(d, m, n);

    for(int i = 0; i < n; i++) {
       free(d[i]); // oslobadjanje memorije za dinamicki zadane matrice
    }
    free(d); // oslobadjanje memorije

    return 0;
}