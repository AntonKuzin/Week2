#define _CRT_SECURE_NO_WARNINGS

#define JUDGE1
#ifdef JUDGE
#include <fstream>
std::ifstream cin("stacks.in");
std::ofstream cout("stacks.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif


#include <vector>

//#define CRTDBG_MAP_ALLOC
//#include <crtdbg.h>


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
	Node<T>* minptr;

public:
	int capacity;
	Node<T>* maxptr;

	Stack<T>()
	{
		last = nullptr;
		capacity = 0;

		maxptr = nullptr;
		minptr = nullptr;
	}

	void Push(T value)
	{
		if (value > 0 || capacity == 0)
		{
			Node<T>* item = new Node<T>();
			item->value = 1;
			item->prev = last;
			last = item;
			if (capacity == 0)
			{
				maxptr = item;
			}
			capacity++;

			minptr = item;
		}
		else
		{
			if (minptr->value < maxptr->value || capacity == 1)
			{
				minptr->value++;
			}

			if (minptr->value == maxptr->value && capacity > 1)
			{
				if (minptr->prev != nullptr && maxptr->value != 1)
				{
					minptr = minptr->prev;
				}
				else
				{
					minptr->value++;
					maxptr = minptr;
					minptr = last;
				}
			}
		}
	}

	T Pop()
	{
		T temp = last->value;
		last = last->prev;
		capacity--;
		return temp;
	}

	T Top()
	{
		return last != nullptr ? last->value : T();
	}

	~Stack<T>()
	{
		delete last;
	}
};


int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int N;
	cin >> N;

	Stack<int> stack;

	for (size_t i = 0; i < N; i++)
	{
		int value;
		cin >> value;
		stack.Push(value);
	}

	cout << stack.maxptr->value;

	return 0;
}