#include <stdio.h>

struct Book {
    char title[20];
    char author[20];
    float price;
};

void sortbyprice(struct Book b[], int n) {
    struct Book temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (b[j + 1].price < b[j].price) {
                temp = b[j + 1];
                b[j + 1] = b[j];
                b[j] = temp;
            }
        }
    }
}

void display(struct Book b) {
    printf("\nBook Details\n");
    printf("Book Name: %s\n", b.title);
    printf("Book Author: %s\n", b.author);
    printf("Book Price: %.2f\n", b.price);
}

int main() {
    struct Book b[5];
    int i, n;

    printf("Enter the number of books: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nBook No %d\n", i + 1);
        printf("Enter Title of the book: ");
        scanf(" %[^\n]%*c", b[i].title);
        printf("Enter Author of the book: ");
        scanf(" %[^\n]%*c", b[i].author);
        printf("Enter price of the book: ");
        scanf("%f", &b[i].price);
    }

    sortbyprice(b, n);

    for (i = 0; i < n; i++) {
        display(b[i]);
    }

    return 0;
}
