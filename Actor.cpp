/**************************************************************************
* Comp 15 Spring 2019 
* Filename: Actor.cpp
* Contains: Implementation of the Actor class 
* Part of: Homework 5 assignment "Graph Traversal" for Comp 15 Spring 2019
* Author: Lewis Bobrow
*************************************************************************/

#include "Actor.h"
#include <iostream>
#include <string>
using namespace std;

//constructor
Actor::Actor(){
	name = "";
	LinkedList<string> MovieList;
}

//parametized constructor
Actor::Actor(string s){
	name = s;
	LinkedList<string> MovieList;
}

//copy constructor
Actor::Actor(const Actor &source){
	this->name = source.name;
	this->MovieList = source.MovieList;
}

// Function: insert
// Parameters: string
// Returns: nothing
// Does: inserts a movie into the actor's linked list of movies
void Actor::insert(string movie){
	MovieList.insert(movie);
}

// Function: appeared_in
// Parameters: string
// Returns: boolean
// Does: returns true if a movie is in the actor's movie list
bool Actor::appeared_in(string movie){
	bool acted;
	MovieList.find(movie, acted);
	return acted;
}

// Function: List
// Parameters: nothing
// Returns: linked list
// Does: returns the actor's movie linked list
LinkedList<string> Actor::List(){
	return MovieList;
}

// Function: connect
// Parameters: Actor
// Returns: string
// Does: returns the first movie that actor1 and actor 2 share in common
//		 in their linked lists of movies
string Actor::connect(Actor actor2){
	string movie;
	bool connection;
	LinkedList<string> actor2movies = actor2.List();
	int length = actor2movies.get_length();
	for(int i = 0; i < length; i++){
		movie = MovieList.find(actor2movies.get_value_at(i), connection);
		if(connection){
			return movie;
		}
	}
	return ""; 
}

// Function: return_name
// Parameters: nothing
// Returns: string
// Does: returns the actor's name
string Actor::return_name(){
	return name;
}

// Function: set_name
// Parameters: string
// Returns: nothing
// Does: sets the actor's name
void Actor::set_name(string s){
	name = s;
}

//== operator overload
bool operator== (const Actor &a1, const Actor &a2){
	if(a2.name == a1.name){
		return true;
	} else{
		return false;
	}
}

//!= operator overload
bool operator!= (const Actor &a1, const Actor &a2){
	if(a2.name != a1.name){
		return true;
	} else{
		return false;
	}
}

//<< operator overload
ostream &operator<< (ostream &out, const Actor &source){
	cout << source.name;
	return out;
}