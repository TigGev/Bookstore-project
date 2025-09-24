#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include "book.h"

#define MAX_BOOKS 100

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Bookstore;

void initBookstore(Bookstore *store);
void addBook(Bookstore *store, Book book);
void listBooks(const Bookstore *store);
int removeBook(Bookstore *store, int id);

#endif
