/**************************************************************************
* Comp 15 Spring 2019 
* Filename: main.cpp
* Contains: Driver for homework 5 
* Part of: Homework 5 assignment "Graph Traversal" for Comp 15 Spring 2019
* Author: Lewis Bobrow
*************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "SixDegrees.h"

using namespace std;

int main(int argc, char* argv[])
{
	argc = 2;
    SixDegrees game;
    if((argv[0] != NULL) && (argv[1] == NULL)){
    	game.run(cin, cout);
    } else if((argv[0] != NULL) && (argv[1] != NULL)){
    	string inputfile = argv[1];
    	ifstream inFile;
    	inFile.open(inputfile);
    	if(!inFile.is_open()){
    		cerr << "Error: file cannot be opened" << endl;
    	}
    	while(!inFile.eof()){
    		game.run(inFile, cout); 
    	}
    } else{
    	cerr << "Invalid number of commandline arguments." << endl;
    }
    return 0;
}
