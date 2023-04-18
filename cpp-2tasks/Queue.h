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
	void add(int elem);//�������� ������� � ����� ������� (��� ������������ � ����������)
	int pop();//����� ������� � ������ ������� (��� ���������� � ����������)
	int getElem();//�������� ������� � ������ ������� (��� ��� �������)
	int getSize();//������ �������
	void makeEmpty();//������� ������� ������
	bool isEmpty();//�������� ������� �� �������
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