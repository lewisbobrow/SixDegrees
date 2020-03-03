/**************************************************************************
* Comp 15 Spring 2019 
* Filename: SixDegrees.cpp
* Contains: Implementation of the SixDegrees class  
* Part of: Homework 5 assignment "Graph Traversal" for Comp 15 Spring 2019
* Author: Lewis Bobrow
**************************************************************************/

#include "SixDegrees.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

SixDegrees::SixDegrees(){
	inputFile = "actors.txt";
	actor_graph.initialize_graph(500);
}

void SixDegrees::populate_graph(){
	string line_content;
	string delimiter = "*";
	int actor_counter = 0;
	Actor actor_array[500];
	ifstream inFile;
	inFile.open(inputFile);
	if(!inFile.is_open()){
		cerr << "ERROR: File cannot be opened" << endl;
		return;
	}
	while(getline(inFile, line_content)){
		bool new_actor = false;
		Actor a(line_content);
		while(!new_actor){
			getline(inFile, line_content);
			if(line_content == delimiter){
				actor_graph.add_vertex(a);
				actor_array[actor_counter] = a;
				actor_counter++;
				new_actor = true;
			} else if(line_content != delimiter){
				string movie = line_content;
				a.insert(movie);
			}
		}
	}
	for(int a1_pos = 0; a1_pos < actor_counter; a1_pos++){
		for(int a2_pos = 1; a2_pos < actor_counter; a2_pos++){
			Actor a1 = actor_array[a1_pos];
			Actor a2 = actor_array[a2_pos];
			actor_graph.add_edge(a1, a2, a1.connect(a2));
		}
	}
}

void SixDegrees::run(istream &in, ostream &out){
	bool prompt = true;
	populate_graph();
	out << "Enter two actor names separated by a new line." << endl;
	out << "Press ctrl-D to quit." << endl;
	while(prompt){
		string a;
		getline(in, a);
		Actor actor1(a);
		if(a == ""){
			return;
		}
		if(!actor_graph.is_vertex(actor1)){
			out << "Sorry, " << a << " is not in the list" << endl;
			continue;
		}
		label:
			string b;
			getline(in, b);
			Actor actor2(b);
			if(b == ""){
				return;
			}
			if(!actor_graph.is_vertex(actor2)){
				out << "Sorry, " << b << "is not in the list" << endl;
				goto label;
			}
			BFS(actor_graph.give_vertex(actor1), 
				actor_graph.give_vertex(actor2), out);
			out << endl;
	}
}

void SixDegrees::BFS(Actor a, Actor b, ostream &out){
    actor_graph.clear_marks();
    actor_graph.initialize_path();
    Queue<Actor> primary;
    Queue<Actor> neighbors;
    Actor cur = a;
    Actor aux;
    primary.enqueue(a);

	while (cur != b){ 
		if(!actor_graph.is_marked(cur)){
			actor_graph.mark_vertex(cur);
			actor_graph.get_to_vertices(cur, neighbors);
		}
		while(!neighbors.is_empty()){
		    neighbors.dequeue(aux);
		    actor_graph.update_predecessor(cur, aux);
		    primary.enqueue(aux);
		}
		if(primary.is_empty()){
			out << a << " and " << b << ": No connection" << endl;
			return;
		} else{
			primary.dequeue(cur);
		} 
	}
	actor_graph.report_path(out, a, b);
}
