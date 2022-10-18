#pragma once
#include <vector>

#pragma region DATA VARIABLES

/// <summary>
/// Data Value Stored on Stack, Queue and Linked List Implementations
/// </summary>
struct data {
    int key; //decimal key
    char* value; //null ended string
};
typedef struct data Data;

#pragma endregion


#pragma region DATA STRUCTURES

struct mySparseMatrix {
    int row;
    int col;
    std::vector<std::vector<Data*>> arr;
};
typedef struct mySparseMatrix MySparseMatrix;


struct myQueue {
    int front, back, size;
    int capacity;
    Data** arr;
};
typedef struct myQueue MyQueue;


struct myStack {
    unsigned int capacity;
    int top;
    Data** arr;
};
typedef struct myStack MyStack;

#pragma endregion