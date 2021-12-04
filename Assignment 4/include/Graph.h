#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>

#include "Node.h"
#include "Queue.h"

class Graph
{
public:
    std::vector<std::vector<bool> > adjacencyMatrix;
    std::vector<Node *> nodes;

    Graph(int numberOfVertices)
    {
        for (unsigned i = 0; i < numberOfVertices; i++)
        {
            nodes.push_back(new Node(i));
        }

        for (int i = 0; i < numberOfVertices; i++)
        {
            adjacencyMatrix.push_back(std::vector<bool>());
            for (int j = 0; j < numberOfVertices; j++)
            {
                adjacencyMatrix[i].push_back(false);
            }
        }

        for (int i = 0; i < numberOfVertices; i++)
        {
            for (int j = 0; j < numberOfVertices; j++)
            {
                if (rand() % 2)
                {
                    adjacencyMatrix[i][j] = true;
                    adjacencyMatrix[j][i] = true;
                }
            }
        }
    }

    void BreadthFirstSearch(Node *startNode)
    {
        std::vector<bool> visited(nodes.size(), false);
        // std::queue<Node *> queue;
        Queue queue;

        // queue.push(startNode);
        queue.enqueue(startNode);

        visited[startNode->id] = true;
        startNode->parent = NULL;
        startNode->level = 0;

        // while (!queue.empty())
        while (!queue.isEmpty())
        {
            // Node *currentNode = queue.front();
            // queue.pop();
            Node *currentNode = queue.dequeue();

            for (unsigned i = 0; i < nodes.size(); i++)
            {
                if (adjacencyMatrix[currentNode->id][i] && !visited[i])
                {
                    // queue.push(nodes[i]);
                    queue.enqueue(nodes[i]);
                    visited[i] = true;
                    nodes[i]->parent = currentNode;
                    nodes[i]->level = currentNode->level + 1;
                }
            }
        }
    }
};
#endif