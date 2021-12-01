#include <iostream>
#include <vector>
#include <ctime>

#include "minHeap.h"
#include "Node.h"
#include "Graph.h"
#include "Event.h"

#define N 100

/**
 * -1 for infected
 * 0 for susceptible
 * 1 for recovered
 */

int main()
{
    printf("Graph begins\n");
    Graph *g = new Graph(N);
    minHeap *eventHeap = new minHeap();

    unsigned randomIndex = rand() % N;
    unsigned i = 0;
    Event *firstEvent = new Event(i, g->nodes[randomIndex], -1);
    // // Event *recoveryOfPrevious = new Event(, g->nodes[randomIndex], 1);
    eventHeap->insert(firstEvent);
    g->BreadthFirstSearch(g->nodes[randomIndex]);
    for (int i = 0; i < g->nodes.size(); i++)
    {
        std::cout << g->nodes[i]->id << " " << g->nodes[i]->level << std::endl;
    }
    while (eventHeap->events.size() > 0)
    {
        Event *currentEvent = eventHeap->deleteMin();
    }

    return 0;
}