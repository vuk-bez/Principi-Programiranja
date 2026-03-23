#include <stdio.h>
#include <string.h>

//zadaci iz fajla string 3

// ZAD 2.
// DNK sekvenca se predstavlja kao string sastavljen od karaktera 'A', 'T', 'G' i 'C'. Za parove karaktera 'A' i
// 'T', odnosno za 'G' i 'C', kažemo da su komplementarni. Za DNK sekvencu kažemo da je
// samokomplementarna ako se njenim okretanjem sa kraja prema početku, a zatim zamjenom svakog karaktera
// njemu komplementarnim karakterom, dobija sama izvorna sekvenca. Na primjer, sekvenca "ACGT" je
// samokomplementarna, jer njeno okretanje daje "TGCA", a zatim se zamjenama 'A' -> 'T', 'T' -> 'A', 'G' -> 'C'
// i 'C' -> 'G' dobija izvorno "ACGT". Napisati C program koji učitava string koji predstavlja DNK sekvencu, a
// zatim pronalazi i štampa njenu najdužu samokomplementarnu podsekvencu (podstring).

void zad2() {

    char ulaz[100];
    scanf("%s", ulaz);

    int n = strlen(ulaz); // duzina stringa po karakterima
    for (int k = n; k >= 0; k--) {
        for (int i = 0; i < n-k+1; i++) {
            char substr[100];
            char tmp[100];
            strncpy(substr, ulaz+i, k);
            substr[k] = '\0';
            strncpy(tmp, ulaz+i, k);
            tmp[k] = '\0';

            for (int j = 0; j < k/2; j++) {
                char c = tmp[j];
                tmp[j] = tmp[k-1-j];
                tmp[k-1-j] = c;
            }
            for (int j = 0; j < k; j++) {
                if (tmp[j] == 'A') tmp[j] = 'T';
                else if (tmp[j] == 'G') tmp[j] = 'C';
                else if (tmp[j] == 'T') tmp[j] = 'A';
                else if (tmp[j] == 'C') tmp[j] = 'G';
            }

            if (strcmp(substr, tmp) == 0) {
                printf("%s\n", substr);
                return;
            }
        }
    }
}

//ZAD 4.
// Neka je data rečenica koja se sastoji isključivo od malih slova i praznina (razmaka). Napisati C program
// koji učitava takav string, a zatim u svakoj riječi iz unijete rečenice okreće redosljed samoglasnika. Riječi u
// rečenici su razdvojene prazninama.

void zad4() {
    char recenica[100];
    char izlaz[100] = ""; //inicijalizujemo prazan string
    gets(recenica); //ucitava string do prvog novog reda

    char* rijec = strtok(recenica, " ");
    while (rijec != NULL) {

        strcat(izlaz, rijec);
        strcat(izlaz, " ");
        
        rijec = strtok(NULL, " ");
    }

}

int main() {

    //zad2();
    zad4();

    return 0;
}