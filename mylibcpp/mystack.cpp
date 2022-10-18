#include "mystack.h"

#pragma region STACK FUNCTIONS

int push(MyStack* myStack, Data* data) {
	if (myStack->top == myStack->capacity - 1)
	{
		return -1;
	}
	myStack->arr[++myStack->top] = data;
}

Data* pop(MyStack* myStack) {
	if (myStack->top == -1)
	{
		return 0;
	}
	return myStack->arr[myStack->top--];
}
Data* top(MyStack* myStack)
{
	if (myStack->top == -1)
	{
		return 0;
	}
	return myStack->arr[myStack->top];
}

Data* bottom(MyStack* myStack)
{
	if (myStack->top == -1)
	{
		return 0;
	}
	return myStack->arr[0];
}

int stackLength(MyStack* myStack) {
	return myStack->top + 1;
}
#pragma endregion