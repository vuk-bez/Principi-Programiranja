#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_uppercase(char s[]) {
    for(int i = 0; s[i] != '\0'; i++) {
       if(s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
    }
}

void my_copy(char s1[], char s2[]) {
    int i;
    for(i = 0; s1[i] != '\0'; i++) {
        s2[i] = s1[i];
    }
    s2[i] = '\0';
}

int main() {

    ///built-in funkcije iz string.h biblioteke, uz strncpy moramo i terminacioni dat
    char s1[10] = {'j', 'e', 'z', 'i', 'k', 'C', '\0'}; // terminacioni karakter --- \0
    printf("%s\n", s1);

    char s2[100] = "principi programiranja";
    printf("%s\n", s2);


    char* s3 = malloc(5);
    s3[0] = 'a';
    s3[1] = 'b';
    s3[2] = 'c';
    s3[3] = 'd';
    s3[4] = '\0';
    printf("%s\n", s3);
    free(s3);

    char* s4 = "principi programiranja"; //konstantni string --- nema promjene nakon unosa; (immutable string)
    printf("%s\n", s4);

    char s[100] = "programiranje 254 -";
    my_uppercase(s);
    printf("%s\n", s);

    char y[100];
    my_copy(s, y);
    printf("%s", y);

    return 0;
}