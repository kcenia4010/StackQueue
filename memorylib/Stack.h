#pragma once

#include <iostream>

using namespace std;

template <class T>
class TStack
{
private:
	T** mas;
	int size;
	int vs;
public:
	TStack();
	TStack(int _size);
	TStack(const TStack& other);
	~TStack();

	void push(T& elem);
	T pull();
};

template<class T>
TStack<T>::TStack()
{
	size = 1;
	mas = new T*[size];
	vs = 0;
	for (int i = 0; i < size; i++)
		mas[i] = 0;
}

template<class T>
inline TStack<T>::TStack(int _size)
{
	if (_size < 0) throw logic_error("invalid_argument");
	size = _size;
	mas = new T*[size];
	vs = 0;
	for (int i = 0; i < size; i++)
		mas[i] = 0;
}

template<class T>
TStack<T>::TStack(const TStack& other)
{
	this->size = other.size;
	this->mas = new T*[size];
	this->vs = other.vs;
	for (int i = 0; i < size; i++)
		this->mas[i] = other.mas[i];
}

template<class T>
 TStack<T>::~TStack()
{
	 if (mas != 0)
		 delete[] mas;
	 size = 0;
	 vs = 0;
	 mas = 0;
}

 template<class T>
 void TStack<T>::push(T& elem)
 {
	 if (vs >= size) throw logic_error("out_of_range");
	 mas[vs] = &elem;
	 vs++;
 }

 template<class T>
T TStack<T>::pull()
 {
	if (vs == NULL) throw logic_error("out_of_range");
	T result = *mas[vs-1];
	mas[vs-1] = NULL;
	vs--;
	 return result;
 }


