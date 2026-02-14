#include <stdio.h>

int main() {
    FILE *ptr1, *even, *odd;
    int arr[10];
    int ch;
 ptr1 = fopen("number.txt", "w");
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        fprintf(ptr1, "%d\n", arr[i]);
    }
    fclose(ptr1);
    ptr1 = fopen("number.txt", "r");
    even = fopen("even.txt", "w");
    odd = fopen("odd.txt", "w");

    while (fscanf(ptr1, "%d", &ch) != EOF) {
        if (ch % 2 == 0) {
            fprintf(even, "%d\n", ch);  
        } else {
            fprintf(odd, "%d\n", ch);    
        }
    }
    fclose(ptr1);
    fclose(even);
    fclose(odd);

    printf("Numbers separated into even.txt and odd.txt\n");

    return 0;
}
