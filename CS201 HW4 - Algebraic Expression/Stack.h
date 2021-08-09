/*
* Title: Algebraic Expression
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 4
* Description: Header file for Stack
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

class Stack {

public:
    Stack();

    Stack(const Stack &aStack);

    ~Stack();

    bool isEmpty() const;

    bool push(string newItem);

    bool pop();

    bool pop(string &stackTop);

    bool getTop(string &stackTop) const;

private:
    struct StackNode {            // a node on the stack
        string item;        // a data item on the stack
        StackNode *next;        // pointer to next node
    };

    StackNode *topPtr;     // pointer to first node in the stack
};


#endif //STACK_H
