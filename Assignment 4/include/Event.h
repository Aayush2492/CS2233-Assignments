#ifndef EVENT_H
#define EVENT_H

#include "Node.h"

class Event
{
public:
    unsigned timeStamp;
    Node *person;
    int typeOfEvent;

    Event(unsigned _timeStamp, Node *_person, int _typeOfEvent)
    {
        timeStamp = _timeStamp;
        person = _person;
        typeOfEvent = _typeOfEvent;
    }
};
#endif