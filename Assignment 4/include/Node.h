#ifndef NODE_H
#define NODE_H

#include <iostream>
class Node
{
public:
    unsigned id;
    unsigned level;
    Node *parent;
    int timeOfInfection;
    Node(unsigned _id)
    {
        id = _id;
        timeOfInfection = -1;
    }
};

#endif