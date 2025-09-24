#include <stdio.h>
#include "book.h"

void printBook(const Book *book) {
    printf("ID: %d | Title: %s | Author: %s | Price: %.2f | Quantity: %d\n",
           book->id, book->title, book->author, book->price, book->quantity);
}
