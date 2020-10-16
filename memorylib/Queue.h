#pragma once

#include <iostream>
using namespace std;

template <class T>
class TQueue
{
private:
	T** mas;
	int size;
	int head;
	int tail;

public:
	TQueue();
	TQueue(int _size);
	TQueue(const TQueue& other);
	~TQueue();

	void push(T& elem);
	T pull();
};

template<class T>
TQueue<T>::TQueue()
{
	size = 1;
	mas = new T * [size];
	head = tail = 0;
	for (int i = 0; i < size; i++)
		mas[i] = 0;
}

template<class T>
TQueue<T>::TQueue(int _size)
{
	if (_size < 0) throw logic_error("invalid_argument");
	size = _size;
	mas = new T * [size];
	head = tail = 0;
	for (int i = 0; i < size; i++)
		mas[i] = 0;
}

template<class T>
TQueue<T>::TQueue(const TQueue& other)
{
	this->size = other.size;
	this->mas = new T * [size];
	this->head = other.head;
	this->tail = other.tail;
	for (int i = 0; i < size; i++)
		this->mas[i] = other.mas[i];
}

template<class T>
TQueue<T>::~TQueue()
{
	if (mas != 0)
		delete[] mas;
	size = 0;
	head =tail = 0;
	mas = 0;
}

template<class T>
void TQueue<T>::push(T& elem)
{
	if (tail >= size) throw logic_error("out_of_range");
	mas[tail] = &elem;
	tail++;
}

template<class T>
T TQueue<T>::pull()
{
	if ((tail == head)&&(mas[tail]==0)) throw logic_error("out_of_range");
	T result = *mas[head];
	mas[head] = NULL;
	head++;
	return result;
}



