#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bookstore.h"
#include "storage.h"

#define DATA_FILE "books.txt"

int main() {
    Bookstore store;
    initBookstore(&store);

    loadFromFile(&store, DATA_FILE);

    int choice;
    do {
        printf("\n===== Bookstore Menu =====\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Remove Book\n");
        printf("4. Save & Exit\n");
        printf("==========================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            Book b;
            printf("Enter ID: "); scanf("%d", &b.id);
            printf("Enter Title: "); getchar(); fgets(b.title, TITLE_LEN, stdin);
            b.title[strcspn(b.title, "\n")] = '\0';
            printf("Enter Author: "); fgets(b.author, AUTHOR_LEN, stdin);
            b.author[strcspn(b.author, "\n")] = '\0';
            printf("Enter Price: "); scanf("%lf", &b.price);
            printf("Enter Quantity: "); scanf("%d", &b.quantity);

            addBook(&store, b);

        } else if (choice == 2) {
            listBooks(&store);

        } else if (choice == 3) {
            int id;
            printf("Enter Book ID to remove: ");
            scanf("%d", &id);
            if (removeBook(&store, id)) {
                printf("✅ Book removed.\n");
            } else {
                printf("❌ Book not found.\n");
            }
        } else if (choice == 4) {
            saveToFile(&store, DATA_FILE);
            printf("👋 Goodbye!\n");
        } else {
            printf("⚠️ Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
