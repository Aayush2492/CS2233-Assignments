CC = gcc
CFLAGS = -c -Wall
OBJS = queue_by_linked_list.o stack_by_linked_list.o node2.o file_reader.o node.o binary_search_tree.o avl_tree.o helpful_functions.o main.o
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

file_reader.o: file_reader.c
		$(CC) $(CFLAGS) file_reader.c

stack_by_linked_list.o: stack_by_linked_list.c
		$(CC) $(CFLAGS) stack_by_linked_list.c

queue_by_linked_list.o: queue_by_linked_list.c
		$(CC) $(CFLAGS) queue_by_linked_list.c

node2.o: node2.c
		$(CC) $(CFLAGS) node2.c

clean:
		rm -rf $(OBJS) $(TARGET) *~
