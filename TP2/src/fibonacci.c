#include <stdio.h>

int main() {
    int n, i;
    unsigned long long a = 0, b = 1, next;

    printf("Entrez le nombre de termes de la suite de Fibonacci à afficher : ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Entrer un nombre entier positif.\n");
        return 1;
    }

    printf("Suite de Fibonacci jusqu'à U%d :\n", n - 1);

    for (i = 0; i < n; i++) {
        if (i == 0) {
            printf("%llu", a);
        } else if (i == 1) {
            printf(", %llu", b);
        } else {
            next = a + b;
            printf(", %llu", next);
            a = b;
            b = next;
        }
    }

    printf("\n");
    return 0;
}
