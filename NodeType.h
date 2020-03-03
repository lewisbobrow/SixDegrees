/*****************************************************************************
* Comp 15 Spring 2019 
* Filename: Nodetype.cpp
* Contains: Interface of the template NodeType class (a node of a linked list)
* Part of: Homework 5 assignment "Graph Traversal" for Comp 15 Spring 2019
* Author: Lewis Bobrow
*****************************************************************************/

#ifndef NODE_TYPE_H_
#define NODE_TYPE_H_

template<class E>
struct NodeType
{
    E info;
    NodeType *next;
};

#endif
