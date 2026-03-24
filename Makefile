CC = gcc
CFLAGS = -O2 -march=native -Wall -Wextra

cloc: main.c
	$(CC) $(CFLAGS) -o cloc main.c