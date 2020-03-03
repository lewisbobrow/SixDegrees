/**************************************************************************
* Comp 15 Spring 2019 
* Filename: SixDegrees.h
* Contains: Interface of the SixDegrees class  
* Part of: Homework 5 assignment "Graph Traversal" for Comp 15 Spring 2019
* Author: Lewis Bobrow
*************************************************************************/

#include "Queue.h"
#include "Actor.h"
#include "Graph.h"
#include <iostream>
#include <ostream>

#ifndef SIXDEGREES_H_
#define SIXDEGREES_H_

class SixDegrees {

public:
	SixDegrees();
	void populate_graph();
	void run(istream &in, ostream &out);
	void BFS(Actor a, Actor b, ostream &out);

private:
	Graph<Actor> actor_graph;
	string inputFile;
};

#endif