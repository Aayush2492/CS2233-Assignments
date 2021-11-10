CC = gcc
CFLAGS = -c -Wall
OBJS = btree.o tree_node.o main.o
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

clean:
		rm -rf $(OBJS) $(TARGET) *~
