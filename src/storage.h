#ifndef STORAGE_H
#define STORAGE_H

#include "bookstore.h"

void saveToFile(const Bookstore *store, const char *filename);
void loadFromFile(Bookstore *store, const char *filename);

#endif
