CC = gcc
CFLAGS = -I include/ -c -Wall -g
OBJS = main.o binary_search_tree.o btree.o file_reader.o tree_node.o bst_node.o disk_simulation.o helpful_functions.o
TARGET = exec

all: MAIN

MAIN: $(OBJS)
		$(CC) -o $(TARGET) $(OBJS) && rm -rf $(OBJS) *~

main.o: main.c
		$(CC) $(CFLAGS) main.c

tree_node.o: tree_node.c
		$(CC) $(CFLAGS) tree_node.c

btree.o: btree.c
		$(CC) $(CFLAGS) btree.c

disk_simulation.o: disk_simulation.c
		$(CC) $(CFLAGS) disk_simulation.c

helpful_functions.o: helpful_functions.c
		$(CC) $(CFLAGS) helpful_functions.c

bst_node.o: bst_node.c
		$(CC) $(CFLAGS) bst_node.c

file_reader.o: file_reader.c
		$(CC) $(CFLAGS) file_reader.c

binary_search_tree.o: binary_search_tree.c
		$(CC) $(CFLAGS) binary_search_tree.c

clean:
		rm -rf $(OBJS) $(TARGET) *~
