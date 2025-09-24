#ifndef BOOK_H
#define BOOK_H

#define TITLE_LEN 100
#define AUTHOR_LEN 100

typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    double price;
    int quantity;
} Book;

void printBook(const Book *book);

#endif
