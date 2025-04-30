#include <stdio.h>

int longueur(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void copier(char *dest, const char *src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }
}

void concatener(char *dest, const char *src) {
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }
    int j = 0;
    while ((dest[i] = src[j]) != '\0') {
        i++;
        j++;
    }
}

int main() {
    char chaine1[100];
    char chaine2[100];
    char copie[100];
    char concat[200];

    printf("Entrez la première chaîne : ");
    fgets(chaine1, sizeof(chaine1), stdin);

    printf("Entrez la deuxième chaîne : ");
    fgets(chaine2, sizeof(chaine2), stdin);

    int l1 = longueur(chaine1);
    if (chaine1[l1 - 1] == '\n') chaine1[l1 - 1] = '\0';

    int l2 = longueur(chaine2);
    if (chaine2[l2 - 1] == '\n') chaine2[l2 - 1] = '\0';

    printf("Longueur de la première chaîne : %d\n", longueur(chaine1));
    printf("Longueur de la deuxième chaîne : %d\n", longueur(chaine2));

    copier(copie, chaine1);
    printf("Copie de la première chaîne : %s\n", copie);

    copier(concat, chaine1);
    concatener(concat, chaine2);
    printf("Concaténation des deux chaînes : %s\n", concat);

    return 0;
}
