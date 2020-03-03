/*************************************************************************
* Comp 15 Spring 2019 
* Filename: Actor.h
* Contains: Interface of the Actor class 
* Part of: Homework 5 assignment "Graph Traversal" for Comp 15 Spring 2019
* Author: Lewis Bobrow
*************************************************************************/

#include <iostream>
#include <ostream>
#include "LinkedList.h"

#ifndef ACTOR_H_
#define ACTOR_H_

class Actor {

public:
	Actor();
	Actor(string name);
	Actor(const Actor &source);
	void insert(string movie);
	string connect(Actor otherActor);
	bool appeared_in(string movie);
	string return_name();
	void set_name(string s);
	friend bool operator ==(const Actor &a1, const Actor &a2);
	friend bool operator !=(const Actor &a1, const Actor &a2);
	friend ostream &operator << (ostream &out, const Actor &source);
	LinkedList<string> List();

private:
	string name;
	LinkedList<string> MovieList;

};

#endif