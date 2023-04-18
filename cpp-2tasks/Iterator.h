#pragma once

#include "Queue.h"

class Iterator {
	Queue *queue;
	int index;
public:
	Iterator(Queue queue);
	void start(); //������ ������� ���������
	void next(); //������� � ���������� ��������
	bool finish(); //�������� ��� �� ��������������
	int getValue(); //�������� ������� �������
};

class EndOfIteratorException : public std::exception {
	const char* message;
public:
	EndOfIteratorException(const char* cmessage) : message(cmessage) { }
	const char* what() const noexcept { return message; }
};
