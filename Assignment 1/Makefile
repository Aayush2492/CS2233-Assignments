#tab before every command

#declaring variables
CC = gcc
CFLAGS = -c -Wall
OBJS = node.o linked_list.o queue_by_linked_list.o stack_by_linked_list.o main.o
TARGET = exec

all: hello # you basically type dependencies after : and space

hello: $(OBJS)
		$(CC) -o $(TARGET) $(OBJS)

main.o: main.c
		$(CC) $(CFLAGS) main.c

node.o: node.c
		$(CC) $(CFLAGS) node.c

linked_list.o: linked_list.c
		$(CC) $(CFLAGS) linked_list.c

queue_by_linked_list.o: queue_by_linked_list.c
		$(CC) $(CFLAGS) queue_by_linked_list.c

stack_by_linked_list.o: stack_by_linked_list.c
		$(CC) $(CFLAGS) stack_by_linked_list.c

clean:
		rm -rf $(OBJS) $(TARGET) *~
