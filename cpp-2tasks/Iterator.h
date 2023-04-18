#pragma once

#include "Queue.h"

class Iterator {
	Queue *queue;
	int index;
public:
	Iterator(Queue queue);
	void start(); //начать перебор элементов
	void next(); //перейти к следующему элементу
	bool finish(); //проверка все ли проитерировано
	int getValue(); //получить элемент очереди
};

class EndOfIteratorException : public std::exception {
	const char* message;
public:
	EndOfIteratorException(const char* cmessage) : message(cmessage) { }
	const char* what() const noexcept { return message; }
};
