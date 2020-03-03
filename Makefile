#
# Comp 15 Spring 2019 
# Filename: Makefile
# Contains: Implementation for queue class (template class) 
# Part of: Homework 5 assignment "Graph Traversal" for Comp 15 Spring 2019
# Author: Lewis Bobrow
#

CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11
DEPS = Graph.h Queue.h Stack.h LinkedList.h Actor.h
 
 %.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

sixdegrees: main.o SixDegrees.o Actor.o Graph.o LinkedList.o Queue.o Stack.o
	$(CC) -o sixdegrees main.o SixDegrees.o Actor.o Graph.o LinkedList.o Queue.o Stack.o

clean:
	rm -f *.o core* *~ search

graphtest: test-graph.o SixDegrees.o Actor.o Graph.o LinkedList.o Queue.o Stack.o
	$(CC) -o graphtest test-graph.o SixDegrees.o Actor.o Graph.o LinkedList.o Queue.o Stack.o