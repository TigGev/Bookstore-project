CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = src/main.o src/book.o src/bookstore.o src/storage.o

bookstore: $(OBJ)
	$(CC) $(CFLAGS) -o bookstore $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o bookstore
