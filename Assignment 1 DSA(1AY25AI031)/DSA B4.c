#include <stdio.h>

typedef struct {
    int row, col, value;
} term;

void fast_transpose(term a[], term b[]) {
    int row_terms[20], starting_pos[20];
    int i, j, num_cols;

    num_cols = a[0].col;

    // Initialize row_terms
    for (i = 0; i < num_cols; i++)
        row_terms[i] = 0;

    // Count terms in each column of original matrix
    for (i = 1; i <= a[0].value; i++)
        row_terms[a[i].col]++;

    // Calculate starting positions
    starting_pos[0] = 1;

    for (i = 1; i < num_cols; i++)
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

    // Print row_terms and starting_pos
    printf("\nrow_terms[]:\n");
    for (i = 0; i < num_cols; i++)
        printf("%d ", row_terms[i]);

    printf("\nstarting_pos[]:\n");
    for (i = 0; i < num_cols; i++)
        printf("%d ", starting_pos[i]);

    // Create transposed triples
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    for (i = 1; i <= a[0].value; i++) {
        j = starting_pos[a[i].col];

        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;

        starting_pos[a[i].col]++;
    }
}

int main() {
    term a[100], b[100];
    int matrix[20][20];
    int rows, cols, i, j, k = 1;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);

            if (matrix[i][j] != 0) {
                a[k].row = i;
                a[k].col = j;
                a[k].value = matrix[i][j];
                k++;
            }
        }
    }

    // Header of original sparse matrix
    a[0].row = rows;
    a[0].col = cols;
    a[0].value = k - 1;

    printf("\nOriginal matrix triples:\n");
    printf("Row Col Value\n");
    for (i = 0; i < k; i++)
        printf("%3d %3d %5d\n",
               a[i].row, a[i].col, a[i].value);

    fast_transpose(a, b);

    printf("\nTransposed triples:\n");
    printf("Row Col Value\n");
    for (i = 0; i <= b[0].value; i++)
        printf("%3d %3d %5d\n",
               b[i].row, b[i].col, b[i].value);

    printf("\nThe transposed triples are in row-major order.\n");

    return 0;
}

