#define _CRT_SECURE_NO_WARNINGS

#define JUDGE1
#ifdef JUDGE

#else
#include <iostream>
using std::cin;
using std::cout;
#endif


#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>

//#define CRTDBG_MAP_ALLOC
//#include <crtdbg.h>


class LinkedStack
{
private:
	short stackValue;
	LinkedStack* prevStack;

public:
	long long mass;

	LinkedStack()
	{
		stackValue = 0;
		prevStack = nullptr;
		mass = 0;
	}

	LinkedStack(LinkedStack* toCopy) : LinkedStack()
	{
		prevStack = toCopy;
		mass = toCopy->mass;
	}

	void Push(short value)
	{
		stackValue = value;
		mass += value;
	}

	static short Pop(LinkedStack*& stack)
	{
		LinkedStack* temp = stack;
		while (temp->stackValue == 0)
		{
			temp = temp->prevStack;			
		}

		stack = temp->prevStack;
		short value = temp->stackValue;
		temp = nullptr;

		return value;
	}

	static long long Weight(LinkedStack* stack)
	{
		if (stack == nullptr)
		{
			return 0;
		}

		long long sum = 0;
			

		sum += stack->stackValue;

		sum += Weight(stack->prevStack);

		return sum;
	}

	~LinkedStack()
	{
		delete prevStack;
	}
};

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	freopen("snowmen.in", "r", stdin);
	freopen("snowmen.out", "w", stdout); 

	int N;
	scanf("%i", &N);
	N++;

	std::vector<LinkedStack*> arr = std::vector<LinkedStack*>(N);
	arr[0] = new LinkedStack();

	for (size_t i = 1; i < N; i++)
	{
		int snowmanNumber, mass;
		scanf(" %i %i", &snowmanNumber, &mass);
		arr[i] = new LinkedStack(arr[snowmanNumber]);
		if (mass > 0)
		{
			arr[i]->Push(mass);
		}
		else
		{
			LinkedStack::Pop(arr[i]);
		}
	}

	long long total = 0;
	for (size_t i = 0; i < N; i++)
	{
		total += arr[i]->mass;
	}

	printf("%lld \n", total);

	fclose(stdin);
	fclose(stdout);

	for (size_t i = 0; i < N; i++)
	{
		delete arr[i];
	}

	return 0;
}