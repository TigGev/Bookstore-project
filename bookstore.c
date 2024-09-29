#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#define MAX_BOOKS 100
#define MAX_NAME_LEN 20

typedef struct {
    char* name;
    char* author;
    float price;
} Book;

// typedef struct {
//     Book* arr;  // unic books array
//     int* count; // count of this book in store
//     int size;   // books types quantity                        arr
// } uniq_book;                                                    | 

typedef struct {    //                                    book1, book2, book3
//                                                          |      |      |  
    int allBookCount;                   //                name;   name;  name;
    Book* arr;  // uniq books            //              author; author; author;
    int* count; // count of this book in store           price;  price;  price;
    int size;   // books types quantity (size of arr)     --------------------
} Bookstore;                               //               5,     3,      1     

union uswap {
    int* iptr;
    Book* bptr;
};

void swap(union uswap arg, bool flag, int index, int size) {
    if (flag) {
        for (int i = index; i < size - 1; ++i) {
        arg.bptr[i] = arg.bptr[i + 1];
        } 
    } else {
        for (int i = index; i < size - 1; ++i) {
        arg.iptr[i] = arg.iptr[i + 1];
        }
    }
}

/////////////////////////////////// AddBook ///////////////////////////////
void addBook(Bookstore *store, Book new_book, int quantity) {
    if ( store -> allBookCount + quantity > MAX_BOOKS) {
        printf("The count of books has been exceeded %d!!!\n", MAX_BOOKS);
        return;
    }
    for (int i = 0; i < store -> size; ++i) {
        if (strcmp(new_book.name, store -> arr[i].name) == 0) {
            store -> allBookCount++;
            store -> count[i] += quantity;
            return;
        }
    }
    store -> allBookCount++;
    store -> arr[store -> size] = new_book; // Push Book
    store -> count[store -> size] += quantity;
    store -> size++;  
}
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// DeleteBook ///////////////////////////////
void deleteBook(Bookstore* store) {
    char* book_name = malloc(MAX_NAME_LEN);
    fgets(book_name, MAX_NAME_LEN, stdin);
    book_name[strcspn(book_name, "\n")] = '\0';
    for (int i = 0; i < store -> size; ++i) {
        if (strcmp(book_name, store -> arr[i].name) == 0) {
            store -> allBookCount--;
            store -> count[i]--;
            if (store -> count[i] == 0) {
                union uswap args;
                args.bptr = store -> arr;
                swap(args, 1, i, store -> size);
                args.iptr = store -> count;
                swap(args, 0, i, store -> size);
            }
            return;
        }
    }
    printf("Invalid book name!!!\n");
    return;
} 
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// InfoBook ///////////////////////////////
void infoBook (Bookstore* store, char* book_name) {
    // printf("Enter your wanted book name\n");
    // char* book_name = malloc(MAX_NAME_LEN);
    // fgets(book_name, MAX_NAME_LEN, stdin);
    // book_name[strcspn(book_name, "\n")] = '\0';
    for (int i = 0; i < store -> size; ++i) {
        if (strcmp(book_name, store -> arr[i].name) == 0) {
            printf("Name: %s\n", store -> arr[i].name);
            printf("Author: %s\n", store -> arr[i].author);
            printf("price: $%.2f\n", store -> arr[i].price);
            printf("In the store have avaliable %d books\n", store -> count[i]);
            return;
        }
    }
    printf("This book is not here in store.\n");
}
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// ListBook ///////////////////////////////
void listBooks(Bookstore* store) {
    for (int i = 0; i < store -> size; ++i) {
        infoBook(store, store -> arr[i].name);
        printf("\n");
    }
}
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// SearchBook ///////////////////////////////
void searchBook(Bookstore* store) {
    char* book_name = malloc(MAX_NAME_LEN);
    fflush(stdin);
    printf("Еnter book name to search: ");
    fgets(book_name, MAX_NAME_LEN, stdin);
    book_name[strcspn(book_name, "\n")] = '\0';
    for (int i = 0; i < store -> size; ++i) {
        if (strcmp(book_name, store -> arr[i].name) == 0) {
            printf("Yes we have this book: %s\n", book_name);
            infoBook(store, book_name);
            return;
        }
    }
    printf("This book has run off: %s\n", book_name);
}
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// ChangePrice ///////////////////////////////
void changePrice(Bookstore* store) {
    printf("Enter the book name to change price: ");
    char* book_name = malloc(MAX_NAME_LEN);
    fgets(book_name, MAX_NAME_LEN, stdin);
    book_name[strcspn(book_name, "\n")] = '\0';
    for (int i = 0; i < store -> size; ++i) {
        if (strcmp(book_name, store -> arr[i].name) == 0) {
            float newPrice;
            printf("Enter a new price to this book: ");
            scanf("%f", &newPrice);
            store -> arr[i].price = newPrice;
            printf("The operation was completed successfully\n");
            return;
        }
    }
    printf("This book is not here in store.\n");
}
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// Get Book Count ///////////////////////////////
int getBookCount(Bookstore *store, char* book_name) {
    for (int i = 0; i < store -> size; ++i) {
        if (strcmp(book_name, store -> arr[i].name) == 0) {
            return store -> count[i];
        }
    }
    printf("This book is not here in store. ");
    return 0;
}

/////////////////////////////////// Search By Author ///////////////////////////////
void search_by_author(Bookstore *store, char *author_name) {
    printf("%s\n", author_name);
    int flag = 0;
    for (int i = 0; i < store -> size; ++i) {
        if (strcmp(author_name, store -> arr[i].author) == 0) {
            flag = 1;
            printf("name: %s\nprice: %.2f\n", store -> arr[i].name, store -> arr[i].price);
        }
    }
    if (!flag) {
        printf("Тhis writer's books are not available in the store\n");
    }
}
//////////////////////////////////////////////////////////////////////////////





int main() {
    Bookstore store;
    store.arr = malloc(MAX_BOOKS * sizeof(Book));
    store.count = malloc(MAX_BOOKS * sizeof(int));

   // store.arr[0] = { "Maro", "Hovhannes Tumanyan", 10.99};
    store.arr[0].name = "Maro";
    store.arr[0].author = "Hovhannes Tumanyan";
    store.arr[0].price = 10.99;
    store.arr[1].name = "Shunn u katun";
    store.arr[1].author = "Hovhannes Tumanyan";
    store.arr[1].price = 14.99;
    store.arr[2].name = "Qaos";
    store.arr[2].author = "Shirvanzade";
    store.arr[2].price = 25.39;
    store.count = calloc(MAX_BOOKS, sizeof(int));
    store.count[0] = 5;
    store.count[1] = 3;
    store.count[2] = 1;
    store.size = 3;
    store.allBookCount = 9;

    // printf("Enter your wanted book name\n");
    // char* book_name = malloc(MAX_NAME_LEN);
    // fgets(book_name, MAX_NAME_LEN, stdin);
    // book_name[strcspn(book_name, "\n")] = '\0';
    // infoBook(&store, book_name);

    Book new_book = {"Samvel", "Raffi", 40.67};

    //deleteBook(&store);
    addBook(&store, new_book, 3);
   // changePrice(&store);
    listBooks(&store);
    //searchBook(&store);
   // printf("%s: %d\n", new_book.name, getBookCount(&store, new_book.name));
    search_by_author(&store, "Hovhannes Tumanyan");
}