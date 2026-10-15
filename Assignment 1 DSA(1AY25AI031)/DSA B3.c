#include <stdio.h>

typedef struct {
    int degree;
    float coef[101];
} polynomial;

polynomial add(polynomial a, polynomial b) {
    polynomial c;
    int i;

    if (a.degree > b.degree)
        c.degree = a.degree;
    else
        c.degree = b.degree;

    for (i = 0; i <= c.degree; i++) {
        int exp = c.degree - i;

        float x = 0, y = 0;

        if (exp <= a.degree)
            x = a.coef[a.degree - exp];

        if (exp <= b.degree)
            y = b.coef[b.degree - exp];

        c.coef[i] = x + y;
    }

    return c;
}

void display(polynomial p) {
    int i, exp, first = 1;

    for (i = 0; i <= p.degree; i++) {
        exp = p.degree - i;

        if (p.coef[i] == 0)
            continue;

        if (!first) {
            if (p.coef[i] > 0)
                printf(" + ");
            else
                printf(" - ");
        } else if (p.coef[i] < 0) {
            printf("-");
        }

        float value = p.coef[i];
        if (value < 0)
            value = -value;

        if (exp == 0)
            printf("%g", value);
        else if (exp == 1)
            printf("%gx", value);
        else
            printf("%gx^%d", value, exp);

        first = 0;
    }

    if (first)
        printf("0");

    printf("\n");
}

int main() {
    polynomial a, b, c;
    int i;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &a.degree);

    printf("Enter coefficients from highest degree to constant:\n");
    for (i = 0; i <= a.degree; i++)
        scanf("%f", &a.coef[i]);

    printf("Enter degree of second polynomial: ");
    scanf("%d", &b.degree);

    printf("Enter coefficients from highest degree to constant:\n");
    for (i = 0; i <= b.degree; i++)
        scanf("%f", &b.coef[i]);

    printf("\nFirst polynomial: ");
    display(a);

    printf("Second polynomial: ");
    display(b);

    c = add(a, b);

    printf("Sum of polynomials: ");
    display(c);

    return 0;
}

