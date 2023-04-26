#include <iostream>
#include "Queue.h"
#include "Iterator.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
    Queue queue(6);
    cout << "Удалим элемент в начале очереди: " << endl;
    queue.pop();
    queue.add(1);
    queue.add(2);
    queue.add(3);
    queue.add(4);
    cout << "Добавим элементы 1,2,3,4 в очередь." << endl;
    cout << "Удалим элемент в начале очереди: " << queue.pop() << endl;
    cout << "Длина очереди:  " << queue.getSize() << endl;
    queue.add(5);
    queue.add(6);
    cout << "Добавим элементы 5,6 в очередь." << endl;
    cout << "Первый элемент очереди: " << queue.getElem() << endl;

    cout << "Start iterator\n";
    Iterator it(queue);
    while (!it.finish()) {
        cout << it.getValue() << " ";
        it.next();
    }
    cout << "\nFinish iterator\n";
    cout << "Удалим элемент в начале очереди: " << queue.pop() << endl;
    queue.add(7);
    cout << "Добавим элемент 7 в очередь." << endl;

    Iterator it1(queue);
    while (!it1.finish()) {
        cout << it1.getValue() << " ";
        it1.next();
    }

    cout <<endl<< "Очередь пуста? " << queue.isEmpty() << endl;
    queue.makeEmpty();
    cout << "Очистим очередь."<<endl<<"Очередь пуста? " << queue.isEmpty() << endl;
}
