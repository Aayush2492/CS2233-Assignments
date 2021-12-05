#ifndef NODE_H
#define NODE_H

#include <iostream>
class Node
{
public:
    int state;
    unsigned id;
    unsigned level;
    Node *parent;
    int timeOfInfection;
    // int timeOfRecovery;
    // bool isRecovered;
    Node(unsigned _id)
    {
        state = 0; // intial state is susceptible
        id = _id;
        timeOfInfection = -1;
        // timeOfRecovery = -1;
        // isRecovered = false;
    }
};

#endif