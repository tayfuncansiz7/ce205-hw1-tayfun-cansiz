#include "myqueue.h"

#pragma region QUEUE FUNCTIONS

int enqueue(MyQueue* myQueue, Data* data) {
	if (myQueue->size == myQueue->capacity)
	{
		return 0;
	}
	myQueue->back = (myQueue->back + 1) % myQueue->capacity;
	myQueue->arr[myQueue->back] = data;
	myQueue->size = myQueue->size + 1;
}

Data* dequeue(MyQueue* myQueue) {
	if (myQueue->size == 0)
	{
		return 0;
	}
	Data* data = myQueue->arr[myQueue->front];
	myQueue->front = (myQueue->front + 1) % myQueue->capacity;
	myQueue->size = myQueue->size - 1;
	return data;
}

Data* front(MyQueue* myQueue) {
	// Empty condition to check
	if (myQueue->size == 0) {
		return 0;
	}
	return myQueue->arr[myQueue->front];
}

Data* back(MyQueue* myQueue) {
	// Empty condition to check
	if (myQueue->size == 0) {
		return 0;
	}
	return myQueue->arr[myQueue->back];
}

int queueLength(MyQueue* myQueue) {
	return myQueue->capacity;
}
#pragma endregion