#include <stdio.h>
#include <stdlib.h>

struct Book {
    char author[50];
    char title[50];
    float price;
};

int main() {
    struct Book b[100], temp;
    int n, i;

    FILE *fp;

    printf("Enter number of books: ");
    scanf("%d", &n);

    // Input books
    for (i = 0; i < n; i++) {
        printf("\nEnter details of book %d:\n", i+1);

        printf("Author name: ");
        scanf("%s", b[i].author);

        printf("Book title: ");
        scanf("%s", b[i].title);

        printf("Book price: ");
        scanf("%f", &b[i].price);
    }

    // Write to file
    fp = fopen("books.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fwrite(b, sizeof(struct Book), n, fp);
    fclose(fp);

    // Read back from file
    fp = fopen("books.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fread(b, sizeof(struct Book), n, fp);
    fclose(fp);

    // Find max and min price book
    struct Book maxBook = b[0];
    struct Book minBook = b[0];

    for (i = 1; i < n; i++) {
        if (b[i].price > maxBook.price)
            maxBook = b[i];

        if (b[i].price < minBook.price)
            minBook = b[i];
    }

    // Display results
    printf("\n===== Book with Maximum Price =====\n");
    printf("Author: %s\n", maxBook.author);
    printf("Title : %s\n", maxBook.title);
    printf("Price : %.2f\n", maxBook.price);

    printf("\n===== Book with Minimum Price =====\n");
    printf("Author: %s\n", minBook.author);
    printf("Title : %s\n", minBook.title);
    printf("Price : %.2f\n", minBook.price);

    return 0;
}
