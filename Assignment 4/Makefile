CC = g++
CPPFLAGS = -I include/ -c -Wall -g
OBJS = main.o minHeap.o Graph.o Event.o Node.o
TARGET = exec

all: MAIN

MAIN: $(OBJS)
		$(CC) -o $(TARGET) $(OBJS) && rm -rf $(OBJS) *~

main.o: main.cpp
		$(CC) $(CPPFLAGS) main.cpp

minHeap.o: minHeap.cpp
		$(CC) $(CPPFLAGS) minHeap.cpp

Graph.o: Graph.cpp
		$(CC) $(CPPFLAGS) Graph.cpp

Event.o: Event.cpp
		$(CC) $(CPPFLAGS) Event.cpp

Node.o: Node.cpp
		$(CC) $(CPPFLAGS) Node.cpp

clean:
		rm -rf $(OBJS) $(TARGET) *~
