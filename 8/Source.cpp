#define _CRT_SECURE_NO_WARNINGS

#define JUDGE1
#ifdef JUDGE

#else
#include <iostream>
using std::cin;
using std::cout;
#endif



#include <vector>
#include <string>
#include <stdlib.h>
#include <cstdio>

//#define CRTDBG_MAP_ALLOC
//#include <crtdbg.h>


template <class T>
class Node
{

public:
	Node<T>* next;
	Node<T>* prev;
	T value;

	Node<T>(T value)
	{
		this->value = value;
		this->next = nullptr;
		this->prev = nullptr;
	}

	~Node<T>()
	{
		delete next;
	}
};


class DLL
{
private:
	Node<int>* first;
	Node<int>* last;
	Node<int>* pivotptr;

public:
	int capacity;

	DLL()
	{
		first = nullptr;
		last = nullptr;
		pivotptr = nullptr;
		capacity = 0;
	}

	void Push(int value)
	{
		Node<int>* item = new Node<int>(value);
		if (capacity == 0)
		{
			first = item;
			last = item;
			pivotptr = item;
		}
		else
		{
			last->next = item;
			item->prev = last;
			last = item;
		}
		capacity++;

		if (capacity > 3 && capacity % 2 == 0)
		{
			pivotptr = pivotptr->next;
		}
	}

	int Pop()
	{
		if (capacity > 0)
		{
			int temp = last->value;
			last = last->prev;
			capacity--;

			if (capacity > 1 && capacity % 2 == 1)
			{
				pivotptr = pivotptr->prev;
			}

			if (capacity == 0)
			{
				first = nullptr;
			}

			return temp;
		}
	}

	void Mum()
	{
		if (capacity <= 1)
		{
			return;
		}

		Node<int>* tempFirst = first;
		Node<int>* tempLast = last;


		first = pivotptr->next;
		first->prev = nullptr;
		last->next = tempFirst;
		tempFirst->prev = last;
		last = pivotptr;
		last->next = nullptr;

		if (capacity % 2 == 1)
		{
			pivotptr = tempLast->prev;
		}
		else
		{
			pivotptr = tempLast;
		}

		tempFirst = tempLast = nullptr;
	}

	void Print()
	{
		Node<int>* temp = first;
		while (temp != nullptr)
		{
			if (temp->next == nullptr)
			{
				printf("%i", temp->value);
			}
			else
			{
				printf("%i ", temp->value);
			}
			temp = temp->next;
		}
	}

	~DLL()
	{
		delete first;
	}
};


int main() {

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	freopen("kenobi.in", "r", stdin);
	freopen("kenobi.out", "w", stdout);

	int N;
	scanf("%i", &N);

	DLL dll;
	for (size_t i = 0; i < N; i++)
	{
		char temp[5];
		int value = 0;

		scanf(" %s", temp);


		if (temp[0] == 'a')
		{
			scanf("%i", &value);
			dll.Push(value);
		}

		if (temp[0] == 't')
		{
			dll.Pop();
		}

		if (temp[0] == 'm')
		{
			dll.Mum();
		}
	}

	printf("%i\n", dll.capacity);
	dll.Print();

	fclose(stdin);
	fclose(stdout);

	return 0;
}