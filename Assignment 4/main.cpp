#include <iostream>
#include <vector>
#include <ctime>
#include <set>

#include "minHeap.h"
#include "Node.h"
#include "Graph.h"
#include "Event.h"

#define N 5

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
    Event *recoveryOfPrevious = new Event(i + rand() % 4 + 1, g->nodes[randomIndex], 1);
    eventHeap->insert(firstEvent);
    eventHeap->insert(recoveryOfPrevious);
    g->nodes[randomIndex]->timeOfInfection = 0;

    g->BreadthFirstSearch(g->nodes[randomIndex]);

    // for (unsigned i = 0; i < g->nodes.size(); i++)
    // {
    //     std::cout << g->nodes[i]->id << " " << g->nodes[i]->level << std::endl;
    // }
    while (eventHeap->events.size() > 0)
    {
        Event *currentEvent = eventHeap->deleteMin();
        std::cout << currentEvent->timeStamp << "," << currentEvent->typeOfEvent << ":";

        std::cout << susceptibleEventSet.size() << " ";
        std::cout << infectionEventSet.size() << " ";
        std::cout << recoveryEventSet.size() << std::endl;

        if (currentEvent->typeOfEvent == 1)
        {
            // If recovery event
            recoveryEventSet.insert(currentEvent->person->id);
            // currentEvent->person->state = 1;
            infectionEventSet.erase(currentEvent->person->id);
        }
        else if (currentEvent->typeOfEvent == -1)
        {
            // If infection event
            infectionEventSet.insert(currentEvent->person->id);
            // currentEvent->person->state = -1;
            susceptibleEventSet.erase(currentEvent->person->id);

            Node *currentNode = currentEvent->person;
            unsigned currentIndex = currentNode->id;
            for (unsigned i = 0; i < N; i++)
            {
                if (g->adjacencyMatrix[currentIndex][i] == true && g->nodes[i]->timeOfInfection == -1)
                {
                    // timeOfInfection = -1 guarantees that the node is not in the heap with infection event
                    unsigned neighborIndex = i;
                    Node *neighbour = g->nodes[neighborIndex];

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
                        // std::cout << "j = " << j << std::endl;
                        Event *newInfectionEvent = new Event(currentEvent->timeStamp + j, neighbour, -1);
                        std::cout << "Inf: " << newInfectionEvent->timeStamp << std::endl;
                        eventHeap->insert(newInfectionEvent);
                        g->nodes[i]->timeOfInfection = currentEvent->timeStamp + j;
                        Event *newRecoveryEvent = new Event(currentEvent->timeStamp + j + rand() % 4 + 1, neighbour, 1);
                        std::cout << "Rec: " << newRecoveryEvent->timeStamp << std::endl;
                        eventHeap->insert(newRecoveryEvent);
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << g->nodes[i]->timeOfInfection << " ";
    }
    return 0;
}