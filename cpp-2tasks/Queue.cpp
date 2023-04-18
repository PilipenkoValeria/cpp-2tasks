#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    this->queue = new int[10];
    this->head = 0;
    this->tail = 0;
    this->size = 10;
    empty = true;
}

Queue::Queue(int size) {
    this->queue = new int[size];
    this->head = 0;
    this->tail = 0;
    this->size = size;
    empty = true;
}

Queue::Queue(const Queue& copy) {
    if (this != &copy) {
        this->head = copy.head;
        this->tail = copy.tail;
        this->size = copy.size;
        this->queue = new int[copy.size];
        for (int i = 0; i < copy.size; i++) {
            this->queue[i] = copy.queue[i];
        }
        this->empty = copy.empty;
    }
}

Queue::~Queue() {
    delete[] queue;
}

void Queue::add(int elem) {
    try
    {
        if (((tail + 1) % size) == head) {
            cout << "endOfQueueException" << endl;;
        }
        if (this->empty) {
            empty = false;
            this->queue[tail] = elem;
        }
        else {
            tail = (tail + 1) % size;
            this->queue[tail] = elem;
        }
    }
    catch (EndOfQueueException& endOfQueueException)
    {
        cerr << endOfQueueException.what() << endl;
    }
}

int Queue::pop() {
    int x;
    try
    {
        if(this->empty){
            cout << "queueIsEmptyException" << endl;
        }
        if (this->tail == this->head) {
            this->empty = true;
            x = this->queue[head];
        }
        else {
            x = this->queue[head];
            this->head = (this->head + 1) % this->size;
        }
        return x;
    }
    catch (QueueIsEmptyException& queueIsEmptyException)
    {
        cerr << queueIsEmptyException.what() << endl;
    }
}

int Queue::getElem() {
    try
    {
        if (this->empty) {
            cout << "QueueIsEmptyException" << endl;
        }
        else return this->queue[head];
    }
    catch (QueueIsEmptyException& queueIsEmptyException)
    {
        cerr << queueIsEmptyException.what() << endl;
    }
}

int Queue::getSize() {
    return this->size;
}

void Queue::makeEmpty() {
    this->empty = true;
    this->head = 0;
    this->tail = 0;
}

bool Queue::isEmpty() {
    return empty;
}
