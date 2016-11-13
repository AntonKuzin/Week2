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
class QueueMin
{
private:
	Node<T>* first;
	Node<T>* last;
	
	T GetMin()
	{
		Node<T>* temp = first;
		T value = 1000000000;
		while (temp != nullptr)
		{
			if (temp->value < value)
			{
				value = temp->value;
			}
			temp = temp->next;
		}
		return value;
	}
	
public:
	int capacity;
	std::vector<T> mins;

	QueueMin<T>()
	{
		first = nullptr;
		last = nullptr;
		capacity = 0;
		mins = std::vector<T>();
	}

	void Push(T value)
	{
		Node<T>* item = new Node<T>(value);
		if (capacity == 0)
		{
			first = item;
			last = item;
			mins.push_back(value);
		}
		else
		{
			last->next = item;
			last = item;
			if (mins[0] > value)
			{
				mins = std::vector<T>();
				mins.push_back(value);
			}
			else if (mins[0] == value)
			{
				mins.push_back(value);
			}
		}
		capacity++;
	}

	T Pop()
	{
		T temp = first->value;
		first = first->next;
		capacity--;

		if (temp == mins[0])
		{
			mins.pop_back();
		}

		if (capacity == 0)
		{
			last = nullptr;
			return temp;
		}

		if (mins.size() == 0)
		{
			mins.push_back(GetMin());
		}
		

		return temp;
	}

	~QueueMin<T>()
	{
		delete first;
	}
};

int main() {

	freopen("queuemin.in", "r", stdin);
	freopen("queuemin.out", "w", stdout);

	int N;
	scanf("%i", &N);

	std::string temp;

	QueueMin<int> queue;
	for (size_t i = 0; i < N; i++)
	{
		char sign = ' ';
		int value = 0;

		scanf(" %c", &sign);


		if (sign == '-')
		{
			queue.Pop();
		}

		if(sign == '+')
		{
			scanf(" %i", &value);
			queue.Push(value);
		}

		if(sign == '?')
		{
			printf("%i \n", queue.mins[0]);
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}