#include <stdio.h>
#include <string.h>
#include "bookstore.h"

void initBookstore(Bookstore *store) {
    store->count = 0;
}

void addBook(Bookstore *store, Book book) {
    if (store->count < MAX_BOOKS) {
        store->books[store->count++] = book;
        printf("✅ Book added successfully!\n");
    } else {
        printf("❌ Bookstore is full!\n");
    }
}

void listBooks(const Bookstore *store) {
    if (store->count == 0) {
        printf("📚 No books available.\n");
        return;
    }
    for (int i = 0; i < store->count; i++) {
        printBook(&store->books[i]);
    }
}

int removeBook(Bookstore *store, int id) {
    for (int i = 0; i < store->count; i++) {
        if (store->books[i].id == id) {
            for (int j = i; j < store->count - 1; j++) {
                store->books[j] = store->books[j + 1];
            }
            store->count--;
            return 1; // success
        }
    }
    return 0; // not found
}
