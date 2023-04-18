#include "Iterator.h"
using namespace std;

Iterator::Iterator(Queue queue){
    this->queue = new Queue(queue);
    this->index = queue.head;
}

void Iterator::start(){
    index = queue->head;
}

void Iterator::next(){
    try
    {
        if (this->finish()) {
            cout << "endOfIteratorException" << endl;
        }
        else {
            index = (index + 1) % queue->size;
        }
    }
    catch (EndOfIteratorException& endOfIteratorException)
    {
        cerr << endOfIteratorException.what() << endl;
    }
}

bool Iterator::finish(){
    return (index == (queue->tail % queue->size));
}

int Iterator::getValue(){
    return queue->queue[index];
}
