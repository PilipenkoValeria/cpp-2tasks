#pragma once
#include <iostream>

class Queue {
private:
	int* queue;
	int size;
	int head, tail;
	bool empty;
public:
	Queue();
	Queue(int size);
	Queue(const Queue &copy);
	~Queue();
	void add(int elem);//добавить элемент в конец очереди (при переполнении Ц исключение)
	int pop();//вз€ть элемент в начале очереди (при отсутствии Ц исключение)
	int getElem();//получить элемент в начале очереди (без его изъ€ти€)
	int getSize();//размер очереди
	void makeEmpty();//сделать очередь пустой
	bool isEmpty();//проверка очереди на пустоту
	void print();

	friend class Iterator;
};

class EndOfQueueException : public std::exception {
	const char* message;
public:
	EndOfQueueException(const char* cmessage) : message(cmessage) { }
	const char* what() const noexcept { return message; }
};

class QueueIsEmptyException : public std::exception {
	const char* message;
public:
	QueueIsEmptyException(const char* cmessage) : message(cmessage) { }
	const char* what() const noexcept { return message; }
};