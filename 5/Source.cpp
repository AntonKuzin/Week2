#define _CRT_SECURE_NO_WARNINGS

#define JUDGE1
#ifdef JUDGE
#include <fstream>
std::ifstream cin("postfix.in");
std::ofstream cout("postfix.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif


#include <string>
#include <cstdlib>


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

	char ch;
	Stack<int> stack;

	while (cin >> ch)
	{
		if (ch == '+')
		{
			int b = stack.Pop();
			int a = stack.Pop();
			int temp = a + b;
			stack.Push(temp);
		}
		else if (ch == '-')
		{
			int b = stack.Pop();
			int a = stack.Pop();
			int temp = a - b;
			stack.Push(temp);
		}
		else if (ch == '*')
		{
			int b = stack.Pop();
			int a = stack.Pop();
			int temp = a * b;
			stack.Push(temp);
		}
		else
		{
			int value = atoi(&ch);
			stack.Push(value);
		}
	}

	cout << stack.Pop() << std::endl;

	return 0;
}