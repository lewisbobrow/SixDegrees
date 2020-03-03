/**************************************************************************
* Comp 15 Spring 2019 
* Filename: TestMain.cpp
* Contains: Driver for homework 5 
* Part of: Homework 5 assignment "Graph Traversal" for Comp 15 Spring 2019
* Author: Lewis Bobrow
*************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "SixDegrees.h"
#include "Actor.h"
#include "Graph.h"

using namespace std;

int main(){
	/************
	* GRAPH CLASS
	************/
	Graph<string> g; //creating instance of Graph of strings
	string a = "a";
	string b = "b";
	string c = "c";
	string d = "d";
	string e = "e";
	string inputfile = "actors.txt";

	//TESTING GET EDGE EDGE CASE: 0 SPACE IN GRAPH, SEG FAULTS

		// g.initialize_graph(0); //EDGE CASE, initializing with 0 space
		// cerr << "initializing graph with 0 space" << endl;
		
		// g.add_vertex(a); //shouldn't work, no space in graph
		// cerr << "adding verted 'a' to graph" << endl;
		// g.add_vertex(b); //shouldn't work, no space in graph
		// cerr << "adding verted 'b' to graph" << endl;
		
		// g.mark_vertex(b); // should seg fault, b is not in graph
		//seg faults, b is not in the graph
		// cerr << "marking b" << endl;

		//g.report_path(cerr, a, b);
		//seg faults, a and b are not in the graph

		// g.add_edge(a, b, "a to b");

		//cerr << "Edge between a and b: " << g.get_edge(a, b) const; << endl;

		//g.clear_marks();
		//cerr << "clearing marks" << endl;
		//cerr << "Number of vertices: " << g.num_vert() << endl; //should be 0

	//TESTING GET_EDGE: BASE CASE AND OTHER EDGE CASE (NO CONNECTION)
		g.initialize_graph(10);
		cerr << "initializing graph with 0 space" << endl;
		//EDGE CASE
		cerr << "is a a vertex? (1/0): " << g.is_vertex(a) << endl;

		g.add_vertex(a);
		cerr << "adding vertex 'a' to graph" << endl;

		//BASE CASE
		cerr << "is a a vertex? (1/0): " << g.is_vertex(a) << endl;
		g.add_vertex(b);
		cerr << "adding vertex 'b' to graph" << endl;
		
		//EDGE CASE, NO EDGE BETWEEN a and b
		cerr << "Edge between a and b:" << g.get_edge(a, b) << endl;
			
		g.add_edge(g.give_vertex(a), g.give_vertex(b), "a to b");
		cerr << "adding edge between a and b" << endl;

		//BASE CASE
		cerr << "Edge between a and b:" << g.get_edge(a, b) << endl;


	//TESTING REPORT PATH: BASE CASE AND EDGE CASE
		g.add_vertex(c);
		cerr << "adding vertex 'c' to graph" << endl;
		g.add_edge(g.give_vertex(b), g.give_vertex(c), "b to c");
		cerr << "adding edge between b and c" << endl;
		g.add_edge(g.give_vertex(a), g.give_vertex(c), "a to c");
		cerr << "adding edge between a and c" << endl;

		g.add_vertex(d);
		cerr << "adding vertex 'd' to graph" << endl;
		g.add_vertex(e);
		cerr << "adding vertex 'e' to graph" << endl;
		g.add_edge(g.give_vertex(d), g.give_vertex(e), "d to e");
		cerr << "adding edge between d and e" << endl;

		//BASE CASE (MULTIPLE PATHS)
		cerr << "path between a and c: " << endl;
		g.report_path(cerr, g.give_vertex(a), g.give_vertex(c));
		cerr << "should be 1 step (direct a->c) because its shorter"
			 << "than (a->b->c)(shorter than path thru b)" << endl;

		//EDGE CASE (NO PATH)
		cerr << "path between a and e" << endl;
		g.report_path(cerr, g.give_vertex(a), g.give_vertex(e));

		//EDGE CASE (ONE PATH)
		cerr << "path between d and e" << endl;
		g.report_path(cerr, g.give_vertex(d), g.give_vertex(e));

	//TESTING BIG THREE
		Graph<string> g2; //constructor
		g2.initialize_graph(5);
		g2.add_vertex(a);
		cerr << "adding vertex a to g2" << endl;
		cerr << "g2 num vertices: " << g2.num_vert() << endl; //should be 1
		
		g2 = g; //assignment overload
		cerr << "setting g2 equal to g" << endl;

		//g2 should be an independent copy, should be 5 (a thru e)
		cerr << "g2 num vertices: " << g2.num_vert() << endl;

		Graph<string> g3 = g; //copy constructor
		//g3 should be an independent copy, should be 5 (a thru e)
		cerr << "g3 num vertices: " << g3.num_vert() << endl;

		//g2 should be an independent copy, should be 5 (a thru e)
		cerr << "g2 num vertices: " << g2.num_vert() << endl;

		cerr << "destructing g" << endl;

		//g2 should be an independent copy, should be 5 (a thru e)
		// even after destructor was invoked on g
		cerr << "g2 num vertices: " << g2.num_vert() << endl;


	/************
	* ACTOR CLASS
	************/
	Actor actor; //creating instance of Actor
	actor.appeared_in("Avatar"); //EDGE CASE
	cerr << "actor appeared in the movie Avatar: (1/0)" << endl;
	actor.insert("Avatar"); //BASE CASE
	cerr << "inserting 'Avatar' into movie linked list" << endl;
	actor.appeared_in("Avatar"); //BASE CASE
	cerr << "actor appeared in the movie Avatar: (1/0)" << endl;
	actor.insert("Avatar"); //EDGE CASE (AVATAR ALREADY IN)
	cerr << "inserting 'Avatar' into a's movie linked list again" << endl;

	//EDGE CASE (no name)
	cerr << "actor name (should be empty): " << actor.return_name() << endl;
	actor.set_name("Brad Pitt"); //BASE CASE
	cerr << "setting actor name to Brad Pitt" << endl;
	//BASE CASE
	cerr << "actor name (should be empty): " << actor.return_name() << endl;
	actor.set_name(""); //EDGE CASE
	
	Actor actor2;
	//EDGE CASE
	cerr << "connection between actor and actor2 (should be ""): " 
		 << actor.connect(actor2) << endl;
	
	actor2.insert("Avatar"); //BASE CASE
	cerr << "inserting 'Avatar' into actor2's movie linked list" << endl;	

	//BASE CASE
	cerr << "connection between actor and actor2 (should be Avatar): " 
		 << actor.connect(actor2) << endl;



	/*****************
	* SIXDEGREES CLASS
	*****************/
		//DONE IN MAIN.CPP, POPULATE_GRAPH() and RUN() are not really testable for
		//base and edge cases, and BFS gets tested with every single actor
		//inside of run() when the inputfile is read
	return 0; //destructors called
}