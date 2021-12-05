#include <iostream>
#include <vector>
#include <ctime>
#include <set>

#include "minHeap.h"
#include "Node.h"
#include "Graph.h"
#include "Event.h"

#define N 100

/**
 *
 * -1 for infected
 * 0 for susceptible
 * 1 for recovered
 *
 */

int main()
{
    printf("Graph begins\n");
    Graph *g = new Graph(N);
    minHeap *eventHeap = new minHeap();
    std::set<unsigned> infectionEventSet;
    std::set<unsigned> recoveryEventSet;
    std::set<unsigned> susceptibleEventSet;

    for (int i = 0; i < N; i++)
    {
        susceptibleEventSet.insert(i);
    }

    unsigned randomIndex = rand() % N;
    unsigned i = 0;
    Event *firstEvent = new Event(i, g->nodes[randomIndex], -1);
    Event *recoveryOfPrevious = new Event(i + 2, g->nodes[randomIndex], 1);
    eventHeap->insert(firstEvent);
    eventHeap->insert(recoveryOfPrevious);

    g->BreadthFirstSearch(g->nodes[randomIndex]);

    // for (unsigned i = 0; i < g->nodes.size(); i++)
    // {
    //     std::cout << g->nodes[i]->id << " " << g->nodes[i]->level << std::endl;
    // }
    while (eventHeap->events.size() > 0)
    {
        Event *currentEvent = eventHeap->deleteMin();
        if (currentEvent->typeOfEvent == 1)
        {
            // If recovery event
            recoveryEventSet.insert(currentEvent->person->id);
            currentEvent->person->state = 1;
            infectionEventSet.erase(currentEvent->person->id);
        }
        else if (currentEvent->typeOfEvent == -1)
        {
            // If infection event
            infectionEventSet.insert(currentEvent->person->id);
            currentEvent->person->state = -1;
            susceptibleEventSet.erase(currentEvent->person->id);

            Node *currentNode = currentEvent->person;
            unsigned currentIndex = currentNode->id;
            for (unsigned i = 0; i < N; i++)
            {
                if (g->adjacencyMatrix[currentIndex][i] == true)
                {
                    unsigned neighborIndex = i;
                    Node *neighbour = g->nodes[neighborIndex];
                    if (neighbour->state == 0)
                    {
                        // Susceptible neighbour
                        // Susceptible neighbour is infected with probability 1-(1/32) = 31/32 = 0.96875
                        unsigned j = 1;
                        for (j = 1; j <= 5; j++)
                        {
                            if (rand() % 2 == 0)
                            {
                                // Head
                                break;
                            }
                        }
                        if (j == 6)
                        {
                            // Head never appeared
                            break;
                        }
                        else
                        {
                            Event *newInfectionEvent = new Event(currentEvent->timeStamp + j, neighbour, -1);
                            eventHeap->insert(newInfectionEvent);
                            Event *newRecoveryEvent = new Event(currentEvent->timeStamp + j + rand() % 4 + 1, neighbour, 1);
                            eventHeap->insert(newRecoveryEvent);
                        }
                    }
                }
            }
        }
        std::cout << currentEvent->timeStamp << std::endl;
    }

    return 0;
}