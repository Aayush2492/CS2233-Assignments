CC = gcc
CFLAGS = -c -Wall
OBJS = node.o binary_search_tree.o avl_tree.o helpful_functions.o main.o
TARGET = exec

all: MAIN

MAIN: $(OBJS)
		$(CC) -o $(TARGET) $(OBJS) && rm -rf $(OBJS) *~

main.o: main.c
		$(CC) $(CFLAGS) main.c

node.o: node.c
		$(CC) $(CFLAGS) node.c

binary_search_tree.o: binary_search_tree.c
		$(CC) $(CFLAGS) binary_search_tree.c

avl_tree.o: avl_tree.c
		$(CC) $(CFLAGS) avl_tree.c

helpful_functions.o: helpful_functions.c
		$(CC) $(CFLAGS) helpful_functions.c

clean:
		rm -rf $(OBJS) $(TARGET) *~
