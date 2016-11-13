#define _CRT_SECURE_NO_WARNINGS

#define JUDGE
#ifdef JUDGE
#include <fstream>
std::ifstream cin("brackets.in");
std::ofstream cout("brackets.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif


#include <string>>


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

char GetClosingBracket(char openingBracket)
{
	if (openingBracket == '(' || openingBracket == '[')
	{
		return openingBracket == '(' ? ')' : ']';
	}
	return ' ';
}

int main() {

	std::string str;

	while (std::getline(cin, str))
	{
		Stack<char> stack;
		bool isValid = true;

		if (str.size() % 2 == 0)
		{
			for (size_t i = 0; i < str.size(); i++)
			{
				char character = str[i];
				if (character == '(' || character == '[')
				{
					stack.Push(character);
				}
				else
				{
					if (GetClosingBracket(stack.Top()) == character)
					{
						stack.Pop();
					}
					else
					{
						isValid = false;
						break;
					}
				}
			}
		}
		else
		{
			isValid = false;
		}

		if (stack.capacity > 0)
		{
			isValid = false;
		}

		if (isValid)
			cout << "YES" << std::endl;
		else
			cout << "NO" << std::endl;
	}

	return 0;
}