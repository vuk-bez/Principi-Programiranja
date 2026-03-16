#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AKO if
#define DOK while
#define VRATI return

void ASCII() {
    for (int i = 33; i < 128; i++) {
        printf("%3d = %c ", i, i);
        if ( i % 10 == 0)
            printf("\n");
    }
}

int mystrcmp(char s1[], char s2[]) {
    int i = 0;
    DOK (s1[i] != '\0' && s2[i] != '\0') {
        AKO (s1[i] < s2[i]) {
            VRATI -1;
        } else AKO (s1[i] > s2[i]) {
            VRATI 1;
        }
        i++;
    }
    AKO (s1[i] == '\0' && s2[i] == '\0') {
        VRATI 0;
    } else {
        VRATI -1;
    }
}

void mystrtok(char s[]) {
    //delim = " "
    char* prev = s;
    char* curr = strchr(s, ' ');
    char token[100];
    strncpy(token, prev, curr - prev);
    token[curr - prev] = '\0';
    printf("%s\n", token);
    while (curr != NULL) {
        prev = curr + 1;
        curr = strchr(prev, ' ');
        if (curr != NULL) {
            strncpy(token, prev, curr - prev);
            token[curr - prev] = '\0';
        }
        else {
            strcpy(token, prev);
        }
        printf("%s\n", token);

    }
}

int main() {

    char s1[100] = "abc";
    char s2[100] = "Abc";
    // za provjeru jesu li stringovi isti, ako vrati 0 jesu
    printf("%d\n", mystrcmp(s1, s2));
    //ASCII();
    char s3[100] = "jabuke banane maline kruske";


    // VEC UGRADJENA FUNKCIJA --- STRTOK
    /*char* token = strtok(s3, ", ");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ", ");
    }

    printf("%s\n", token); */

    // NASA CUSTOM MADE
    mystrtok(s3);

    //KOVERZIJE
    char s4[10] = "2026";
    int x = atoi(s4);
    printf("%d\n", x);

    int y;
    sscanf(s4, "%d", &y);
    printf("%d\n", y);

    VRATI 0;
}