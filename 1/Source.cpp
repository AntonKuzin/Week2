#define JUDGE
#ifdef JUDGE

#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <stdlib.h> 

template <class T>
class Node
{
public:
	Node<T>* prev;
	T value;
	
	~Node<T>()
	{
		delete prev;
	}
};


template <class T>
class Stack
{
private:
	Node<T>* last;

public:
	int capacity;

	Stack<T>()
	{
		last = nullptr;
		capacity = 0;
	}

	void Push(T value)
	{
		Node<T>* item = new Node<T>();
		item->value = value;
		item->prev = last;
		last = item;
		capacity++;
	}

	T Pop()
	{
		T temp = last->value;
		last = last->prev;
		capacity--;
		return temp;
	}

	~Stack<T>()
	{
		delete last;
	}
};

#include <cstdio>

int main() {

	freopen("stack.in", "r", stdin);
	freopen("stack.out", "w", stdout);

	int N;
	scanf("%i", &N);

	std::string temp;

	Stack<int> stack;
	for (size_t i = 0; i < N; i++)
	{
		char sign = ' ';
		int value = 0;

		scanf(" %c", &sign);

		
		if (sign == '-')
		{
			printf("%i \n", stack.Pop());
		}
		else
		{
			scanf(" %i", &value);
			stack.Push(value);
		}
	}

	return 0;
}