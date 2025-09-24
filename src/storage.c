#include <stdio.h>
#include <stdlib.h>
#include "storage.h"

void saveToFile(const Bookstore *store, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("❌ Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < store->count; i++) {
        fprintf(f, "%d,%s,%s,%.2f,%d\n",
                store->books[i].id,
                store->books[i].title,
                store->books[i].author,
                store->books[i].price,
                store->books[i].quantity);
    }
    fclose(f);
    printf("💾 Data saved to %s\n", filename);
}

void loadFromFile(Bookstore *store, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("⚠️ No existing data found. Starting fresh.\n");
        return;
    }
    store->count = 0;
    while (fscanf(f, "%d,%99[^,],%99[^,],%lf,%d\n",
                  &store->books[store->count].id,
                  store->books[store->count].title,
                  store->books[store->count].author,
                  &store->books[store->count].price,
                  &store->books[store->count].quantity) == 5) {
        store->count++;
    }
    fclose(f);
    printf("📂 Data loaded from %s\n", filename);
}
