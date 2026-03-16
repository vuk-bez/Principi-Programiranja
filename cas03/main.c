#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stampa_matrice(int n, int m, int mat[][100]) { 
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void unos_matrice(int n, int m, int mat[][100]) { 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void rnd_matrice(int n, int m, int mat[][100]) { 
    srand(time(0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mat[i][j] = rand() % 10;
        }
    }
}
// prvi zadatak za prikazivanje pomjeraja kroz niza
void lokalMaksimum(int m, int n, int a[][100]) {
    
    
    int di[] = {-1,-1,-1,0,0,1,1,1}; //pomjeraj po i
    int dj[] = {-1,0,1,-1,1,-1,0,1}; //pomjeraj po j
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
            int jesteMax = 1;
            for(int k = 0; k < 8 ; k++) {
                int si = i + di[k];
                int sj = j + dj[k]; 
                if (si >= 0 && si < m && sj >=0 && sj < n) {
                    if(a[si][sj] >= a[i][j]){
                        jesteMax = 0;
                        break;
                    }
                }
                
            }
            if(jesteMax == 1) 
            printf("%d ", a[i][j]);  
        }
    }
}
// popunjavanje matrice spiralno
int** spiralnaMatrica(int m, int n) {
    int ** a = alociraj_matricu(m,n);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    int br = 1; 
    int i = 0;
    int j = 0;
    int smjer = 0;

    while(br <= m*n) {
        a[i][j] = br;
        br++;

        if(smjer == 0) {
            if(j + 1 < n && a[i][j+1] == 0){
                j++;
            } else {
                smjer = 1;
                i++;
            }
        } else if(smjer == 1) {
            if(i + 1 < m && a[i+1][j] == 0){
                i++;
            } else {
                smjer = 2;
                j--;
            }
        } else if(smjer == 2) {
            if(j-1 >= 0 && a[i][j-1] == 0){
                j--;
            } else {
                smjer = 3;
                i--;
            }
        } else if(smjer == 3) {
            if(i-1 >= 0 && a[i-1][j] == 0){
                i--;
            } else {
                smjer = 0;
                j--;
            }
        }
    }
    return a;
}
int main() {

    int b[100][100];
    int m = 4;
    int n = 5;
    //rnd_matrice(m,n,a);
    //stampa_matrice(m,n,a);
    //lokalMaksimum(m,n,a);

    int** a = spiralnaMatrica(m,n);
    stampa_matrice(m,n,a);

    // sa 4 for petlje koje uparuju I J pocetak sa I J kraj

    return 0;
}