#include <iostream>
#include <vector>
#include <ctime>
#include <set>
#include <fstream>

#include "minHeap.h"
#include "Node.h"
#include "Graph.h"
#include "Event.h"

#define N 1000

/**
 *
 * -1 for infected
 * 0 for susceptible
 * 1 for recovered
 *
 */

using pairuu = std::pair<unsigned, unsigned>;
using event_tuple = std::pair<unsigned, pairuu>;
using time_events = std::pair<unsigned, event_tuple>;

int main()
{
    Graph *g = new Graph(N);

    minHeap *eventHeap = new minHeap();
    std::set<unsigned> infectionEventSet;
    std::set<unsigned> recoveryEventSet;
    std::set<unsigned> susceptibleEventSet;
    std::vector<time_events> timeEvents;

    // std::vector<unsigned> infectedWithTime;
    // std::vector<unsigned> susceptibleWithTime;
    // std::vector<unsigned> recoveredWithTime;

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

    while (eventHeap->events.size() > 0)
    {
        Event *currentEvent = eventHeap->deleteMin();

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
                        eventHeap->insert(newInfectionEvent);
                        g->nodes[i]->timeOfInfection = currentEvent->timeStamp + j;
                        Event *newRecoveryEvent = new Event(currentEvent->timeStamp + j + rand() % 4 + 1, neighbour, 1);
                        eventHeap->insert(newRecoveryEvent);

                        // std::cout << "Infected nodes distance " << neighbour->level << " at time " << currentEvent->timeStamp + j << std::endl;
                    }
                }
            }
        }

        if ((int)timeEvents.size() - 1 >= 0)
        {
            std::cout << timeEvents.size() << std::endl;
            if (timeEvents[timeEvents.size() - 1].first == currentEvent->timeStamp)
            {
                timeEvents.pop_back();
            }
        }
        timeEvents.push_back(std::make_pair(currentEvent->timeStamp, std::make_pair(susceptibleEventSet.size(), std::make_pair(infectionEventSet.size(), recoveryEventSet.size()))));
        // infectedWithTime.push_back(infectionEventSet.size());
        // susceptibleWithTime.push_back(susceptibleEventSet.size());
        // recoveredWithTime.push_back(recoveryEventSet.size());
    }

    // for (int i = 0; i < infectedWithTime.size(); i++)
    // {
    //     std::cout << "At time " << i << " : ";
    //     std::cout << infectedWithTime[i] << " " << susceptibleWithTime[i] << " " << recoveredWithTime[i] << std::endl;
    // }

    std::ofstream outfile;
    outfile.open("data.csv");

    for (int i = 0; i < timeEvents.size(); i++)
    {
        // std::cout << "At time " << timeEvents[i].first << " : ";
        // std::cout << timeEvents[i].second.first << " " << timeEvents[i].second.second.first << " " << timeEvents[i].second.second.second << std::endl;
        outfile << timeEvents[i].first << "," << timeEvents[i].second.first << "," << timeEvents[i].second.second.first << "," << timeEvents[i].second.second.second << std::endl;
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << "Node " << i << " with level " << g->nodes[i]->level << " got infected at " << g->nodes[i]->timeOfInfection << std::endl;
    }
    return 0;
}