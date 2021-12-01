#ifndef NODE_H
#define NODE_H

#include <iostream>
class Node
{
public:
    int state;
    unsigned id;
    unsigned level;
    bool visited;
    Node *parent;
    // int timeOfInfection;
    // int timeOfRecovery;
    Node(unsigned _id)
    {
        state = 0;
        id = _id;
        // timeOfInfection = -1;
        // timeOfRecovery = -1;
    }
};

#endif