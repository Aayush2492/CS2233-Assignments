#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

#include "Node.h"

class Queue
{
private:
    std::vector<Node *> queue;
    unsigned front;
    unsigned back;

public:
    Queue()
    {
        back = 0;
        front = 0;
    }

    void enqueue(Node *node)
    {
        queue.push_back(node);
        back++;
    }

    Node *dequeue()
    {
        if (front == back)
        {
            // Queue is empty
            return NULL;
        }
        Node *node = queue[front];
        front++;
        return (queue[front - 1]);
    }

    bool isEmpty()
    {
        return (front == back);
    }
};
#endif