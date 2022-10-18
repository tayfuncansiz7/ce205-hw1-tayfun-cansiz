#include "CppUnitTest.h"
#include "..\mylibcpp\mydata.h"
#include "..\mylibcpp\myqueue.h"
#include "..\mylibcpp\mystack.h"
#include "..\mylibcpp\mysparsematrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace mylibcpptest
{
	TEST_CLASS(mylibcppteststack)
	{
	public:

		TEST_METHOD(TestStackPushWorking)
		{

			MyStack* stack = new MyStack();

			stack->top = -1;
			stack->capacity = 1;
			stack->arr = (Data**)malloc(stack->capacity * sizeof(Data*));

			Data* dataStored = new Data();
			Data* dataRestored = 0;

			dataStored->value = new char[12]{ "Hello" };
			dataStored->key = 100;

			push(stack, dataStored);

			dataRestored = pop(stack);

			Assert::AreEqual(dataRestored->key, dataStored->key);
			Assert::AreEqual(dataRestored->value, dataStored->value);

			delete[] dataStored->value;
			delete dataStored;
		}

		TEST_METHOD(TestStackPopWorking)
		{
			MyStack* stack = new MyStack();

			stack->top = -1;
			stack->capacity = 1;
			stack->arr = (Data**)malloc(stack->capacity * sizeof(Data*));

			Data* dataStored = new Data();
			Data* dataRestored = 0;

			dataStored->value = new char[12]{ "Hello" };
			dataStored->key = 100;

			push(stack, dataStored);

			dataRestored = pop(stack);

			Assert::AreEqual(dataRestored->key, dataStored->key);
			Assert::AreEqual(dataRestored->value, dataStored->value);

			delete[] dataStored->value;
			delete dataStored;
		}

		TEST_METHOD(TestStackTopWorking)
		{
			MyStack* stack = new MyStack();

			stack->top = -1;
			stack->capacity = 3;
			stack->arr = (Data**)malloc(stack->capacity * sizeof(Data*));

			Data* dataStored1 = new Data();
			Data* dataStored2 = new Data();
			Data* dataStored3 = new Data();
			Data* dataRestored = 0;

			dataStored1->value = new char[12]{ "Hello1" };
			dataStored1->key = 101;

			dataStored2->value = new char[12]{ "Hello2" };
			dataStored2->key = 102;

			dataStored3->value = new char[12]{ "Hello3" };
			dataStored3->key = 103;

			push(stack, dataStored1);
			push(stack, dataStored2);
			push(stack, dataStored3);

			dataRestored = top(stack);

			Assert::AreEqual(dataRestored->key, dataStored3->key);
			Assert::AreEqual(dataRestored->value, dataStored3->value);

			delete[] dataStored1->value;
			delete dataStored1;
			delete[] dataStored2->value;
			delete dataStored2;
			delete[] dataStored3->value;
			delete dataStored3;
		}

		TEST_METHOD(TestStackBottomWorking)
		{
			MyStack* stack = new MyStack();

			stack->top = -1;
			stack->capacity = 3;
			stack->arr = (Data**)malloc(stack->capacity * sizeof(Data*));

			Data* dataStored1 = new Data();
			Data* dataStored2 = new Data();
			Data* dataStored3 = new Data();
			Data* dataRestored = 0;

			dataStored1->value = new char[12]{ "Hello1" };
			dataStored1->key = 101;

			dataStored2->value = new char[12]{ "Hello2" };
			dataStored2->key = 102;

			dataStored3->value = new char[12]{ "Hello3" };
			dataStored3->key = 103;

			push(stack, dataStored1);
			push(stack, dataStored2);
			push(stack, dataStored3);

			dataRestored = bottom(stack);

			Assert::AreEqual(dataRestored->key, dataStored1->key);
			Assert::AreEqual(dataRestored->value, dataStored1->value);

			delete[] dataStored1->value;
			delete dataStored1;
			delete[] dataStored2->value;
			delete dataStored2;
			delete[] dataStored3->value;
			delete dataStored3;
		}

		TEST_METHOD(TestStackLengthWorking)
		{
			MyStack* stack = new MyStack();

			stack->top = -1;
			stack->capacity = 3;
			stack->arr = (Data**)malloc(stack->capacity * sizeof(Data*));

			Data* dataStored1 = new Data();
			Data* dataStored2 = new Data();
			Data* dataStored3 = new Data();
			int length = -1;

			dataStored1->value = new char[12]{ "Hello1" };
			dataStored1->key = 101;

			dataStored2->value = new char[12]{ "Hello2" };
			dataStored2->key = 102;

			dataStored3->value = new char[12]{ "Hello3" };
			dataStored3->key = 103;

			push(stack, dataStored1);
			push(stack, dataStored2);
			push(stack, dataStored3);

			length = stackLength(stack);

			Assert::AreEqual(length, 3);

			delete[] dataStored1->value;
			delete dataStored1;
			delete[] dataStored2->value;
			delete dataStored2;
			delete[] dataStored3->value;
			delete dataStored3;
		}

	};

	TEST_CLASS(mylibcpptestqueue)
	{
	public:

		TEST_METHOD(TestQueueEnqueueWorking)
		{
			MyQueue* queue = new MyQueue();
			queue->capacity = 100;
			queue->front, queue->size = 0;
			queue->back = queue->capacity - 1;
			queue->arr = (Data**)malloc(sizeof(Data*) * queue->capacity);

			Data* dataStored1 = new Data();
			Data* dataStored2 = new Data();
			Data* dataStored3 = new Data();

			Data* dataRestored = new Data();

			dataStored1->value = new char[12]{ "Hello1" };
			dataStored1->key = 101;

			dataStored2->value = new char[12]{ "Hello2" };
			dataStored2->key = 102;

			dataStored3->value = new char[12]{ "Hello3" };
			dataStored3->key = 103;

			enqueue(queue, dataStored1);
			enqueue(queue, dataStored2);
			enqueue(queue, dataStored3);

			dataRestored = dequeue(queue);

			Assert::AreEqual(dataRestored->key, dataStored1->key);
			Assert::AreEqual(dataRestored->value, dataStored1->value);

			delete[] dataStored1->value;
			delete dataStored1;
			delete[] dataStored2->value;
			delete dataStored2;
			delete[] dataStored3->value;
			delete dataStored3;
		}

		TEST_METHOD(TestQueueDequeueWorking)
		{
			MyQueue* queue = new MyQueue();
			queue->capacity = 100;
			queue->front, queue->size = 0;
			queue->back = queue->capacity - 1;
			queue->arr = (Data**)malloc(sizeof(Data*) * queue->capacity);

			Data* dataStored1 = new Data();
			Data* dataStored2 = new Data();
			Data* dataStored3 = new Data();

			dataStored1->value = new char[12]{ "Hello1" };
			dataStored1->key = 101;

			dataStored2->value = new char[12]{ "Hello2" };
			dataStored2->key = 102;

			dataStored3->value = new char[12]{ "Hello3" };
			dataStored3->key = 103;

			enqueue(queue, dataStored1);
			enqueue(queue, dataStored2);
			enqueue(queue, dataStored3);

			Data* dataRestored = dequeue(queue);

			Assert::AreEqual(dataRestored->key, dataStored1->key);
			Assert::AreEqual(dataRestored->value, dataStored1->value);

			delete[] dataStored1->value;
			delete dataStored1;
			delete[] dataStored2->value;
			delete dataStored2;
			delete[] dataStored3->value;
			delete dataStored3;
		}

		TEST_METHOD(TestQueueFrontWorking)
		{
			MyQueue* queue = new MyQueue();
			queue->capacity = 100;
			queue->front, queue->size = 0;
			queue->back = queue->capacity - 1;
			queue->arr = (Data**)malloc(sizeof(Data*) * queue->capacity);

			Data* dataStored1 = new Data();
			Data* dataStored2 = new Data();
			Data* dataStored3 = new Data();

			dataStored1->value = new char[12]{ "Hello1" };
			dataStored1->key = 101;

			dataStored2->value = new char[12]{ "Hello2" };
			dataStored2->key = 102;

			dataStored3->value = new char[12]{ "Hello3" };
			dataStored3->key = 103;

			enqueue(queue, dataStored1);
			enqueue(queue, dataStored2);
			enqueue(queue, dataStored3);

			Data* dataRestored = front(queue);

			Assert::AreEqual(dataRestored->key, dataStored1->key);
			Assert::AreEqual(dataRestored->value, dataStored1->value);

			delete[] dataStored1->value;
			delete dataStored1;
			delete[] dataStored2->value;
			delete dataStored2;
			delete[] dataStored3->value;
			delete dataStored3;
		}

		TEST_METHOD(TestQueueBackWorking)
		{
			MyQueue* queue = new MyQueue();
			queue->capacity = 100;
			queue->front, queue->size = 0;
			queue->back = queue->capacity - 1;
			queue->arr = (Data**)malloc(sizeof(Data*) * queue->capacity);

			Data* dataStored1 = new Data();
			Data* dataStored2 = new Data();
			Data* dataStored3 = new Data();

			dataStored1->value = new char[12]{ "Hello1" };
			dataStored1->key = 101;

			dataStored2->value = new char[12]{ "Hello2" };
			dataStored2->key = 102;

			dataStored3->value = new char[12]{ "Hello3" };
			dataStored3->key = 103;

			enqueue(queue, dataStored1);
			enqueue(queue, dataStored2);
			enqueue(queue, dataStored3);

			Data* dataRestored = back(queue);

			Assert::AreEqual(dataRestored->key, dataStored3->key);
			Assert::AreEqual(dataRestored->value, dataStored3->value);

			delete[] dataStored1->value;
			delete dataStored1;
			delete[] dataStored2->value;
			delete dataStored2;
			delete[] dataStored3->value;
			delete dataStored3;
		}

		TEST_METHOD(TestQueueLengthWorking)
		{
			MyQueue* queue = new MyQueue();
			queue->capacity = 100;
			queue->front, queue->size = 0;
			queue->back = queue->capacity - 1;
			queue->arr = (Data**)malloc(sizeof(Data*) * queue->capacity);

			Data* dataStored1 = new Data();
			Data* dataStored2 = new Data();
			Data* dataStored3 = new Data();
			int length = 0;

			dataStored1->value = new char[12]{ "Hello1" };
			dataStored1->key = 101;

			dataStored2->value = new char[12]{ "Hello2" };
			dataStored2->key = 102;

			dataStored3->value = new char[12]{ "Hello3" };
			dataStored3->key = 103;

			enqueue(queue, dataStored1);
			enqueue(queue, dataStored2);
			enqueue(queue, dataStored3);

			dequeue(queue);

			length = queueLength(queue);

			Assert::AreEqual(2, queue->size);

			delete[] dataStored1->value;
			delete dataStored1;
			delete[] dataStored2->value;
			delete dataStored2;
			delete[] dataStored3->value;
			delete dataStored3;
		}
	};

	TEST_CLASS(mylibcpptestsparsematrix)
	{
	public:

		TEST_METHOD(TestSparseMatrixInsertWorking)
		{
			MySparseMatrix* matrix = new MySparseMatrix();
			matrix = initSparseMatrix(5, 6);

			Data* dataStored1 = new Data();
			Data* dataStored2 = new Data();
			Data* dataStored3 = new Data();

			dataStored1->value = new char[12]{ "Hello1" };
			dataStored1->key = 101;

			dataStored2->value = new char[12]{ "Hello2" };
			dataStored2->key = 102;

			dataStored3->value = new char[12]{ "Hello3" };
			dataStored3->key = 103;

			insertSparseMatrix(matrix, 4, 5, dataStored1);
			insertSparseMatrix(matrix, 1, 5, dataStored2);
			insertSparseMatrix(matrix, 0, 5, dataStored3);

			Assert::AreEqual(dataStored1->key, getSparseMatrix(matrix, 4, 5)->key);
			Assert::AreEqual(dataStored1->value, getSparseMatrix(matrix, 4, 5)->value);

			Assert::AreEqual(dataStored2->key, getSparseMatrix(matrix, 1, 5)->key);
			Assert::AreEqual(dataStored2->value, getSparseMatrix(matrix, 1, 5)->value);

			Assert::AreEqual(dataStored3->key, getSparseMatrix(matrix, 0, 5)->key);
			Assert::AreEqual(dataStored3->value, getSparseMatrix(matrix, 0, 5)->value);

			delete[] dataStored1->value;
			delete dataStored1;
			delete[] dataStored2->value;
			delete dataStored2;
			delete[] dataStored3->value;
			delete dataStored3;
		}

		TEST_METHOD(TestSparseMatrixGetWorking)
		{
			MySparseMatrix* matrix = initSparseMatrix(5, 6);

			Data* dataStored1 = new Data();
			Data* dataStored2 = new Data();
			Data* dataStored3 = new Data();

			dataStored1->value = new char[12]{ "Hello1" };
			dataStored1->key = 101;

			dataStored2->value = new char[12]{ "Hello2" };
			dataStored2->key = 102;

			dataStored3->value = new char[12]{ "Hello3" };
			dataStored3->key = 103;

			insertSparseMatrix(matrix, 4, 5, dataStored1);
			insertSparseMatrix(matrix, 1, 5, dataStored2);
			insertSparseMatrix(matrix, 0, 5, dataStored3);

			Assert::AreEqual(dataStored1->key, getSparseMatrix(matrix, 4, 5)->key);
			Assert::AreEqual(dataStored1->value, getSparseMatrix(matrix, 4, 5)->value);

			Assert::AreEqual(dataStored2->key, getSparseMatrix(matrix, 1, 5)->key);
			Assert::AreEqual(dataStored2->value, getSparseMatrix(matrix, 1, 5)->value);

			Assert::AreEqual(dataStored3->key, getSparseMatrix(matrix, 0, 5)->key);
			Assert::AreEqual(dataStored3->value, getSparseMatrix(matrix, 0, 5)->value);

			delete[] dataStored1->value;
			delete dataStored1;
			delete[] dataStored2->value;
			delete dataStored2;
			delete[] dataStored3->value;
			delete dataStored3;
		}

		TEST_METHOD(TestSparseMatrixDeleteWorking)
		{
			MySparseMatrix* matrix = new MySparseMatrix();
			matrix = initSparseMatrix(5, 6);

			Data* dataStored1 = new Data();
			Data* dataStored2 = new Data();
			Data* dataStored3 = new Data();

			Data* deletedData = new Data();
			deletedData->key = 0;
			deletedData->value = new char[12]{ '0' };

			dataStored1->value = new char[12]{ "Hello1" };
			dataStored1->key = 101;

			dataStored2->value = new char[12]{ "Hello2" };
			dataStored2->key = 102;

			dataStored3->value = new char[12]{ "Hello3" };
			dataStored3->key = 103;

			insertSparseMatrix(matrix, 4, 5, dataStored1);
			insertSparseMatrix(matrix, 1, 5, dataStored2);
			insertSparseMatrix(matrix, 0, 5, dataStored3);

			deleteSparseMatrix(matrix, 4, 5);

			Assert::AreEqual(deletedData->key, getSparseMatrix(matrix, 4, 5)->key);
			Assert::AreNotEqual(deletedData->value, getSparseMatrix(matrix, 4, 5)->value);

			Assert::AreEqual(dataStored2->key, getSparseMatrix(matrix, 1, 5)->key);
			Assert::AreEqual(dataStored2->value, getSparseMatrix(matrix, 1, 5)->value);

			Assert::AreEqual(dataStored3->key, getSparseMatrix(matrix, 0, 5)->key);
			Assert::AreEqual(dataStored3->value, getSparseMatrix(matrix, 0, 5)->value);

			delete[] dataStored1->value;
			delete dataStored1;
			delete[] dataStored2->value;
			delete dataStored2;
			delete[] dataStored3->value;
			delete dataStored3;
		}

		TEST_METHOD(TestSparseMatrixCopyWorking)
		{
			MySparseMatrix* matrix = new MySparseMatrix();
			matrix = initSparseMatrix(5, 6);

			MySparseMatrix* matrix2 = new MySparseMatrix();
			matrix2 = initSparseMatrix(5, 6);

			Data* dataStored1 = new Data();
			Data* dataStored2 = new Data();
			Data* dataStored3 = new Data();

			dataStored1->value = new char[12]{ "Hello1" };
			dataStored1->key = 101;

			dataStored2->value = new char[12]{ "Hello2" };
			dataStored2->key = 102;

			dataStored3->value = new char[12]{ "Hello3" };
			dataStored3->key = 103;

			insertSparseMatrix(matrix, 4, 5, dataStored1);
			insertSparseMatrix(matrix, 1, 5, dataStored2);
			insertSparseMatrix(matrix, 0, 5, dataStored3);

			copySparseMatrix(matrix, matrix2);

			Assert::AreEqual(dataStored1->key, getSparseMatrix(matrix, 4, 5)->key);
			Assert::AreEqual(dataStored1->value, getSparseMatrix(matrix, 4, 5)->value);

			Assert::AreEqual(dataStored2->key, getSparseMatrix(matrix, 1, 5)->key);
			Assert::AreEqual(dataStored2->value, getSparseMatrix(matrix, 1, 5)->value);

			Assert::AreEqual(dataStored3->key, getSparseMatrix(matrix, 0, 5)->key);
			Assert::AreEqual(dataStored3->value, getSparseMatrix(matrix, 0, 5)->value);

			delete[] dataStored1->value;
			delete dataStored1;
			delete[] dataStored2->value;
			delete dataStored2;
			delete[] dataStored3->value;
			delete dataStored3;
		}

		TEST_METHOD(TestSparseMatrixDestroyWorking)
		{
			MySparseMatrix* matrix = new MySparseMatrix();
			matrix = initSparseMatrix(5, 6);

			Data* dataStored1 = new Data();
			Data* dataStored2 = new Data();
			Data* dataStored3 = new Data();

			Data* deletedData = new Data();
			deletedData->key = 0;
			deletedData->value = new char[12]{ '0' };

			dataStored1->value = new char[12]{ "Hello1" };
			dataStored1->key = 101;

			dataStored2->value = new char[12]{ "Hello2" };
			dataStored2->key = 102;

			dataStored3->value = new char[12]{ "Hello3" };
			dataStored3->key = 103;

			insertSparseMatrix(matrix, 4, 5, dataStored1);
			insertSparseMatrix(matrix, 1, 5, dataStored2);
			insertSparseMatrix(matrix, 0, 5, dataStored3);

			deleteSparseMatrix(matrix);

			Assert::AreEqual(deletedData->key, getSparseMatrix(matrix, 4, 5)->key);
			Assert::AreNotEqual(deletedData->value, getSparseMatrix(matrix, 4, 5)->value);

			Assert::AreEqual(deletedData->key, getSparseMatrix(matrix, 1, 5)->key);
			Assert::AreNotEqual(deletedData->value, getSparseMatrix(matrix, 1, 5)->value);

			Assert::AreEqual(deletedData->key, getSparseMatrix(matrix, 0, 5)->key);
			Assert::AreNotEqual(deletedData->value, getSparseMatrix(matrix, 0, 5)->value);

			delete[] dataStored1->value;
			delete dataStored1;
			delete[] dataStored2->value;
			delete dataStored2;
			delete[] dataStored3->value;
			delete dataStored3;
		}
	};
}
