CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = 
DEBUG_FLAGS = -ggdb
RELEASE_FLAGS = -O2 -march=native

.DEFAULT_GOAL := debug

debug: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(DEBUG_FLAGS) -o clok main.c

release: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(RELEASE_FLAGS) -o clok main.c
