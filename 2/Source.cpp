#define _CRT_SECURE_NO_WARNINGS

#define JUDGE1
#ifdef JUDGE

#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <string>
#include <stdlib.h> 

template <class T>
class Node
{
	
public:
	Node<T>* next;
	T value;

	Node<T>(T value)
	{
		this->value = value;
		this->next = nullptr;
	}

	~Node<T>()
	{
		delete next;
	}
};


template <class T>
class Queue
{
private:
	Node<T>* first;
	Node<T>* last;

public:
	int capacity;

	Queue<T>()
	{
		first = nullptr;
		last = nullptr;
		capacity = 0;
	}

	void Push(T value)
	{
		Node<T>* item = new Node<T>(value);
		if (capacity == 0)
		{
			first = item;
			last = item;
		}
		else
		{
			last->next = item;
			last = item;
		}
		capacity++;
	}

	T Pop()
	{
		T temp = first->value;
		first = first->next;
		capacity--;
		return temp;
	}

	~Queue<T>()
	{
		delete first;
	}
};

#include <cstdio>

int main() {

	freopen("queue.in", "r", stdin);
	freopen("queue.out", "w", stdout);

	int N;
	scanf("%i", &N);

	std::string temp;

	Queue<int> queue;
	for (size_t i = 0; i < N; i++)
	{
		char sign = ' ';
		int value = 0;

		scanf(" %c", &sign);


		if (sign == '-')
		{
			printf("%i \n", queue.Pop());
		}
		else
		{
			scanf(" %i", &value);
			queue.Push(value);
		}
	}

	return 0;
}