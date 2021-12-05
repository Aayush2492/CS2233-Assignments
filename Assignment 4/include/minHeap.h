#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <math.h>
#include <iostream>

#include "Event.h"

class minHeap
{
public:
    std::vector<Event *> events;

    void insert(Event *eventToInsert)
    {
        events.push_back(eventToInsert);

        unsigned currentIndex = events.size() - 1;
        while (events[currentIndex]->timeStamp < events[ceil(currentIndex / 2.0) - 1]->timeStamp && currentIndex != 0)
        {
            std::swap(events[currentIndex], events[ceil(currentIndex / 2.0) - 1]);
            currentIndex = ceil(currentIndex / 2.0) - 1;
        }
    }

    Event *deleteMin()
    {
        Event *min = events[0];
        events[0] = events[events.size() - 1];
        events.pop_back();

        heapify(0);

        return min;
    }

private:
    unsigned numberOfEvents = events.size();
    void heapify(unsigned index)
    {
        unsigned left = 2 * index + 1;
        unsigned right = 2 * index + 2;
        unsigned smallest = index;

        if (left < events.size())
        {
            if (events[left]->timeStamp < events[smallest]->timeStamp)
            {
                smallest = left;
            }
        }

        if (right < events.size())
        {
            if (events[right]->timeStamp <= events[smallest]->timeStamp)
            {
                smallest = right;
            }
        }

        if (smallest != index)
        {
            std::swap(events[index], events[smallest]);
            heapify(smallest);
        }
    }
};
#endif
