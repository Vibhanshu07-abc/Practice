#include <stdio.h>

int main() {
    int r, c, p, q, i, j;

    printf("Enter the number of rows of 1st matrix: ");
    scanf("%d", &r);
    printf("Enter the number of columns of 1st matrix: ");
    scanf("%d", &c);

    int a[r][c]; // Declare the first matrix
    printf("Enter the elements of 1st matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of rows of 2nd matrix: ");
    scanf("%d", &p);
    printf("Enter the number of columns of 2nd matrix: ");
    scanf("%d", &q);

    int b[p][q]; // Declare the second matrix
    printf("Enter the elements of 2nd matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    if (c != p) {
        printf("Cannot multiply: Number of columns of the first matrix must equal the number of rows of the second matrix.\n");
        return 1; // Exit with an error code
    } else {
        int res[r][q]; // Declare the result matrix
        for (i = 0; i < r; i++) {
            for (j = 0; j < q; j++) {
                res[i][j] = 0; // Initialize the result matrix element to zero

                // Perform multiplication
                for (int k = 0; k < c; k++) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }

    // Print the result
    printf("The result is:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0; // Return success
}
